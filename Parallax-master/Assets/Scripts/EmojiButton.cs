using System;
using System.Linq;
using EasyUI.Dialogs;
using TMPro;
using UnityEngine;

public class EmojiButton : MonoBehaviour
{
    [SerializeField] private SaveAndLoad saveAndLoad;
    [SerializeField] private DialogUI dialogUI;
    [SerializeField] private CalendarManager calendarManager;
    private void UpdateOrAddEntry(string emotion)
    {
        var date = dialogUI.currentDate;
        var existingEntry = saveAndLoad.gameData.moodJournal
            .FirstOrDefault(entry => entry.day == date.Day && entry.month == date.Month && entry.year == date.Year);

        if (existingEntry != null)
        {
            existingEntry.emotion = emotion;
        }
        else
        {
            var moodJournal = new MoodJournal
            {
                emotion = emotion,
                day = date.Day,
                month = date.Month,
                year = date.Year
            };
            saveAndLoad.gameData.moodJournal.Add(moodJournal);
        }

        saveAndLoad.Save();
        calendarManager.Refresh(date.Year, date.Month, date.Day);
        dialogUI.Hide();
    }

    public void Excellent()
    {
        UpdateOrAddEntry("Excellent");
    }

    public void Good()
    {
        UpdateOrAddEntry("Good");
    }

    public void Okay()
    {
        UpdateOrAddEntry("Okay");
    }

    public void Bad()
    {
        UpdateOrAddEntry("Bad");
    }

    public void Terrible()
    {
        UpdateOrAddEntry("Terrible");
    }

    public void Sad()
    {
        UpdateOrAddEntry("Sad");
    }
}