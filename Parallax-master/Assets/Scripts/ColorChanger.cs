using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ColorChanger : MonoBehaviour
{
    public GameObject colorbtn, colorMenu, chHead, chBody;
    Color32 purple = new Color32(252,3,248,255);
    Color32 orange = new Color32(252,123,3,255);
    
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void OpenColorMenu()
    {
        colorbtn.SetActive(false);
        colorMenu.SetActive(true);
    }
    public void CloseColorMenu()
    {
        colorbtn.SetActive(true);
        colorMenu.SetActive(false);
    }

    public void ChangeGreen()
    {
        chHead.GetComponent<Renderer>().material.SetColor("_Color", Color.green);
        chBody.GetComponent<Renderer>().material.SetColor("_Color", Color.green);
    }
    public void ChangeRed()
    {
        chHead.GetComponent<Renderer>().material.SetColor("_Color", Color.red);
        chBody.GetComponent<Renderer>().material.SetColor("_Color", Color.red);
    }
    public void ChangeBlue()
    {
        chHead.GetComponent<Renderer>().material.SetColor("_Color", Color.cyan);
        chBody.GetComponent<Renderer>().material.SetColor("_Color", Color.cyan);
    }
    public void ChangeYellow()
    {
        chHead.GetComponent<Renderer>().material.SetColor("_Color", Color.yellow);
        chBody.GetComponent<Renderer>().material.SetColor("_Color", Color.yellow);
    }
    public void ChangePurple()
    {
        chHead.GetComponent<Renderer>().material.SetColor("_Color", purple);
        chBody.GetComponent<Renderer>().material.SetColor("_Color", purple);
    }
    public void ChangeOrange()
    {
        chHead.GetComponent<Renderer>().material.SetColor("_Color", orange);
        chBody.GetComponent<Renderer>().material.SetColor("_Color", orange);
    }
}
