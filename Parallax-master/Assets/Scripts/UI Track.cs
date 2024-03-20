using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UITrack : MonoBehaviour
{
    // Start is called before the first frame update
    public Transform target;
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (target != null)
        {
            // Rotate this object to look at the target
            transform.LookAt(target);
        }    }
}
