using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.IO;
using System.Linq;
using HuggingFace.API;


public class SpeechRecognition : MonoBehaviour
{
    [SerializeField] private Button startButton;
    [SerializeField] private Button stopButton;
    [SerializeField] private TMP_InputField Inputtext;

    private AudioClip clip;
    private byte[] bytes;
    public bool recording;
    
    public UdpSocket udpSocket;
    public FaceDetect faceDetect;
    public Renderer charRenderer;



    //record Microphone input and encode it in WAV format
    private void Start() {
        startButton.onClick.AddListener(StartRecording);
        stopButton.onClick.AddListener(StopRecording);
        stopButton.interactable = false;
    }

    private void Update() {
        if (recording && Microphone.GetPosition(null) >= clip.samples) {
            StopRecording();
        }
    }

    

    private void StartRecording() {
        //text.color = Color.white;
        Inputtext.text = "Recording...";
        startButton.interactable = false;
        stopButton.interactable = true;
        clip = Microphone.Start(null, false, 10, 44100);
        recording = true;
    }

    //truncate the recording and encode it in WAV format
    private void StopRecording() {
        var position = Microphone.GetPosition(null);
        Microphone.End(null);
        var samples = new float[position * clip.channels];
        clip.GetData(samples, 0);
        bytes = EncodeAsWAV(samples, clip.frequency, clip.channels);
        recording = false;
        SendRecording();
        Debug.Log("stopped recording");
        
        //Un-comment the next line of code and a test.wav file should be saved in Unity Assets folder with the recorded audio.
        //File.WriteAllBytes(Application.dataPath + "/test.wav", bytes);
        
    }

        private void SendRecording() {
        //Inputtext.text.color = Color.yellow;
        Inputtext.text = "Sending...";
        stopButton.interactable = false;
        HuggingFaceAPI.AutomaticSpeechRecognition(bytes, response => {
            //text.color = Color.white;
            Debug.Log(response);
            udpSocket.SendData(response);
            while (udpSocket.text == null) ;
            string maxEmotion = "Neutral";
            var maxCount = faceDetect.histogram.Values.Max();

            if (faceDetect.histogram.Count(kv => kv.Value == maxCount) == 1)
            {
                maxEmotion = faceDetect.histogram.Aggregate((l, r) => l.Value > r.Value ? l : r).Key;
            }
            Debug.Log("histogram max: " + maxEmotion);
            Inputtext.text = response+";"+udpSocket.text+","+maxEmotion;
            faceDetect.ClearHistogramValues();
            startButton.interactable = true;
        }, error => {
            //Inputtext.text.color = Color.red;
            Inputtext.text = error;
            startButton.interactable = true;
        });
    }
    
    //prepare the audio data for the Hugging Face API
    private byte[] EncodeAsWAV(float[] samples, int frequency, int channels) { 
        using (var memoryStream = new MemoryStream(44 + samples.Length * 2)) {
            using (var writer = new BinaryWriter(memoryStream)) {
                writer.Write("RIFF".ToCharArray());
                writer.Write(36 + samples.Length * 2);
                writer.Write("WAVE".ToCharArray());
                writer.Write("fmt ".ToCharArray());
                writer.Write(16);
                writer.Write((ushort)1);
                writer.Write((ushort)channels);
                writer.Write(frequency);
                writer.Write(frequency * channels * 2);
                writer.Write((ushort)(channels * 2));
                writer.Write((ushort)16);
                writer.Write("data".ToCharArray());
                writer.Write(samples.Length * 2);

                foreach (var sample in samples) {
                    writer.Write((short)(sample * short.MaxValue));
                }
            }
            return memoryStream.ToArray();
        }
    }
}
