import requests
import sys
from config import WEBHOOK_URL

Webhook_Url=WEBHOOK_URL

def send_disc_melding(webhook_url, message):
    print("\nSender melding til Discord webhook. Venligst Vent..")

    data ={"content": message}
    
    try:
        response = requests.post(webhook_url, json=data)

        if response.status_code == 204:
            print("\nMelding sendt!")
        
        else:
            print("\nFeil: Meldingen ble ikke sendt!")
    except  requests.exceptions.RequestException as e:
        print("Error", e)
    
if __name__ == "__main__": #Hvis discord brukes alene vil jeg at brukeren skal skrive meldingen manuelt
    if len(sys.argv) < 2:
            print("\nVennligst oppgi meldingen som skal sendes som et argument!")
    else:
            melding = sys.argv[1]
            send_disc_melding(WEBHOOK_URL, melding)



