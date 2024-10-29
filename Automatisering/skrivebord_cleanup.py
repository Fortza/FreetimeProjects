#Skriptet skal rydde filer fra skrivebordet til bestemte mapper.
#Skrivebordet er fult av feks pdf'er fra skole og søknader som sendes til en bestemt PDF mappe
#Skriptet sender meg melding på discord når oppgaven er utført.

import os 
import shutil #allows us to copy and overwrite
import sys # commandline arguments
import regex

def create_dir(BackupDir): #lager detinasjonsmappe om den ikke eksisterer
    if not os.path.exists(BackupDir):
        os.mkdir(BackupDir)

SourceDir = "C:\Users\arvid\Desktop"
BackupDir = "D:\\Skoleogprivat\\Backup"
create_dir(BackupDir)

DocBackupDir = os.path.join(BackupDir, "Docs")
PdfBackupDir = os.path.join(BackupDir, "PDF")
create_dir(DocBackupDir)
create_dir(PdfBackupDir)

for file in os.listdir(SourceDir): #iterere gjennom skrivebord filene/mapper
    file = file.strip()
    file_path = os.path.join(SourceDir, file) #legger til filen i path slik at vi kan kopiere den  
   
    if os.path.isfile(file_path):  # sjekker om det er en fil
        if file.endswith('.docx'): #finner en pdf fil
            if os.path.exists(file_path):
                try:
                    shutil.move(file_path, os.path.join(DocBackupDir, file))
                    print(f"Flyttet: {file_path} til {DocBackupDir}")
                except Exception as e:
                    print(f"Kunne ikke flytte {file_path}: {e}")
    
        elif file.endswith('.pdf'):
            if os.path.exists(file_path):
                try: 
                    shutil.move(file_path, os.path.join(PdfBackupDir, file))
                    print(f"Flyttet: {file_path} til {PdfBackupDir}")
                except Exception as e:
                    print(f"Kunne ikke flytte {file_path}: {e}")