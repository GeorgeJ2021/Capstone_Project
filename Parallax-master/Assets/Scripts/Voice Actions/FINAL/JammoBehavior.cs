using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

/// <summary>
/// This class is used to control the behavior of our Robot (State Machine and Utility function)
/// </summary>
public class JammoBehavior : MonoBehaviour
{
    /// <summary>
    /// The Robot Action List
    /// </summary>
    [System.Serializable]
    public struct Actions
    {
        public string sentence;
        public string verb;
        public string noun;
    }

    /// <summary>
    /// Enum of the different possible states of our Robot
    /// </summary>
    private enum State
    {
        Idle,
        Hello, // Say hello
        Happy, // Be happy
        Puzzled, // Be Puzzled
        MoveTo, // Move to a pillar
        BringObject, // Step one of bring object (move to it and grab it)
        BringObjectToPlayer // Step two of bring object (move to player and drop the object)
    }

    [Header("Robot Brain")]
    public JammoBrain jammoBrain;

    [Header("Robot list of actions")]
    public List<Actions> actionsList;
    
    [Header("NavMesh and Animation")]
    public Animator anim;                       // Robot Animator
    public NavMeshAgent agent;                  // Robot agent (takes care of robot movement in the NavMesh)
    public float reachedPositionDistance;       // Tolerance distance between the robot and object.
    public float reachedObjectPositionDistance; // Tolerance distance between the robot and object.
    public Transform playerPosition;            // Our position
    public GameObject goalObject;               
    public GameObject grabPosition;             // Position where the object will be placed during the grab

    public Camera cam;                          // Main Camera

    [Header("Input UI")]
    public TMPro.TMP_InputField inputField;     // Our Input Field UI

    private State state;

    [HideInInspector]
    public List<string> sentences; // Robot list of sentences (actions)
    public string[] sentencesArray;

    [HideInInspector]
    public float maxScore;
    public int maxScoreIndex;

    private void Awake()
    {
        // Set the State to Idle
        state = State.Idle;

        // Take all the possible actions in actionsList
        foreach (JammoBehavior.Actions actions in actionsList)
        {
            sentences.Add(actions.sentence);
        }
        sentencesArray = sentences.ToArray();
    }

    /// <summary>
    /// Rotate the agent towards the camera
    /// </summary>
    private void RotateTo()
    {
        var _lookRotation = Quaternion.LookRotation(cam.transform.position);
        agent.transform.rotation = Quaternion.RotateTowards(agent.transform.rotation, _lookRotation, 360);
    }

    /// <summary>
    /// Grab the object by putting it in the grabPosition
    /// </summary>
    /// <param name="gameObject">Cube of color</param>
    void Grab(GameObject gameObject)
    {
        // Set the gameObject as child of grabPosition
        gameObject.transform.parent = grabPosition.transform;

        // To avoid bugs, set object velocity and angular velocity to 0
        gameObject.GetComponent<Rigidbody>().isKinematic = true;
        gameObject.GetComponent<Rigidbody>().velocity = Vector3.zero;
        gameObject.GetComponent<Rigidbody>().angularVelocity = Vector3.zero;

        // Set the gameObject transform position to grabPosition
        gameObject.transform.position = grabPosition.transform.position;
    }

    /// <summary>
    /// Drop the gameObject
    /// </summary>
    /// <param name="gameObject">Cube of color</param>
    void Drop(GameObject gameObject)
    {
        gameObject.GetComponent<Rigidbody>().isKinematic = false;
        gameObject.transform.SetParent(null);
    }

    /// <summary>
    /// Utility function: Given the results of HuggingFaceAPI, select the State with the highest score
    /// </summary>
    /// <param name="maxValue">Value of the option with the highest score</param>
    /// <param name="maxIndex">Index of the option with the highest score</param>
    public void Utility(float maxScore, int maxScoreIndex)
    {
        // First we check that the score is > of 0.2, otherwise we let our agent perplexed;
        // This way we can handle strange input text (for instance if we write "Go see the dog!" the agent will be puzzled).
        if (maxScore < 0.20f)
        {
            state = State.Puzzled;
        }
        else
        {
            // Get the verb and noun (if there is one)
            goalObject = GameObject.Find(actionsList[maxScoreIndex].noun);

            string verb = actionsList[maxScoreIndex].verb;

            // Set the Robot State == verb
            state = (State)System.Enum.Parse(typeof(State), verb, true);
        }
    }

    /// <summary>
    /// When the user finished to type the order
    /// </summary>
    /// <param name="prompt"></param>
    public void OnOrderGiven(string prompt)
    {
        jammoBrain.RankSimilarityScores(prompt, sentencesArray);
    }
        

    private void Update()
    {
        // Here's the State Machine, where given its current state, the agent will act accordingly
        switch(state)
        {
            default:
            case State.Idle:
                break;

            case State.Hello:
                agent.SetDestination(playerPosition.position);
                if (Vector3.Distance(transform.position, playerPosition.position) < reachedPositionDistance)
                {
                    RotateTo();
                    anim.SetBool("hello", true);
                    state = State.Idle;
                }
                break;

            case State.Happy:
                agent.SetDestination(playerPosition.position);
                if (Vector3.Distance(transform.position, playerPosition.position) < reachedPositionDistance)
                {
                    RotateTo();
                    anim.SetBool("happy", true);
                    state = State.Idle;
                }
                break;

            case State.Puzzled:
                agent.SetDestination(playerPosition.position);
                if (Vector3.Distance(transform.position, playerPosition.position) < reachedPositionDistance)
                {
                    RotateTo();
                    anim.SetBool("puzzled", true);
                    state = State.Idle;
                }
                break;

            case State.MoveTo:
                agent.SetDestination(goalObject.transform.position);
                
                if (Vector3.Distance(transform.position, goalObject.transform.position) < reachedPositionDistance)
                {
                    state = State.Idle;
                }
                break;

            case State.BringObject:
                // First move to the object
                agent.SetDestination(goalObject.transform.position);
                if (Vector3.Distance(transform.position, goalObject.transform.position) < reachedObjectPositionDistance)
                {
                    Grab(goalObject);
                    state = State.BringObjectToPlayer;
                }
                break;

            case State.BringObjectToPlayer:
                agent.SetDestination(playerPosition.transform.position);
                if (Vector3.Distance(transform.position, playerPosition.transform.position) < reachedObjectPositionDistance)
                {
                    Drop(goalObject);
                    state = State.Idle;
                }
                break;
        }
    }
}
