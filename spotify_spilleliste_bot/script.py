import spotipy
from spotipy.oauth2 import SpotifyOAuth

#Setting up authentication
scope = 'user-library-modify'
sp = spotipy.Spotify(auth_manager=SpotifyOAuth(scope=scope))


#definerer spilleliste-ID og sanger osom skal legges til
playlist_id = 'https://open.spotify.com/playlist/6RMJRg6d6KTXWPiA5yzRPr?si=42ac1423558e4d04'

#Adding songs 
songs = ['https://open.spotify.com/track/3AJwUDP919kvQ9QcozQPxg?si=cd1aa9cdbbb24805', 'https://open.spotify.com/track/2cGxRwrMyEAp8dEbuZaVv6?si=f2bb432e0e2b4b89']
song_ids = []

for song_url in songs:
    song_id = song_url.split('/')[-1]
    if song_id.startswith('track'):
        song_id = song_id[6:]
        song_ids.append(song_id)

sp.playlist_add_items(playlist_id,song_url,postition=0)

result = sp.current_user_saved_tracks_add(tracks=song_ids)

if result['snapshot_id']:
    print("Songs added to library!")

else:
    print("failed to add songs to playlist!")
