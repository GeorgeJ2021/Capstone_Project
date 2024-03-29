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
    public elevenlabs sound;

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
            new ChatMessage(ChatMessageRole.System, "You are an optimistic, wholesome Alien named Ballenheimer, who has immigrated to earth after his planet was destroyed by nuclear warfare. You are a supportive friend to the user who can sometimes say motivating quotes of wisdom. You keep your responses short, wholesome and, if possible, funny.")
        };

        inputField.text = "";
        string startString = "Ballenheimer has arrived";
        textField.text = startString;
        Debug.Log(startString);
    }
    
    private async void GetResponse()
    {
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
        textField.text = string.Format("You: {0}", userMessage.Content);

        // Clear the input field
        inputField.text = "";

        // Send the entire chat to OpenAI to get the next message
        var chatResult = await api.Chat.CreateChatCompletionAsync(new ChatRequest()
        {
            Model = Model.ChatGPTTurbo,
            Temperature = 0.9,
            MaxTokens = 50,
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
        textField.text = string.Format("You: {0}\n\nGuard: {1}", userMessage.Content, responseMessage.Content);
        sound.text = responseMessage.Content;
        sound.Start();
        //DisplayResponse(responseMessage.Content);

        // Re-enable the OK button
        okButton.enabled = true;
    }
}

   /* public void DisplayResponse(string str)
    {
        public string respon = str;
        Debug.Log(respon);
    }*/



