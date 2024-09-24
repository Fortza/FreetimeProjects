#!/bin/bash

#lite skript som skal ta backup av terraform filen og sende det til et bestemt område

echo "Starter backup, ikke slå av maskinen"

#Variabler henter riktig lokasjon i linux tre
Source_Dir="/home/ubuntu/terraform/files"
Backup_Dir="/home/ubuntu/backup/terraform"

#Opretter backup katalog
mkdir -p $Backup_Dir

Date=$(date +"%Y%m%d-%H%M%S")

#For alle filer som finnes i banen /sourcedir og som ender på .tf -> gjør ...

for file in $Source_Dir/*.tf; do 
	filename=$(basename "$file")
	cp "$file" "$Backup_Dir/${filename%.*}-$Date.tf"

done

echo "Backup fullført til $Backup_Dir"

