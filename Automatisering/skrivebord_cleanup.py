#Skriptet skal rydde filer fra skrivebordet til bestemte mapper.
#Skrivebordet er fult av feks pdf'er fra skole og søknader som sendes til en bestemt PDF mappe
#Skriptet sender meg melding på discord når oppgaven er utført.

import os 
import shutil #allows us to copy and overwrite
from config import SOURCE_DIR, BACKUP_DIR, TEST_DIR, WEBHOOK_URL
from discordMessages import send_disc_melding # Bruker WEBHOOK til å sende egendefinert melding til discord kanalen



def create_dir(BackupDir): #lager detinasjonsmappe om den ikke eksisterer
    if not os.path.exists(BackupDir):
        os.mkdir(BackupDir)

SourceDir = TEST_DIR #Bruk TEST_DIR under testing.
BackupDir = BACKUP_DIR 

create_dir(BackupDir)

DocBackupDir = os.path.join(BackupDir, "Docs")
PdfBackupDir = os.path.join(BackupDir, "PDF")
create_dir(DocBackupDir)
create_dir(PdfBackupDir)

files_moved = []  # liste for å holde styr på flyttede filer

for file in os.listdir(SourceDir): #iterere gjennom skrivebord filene/mapper
    file = file.strip() #enklere å behandle paths uten blank spaces
    file_path = os.path.join(SourceDir, file) #legger til filen i path slik at vi kan kopiere den  
   
    if os.path.isfile(file_path):  # sjekker om det er en fil
        if file.endswith('.docx'): #finner en pdf fil
            if os.path.exists(file_path):
                try:
                    shutil.move(file_path, os.path.join(DocBackupDir, file))
                    print(f"Flyttet: {file_path} til {DocBackupDir}")
                    files_moved.append(file)
                except Exception as e:
                    print(f"Kunne ikke flytte {file_path}: {e}")
    
        elif file.endswith('.pdf'):
            if os.path.exists(file_path):
                try: 
                    shutil.move(file_path, os.path.join(PdfBackupDir, file))
                    print(f"Flyttet: {file_path} til {PdfBackupDir}")
                    files_moved.append(file)
                except Exception as e:
                    print(f"Kunne ikke flytte {file_path}: {e}")

# Send melding til Discord hvis filer ble flyttet
if files_moved:
    cleaned_files = [repr(file) for file in files_moved]
    message = f"Følgende filer ble flyttet: {', '.join(cleaned_files)}"
    #message = f"Følgende filer ble flyttet: {', '.join(files_moved)}"
    send_disc_melding(WEBHOOK_URL, message)
else:
    print("Ingen filer ble flyttet.")
