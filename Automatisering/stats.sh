#!/bin/bash
#Filen skal vise brukeren litt tall på hva som er lagret i Automasjon mappen.
#Finner og skriver ut antall skript og antall tegn i skriptet:
#Antall Python og bash skript. 



for  fil in *.sh; do
	antBytes=$( wc -c <  "$fil")
	printf "\n $fil \t har: \t $antBytes Bytes i skriptet"
done

bashFil=$(ls *.sh | wc -l) #teller antall bash fielr
pyFil=$(ls *.py | wc -l) # teller antall python filer

printf "\n Det er Totalt \t %d bash-skript" "$bashFil"
printf "\n Det er Totalt \t %d python-skript" "$pyFil"

if [ $pyFil -lt $bashFil ]; then
	printf "\n Det er færre python skript enn det er Bash skript"
else printf "Det er færre bash skript enn python script"
fi

