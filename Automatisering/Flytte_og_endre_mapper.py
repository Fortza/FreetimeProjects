# Hensiktet til skriptet er
# Kopiere mapper med et bestemt navn til et annet område
# Bruker skal kunne velge source og destinasjons område
# Bruke Regex for å finne riktig navn
# Aksepterer 2 kommando linje argumenter

import os 
import shutil #allows us to copy and overwrite
import sys # commandline arguments
import re #regex

GAME_DIR_PATTERN = "game"

# Finner og returnerer alle mapper under source directory som har navnet "game" i seg.
def find_all_game_paths(source):
    game_paths = [] 

    for root, dirs, files in os.walk(source): #Gå gjennom alle folders i mappestrukturen
        for directory in dirs:  
            if GAME_DIR_PATTERN in directory.lower(): #leter bare etter mappene med game i navnet.
                path = os.path.join(source, directory) #Legger til destinasjon directory inn i pathen til source og legger til /
                game_paths.append(path) #legger inn pathen til mappen med "game" i navnet inn i game_paths arrayen.
        break  # Stopper etter første nivå slik at vi ikke rekrusivt går gjennom alle mapper under.
    
    
    return game_paths #returnerer game_path som har path til mapper med "game" i navnet


def create_dir(path): #lager detinasjonsmappe om den ikke eksisterer
    if not os.path.exists(path):
        os.mkdir(path)

def get_navn_fra_path(paths, fjerne): #Henter ut ordet "game" fra mappenavn før vi sender til destinasjon
    nye_navn = []
    for path in paths:
        _, dir_navn = os.path.split(path) # Deler opp pathen 
        new_dir_navn = re.sub(r'_?game_?', '', dir_navn) #fjerner navnet game og eventuelle Understreker før og etter med Ragex
        nye_navn.append(new_dir_navn) # Legger det nye navnet til mappa/filen inn i nye_navn array
        
    return nye_navn #returnerer nye verdi (nytt navn på endefil)


def kopier_og_overskriv(source, dest): # kopier, og overskriv om mappen allerede finnes
    if os.path.exists(dest):  # sjekker om mappen allerede finnes
        shutil.rmtree(dest)   # Om den fantes, fjern
    shutil.copytree(source, dest) #Nå kan vi kopiere over innhold. Siden vi bryjer copytree, vil alt bli sendt rekursive.
    


def main(source, target):
    cwd = os.getcwd() #current working directory
    source_path = os.path.join(cwd, source) # veien fra CWD til source path. 
                                     #Bruk av os.path.isabs for å sjekke om en path inkludert som argument (target) er absolutt eller ei.
    if os.path.isabs(target): # Brukeren har skrevet en fullstendig sti
        target_path = target # Bruk target som absolutt sti
    else: #hvis brukeren bare skriver mappe navn, bruker vi samme logikk som source path.
        target_path = os.path.join(cwd, target) # veien fra CWD til target path. Altså en undermappe av hvor skriptet befinner seg!

    game_path = find_all_game_paths(source_path) # Lagrer unna alle game paths funnet fra start mappa   
    new_game_dirs = get_navn_fra_path(game_path, "game")

    create_dir(target_path)

    for src, dest, in zip(game_path, new_game_dirs): #iterer gjennom zip og legger til game_path,
            dest_path = os.path.join(target_path, dest)
            kopier_og_overskriv(src, dest_path)

if __name__ == "__main__": #legger til slik skriptet bare kjører om vi executer filen fra commandline.
    args = sys.argv #Legger til commandline argument
    if len(args) != 3: # 3 pga filnavn, source directory, destination directory. 
        raise Exception("You must pass 1. Source path  2. Destination Directory name or full path!")
    
    source, target = args[1:] #lager source og target variablene, knytter dem til command arguments. Fjerner første arg som er filnavn.
    main(source, target)



