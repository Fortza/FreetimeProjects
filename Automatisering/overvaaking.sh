#!/bin/bash

#Skriptet skal overvåke mappen den befinner seg i ved å se etter endringer av filer de siste 24 timene.
#Lager en backup mappe og sender alle modifiserte filer dit.
#Lager en log fil i backup som logger alle filer som blir sendt til mappen.
#Fargekode log filen slik at brukeren rask kan se hvor lenge siden en fil ble lagt til.

# Definerer fargekoder
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
ORANGE='\033[0;33m'
RESET='\033[0m'

#Variabler for lokasjon og tid
mappe=$(pwd) 
selv=$(basename "$0")
naTid=$(date +%s) #Unix timestempel 
bakTid=$((naTid - 86400 )) #24 timer. 
tretti_min=$((naTid - 1800)) # 30 minutter
en_time=$((naTid - 3600)) # 1 time

#Backup Variabler 
backupPath="$mappe/backup"
mkdir -p "$backupPath" #Lage mappe om ikke finnes for backup 

for file in "$mappe"/*; do #iterere gjennom mappa
	if [ -f "$file" ]; then #sjekk om forløkka stoppet på en fil
		sist_endret=$(stat -f  "%m" "$file") #Unix timestempel vi kan bruke for sammenlinge
		filLaget=$(stat -f "%B" "$file")
		filnavn=$(basename "$file")
		
		# Sjekk om filen er skriptet selv, og hopp over den hvis den er det
       		if [ "$filnavn" == "$selv" ]; then
            		continue
        	fi	
		if [ $sist_endret -gt $bakTid ]; then #Er sist endret større enn 24 timer så har filen blitt endret på siste døgn.
			lesbarEndret=$(date -r "$sist_endret" +"%Y-%m-%d %H:%M%S")	 # Vise tid for endring.
			lesbarLaget=$(date -r "$filLaget" +"%Y-%m-%d %H:%M%S")   # Vise når den ble laget.
			# Vis filnavnet og sist endret tid			
			printf "\nFilnavn: %s \nOpprettet: %s\nSist endret: %s\n" "$filnavn" "$lesbarLaget" "$lesbarEndret"

			if ls "$backupPath/${filnavn%.*}_"* &> /dev/null; then # Om filen allerede finnes i backup mappen. (vil ha ulike navn så løser med regex)
				rm "$backupPath/${filnavn%.*}_"* # Slett gamle versjoner først
			fi	

				#Bestemmer fargen på logfilen. Grønn for de nye under 30 min gamle.
				if [ $sist_endret -gt $tretti_min ]; then
					farge=${GREEN}
				#Bytter farge på tidspunkt til gul over 1 time
				elif [ $sist_endret -gt $en_time ]; then
					farge=${YELLOW}
				else #Alt annet opp til 24t er rødt
					farge=${RED}
				fi
			#Farge blir valgt på tidsstemplet utifra if statement ovenfor. Enklere å lese for brukeren
			echo -e "${farge}$(date +'%Y-%m-%d %H:%M:%S')${RESET} - Sikkerhetskopiert: $filnavn" >> "$backupPath/backup.log"
			echo -e "Filen ${GREEN}$filnavn${RESET} ble sendt til backup mappen"

			dato=$(date -r "$sist_endret" +"%Y-%m-%d--%H:%M") #Dato format for nye filer til backup
			nytt_filnavn="${filnavn%.*}_$dato.${filnavn##*.}" #Nytt format på navnet til filene som skal setter i backup
			cp "$file" "$backupPath/$nytt_filnavn" #Kopierer ny fil til backup mappen med nytt navnFormat.
		fi		
	fi
done  
	
		


