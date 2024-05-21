using System;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class Timer : MonoBehaviour
{
    public float timeRemaining = 10;
    public bool timerIsRunning = false;
    public TextMeshProUGUI timeText;
    public TextMeshProUGUI buttonText;
    public Button button;
    public Button altButton;
    public float backupTime;
    public string backupButtonText;
    public AIController aiController;
    private bool isButtonClicked = false;
    public TextToSpeech sound;
    
    [EditorCools.Button]
    private void CheckFocus() => CheckFocusAlert();


    private void Start()
    {
        backupButtonText = buttonText.text;
    }
    
    public void TaskOnClick()
    {
        if (isButtonClicked)
        {
            StopTimer();
        }
        else
        {
            StartTimer();
        }
        isButtonClicked = !isButtonClicked;
    }

    public void StartTimer()
    {
        // Starts the timer automatically
        timerIsRunning = true;
        buttonText.text = "Stop Timer";
        altButton.interactable = false;

        if (backupButtonText=="Focus")
        {
            aiController.GetMotivation("I'm gonna start a pomodoro time. Give me best wishes and How would u motivate me when I start it.");
        }
        else
        {
            aiController.GetMotivation("I'm gonna start a Break Time.");
        }
    }

    public void StopTimer()
    {
        timerIsRunning = false;
        timeRemaining = backupTime;
        //timeText.text = "Start Timer";
        timeText.text = " ";
        buttonText.text = backupButtonText;
        altButton.interactable = true;
        if (backupButtonText=="Focus")
            aiController.GetMotivation("I've completed the pomodora session");
        else
        {
            aiController.GetMotivation("I've completed my break time");
        }
    }

    void Update()
    {
        if (timerIsRunning)
        {
            if (timeRemaining > 0)
            {
                timeRemaining -= Time.deltaTime;
                DisplayTime(timeRemaining);
            }
            else
            {
                Debug.Log("Time has run out!");
                timeRemaining = 0;
                timerIsRunning = false;
            }
        }
    }

    void DisplayTime(float timeToDisplay)
    {
        timeToDisplay += 1;

        float minutes = Mathf.FloorToInt(timeToDisplay / 60); 
        float seconds = Mathf.FloorToInt(timeToDisplay % 60);
        if((int)timeRemaining==(int)backupTime/2 && backupButtonText == "Focus") CheckFocusAlert();
        timeText.text = string.Format("{0:00}:{1:00}", minutes, seconds);
    }

    void CheckFocusAlert()
    {
        sound.text = "Hey, are you still in the zone, or did the focus monster take a break? ";
        sound.Start();
    }
}
