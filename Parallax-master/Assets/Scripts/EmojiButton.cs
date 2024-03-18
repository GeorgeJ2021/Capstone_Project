using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EmojiButton : MonoBehaviour
{
    [SerializeField] private SaveAndLoad saveAndLoad;
    // Start is called before the first frame update
    public void Excellent()
    {
        var date = DateTime.Now.ToString().Split()[0];
        var dateList = Array.ConvertAll(date.Split('-'), int.Parse);
        Debug.Log(date);
        var moodJournal = new MoodJournal();
        moodJournal.emotion = "Excellent";
        moodJournal.day = dateList[0];
        moodJournal.month = dateList[1];
        moodJournal.year = dateList[2];
        saveAndLoad.gameData.moodJournal.Add(moodJournal);
        saveAndLoad.Save();
    }
    
    public void Good()
    {
        var date = DateTime.Now.ToString().Split()[0];
        var dateList = Array.ConvertAll(date.Split('-'), int.Parse);
        Debug.Log(date);
        var moodJournal = new MoodJournal();
        moodJournal.emotion = "Good";
        moodJournal.day = dateList[0];
        moodJournal.month = dateList[1];
        moodJournal.year = dateList[2];
        saveAndLoad.gameData.moodJournal.Add(moodJournal);
        saveAndLoad.Save();
    }    
    
    public void Okay()
    {
        var date = DateTime.Now.ToString().Split()[0];
        var dateList = Array.ConvertAll(date.Split('-'), int.Parse);
        Debug.Log(date);
        var moodJournal = new MoodJournal();
        moodJournal.emotion = "Okay";
        moodJournal.day = dateList[0];
        moodJournal.month = dateList[1];
        moodJournal.year = dateList[2];
        saveAndLoad.gameData.moodJournal.Add(moodJournal);
        saveAndLoad.Save();
    } 
    
    public void Bad()
    {
        var date = DateTime.Now.ToString().Split()[0];
        var dateList = Array.ConvertAll(date.Split('-'), int.Parse);
        Debug.Log(date);
        var moodJournal = new MoodJournal();
        moodJournal.emotion = "Bad";
        moodJournal.day = dateList[0];
        moodJournal.month = dateList[1];
        moodJournal.year = dateList[2];
        saveAndLoad.gameData.moodJournal.Add(moodJournal);
        saveAndLoad.Save();
    } 
    
    public void Terrible()
    {
        var date = DateTime.Now.ToString().Split()[0];
        var dateList = Array.ConvertAll(date.Split('-'), int.Parse);
        Debug.Log(date);
        var moodJournal = new MoodJournal();
        moodJournal.emotion = "Terrible";
        moodJournal.day = dateList[0];
        moodJournal.month = dateList[1];
        moodJournal.year = dateList[2];
        saveAndLoad.gameData.moodJournal.Add(moodJournal);
        saveAndLoad.Save();
    } 
    
    public void Sad()
    {
        var date = DateTime.Now.ToString().Split()[0];
        var dateList = Array.ConvertAll(date.Split('-'), int.Parse);
        Debug.Log(date);
        var moodJournal = new MoodJournal();
        moodJournal.emotion = "Sad";
        moodJournal.day = dateList[0];
        moodJournal.month = dateList[1];
        moodJournal.year = dateList[2];
        saveAndLoad.gameData.moodJournal.Add(moodJournal);
        saveAndLoad.Save();
    }
}


