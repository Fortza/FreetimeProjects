## Oppdaterer systemet og installerer nødvendige pakker
sudo apt-get update -y &&
sudo apt-get install -y \
    apt-transport-https \
    ca-certificates \
    curl \
    gnupg-agent \
    software-properties-common &&

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

echo "Docker installasjon fullført. Vennligst logg ut og inn igjen for å aktivere gruppeendringen."
