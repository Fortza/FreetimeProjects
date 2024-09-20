# Public repo
**Samling av prosjekter som jeg jobber med på fritiden og under studietiden.**

## Automatisering
Denne mappen inneholder både Python- og Bash-skript som automatiserer ulike oppgaver. Eksempler inkluderer kopiering av mapper med spesifikke navn og administrasjon av infrastruktur.

### Flytte og endre mapper Python
Automatiserer prosessen med å kopiere mapper med et bestemt navn (i dette tilfellet "game") fra en kilde til et destinasjonsområde. Brukeren spesifiserer kilde- og destinasjonsområder via kommandolinjeargumenter.

#### Utbytte av Python-skriptet
- **Fil- og mappehåndtering**: Bruk av `os` og `shutil` for å navigere i filsystemet, finne, kopiere og overskrive mapper.
- **Regex**: Regulære uttrykk brukt med `re.sub()` for å manipulere mappenavn.
- **Kommandolinjeargumenter**: Håndtering av input fra brukeren med `sys.argv`.
- **Feilhåndtering**: Sikring av riktig antall kommandolinjeargumenter med `raise Exception`.
- **Arbeid med paths**: Dynamisk opprettelse og manipulering av paths med `os.path.join()` og `os.path.isabs()`.

### Linux backup files
Dette skriptet tar en sikkerhetskopi av Terraform-filer fra en kildeplassering og lagrer dem i en angitt backup-katalog. Skriptet oppretter backup-katalogen hvis den ikke allerede eksisterer, og legger til tidsstempel i filnavnene for å unngå overskriving.

### Utbytte av skriptet
- **Backup-håndtering**: Automatiserer prosessen med å ta sikkerhetskopi av Terraform-filer.
- **Variabelhåndtering**: Bruk av variabler for å definere kilde- og backup-kataloger.
- **Datohåndtering**: Genererer tidsstempelet for filnavn for å holde oversikt over sikkerhetskopier.
- **Looping**: Itererer gjennom filer med spesifikke endelser (`.tf`) for å utføre kopiering.

## Azure / Terraform
Enkel infrastruktur ment for å lære Syntax og dokumentasjon av Terraform x Azure. Laget en enkel linux VM som laster ned Docker via custom bash skript før brukeren logger seg på. Sikret gjennom SSH og ACL regler.

### Utbytte av prosjektet 
- Lage Linux VM
- Custom Script lastes ned på ny VMs
- ACL regler som filtrerer tilgang til VM via IP
- Lage privat adresserom og public IP addresse
- Laget subnett
- Bruk av variabler for å skjule sensitiv data fra main.tf

## SpotifyAPI

Fritidsprosjekt for å leke med Web API’er. Program som requester informasjon fra Spotify angående artister og deres top 10 sanger.  

### Utbytte av prosjektet
- Python
- OAuth 2.0 authorization (credential code flow)
- Web API GET/POST
- JSON
- Datahåndtering
- Authentication & Authorization
 
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
  



