using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;

using HuggingFace.API;

using SimpleJSON;
using MiniJSON;
using System.Linq;

/// <summary>
/// This class handles:
///     - API Call to Sentence Similarity: Given a user input text and a set of sentences candidates, call HF model to score each of them.
/// </summary>
public class JammoBrain: MonoBehaviour
{
    [HideInInspector]
    public string source_sentence; // User input text

    [HideInInspector]
    public float maxScore; // Value of the action with the highest score

    [HideInInspector]
    public int maxScoreIndex; // Index of the action with the highest score

    public JammoBehavior jammoBehavior;

    private SentenceSimilarity sentenceSimilarity = new SentenceSimilarity();


    /// <summary>
    /// Given a user input text and a set of sentences candidates, call HF model to score each of them.
    /// The JSON looks like this:
    /// 
    /// {
    /// "inputs": {
    ///     "source_sentence": "Go to the left tree",
    ///     "sentences": [
    ///         "Bring me the red cube",
    ///         "Move to the left tree",
    ///         "Eat a hot dog"
    ///         ]
    ///         },
    /// }
    /// </summary>
    /// <param name="source_sentence">user input sentence</param>
    /// <param name="sentences">all sentences to compare to user input sentence</param>
    public (float maxScore, int maxScoreIndex) RankSimilarityScores(string source_sentence, string[] sentences)
    {
        HuggingFaceAPI.SentenceSimilarity(source_sentence, results => 
        {
            maxScore = sentenceSimilarity.FindBestSimilarityScoreValue(results);
            maxScoreIndex = sentenceSimilarity.FindBestSimilarityScoreIndex(results);
            jammoBehavior.Utility(maxScore, maxScoreIndex);
        }, 
        error => 
        {
            // Handle errors
            Debug.LogError(error);
        }, 
        sentences);
        return (maxScore, maxScoreIndex);
    }
}
