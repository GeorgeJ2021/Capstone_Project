using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using OpenCVForUnity;
using OpenCVForUnityExample;
using OpenCVForUnity.CoreModule;
using OpenCVForUnity.ObjdetectModule;
using OpenCVForUnity.ImgprocModule;
using Rect = OpenCVForUnity.CoreModule.Rect;
using System;
using System.Drawing;
using UnityEngine.UI;
using OpenCVForUnity.ImgcodecsModule;
using OpenCVForUnity.UnityUtils;
using System.IO;
using Unity.Barracuda;
using System.Linq;
using TMPro;
using Point = OpenCVForUnity.CoreModule.Point;
using Size = OpenCVForUnity.CoreModule.Size;


public class FaceDetect : MonoBehaviour
{
    public NNModel modelAsset;
    private Model _runtimeModel;
    private IWorker _engine;
    private Texture2D bTexture2D;
    
    [Serializable]
    public struct  Prediction
    {
        public int predictedValue;
        private float[] predicted;

        public void SetPrediction(Tensor t)
        {
            predicted = t.AsFloats();
            predictedValue = Array.IndexOf(predicted, predicted.Max());
            Debug.Log($"Predicted {predictedValue}");
            
        }
    }

    public Prediction prediction;
    
    private WebCamTexture webcamTexture;
    private Mat rgbaMat;
    WebCamTextureToMatExample webCamTextureToMat;
    string faceXml_path;
    Mat gray;
    private Texture2D texture;
    private int flag = 1;
    private Mat grayMat;
    MatOfRect faceRect;
    CascadeClassifier classifier;
    private GameObject img;
    public GameObject chat;
    public Vector2 eyeShift;
    public Vector2 converterEye;
    public Vector3 pov;
    List<string> labels = new List<string>() { "Angry", "Disgusted", "Fearful", "Happy", "Neutral", "Sad", "Surprised" };
    
    //intterpolation
    public float moveSpeed;
    private Transform current;
    private Transform target;
    private float sinTime;
    WebCamDevice Device;
    
    // Start is called before the first frame update
    void Start()
    {//test
        
        _runtimeModel = ModelLoader.Load(modelAsset);
        _engine = WorkerFactory.CreateWorker(_runtimeModel, WorkerFactory.Device.GPU);
        prediction = new Prediction();
        //obtain cameras avialable
        img = FindObjectOfType<RawImage>().gameObject;
        WebCamDevice[] cam_devices = WebCamTexture.devices;
        
        foreach (var device in cam_devices) {
            // if (device.isFrontFacing)
            // {
            //     Device = device;
            //     break;
            // }
            // else
            // {
            //     Device = cam_devices[0];
            // }
            Device = cam_devices[1];
        }
        //create camera texture
        webcamTexture = new WebCamTexture(Device.name, 640, 360, 30); //480 width 
        //start camera
        webcamTexture.Play();
        //rotate RawImage according to rotation of webcamtexture
        img.GetComponent<RectTransform>().Rotate(new Vector3(0, 0, 360 - webcamTexture.videoRotationAngle));
        rgbaMat = new Mat(webcamTexture.height, webcamTexture.width, CvType.CV_8UC4);
        grayMat = new Mat(webcamTexture.height, webcamTexture.width, CvType.CV_8UC4);
 
        //initialize texture2d
        texture = new Texture2D(rgbaMat.cols(), rgbaMat.rows(), TextureFormat.RGBA32, false);
        
        //webCamTextureToMat = transform.GetComponent<WebCamTextureToMatExample>();
        //faceXml_path = Application.streamingAssetsPath + "/lbpcascade_frontalface.xml";
        faceXml_path = Utils.getFilePath("lbpcascade_frontalface_improved.xml", true);
        gray = new Mat();
        faceRect = new MatOfRect();
        classifier = new CascadeClassifier(faceXml_path);
        if (classifier.empty())
        {
            Debug.Log("classifier load failed");
        }
        else
        {
            Debug.Log("load successful");
        }

        target = this.transform;

    }

