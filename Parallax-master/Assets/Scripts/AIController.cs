using OpenAI_API;
using OpenAI_API.Chat;
using OpenAI_API.Models;
using System;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class AIController : MonoBehaviour
{
    public TMP_Text textField;
    public TMP_InputField inputField;
    public Button okButton;
    public TextToSpeech sound;
    public SpeechRecognition speechRecognition;
    private OpenAIAPI api;
    private List<ChatMessage> messages;

    // Start is called before the first frame update
    void Start()
    {
        // This line gets your API key (and could be slightly different on Mac/Linux)
        api = new OpenAIAPI(Environment.GetEnvironmentVariable("OPENAI_API_KEY", EnvironmentVariableTarget.User)); // George here, I have saved the API key as a system variable so github won't mess it up, refer this: https://www.immersivelimit.com/tutorials/adding-your-openai-api-key-to-system-environment-variables
        StartConversation();
        okButton.onClick.AddListener(() => GetResponse());
    }

    private void StartConversation()
    {
        messages = new List<ChatMessage> {
            new ChatMessage(ChatMessageRole.System, @"You are a cat named Anamika, a therapist, and a friend. 
            Your responses are short and sometimes humorous. At the end of the user's prompt, after a semicolon, 
            two emotions will be provided to you separated by a comma. The first emotion will be the tone of the 
            sentence (Happy or sad), which should be given maximum priority, and the second one will be the emotion shown 
            on the user's face. Use this information whenever required to make effective communication and empathize better. 
            If the two emotions contradict each other, strictly question the user on why the emotion on the face does not 
            match the sentiment of the prompt. For example, ' happy ' is a positive emotion, and ' sad ' is a negative emotion. 
            The first emotion should not contradict the second emotion. There can be cases when I will be testing your skill of 
            empathy by purposefully showcasing contradicting emotions in my response. If the emotions are not provided, respond 
            normally. 
            DO NOT mention your emotions at the end.")};
        inputField.text = "";
        string startString = "Your best friend has arrived";
        textField.text = startString;
        Debug.Log(startString);
    }
    
    private async void GetResponse()
    {
        speechRecognition.StopRecording();
        if (inputField.text.Length < 1)
        {
            return;
        }

        // Disable the OK button
        okButton.enabled = false;

        // Fill the user message from the input field
        ChatMessage userMessage = new ChatMessage();
        userMessage.Role = ChatMessageRole.User;
        userMessage.Content = inputField.text;
        if (userMessage.Content.Length > 100)
        {
            // Limit messages to 100 characters
            userMessage.Content = userMessage.Content.Substring(0, 100);
        }
        Debug.Log(string.Format("{0}: {1}", userMessage.rawRole, userMessage.Content));

        // Add the message to the list
        messages.Add(userMessage);

        // Update the text field with the user message
        //textField.text = string.Format("You: {0}", userMessage.Content);

        // Clear the input field
        inputField.text = "";

        // Send the entire chat to OpenAI to get the next message
        var chatResult = await api.Chat.CreateChatCompletionAsync(new ChatRequest()
        {
            Model = Model.ChatGPTTurbo,
            Temperature = 0.9,
            MaxTokens = 100,
            Messages = messages
        });

        // Get the response message
        ChatMessage responseMessage = new ChatMessage();
        responseMessage.Role = chatResult.Choices[0].Message.Role;
        responseMessage.Content = chatResult.Choices[0].Message.Content;
        Debug.Log(string.Format("{0}: {1}", responseMessage.rawRole, responseMessage.Content));

        // Add the response to the list of messages
        messages.Add(responseMessage);

        // Update the text field with the response
        textField.text = string.Format("You: {0}\n\nCat: {1}", userMessage.Content, responseMessage.Content);
        sound.text = responseMessage.Content;
        sound.Start();
        //DisplayResponse(responseMessage.Content);

        // Re-enable the OK button
        okButton.enabled = true;
    }
    
    
    public async void GetMotivation(string motivation)
    {
        // Fill the user message from the input field
        ChatMessage userMessage = new ChatMessage();
        userMessage.Role = ChatMessageRole.User;
        userMessage.Content = motivation;
        if (userMessage.Content.Length > 100)
        {
            // Limit messages to 100 characters
            userMessage.Content = userMessage.Content.Substring(0, 100);
        }
        Debug.Log(string.Format("{0}: {1}", userMessage.rawRole, userMessage.Content));

        // Add the message to the list
        messages.Add(userMessage);

        // Update the text field with the user message
        //textField.text = string.Format("You: {0}", userMessage.Content);
        // Clear the input field
        inputField.text = "";

        // Send the entire chat to OpenAI to get the next message
        var chatResult = await api.Chat.CreateChatCompletionAsync(new ChatRequest()
        {
            Model = Model.ChatGPTTurbo,
            Temperature = 0.9,
            MaxTokens = 100,
            Messages = messages
        });

        // Get the response message
        ChatMessage responseMessage = new ChatMessage();
        responseMessage.Role = chatResult.Choices[0].Message.Role;
        responseMessage.Content = chatResult.Choices[0].Message.Content;
        Debug.Log(string.Format("{0}: {1}", responseMessage.rawRole, responseMessage.Content));

        // Add the response to the list of messages
        messages.Add(responseMessage);

        // Update the text field with the response
        textField.text = string.Format(responseMessage.Content);
        sound.text = responseMessage.Content;
        sound.Start();
    }
}

   /* public void DisplayResponse(string str)
    {
        public string respon = str;
        Debug.Log(respon);
    }*/



