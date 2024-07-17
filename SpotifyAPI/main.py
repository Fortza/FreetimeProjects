# Programmet gjør som følger:
# 1. Importerer relevante libs
# 2. Henter client ID og Secret fra Spotify, lagret som env variabler for økt sikkerhet
# 3. Bruker Get_token() POST for å hente client credential info i følge OAuth 2.0 best prac for server-server. Limited rettigheter
# 4. Bruker get_auth_header() funksjonen for videre authn/authz for GET requests.
# 5. search_for_artist() funksjonen finner mest populære artisten innen Norge for det navnet som brukeren skriver inn. Må ikke være helt riktig.
# 6. Finner mest populære artisten innen Norge for det navnet som brukeren skriver inn. Må ikke være helt riktig.
# 7. Skriver ut TOP 10 mest populære sanger for Artisten via funksjonen get_top_track_by_artist()
# 8. Om artisten ikke blir funnet får brukeren en melding før programmet avsluttes
# 9. Skriver ut de siste 10 album fra artisten og deres realease date

import os # operativsystem funksjoner, i dette tilfellet tilgang til .env 
import requests #HTTP requests, brukes for å kommunisere med Spotify Web API
from dotenv import load_dotenv #Pakke dotenv installert, henter load dotenv for å hente env variabler lagret i samme mappe (.env fil)
import base64 #spotify requirement er base64 encoding
from requests import post, get #sender post og get requests
import json #formatere til json objekt, og finne variabler innad i objektet
import sys #brukes for sys.exit som stopper om vi ikke finner artisten

load_dotenv() #Funksjon fra dotenv, henter .env variablene

#Skriv inn Artist Navn her 
print("\nWrite Artist Name: ")
navn = input()
print("\n")


#Definerer hvilke env variabler vi ønsker å hente, og setter de i nye variabler vi kan bruke i dette dokumentet.
client_id = os.getenv("CLIENT_ID")
client_secret = os.getenv("CLIENT_SECRET")

# Definerer en funksjon hvor vi følger kravene til Client_credential grant (oAuth2) fra Spotify for å gjøre klar en Post request
# Ender ved å legge til alt av url, header og data inn  i result variabel som vi sender som en Post request.  
def get_token():
    auth_string = client_id + ":" + client_secret
    auth_bytes = auth_string.encode("utf-8")
    auth_base64 = str(base64.b64encode(auth_bytes), "utf-8")
    
    url = "https://accounts.spotify.com/api/token"
    headers = { # required header parametere
        "Authorization":"Basic " + auth_base64,
        "Content-Type": "application/x-www-form-urlencoded"
    }

    data = { "grant_type": "client_credentials" } #required body parametere

    result = post(url, headers=headers, data=data) # Nå som alle variabler i requesten er definert legger vi det inn i result og POST
    json_result = json.loads(result.content) # får tilbake en json, vi ønsker å se på innholdet
    token = json_result["access_token"] #spesifiserer at vi ønsker å se på access_token delen av json objektet og legge det inn i token
    return token #returnerer access token som er det eneste vi ønsker av json objektet! 
   


## Nå som vi har vår token, kan vi bruke denne videre for alle requests for å hente informasjon fra Spotify Web API
#Videre requests bruker nå bearer + vår access token for å hente informasjon. Dette definerer vi under 
def get_auth_header(token):
    return {"Authorization":"Bearer " + token}

#Definerer funksjon for å søke gjennom biblioteket til Spotify etter en Artist
def search_for_artist(token, artist_name):
    url = "https://api.spotify.com/v1/search"
    headers = get_auth_header(token)
    query = f"?q={artist_name}&type=artist&limit=1"

    query_url = url + query
    result = get(query_url, headers=headers)
    json_result = json.loads(result.content)["artists"]["items"]
    if len(json_result) == 0:
        print("\n No artist with this name exists SORRY! \n")
        sys.exit()

    return json_result[0] 
    

def get_top_track_by_artist(token, artists_id):
    url = f"https://api.spotify.com/v1/artists/{artists_id}/top-tracks?country=NO"
    headers = get_auth_header(token)
    result = get(url, headers=headers)
    json_result = json.loads(result.content)["tracks"]
    return json_result


def get_artist_album(token, artists_id):
    url = f"https://api.spotify.com/v1/artists/{artists_id}/albums?offset=0&limit=10"
    headers = get_auth_header(token)
    result = get(url, headers=headers)
    json_result = json.loads(result.content)
    return json_result['items']


token = get_token() #Kjører gettoken for å hente access token fra Spotify
result = search_for_artist(token, navn)
artists_id = result["id"] #nå har vi endelig iD til artisten som vi har søkt opp, denne kan brukes for andre funksjoner hos Spotify
print("\n")
print(result["name"])
print("\n")
album = get_artist_album(token, artists_id)
songs = get_top_track_by_artist(token, artists_id)
print ("Top 10 songs on Spotify by", str.upper(result["name"]))


for idx, song in enumerate(songs):
    print(f"{idx + 1 }. {song['name']}")

if album:
    print(f"\nAlbums by {result['name']}:")
    for idx, album in enumerate(album):
        release_year = album['release_date'].split('-')[0]
        print(f"{idx + 1}. {album['name']} (Year: {release_year})")