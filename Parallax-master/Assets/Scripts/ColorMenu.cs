using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ColorMenu : MonoBehaviour
{
    public GameObject openbutton,backButton;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void openColor()
    {   
        openbutton.gameObject.SetActive(false);
        backButton.gameObject.SetActive(true);
    }
    public void BackButton()
    {
        openbutton.gameObject.SetActive(true);
        backButton.gameObject.SetActive(false);
    }
}
