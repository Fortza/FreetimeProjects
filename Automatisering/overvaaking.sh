#!/bin/bash

#Skriptet skal overvåke mappen den befinner seg i ved å se etter endringer av filer de siste 2 timene.
#Rapportere filer som har forandret seg.
#Rapportere antall nye filer
#Rapportere antall filer som er fjernet.


#Variabler for lokasjon og tid
mappe=$(pwd) 
selv=$(basename "$0")
naTid=$(date +%s) #Unix timestempel 
bakTid=$((naTid - 86400 )) #Minus 24 timer. 

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

			# Før vi lager ny backup, fjerner vi eventuelle tidligere versjoner av filen med tidsstempel
#			filnavn_base="${filnavn%.*}"
#            		find "$backupPath" -name "${filnavn_base}_*.${filnavn##*.}" -exec rm {} \;
			if [ -f "$backupPath/$filnavn" ]; then # Om filen allerede finnes i backup mappen.
				rm  $backupPath/$filnavn # Slett gamle filen først
			fi	
			
			dato=$(date -r "$sist_endret" +"%Y-%m-%d--%H:%M") #Dato format for nye filer til backup mappe senere
			nytt_filnavn="${filnavn%.*}_$dato.${filnavn##*.}"
			cp "$file" "$backupPath/$nytt_filnavn" #Kopierer ny fil til backup mappen

		fi		
	fi
done  
	
		