    // Update is called once per frame
    void Update()
    {
        DetectFace();
    }

    public void DetectFace()
    {
        Utils.webCamTextureToMat(webcamTexture, rgbaMat);
        Imgproc.cvtColor(rgbaMat, gray, Imgproc.COLOR_RGB2GRAY);
        classifier.detectMultiScale(gray, faceRect, 1.1d, 2, 2, new Size(20, 20), new Size());
        Rect[] rects = faceRect.toArray();
        
        if (rects.Length == 0)
        {
            img.GetComponent<RawImage>().texture = webcamTexture;
            return;
        }
        
        var mainFace = rects[0];
        foreach (var face in rects)
        {
            if (face.height * face.width > mainFace.height * face.width)
            {
                mainFace = face;
            }
        }
    
        Size dsize = new Size(48, 48); 
        Mat cropped_img = new Mat(dsize, CvType.CV_8UC1);
        Mat roi_gray = new Mat(gray, mainFace);
        Imgproc.resize(roi_gray, cropped_img, dsize);
        bTexture2D = new Texture2D(48, 48);
        Utils.matToTexture2D(cropped_img,bTexture2D);

            
        //Barracuda stuffs
        if (true)
        {
            var channelCount = 1;
            var inputX = new Tensor(bTexture2D, channelCount);
            Tensor outputY = _engine.Execute(inputX).PeekOutput();
            inputX.Dispose();
            prediction.SetPrediction(outputY);
        }
        
        
        Debug.Log(labels[prediction.predictedValue]);
        chat.GetComponent<TextMeshProUGUI>().text = "Hey! You are " + labels[prediction.predictedValue];
        Imgproc.putText(rgbaMat, labels[prediction.predictedValue], new Point(mainFace.tl().x, mainFace.tl().y), Imgproc.FONT_HERSHEY_SIMPLEX, 1, new Scalar(255, 255, 255), 2, Imgproc.LINE_AA);
        Imgproc.rectangle(rgbaMat, new Point(mainFace.x, mainFace.y), new Point(mainFace.x + mainFace.width, mainFace.y + mainFace.height), new Scalar(0, 255, 0, 255), 2);
        
        PointF eyes = new PointF((float) mainFace.x + (float) mainFace.width / eyeShift.x, (float) mainFace.y + (float) mainFace.height / eyeShift.y /* - 60.0f*/);
        Imgproc.circle(rgbaMat, new Point(eyes.X, eyes.Y), 3, new Scalar(0, 0, 255, 255));
        
        // Find the screen width and height
        float screenWidth = GetComponent<AsymFrustum>().width;
        float screenHeight = GetComponent<AsymFrustum>().height;

        converterEye = new Vector2((eyes.X / 640f), -((eyes.Y / (360))));
        // Convert left eye position to camera position
        pov = new Vector3(((eyes.X / 640f) - 0.5f) * screenWidth, -((eyes.Y / (360-60.0f)) - 0.5f) * screenHeight, transform.position.z);
        
        //transform.position = pov;

        if (transform.position != pov)
        {
            sinTime += Time.deltaTime * moveSpeed;
            sinTime = Mathf.Clamp(sinTime, 0, Mathf.PI);
            float t = evaluate(sinTime);
           transform.position = Vector3.Lerp(transform.position, pov, t);
        }
        
        //convert rgb mat back to texture
        Utils.fastMatToTexture2D(rgbaMat, texture);
 
        //set rawimage texture
        img.GetComponent<RawImage>().texture = texture;

    }
    private int getMaxIndex(float[] arr)
    {
        float Max = 0;
        int index = 0;
        for (int i = 0; i < arr.Length; i++)
        {
            if (arr[i] > Max)
            {
                Max = arr[i];
                index = i;
            }
        }
        //Log.e(TAG, "max result: " + Max);
        return index;
    }

    public float evaluate(float x)
    {
        return 0.5f * Mathf.Sin(x - Mathf.PI / 2f) + 0.5f;
    }

    private void OnDestroy()
    {
        _engine?.Dispose();
    }
}
