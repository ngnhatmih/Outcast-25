import json
import requests

def ai_function(function, args, description, model = "gpt-3.5-turbo"):
    # parse args to comma separated string
    args = ", ".join(args)
    messages = [{"role": "system", "content": f"You are now the following python function: ```# {description}\n{function}```\n\nOnly respond with your `return` value. Do not include any other explanatory text in your response."},{"role": "user", "content": args}]
    endpoint = "https://free.churchless.tech/v1/chat/completions/"
    headers = {
        "Content-Type":"application/json"
    }
    payload = {
        "model":"gpt-3.5-turbo",
        "messages": messages
    }
    response = requests.post(endpoint, headers=headers, json=payload)
    return response.json()["choices"][0]["message"]["content"]

print(ai_function("def sum(a:int, b:int) -> int:", ["2", "3"], "Adds two integers"))