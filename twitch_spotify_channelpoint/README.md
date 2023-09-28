Prosjekt python kode som lar twitchbrukere legge til sanger på spotify på en spilleliste som streameren eier. 
Dette skal fungere ved at brukerne løser inn channelpoints som gir dem en mulighet til å lime inn spotify sangens URL. 
Programmet jeg skriver skal i bakgrunnen ta denne URL'en og legge den på bunnen av en spilleliste som streameren har valgt. 
Ideen er at dette skal gjøre streamen mer interaktiv for brukeren.
Mål lære:
+ API
	+ Twitch API
	+ Spotify API
+ Python koding


Bruke couchDB som NOSQL database for lagring av data queries i form av JSON objekter som holder på informasjon fra twitch API og pusher ut med Spotify API 


Mappe struktur 

twitch_spotify_channelpoint/
  ├── README.md
  ├── requirements.txt
  ├── spotify/
  │   ├── __init__.py
  │   ├── spotify_client.py
  │   └── spotify_playlist.py
  ├── twitch/
  │   ├── __init__.py
  │   ├── twitch_client.py
  │   └── twitch_webhook.py
  ├── main.py
  └── config.py
