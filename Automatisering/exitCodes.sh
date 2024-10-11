#!/bin/bash

exit_code=$?

if [ $exit_code -eq 0 ]; then
    echo "Det siste skriptet var velykket"

elif [ $exit_code -eq 1 ]; then
    echo "Skriptet møtte på et problem ved opprettelse av backup mappe"
    ./discordMessage "Arvid, Det er problemer med å lage backup mappe i overvåkningskriptet."

elif [ $exit_code -eq 2 ]; then 
    echo "Skriptet Overvåkning.sh møtte på et problem ved kopiering"
    ./discordMessage "Arvid, Det er problemer med kopiering av filer via overvåkningskriptet."

else echo "Ukjent feil, exit code $?"
fi