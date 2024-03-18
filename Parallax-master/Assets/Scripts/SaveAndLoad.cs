using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Security.Cryptography;
using UnityEngine;
using ProtoBuf;


public class SaveAndLoad : MonoBehaviour
{
    public string filePath;
    public ValueList gameData;
    
    
    [EditorCools.Button]
    private void SaveProto() => Save();
    [EditorCools.Button]
    private void LoadProto() => Load();
    [EditorCools.Button]
    private void DeleteProtoFile() => Delete(); 

    public void Save()
    {
        //gameData = csvReader.myValueList;
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
    
    public void Load()
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

    private void Awake()
    {
        Load();
    }

    private void Delete()
    {
        File.Delete(filePath);
        gameData = null;
    }
}
