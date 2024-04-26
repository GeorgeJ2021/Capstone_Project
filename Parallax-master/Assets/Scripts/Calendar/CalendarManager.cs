using System;
using System.Globalization;
using UnityEngine;
using EasyUI.Popup;
using EasyUI.Dialogs;

public class CalendarManager : MonoBehaviour
{
	#region Fields

	[SerializeField]
	private HeaderManager headerManager;

	[SerializeField]
	private BodyManager bodyManager;

	[SerializeField]
	private TailManager tailManager;

	[SerializeField] private SaveAndLoad saveAndLoad;

	private DateTime targetDateTime;
	private CultureInfo cultureInfo;

	#endregion

	#region Public Methods

	public void OnGoToPreviousOrNextMonthButtonClicked(string param)
	{
		targetDateTime = targetDateTime.AddMonths(param == "Prev" ? -1 : 1);
		Refresh(targetDateTime.Year, targetDateTime.Month, targetDateTime.Day);
	}

	#endregion

	#region Private Methods

	private void Start()
	{
		targetDateTime = DateTime.Now;
		cultureInfo = new CultureInfo("en-US");
		Refresh(targetDateTime.Year, targetDateTime.Month, targetDateTime.Day);
		
	}

	#endregion

	#region Event Handlers
	
	private string EntryExistsForDate(string day, string month, string year)
	{
		foreach (var entry in saveAndLoad.gameData.moodJournal)
		{
			if (entry.day.ToString() == day && entry.month.ToString() == month && entry.year.ToString() == year)
			{
				return entry.emotion;
			}
		}
		return null;
	}

	public void Refresh(int year, int month, int day)
	{
		headerManager.SetTitle($"{year} {cultureInfo.DateTimeFormat.GetMonthName(month)}");
		bodyManager.Initialize(year, month, day, OnButtonClicked);
	}
	
	public string FindDayOfWeek(string dayStr, string monthStr, string yearStr)
	{
		if (int.TryParse(dayStr, out int day) && int.TryParse(monthStr, out int month) && int.TryParse(yearStr, out int year))
		{
			try
			{
				// Create a DateTime object from the parsed integers
				DateTime date = new DateTime(year, month, day);

				// Get the day of the week
				DayOfWeek dayOfWeek = date.DayOfWeek;

				// Convert day of the week to string
				string dayOfWeekString = dayOfWeek.ToString();

				// Return the day of the week string
				return dayOfWeekString;
			}
			catch (ArgumentOutOfRangeException e)
			{
				Debug.LogError("Invalid date components! " + e.Message);
				return null;
			}
		}
		else
		{
			Debug.LogError("Failed to parse date components!");
			return null;
		}
	}

	private void OnButtonClicked((string day, string month, string year, string legend) param)
	{
		
		DialogUI.Instance
			.SetTitle ( FindDayOfWeek(param.day, param.month, param.year) )
			.SetMessage (EntryExistsForDate(param.day, param.month, param.year))
			.SetDate(param.day, param.month, param.year)
			.OnClose ( ( ) => Debug.Log ( "Closed 1" ) )
			.Show ();
	}

	#endregion
}
