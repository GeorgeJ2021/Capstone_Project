using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using ProtoBuf;
using System;

[Serializable]
[ProtoContract]
public class ValueList
{
    [ProtoMember(1)]
    public Game[] game;
    [ProtoMember(2)]
    public List<MoodJournal> moodJournal = new List<MoodJournal>();
    //[ProtoMember(3)]
    // public Element2[] element2;
    // [ProtoMember(4)]
    // public Element3[] element3;
    // [ProtoMember(5)]
    // public Element4[] element4;
}

[ProtoContract]
[Serializable]
public class Game
{
    [ProtoMember(1)]
    public int level;
    [ProtoMember(2)]
    public int duration;
    [ProtoMember(3)]
    public string type;

}

[ProtoContract]
[Serializable]
public class MoodJournal
{
    [ProtoMember(1)]
    public string emotion;
    [ProtoMember(2)]
    public int day;
    [ProtoMember(3)]
    public int month;
    [ProtoMember(4)]
    public int year;
}

[ProtoContract]
[Serializable]
public class Element2
{
    [ProtoMember(1)]
    public int speed;
    [ProtoMember(2)]
    public int minSpawnTime;
    [ProtoMember(3)]
    public int maxSpawnTime;
}

[ProtoContract]
[Serializable]
public class Element3
{
    [ProtoMember(1)]
    public int speed;
    [ProtoMember(2)]
    public int minSpawnTime;
    [ProtoMember(3)]
    public int maxSpawnTime;
}

[ProtoContract]
[Serializable]
public class Element4
{
    [ProtoMember(1)]
    public int speed;
    [ProtoMember(2)]
    public int minSpawnTime;
    [ProtoMember(3)]
    public int maxSpawnTime;
}

[ProtoContract]
[Serializable]
public class Element5
{
    [ProtoMember(1)]
    public string type;
    [ProtoMember(2)]
    public int speed;
    [ProtoMember(3)]
    public int minSpawnTime;
    [ProtoMember(4)]
    public int maxSpawnTime;

}
