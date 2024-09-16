# Hensiktet til skriptet er
# 1. Lære generelle Python Skripting 
# Kopiere filer fra et filsystem til et annet 

import os 
import json  
import shutil #allows us to copy and overwrite
from subprocess import PIPE, run # allow us to run the GO code
import sys # commandline arguments

GAME_DIR_PATTERN = "game"


def find_all_game_paths(source):
    game_paths = []

    for root, dirs, files in os.walk(source): #gå gjennom alle folders i mappestrukturen
        for directory in dirs:  
            if GAME_DIR_PATTERN in directory.lower(): #leter bare etter mappene med game i navnet.
                path = os.path.join(source, directory)
                game_paths.append(path)
        break 

def main(source, target):
    cwd = os.getcwd() #current working directory
    source_path = os.path.join(cwd, source) # veien fra CWD til source path. 
    target_path = os.path.join(cwd, target) # veien fra CWD til target path.


if __name__ == "__main__": #legger til slik skriptet bare kjører om vi executer filen fra commandline.
    args = sys.argv #Legger til commandline argument
    if len(args) != 3: # 3 pga filnavn, source directory, destination directory. 
        raise Exception("You must pass a Source and Destination Directory!")
    
    source, target = args[1:] #lager source og target variablene, knytter dem til command arguments. Fjerner første arg som er filnavn.
    main(source, target)

