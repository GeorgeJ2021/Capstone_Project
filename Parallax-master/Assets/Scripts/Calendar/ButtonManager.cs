using System;
using System.Linq;
using TMPro;
using UnityEngine;
using UnityEngine.Events;
using UnityEngine.UI;



[RequireComponent(typeof(Button))]
public class ButtonManager : MonoBehaviour
{
	#region Fields

	[SerializeField]
	private TextMeshProUGUI label;
	
	[SerializeField] private SaveAndLoad saveAndLoad;

	private Button button;
	private UnityAction buttonAction;
	
	[System.Serializable]
	public struct EmotionSprite
	{
		public string emotionName;
		public Sprite sprite;
	}

	public EmotionSprite[] emotionSpritesArray;

	#endregion

	#region Public Methods
	
	public Sprite GetSpriteByName(string emotionName)
	{
		// Find the EmotionSprite with the given name
		var emotionSprite = emotionSpritesArray.FirstOrDefault(es => es.emotionName == emotionName);
        
		// Return the sprite if found, otherwise return null
		return emotionSprite.sprite;
	}
	
	private string EntryExistsForDate(string day, string month, string year)
	{
		foreach (var entry in saveAndLoad.gameData.moodJournal)
		{
			if (entry.day.ToString() == day && entry.month.ToString() == month && entry.year.ToString() == year)
			{
				return entry.emotion;
			}
		}
		return "Empty";
	}

	public void Initialize(string label, string month, string year, Action<(string, string,string, string)> clickEventHandler, bool today)
	{
		this.label.text = label;
		saveAndLoad = FindObjectOfType<SaveAndLoad>();
		button.image.sprite = GetSpriteByName(EntryExistsForDate(label, month, year));
		buttonAction += () => clickEventHandler((label, month, year, label));
		button.onClick.AddListener(buttonAction);
		if(today)
		{
			//GetComponent<Image>().color = Color.cyan;
			this.label.text = "Today";
		}
	}

	#endregion

	#region Private Methods

	private void Awake()
	{
		button = GetComponent<Button>();
	}

	private void OnDestroy()
	{
		button.onClick.RemoveListener(buttonAction);
	}

	#endregion
}
