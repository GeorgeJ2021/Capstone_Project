using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using UnityEngine;
using UnityEditor;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using NativeWebSocket;
using TMPro;

[System.Serializable]
public class DeepgramResponse
{
    public int[] channel_index;
    public bool is_final;
    public Channel channel;
}

[System.Serializable]
public class Channel
{
    public Alternative[] alternatives;
}

[System.Serializable]
public class Alternative
{
    public string transcript;
}

public class DeepgramInstance : MonoBehaviour
{
    WebSocket websocket;
    public FaceDetect faceDetect;
    public Renderer charRenderer;
    public ConfigDeepGram config;
    public UdpSocket udpSocket;
    public SpeechRecognition speechRecognition;
    [SerializeField] private TMP_InputField Inputtext;
    public string conversation;
    byte[] keepAliveBytes = Encoding.UTF8.GetBytes("{\"type\": \"KeepAlive\"}");
    public MicrophoneInstance microphoneInstance;

    async void Start()
    {
        
        var headers = new Dictionary<string, string>
        {
            { "Authorization", "Token " + config.apiKey }
        };
        websocket = new WebSocket(config.sttUrl + "&sample_rate=" + AudioSettings.outputSampleRate.ToString(), headers);
        
        websocket.OnOpen += () =>
        {
            Debug.Log("Connected to Deepgram!");
        };

        websocket.OnError += (e) =>
        {
            Debug.Log("Error: " + e);
        };

        websocket.OnClose += (e) =>
        {
            Debug.Log("Connection closed!");
        };

        websocket.OnMessage += async (bytes) =>
        {
            var message = System.Text.Encoding.UTF8.GetString(bytes);
            //Debug.Log("OnMessage: " + message);
            
            DeepgramResponse deepgramResponse = new DeepgramResponse();
            object boxedDeepgramResponse = deepgramResponse;
            EditorJsonUtility.FromJsonOverwrite(message, boxedDeepgramResponse);
            deepgramResponse = (DeepgramResponse) boxedDeepgramResponse;
            if (deepgramResponse.is_final)
            {
                var transcript = deepgramResponse.channel.alternatives[0].transcript;
                if (!string.IsNullOrWhiteSpace(transcript) && microphoneInstance.recording)
                {
                    conversation += " " + transcript;
                    Debug.Log(transcript);
                    udpSocket.SendData(conversation);
                    while (udpSocket.text == null) await Task.Yield();
                    string maxEmotion = "Neutral";
                    var maxCount = faceDetect.histogram.Values.Max();
                    Debug.Log(udpSocket.text);
                    if (faceDetect.histogram.Count(kv => kv.Value == maxCount) == 1)
                    {
                        maxEmotion = faceDetect.histogram.Aggregate((l, r) => l.Value > r.Value ? l : r).Key;
                    }

                    Debug.Log("histogram max: " + maxEmotion);
                    string emotion = "";
                    switch (udpSocket.text)
                    {
                        case "Extremely Positive":
                            emotion = "Extremely Happy";
                            break;
                        case "Positive":
                            emotion = "Happy";
                            break;
                        case "Neutral":
                            emotion = "Neutral";
                            break;
                        case "Negative":
                            emotion = "Sad";
                            break;
                        case "Extremely Negative":
                            emotion = "Extremely Sad";
                            break;
                    }

                    Inputtext.text = conversation + ";" + emotion + "," + maxEmotion;
                    faceDetect.ClearHistogramValues();
                }
            }
        };
        await websocket.Connect();

       // await websocket.Connect();
    }
    async void Update()
    {
    #if !UNITY_WEBGL || UNITY_EDITOR
        websocket.DispatchMessageQueue();
    #endif
        
    }

    private async void OnApplicationQuit()
    {
        await websocket.Close();
    }

    public async void ProcessAudio(byte[] audio)
    {
        
        if (websocket.State == WebSocketState.Open)
        {
            await websocket.Send(audio);
        }
        
    }
    


}

