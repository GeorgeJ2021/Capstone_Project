using System.IO;
using UnityEngine;
using ProtoBuf;

public class ProtoBuffHandler : MonoBehaviour
{
    public ValueList gameData;
    public string filePath;

    void OnGUI()
    {
        if (GUI.Button(new Rect(10, 10, 200, 100), "Load File 1"))
        {
            if (string.IsNullOrEmpty(filePath))
            {
                Debug.LogError("Path is empty");
                return;
            }

            if (!File.Exists(filePath))
            {
                Debug.LogError("File doesn't exist");
                return;
            }

            gameData = Serializer.Deserialize<ValueList>(new FileStream(filePath, FileMode.Open, FileAccess.Read));
            
        }

        if (GUI.Button(new Rect(10, 120, 200, 100), "Save File 1"))
        {
            if (string.IsNullOrEmpty(filePath))
            {
                Debug.LogError("Path is empty");
                return;
            }

            if (gameData == null)
            {
                Debug.LogError("Value is null");
                return;
            }

            using (FileStream Stream = new FileStream(filePath, FileMode.Create, FileAccess.Write))
            {
                Serializer.Serialize<ValueList>(Stream, gameData);
                Stream.Flush();
            }
        }
    }
}
