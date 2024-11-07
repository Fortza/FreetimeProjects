#!/bin/bash

echo "InstallDocker.sh started" > /tmp/installDocker.log
# Oppdaterer systemet og installerer nødvendige pakker
sudo apt-get update -y &&
sudo apt-get install -y \
    apt-transport-https \
    ca-certificates \
    curl \
    gnupg-agent \
    software-properties-common \
    git && #For å kunne installere repoet for docker

# Legger til Docker sin offisielle GPG-nøkkel
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add - &&

# Legger til Docker sitt repositorium
sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable" &&

# Oppdaterer pakkelisten og installerer Docker
sudo apt-get update -y &&
sudo apt-get install -y docker-ce docker-ce-cli containerd.io &&

# Legger brukeren 'ubuntu' til Docker-gruppen for å kjøre Docker uten sudo
sudo usermod -aG docker ubuntu


# Lage å gå til 'dir' hvor Web appliklasjonen ligger
mkdir -p /home/ubuntu/webapp
cd /home/ubuntu/webapp
#Kopier hele Fortza Repo
git clone https://github.com/Fortza/Projects.git 

# Kjører Docker-containeren på port 5000
sudo docker build -t flask-app .
sudo docker run -d -p 5000:5000 flask-app

# Henter public IP-adressen til VM-en
# Det er denne adressen web applikasjonen skal kjøre på. Pluss port 5000
VM_IP=$(hostname -I | awk '{print $1}')

echo "Docker installasjon Velykket" > /tmp/installDocker.log
echo "Docker installasjon og Flask-applikasjon er nå kjørt."
echo "Du kan nå åpne webapplikasjonen ved curl http://$VM_IP:5000"
