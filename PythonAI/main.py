import win32com.client
import speech_recognition as sr

speaker = win32com.client.Dispatch("SAPI.SpVoice")
def takeCommand():
    print("take command started")
    r = sr.Recognizer()
    mic = sr.Microphone(device_index=2)
    with mic as source:
        r.pause_threshold = 1
        audio = r.listen(source)
        query = r.recognize_google(audio, language="en-in")
        print("User said: ", {query})
        return query

speaker.Speak("Hello world. I am Ballenheimer")
#print(sr.Microphone.list_microphone_names())
while 1:
    print("Listening...")
    text = takeCommand()
    speaker.Speak(text)


