using System;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class TextClock : MonoBehaviour
{
    private TextMeshProUGUI textClock;
    string amPM = "AM";

    void Start ()
    {
        textClock = GetComponent<TextMeshProUGUI>();
    }
	
    void Update ()
    {
        SetTime();
    }
        
    public void SetTime()
    {
        DateTime time = DateTime.Now;
        
        int hour = time.Hour % 12;
        if (hour == 0)
        {
            hour = 12;   
        }
        if(hour < 12)
        {
            amPM = "PM";
        }
        
        int minute = time.Minute;
        int second = time.Second;

        string mins = ConvertToTwoDigit(minute);
        string seconds = ConvertToTwoDigit(second);

        textClock.text = DateTime.Now.DayOfWeek + " | ".ToString() +hour +  ":" + mins + " " + amPM;
    }

    string ConvertToTwoDigit(int incomingValue)
    {
        
        string currentString = incomingValue.ToString();
        if(currentString.Length == 1)
        {
            currentString = "0" + currentString;
        }
        return currentString;
    }
}
