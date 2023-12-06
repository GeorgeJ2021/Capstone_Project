using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ChangingColor : MonoBehaviour
{
     public Material colour;
     public GameObject head,body;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void ChangeColor()
    {
        head.GetComponent<SkinnedMeshRenderer> ().material = colour;
        body.GetComponent<SkinnedMeshRenderer> ().material = colour;
    }
}
