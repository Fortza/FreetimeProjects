# Hensiktet til skriptet er
# 1. Lære generelle Python Skripting 
# Kopiere filer fra et filsystem til et annet 

import os 
import json  
import shutil #allows us to copy and overwrite
from subprocess import PIPE, run # allow us to run the GO code
import sys # commandline arguments

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

def main(source, target):
    cwd = os.getcwd() #current working directory
    source_path = os.path.join(cwd, source) # veien fra CWD til source path. 
    
    #Bruk av os.path.isabs for å sjekke om en path inkludert som argument (target) er absolutt eller ei.
    if os.path.isabs(target): # Brukeren har skrevet en fullstendig sti (starter med C:\ eller / )
        target_path = target # Bruk target som absolutt sti
    
    else: #hvis brukeren bare skriver mappe navn, bruker vi samme logikk som source path.
        target_path = os.path.join(cwd, target) # veien fra CWD til target path. Altså en undermappe av hvor skriptet befinner seg!


if __name__ == "__main__": #legger til slik skriptet bare kjører om vi executer filen fra commandline.
    args = sys.argv #Legger til commandline argument
    if len(args) != 3: # 3 pga filnavn, source directory, destination directory. 
        raise Exception("You must pass 1. Source path  2. Destination Directory name or full path!")
    
    source, target = args[1:] #lager source og target variablene, knytter dem til command arguments. Fjerner første arg som er filnavn.
    main(source, target)

#!!!!!!!!!!!!!!!!!!!!!!!!!!!
#!!!!!!!!!!!!!!!!!!!!!!!!!!!
#!!!!!!!!!!!!!!!!!!!!!!!!!!!
#!!!!!!!!!!!!!!!!!!!!!!!!!!!
#!!!!!!!!!!!!!!!!!!!!!!!!!!!

#Må sjekke med GPT om hvordan vi kan lage mappe destinasjon om den ikke finnes for både undermappe og for absolutt sti!
