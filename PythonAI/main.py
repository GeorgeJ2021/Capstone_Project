import win32com.client

speaker = win32com.client.Dispatch("SAPI.SpVoice")

speaker.Speak("Hello world. I am Ballenheimer")
while 1:
    print("Enter Text: ")
    s= input()
    speaker.Speak(s)


