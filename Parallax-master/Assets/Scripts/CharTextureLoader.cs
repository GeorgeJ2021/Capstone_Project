using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CharTextureLoader : MonoBehaviour
{

    public UdpSocket udpSocket;
    public int talking = 0;
    public int startFlag = 1;

    // Start is called before the first frame update
    void Start()
    {
        udpSocket = GetComponent<UdpSocket>();
    }

    // Update is called once per frame
    void Update()
    {
        if (talking == 1 && startFlag == 1)
        {
            Speak();
            startFlag = 0;
        }
        else if(talking==0)
        {
            GetComponent<Renderer>().material.mainTexture =
                udpSocket.textures[udpSocket.textureFlag]; 
            startFlag = 1;
        }
        
        
    }

    public void Speak()
    {
        GetComponent<Renderer>().material.mainTexture =
            udpSocket.textures[Random.Range(3, 6)]; 
        if (talking == 1)
            Invoke("Speak", 0.1f);
    }
    
    
    
}
