using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.IO;
using System.Linq;
using UnityEditor;


public class SpeechRecognition : MonoBehaviour
{
    [SerializeField] private Button startButton;
    [SerializeField] private Button stopButton;
    [SerializeField] private TMP_InputField Inputtext;
    public MicrophoneInstance microphoneInstance;
    public bool recording;
    public DeepgramInstance deepgramInstance;
    // Start is called before the first frame update
    void Start()
    {
        startButton.onClick.AddListener(StartRecording);
        stopButton.onClick.AddListener(StopRecording);
        stopButton.interactable = false;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    
    private void StartRecording() {
        //text.color = Color.white;
        Inputtext.text = "Recording...";
        startButton.interactable = false;
        stopButton.interactable = true;
        microphoneInstance.StartMicrophone();
        recording = true;
    }
    
    private void StopRecording() {
        microphoneInstance.StopMicrophone();
        Debug.Log("stopped recording");
        deepgramInstance.conversation = null;
        stopButton.interactable = false;
        startButton.interactable = true;
        if(Inputtext.text == "Recording...") Inputtext.text = "";
    }
    
    
    
}