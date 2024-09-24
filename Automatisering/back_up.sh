#!/bin/bash

#lite skript som skal ta backup av terraform filen og sende det til et bestemt område


#Variabler henter riktig lokasjon i linux tre
Source_Dir="/home/ubuntu/terraform/files"
Backup_Dir="/home/ubuntu/backup/terraform"

if [ ! -d "$Source_Dir" ]; then
    echo "Kildekatalogen finnes ikke: $Source_Dir"
    exit 1
fi

echo "Starter backup, ikke slå av maskinen!"

#Opretter backup katalog
mkdir -p $Backup_Dir

Date=$(date +"%Y%m%d-%H%M%S")

#For alle filer som finnes i banen /sourcedir og som ender på .tf -> gjør ...

for file in $Source_Dir/*.tf; do 
	filename=$(basename "$file")
	cp "$file" "$Backup_Dir/${filename%.*}-$Date.tf"

done

echo "Backup fullført til $Backup_Dir"

