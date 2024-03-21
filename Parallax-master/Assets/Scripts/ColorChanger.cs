using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ColorChanger : MonoBehaviour
{
    public GameObject colorbtn, colorMenu, chHead, chBody;
    public Material red, blue, yellow, green, purple, orange;
    //Color32 purple = new Color32(252,3,248,255);
    //Color32 orange = new Color32(252,123,3,255);
    
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
        chHead.GetComponent<Renderer>().material= green;
        chBody.GetComponent<Renderer>().material= green;   
        //chHead.GetComponent<Renderer>().material.SetColor("_Color", Color.green);
        //chBody.GetComponent<Renderer>().material.SetColor("_Color", Color.green);
    }
    public void ChangeRed()
    {
        chHead.GetComponent<Renderer>().material= red;
        chBody.GetComponent<Renderer>().material= red;
    }
    public void ChangeBlue()
    {
        chHead.GetComponent<Renderer>().material= blue;
        chBody.GetComponent<Renderer>().material= blue;
    }
    public void ChangeYellow()
    {
        chHead.GetComponent<Renderer>().material= yellow;
        chBody.GetComponent<Renderer>().material= yellow;
    }
    public void ChangePurple()
    {
        chHead.GetComponent<Renderer>().material= purple;
        chBody.GetComponent<Renderer>().material= purple;
    }
    public void ChangeOrange()
    {
        chHead.GetComponent<Renderer>().material= orange;
        chBody.GetComponent<Renderer>().material= orange;
    }
}
