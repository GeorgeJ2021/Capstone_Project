using System.Collections;
using System.Collections.Generic;
using System;
using UnityEngine;

[CreateAssetMenu(fileName = "DeepGramConfig", menuName = "DeepGram/DeepGram Configuration")]
public class ConfigDeepGram : ScriptableObject
{
    // Start is called before the first frame update
    
    public string apiKey = Environment.GetEnvironmentVariable("DeepGramAPI", EnvironmentVariableTarget.User);
    public string voiceURL = "https://api.deepgram.com/v1/speak?encoding=linear16";
    public string sttUrl = "wss://api.deepgram.com/v1/listen?encoding=linear16";
}
