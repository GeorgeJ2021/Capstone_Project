import os
import openai
from config import apikey

openai.api_key = apikey
response = openai.ChatCompletion.create(
  model="gpt-3.5-turbo",
  messages=[
    {
      "role": "system",
      "content": "Write an email to dean\n"
    },
    {
      "role": "user",
      "content": ""
    },
    {
      "role": "assistant"
    },
    {
      "role": "user"
    }
  ],
  temperature=1,
  max_tokens=256,
  top_p=1,
  frequency_penalty=0,
  presence_penalty=0
)