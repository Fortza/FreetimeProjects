#!/bin/bash

echo "InstallSpark.sh started" | tee -a /tmp/installSpark.log

# Oppdater systemet og installer nødvendige pakker
sudo apt-get update -y &&
sudo apt-get install -y \
    apt-transport-https \
    ca-certificates \
    curl \
    gnupg-agent \
    software-properties-common \
    git && # Trengs for repo med cvs fil.


# Installer Docker hvis det ikke allerede er installert
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add - &&
sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable" &&
sudo apt-get update -y &&
sudo apt-get install -y docker-ce docker-ce-cli containerd.io &&

# Legg brukeren 'ubuntu' til Docker-gruppen for å kjøre Docker uten sudo
sudo usermod -aG docker ubuntu

# Trekk ned og kjør en Docker-container med Apache Spark
sudo docker pull bitnami/spark &&
sudo docker run -d --name spark-container -p 4040:4040 -p 7077:7077 bitnami/spark # 4040 Spark web UI, 7077 kommunikasjon mellom Noder


# Lag en katalog for data og last ned CSV-filen fra GitHub
mkdir -p /home/adminUser/data
curl -o /home/adminUser/data/mydata.csv https://raw.githubusercontent.com/deryaoruc/Spark_Exercises/refs/heads/main/Sample%20-%20EU%20Superstore.csv


# Legg til alias for å kunne bruke "Spark" kommandoen
echo "alias Spark='sudo docker exec -it spark-container bash'" >> /home/adminUser/.bashrc

# Sørg for at aliaset blir lastet inn med shellet
source /home/adminUser/.bashrc

# Logg og bekreft installasjonen
echo "Apache Spark installasjon i Docker-container er fullført." | tee -a /tmp/installSpark.log # -a for å ikke overskrive, sender bakerst på loggen.
echo "CSV-fil lastet ned til /home/ubuntu/data/mydata.csv"
echo "Skriv Spark for å komme deg inn i kontaineren" 

