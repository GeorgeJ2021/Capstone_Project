using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(fileName = "ElevenLabsConfig", menuName = "ElvenLabs/ElvenLabs Configuration")]
public class ElevenLabsConfig : ScriptableObject
{
    public string apiKey = Environment.GetEnvironmentVariable("elevenlabsAPI", EnvironmentVariableTarget.User);
    //public string apiKey = "38f0de67f8bace{delete}e813d55793e3e25082";
    public string voiceId = "zcAOhNBS3c14rBihAFp1";
    public string ttsUrl = "https://api.elevenlabs.io/v1/text-to-speech/zcAOhNBS3c14rBihAFp1/stream";

}
