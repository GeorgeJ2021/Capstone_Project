using System;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class Date : MonoBehaviour
{

    public TextMeshProUGUI textMeshPro;
    

    private void Awake()
    {
        textMeshPro = GetComponent<TextMeshProUGUI>();
        var date = DateTime.Now.ToString().Split()[0];
        var time = DateTime.Now.ToString().Split()[1];
        var dateList = Array.ConvertAll(date.Split(new[] {'-', ':'}), int.Parse);    
        switch (this.name)
        {
            case "Day":
                textMeshPro.text = dateList[0].ToString().Length < 2? '0' + dateList[0].ToString() : dateList[0].ToString();
                break;
            case "Month":
                textMeshPro.text = dateList[1].ToString().Length < 2? '0' + dateList[1].ToString() : dateList[1].ToString();
                break;
            case "Year":
                textMeshPro.text = dateList[2].ToString().Substring(2,2);
                break;
        }
    }

    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
