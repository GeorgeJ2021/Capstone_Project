using UnityEditor;

[CustomEditor(typeof(UIBlurController))]
public class UIBlurEditor : Editor
{
    SerializedProperty _propBlurAmount;
    UIBlurController _target;

    private void OnEnable()
    {
        _propBlurAmount = serializedObject.FindProperty("BlurAmount");
        _target = (UIBlurController)target;
    }

    public override void OnInspectorGUI()
    {
        serializedObject.Update();
        EditorGUILayout.PropertyField(_propBlurAmount);

        if (serializedObject.ApplyModifiedProperties())
        {
            _target.SetBlurAmount();
        }
    }
}
