# Public repo
**Samling av prosjekter som jeg jobber med på fritiden og under studietiden.**

## Automatisering
Dette skriptet automatiserer prosessen med å kopiere mapper med et bestemt navn (i dette tilfellet "game") fra en kilde til et destinasjonsområde. Brukeren kan spesifisere kilde- og destinasjonsområder ved hjelp av kommandolinjeargumenter.

### Utbytte av skriptet
- Fil- og mappehåndtering: Bruk av os og shutil for å navigere i filsystemet, finne, kopiere og overskrive mapper.
- Regex: Bruk av regulære uttrykk for å manipulere mappenavn, som å fjerne ordet "game" med re.sub().
- Kommandolinjeargumenter: Håndtering av input fra brukeren ved hjelp av sys.argv for å spesifisere kilde og destinasjon.
- Feilhåndtering: Sikring av riktig antall kommandolinjeargumenter med raise Exception hvis brukeren ikke oppgir korrekt input.
- Arbeid med paths: Dynamisk opprettelse og manipulering av paths med os.path.join() og os.path.isabs().


## Azure / Terraform
Enkel infrastruktur ment for å lære Syntax og dokumentasjon av Terraform x Azure. Laget en enkel linux VM som laster ned Docker via custom bash skript før brukeren logger seg på. Sikret gjennom SSH og ACL regler.

### Utbytte av prosjektet 
- Lage Linux VM
- Custom Script lastes ned på ny VMs
- ACL regler som filtrerer tilgang til VM via IP
- Lage privat adresserom og public IP addresse
- Laget subnett
- Bruk av variabler for å skjule sensitiv data fra main.tf

 
## Maximus Cup Arrrangement
Skoleprosjekt i faget Programvareutvikling. Laget programvare i C++ som lar fotballklubber oprette og oppdatere turneringer.

### Utbytte av prosjektet 
- Scrum
- C++
- Prosjekt/Gruppearbeid
- UML
- Universal design principles
- Software testing, user participation, prototyping
- Cmake
  

## SpotifyAPI

Fritidsprosjekt for å leke med Web API’er. Program som requester informasjon fra Spotify angående artister og deres top 10 sanger.  

### Utbytte av prosjektet
- Python
- OAuth 2.0 authorization (credential code flow)
- Web API GET/POST
- JSON
- Datahåndtering
- Authentication & Authorization

