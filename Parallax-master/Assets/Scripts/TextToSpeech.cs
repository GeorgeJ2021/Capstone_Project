using System;
using System.Collections;
using System.IO;
using System.Text;
using UnityEngine;
using UnityEngine.Networking;

public class TextToSpeech : MonoBehaviour
{
    public ConfigDeepGram config;
    public string text = "Hello, how can I help you today?";
    public DeepgramInstance deepgramInstance;
    public CharTextureLoader charTextureLoader;
    public bool ttsStatus;
    public void Start()
    {
        StartCoroutine(SendRequest(text));
    }
    

private IEnumerator SendRequest(string text)
{
    ttsStatus = true;
    // Define your JSON object
    string json = "{\"text\": \"" + text + "\"}";

    // Create a UnityWebRequest
    UnityWebRequest www = new UnityWebRequest(config.voiceURL, "POST");
    byte[] bodyRaw = Encoding.UTF8.GetBytes(json);
    www.uploadHandler = new UploadHandlerRaw(bodyRaw);
    www.downloadHandler = new DownloadHandlerBuffer();
    www.SetRequestHeader("Content-Type", "application/json");
    www.SetRequestHeader("Authorization", "token " + config.apiKey);

    // Send the request and wait for a response
    //deepgramInstance.DisconnectSocket();
    yield return www.SendWebRequest();

    if (www.result != UnityWebRequest.Result.Success)
    {
        Debug.Log(www.error);
        ttsStatus = false;
    }
    else
    {
        // Get the audio data from the response
        byte[] audioData = www.downloadHandler.data;

        // Convert the audio data to an AudioClip
        AudioClip audioClip = ToAudioClip(audioData);
    
        // Play the audio clip
        AudioSource audioSource = GetComponent<AudioSource>();
        audioSource.clip = audioClip;
        audioSource.Play();
        charTextureLoader.talking = 1;
        www.Abort();
        www.Dispose();
      //  deepgramInstance.ConnectSocket();
        yield return new WaitForSeconds(audioClip.length);
        
    }
    ttsStatus = false;
    charTextureLoader.talking = 0;
}

private AudioClip ToAudioClip(byte[] wav)
{
    // Convert the audio data to an AudioClip
    // Note: This assumes the audio data is in WAV format
    using (var stream = new MemoryStream(wav))
    {
        var reader = new System.IO.BinaryReader(stream);
        var riff = reader.ReadBytes(4);
        var chunkSize = reader.ReadUInt32();
        var format = reader.ReadBytes(4);
        var subchunk1ID = reader.ReadBytes(4);
        var subchunk1Size = reader.ReadUInt32();
        var audioFormat = reader.ReadUInt16();
        var numChannels = reader.ReadUInt16();
        var sampleRate = reader.ReadUInt32();
        var byteRate = reader.ReadUInt32();
        var blockAlign = reader.ReadUInt16();
        var bitsPerSample = reader.ReadUInt16();
        var datastring = new string(reader.ReadChars(4));
        var subchunk2Size = reader.ReadUInt32();

        var bytes = new float[wav.Length / 2];

        for (int i = 44; i < wav.Length; i += 2)
        {
            bytes[i / 2] = BitConverter.ToInt16(wav, i) / 32768.0F;
        }

        var audioClip = AudioClip.Create("testSound", bytes.Length, 1, (int)sampleRate, false);
        audioClip.SetData(bytes, 0);

        return audioClip;
    }
}

}
