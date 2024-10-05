#!/bin/bash

#Skriptet skal overvåke mappen den befinner seg i ved å se etter endringer av filer de siste 2 timene.
#Rapportere filer som har forandret seg.
#Rapportere antall nye filer
#Rapportere antall filer som er fjernet.

mappe=$(pwd) 
naTid=$(date +%s) #Unix timestempel 
bakTid=$((naTid - 7200)) #7200 er 2 timer

for file in "$mappe"/*; do #iterere gjennom mappa
	if [ -f "$file" ]; then #sjekk om forløkka stoppet på en fil
		sist_endret=$(stat -f  "%m" "$file") #unix timestempel vi kan bruke for sammenlinge
		filLaget=$(stat -f "%B" "$file")
		filnavn=$(basename "$file")
		
	#	printf "\n %s" "$filnavn"
	#	printf "\n %s" "$sist_endret"
	
		if [ $sist_endret -ge $bakTid ]; then
			lesbarTid=$(date -r "$sist_endret" +"%Y-%m-%d %H:%M%S")	
			lesbarLaget=$(date -r "$filLaget" +"%Y-%m-%d %H:%M%S")
			# Vis filnavnet og sist endret tid			
			printf "\nFilnavn: %s \nOpprettet: %s\nSist endret: %s\n" "$filnavn" "$lesbarLaget" "$lesbarTid"
		fi
	fi
done  
	
		


