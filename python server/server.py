import UdpComms as U
import time

# Importing transformers model

from transformers import pipeline
pipe = pipeline("text-classification", model="kwang123/bert-sentiment-analysis")

# Create UDP socket to use for sending (and receiving)
sock = U.UdpComms(udpIP="127.0.0.1", portTX=8000, portRX=8001, enableRX=True, suppressWarnings=True)

i = pipe("mom scolded me")[0]['label']

while True:
    data = sock.ReadReceivedData() # read data

    if data != None: # if NEW data has been received since last ReadReceivedData function call
        print(data) # print new received data
        i = pipe(data)[0]['label']
        print(i)
        sock.SendData(str(i)) # Send this string to other application
    time.sleep(1)