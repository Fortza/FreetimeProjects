#!/bin/bash

#Definerer variabler for mappe lokasjoner.
backup_dir="$(pwd)/backup" #Mappe filene ligger /backup i praksis
komprimer_mappe="$(pwd)/tar_mappe"

mkdir -p "$komprimer_mappe" #Mappen hvor de komprimerte filene skal ligge

#Funksjon som skal finne filer i backupo_dir som er eldre enn 24 timer, og komprimere disse ved bruk av tar.
komprimer_filer() {
    # Finn filer i backup-mappen som er eldre enn 24 timer
    
    #gamle_filer=$(ls -1t "$backup_dir" | grep -E "$(date -d '1 day ago' +%Y-%m-%d)")
    gamle_filer=$(find "$backup_dir" -type f) # -mtime +1)

    echo "Gamle filer som skal komprimeres:"
    echo "$gamle_filer"

    if [ -n "$gamle_filer" ]; then
        # Komprimer de gamle filene
        cd "$backup_dir" || exit 1
        #tar -czvf "$komprimer_mappe/$(date +%Y%m%d).tar.gz" -C "$backup_dir" $gamle_filer 
        #tar -czvf "$komprimer_mappe/$(date +%d%m%Y).tar.gz" -C "$backup_dir" $(basename $gamle_filer)
        #tar -czvf "$komprimer_mappe/$(date +%Y%m%d).tar.gz" -C "$backup_dir" $(echo "$gamle_filer" | xargs -d '\n' -I {} basename {})
        tar_file="$komprimer_mappe/$(date +%Y%m%d).tar.gz"
        tar -czvf "$tar_file" -C "$backup_dir" $(printf '%q ' $gamle_filer)

        echo "Filer komprimert til $komprimer_mappe/$(date +%Y%m%d).tar.gz"
    else
        echo "Ingen filer å komprimere."
    fi
}

komprimer_filer