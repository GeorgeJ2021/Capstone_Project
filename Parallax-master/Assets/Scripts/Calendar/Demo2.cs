using UnityEngine;
using EasyUI.Popup;

public class Demo2 : MonoBehaviour {

	void Start ( ) {

		// First Dialog -----------------------------
		PopupUI.Instance
		.SetTitle ( "Message 1" )
		.SetMessage ( "Hello!" )
		.SetButtonColor ( PopupButtonColor.Blue )
		.OnClose ( ( ) => Debug.Log ( "Closed 1" ) )
		.Show ( );


		// Second Dialog ----------------------------
		PopupUI.Instance
		.SetTitle ( "Message 2" )
		.SetMessage ( "Hello Again :)" )
		.SetButtonColor ( PopupButtonColor.Magenta )
		.SetButtonText ( "ok" )
		.OnClose ( ( ) => Debug.Log ( "Closed 2" ) )
		.Show ( );


		// Third Dialog -----------------------------
		PopupUI.Instance
		.SetTitle ( "Message 3" )
		.SetMessage ( "Bye!" )
		.SetFadeInDuration ( 1f )
		.SetButtonColor ( PopupButtonColor.Red )
		.OnClose ( ( ) => Debug.Log ( "Closed 3" ) )
		.Show ( );

	}

}
