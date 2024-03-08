using UnityEngine;
using UnityEngine.UI;

public class UIBlurController : MonoBehaviour
{
    [HideInInspector] [Range(0.001f, 0.015f)]public float BlurAmount = 0.005f;
    private Image _uiImage;

    void Start()
    {        
        SetBlurAmount();
    }
    
    public void SetBlurAmount()
    {
        if (_uiImage == null)
        {
            _uiImage = GetComponent<Image>();
        }        

        float aspect = Camera.main.aspect;

        float xAmount = BlurAmount;
        float yAmount = BlurAmount;

        if (aspect > 1f)
        {
            xAmount /= aspect;
        }
        else
        {
            yAmount *= aspect;
        }
            
        _uiImage.material.SetFloat("_yBlur", yAmount);
        _uiImage.material.SetFloat("_xBlur", xAmount);
    }
}
