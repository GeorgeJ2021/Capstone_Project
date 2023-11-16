import webbrowser

import win32com.client
import speech_recognition as sr

recognizer = sr.Recognizer()
microphone = sr.Microphone()

speaker = win32com.client.Dispatch("SAPI.SpVoice")
def listen(recognizer, microphone):
    while True:
        try:
            with microphone as source:
                print("Listening...")
                recognizer.adjust_for_ambient_noise(source)
                recognizer.dynamic_energy_threshold = 3000
                audio = recognizer.listen(source, timeout=5.0)
                response = recognizer.recognize_google(audio, language="en-in")
                print(response)

                return response
        except sr.WaitTimeoutError:
            pass
        except sr.UnknownValueError:
            pass
        except sr.RequestError:
            print("Network Error.")



#print(sr.Microphone.list_microphone_names())
print("Hello world. I am your virtual pet")
speaker.Speak("Hello world. I am your virtual pet")
while True:
    Response = listen(recognizer, microphone)
    if "Open YouTube".lower() in Response.lower():
        speaker.Speak("Opening YouTube")
        print("Opening YouTube")
        webbrowser.open("https://www.youtube.com/")

    else:
        speaker.Speak(Response)



