using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Events;
using System.Collections;
using System.Collections.Generic;
 using TMPro;

 namespace EasyUI.Popup {

	public enum PopupButtonColor {
		Black,
		Purple,
		Magenta,
		Blue,
		Green,
		Yellow,
		Orange,
		Red
	}

	public class Popup {
		public string Title = "Title";
		public string Message = "Message goes here.";
		public string ButtonText = "Close";
		public float FadeInDuration = .3f;
		public PopupButtonColor ButtonColor = PopupButtonColor.Black;
		public UnityAction OnClose = null;
	}

	public class PopupUI : MonoBehaviour {
		[SerializeField] GameObject canvas;
		[SerializeField] Text titleUIText;
		[SerializeField] Text messageUIText;
		[SerializeField] Button closeUIButton;

		Image closeUIButtonImage;
		Text closeUIButtonText;
		CanvasGroup canvasGroup;

		[Space ( 20f )]
		[Header ( "Close button colors" )]
		[SerializeField] Color[] buttonColors;

		Queue<Popup> popupQueue = new Queue<Popup> ( );
		Popup popup = new Popup ( );
		public Popup tempPopup;

		[HideInInspector] public bool IsActive = false;

		//Singleton pattern
		public static PopupUI Instance;



		void Awake ( ) {
			Instance = this;

			closeUIButtonImage = closeUIButton.GetComponent <Image> ( );
			closeUIButtonText = closeUIButton.GetComponentInChildren <Text> ( );
			canvasGroup = canvas.GetComponent <CanvasGroup> ( );

			//Add close event listener
			closeUIButton.onClick.RemoveAllListeners ( );
			closeUIButton.onClick.AddListener ( Hide );
		}

		
		public PopupUI SetTitle ( string title ) {
			popup.Title = title;
			return Instance;
		}

		
		public PopupUI SetMessage ( string message ) {
			popup.Message = message;
			return Instance;
		}

		
		public PopupUI SetButtonText ( string text ) {
			popup.ButtonText = text;
			return Instance;
		}

		
		public PopupUI SetButtonColor ( PopupButtonColor color ) {
			popup.ButtonColor = color;
			return Instance;
		}

		
		public PopupUI SetFadeInDuration ( float duration ) {
			popup.FadeInDuration = duration;
			return Instance;
		}

		
		public PopupUI OnClose ( UnityAction action ) {
			popup.OnClose = action;
			return Instance;
		}

		//-------------------------------------
		
		public void Show ( ) {
			popupQueue.Enqueue ( popup );
			//Reset Popup
			popup = new Popup ( );

			if ( !IsActive )
				ShowNextPopup ( );
		}


		void ShowNextPopup ( ) {
			tempPopup = popupQueue.Dequeue ( );

			titleUIText.text = tempPopup.Title;
			messageUIText.text = tempPopup.Message;
			//closeUIButtonText.text = tempPopup.ButtonText.ToUpper ( );
			//closeUIButtonImage.color = buttonColors [ ( int )tempPopup.ButtonColor ];

			canvas.SetActive ( true );
			IsActive = true;
			StartCoroutine ( FadeIn ( tempPopup.FadeInDuration ) );
		}


		// Hide Popup
		public void Hide ( ) {
			canvas.SetActive ( false );
			IsActive = false;

			// Invoke OnClose Event
			if ( tempPopup.OnClose != null )
				tempPopup.OnClose.Invoke ( );

			StopAllCoroutines ( );

			if ( popupQueue.Count != 0 )
				ShowNextPopup ( );
		}


		//-------------------------------------

		IEnumerator FadeIn ( float duration ) {
			float startTime = Time.time;
			float alpha = 0f;

			while ( alpha < 1f ) {
				alpha = Mathf.Lerp ( 0f, 1f, (Time.time - startTime) / duration );
				canvasGroup.alpha = alpha;

				yield return null;
			}
		}
	}

}