#!/bin/bash
#Filen Stats.sh skal vise brukeren litt tall på hva som er lagret i Automasjon mappen.
#Finner og skriver ut antall skript og antall tegn i skriptet:
#Anall Python og bash skript. 

FILE1=0 #Tilbakestill før bruk 


for  fil in *.sh; do

	FILE1=$((FILE1 + 1))
	antOrd=$( wc -c < "$fil")
	printf "\n $fil \t har: \t $antOrd tegn i skriptet"
done

pyFil=$(ls *.py | wc -l) # teller antall filer som ender på ".py" og teller antall

printf "\n Det er Totalt \t %d bash-skript" "$FILE1"
printf "\n Det er Totalt \t %d python-skript" "$pyFil"

if [ $pyFil -lt $FILE1 ]; then
	printf "\n Det er færre python skript enn det er Bash skript"
fi

