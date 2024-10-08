
**Samling av prosjekter som jeg jobber med på fritiden og under studietiden.**

# Automatisering
Denne mappen inneholder både Python- og Bash-skript som automatiserer ulike oppgaver.

### FilHandling.py

Automatiserer prosessen med å kopiere mapper med et bestemt navn fra en kilde til et destinasjonsområde. Brukeren spesifiserer kilde- og destinasjonsområder via kommandolinjeargumenter.
- **Fil- og mappehåndtering**: Bruk av `os` og `shutil` for å navigere i filsystemet, finne, kopiere og overskrive mapper.
- **Regex**: Regulære uttrykk brukt med `re.sub()` for å manipulere mappenavn.
- **Kommandolinjeargumenter**: Håndtering av input fra brukeren med `sys.argv`.
- **Feilhåndtering**: Sikring av riktig antall kommandolinjeargumenter med `raise Exception`.
- **Arbeid med paths**: Dynamisk opprettelse og manipulering av paths med `os.path.join()` og `os.path.isabs()`.


### Monitor_and_Backup.sh
Dette skriptet overvåker mappen det befinner seg i for filendringer de siste 24 timene, og kopierer endrede filer til en egen backup-mappe. Det oppretter også en loggfil i backup-mappen med tidsstemplet informasjon om når filene ble sikkerhetskopiert, med fargekoding som hjelper brukeren å se hvor nylig endringene skjedde.

- **Mappemonitorering**: Overvåker filer i gjeldende mappe for endringer innenfor de siste 24 timene.
- **Backup-funksjonalitet**: Kopierer modifiserte filer til en dedikert backup-mappe med tidsstemplet filnavn.
- **Loggføring**: Oppretter en loggfil med informasjon om sikkerhetskopierte filer, fargekodet basert på hvor nylig endringene ble gjort:
- **Feilhåndtering**: Sikrer at backup-mappen eksisterer før kopiering, og unngår å sikkerhetskopiere skriptet selv.


### Back_up.sh
Dette skriptet tar en sikkerhetskopi av Terraform-filer fra en kildeplassering og lagrer dem i en angitt backup-katalog. Skriptet oppretter backup-katalogen hvis den ikke allerede eksisterer, og legger til tidsstempel i filnavnene for å unngå overskriving.

- **Backup-håndtering**: Automatiserer prosessen med å ta sikkerhetskopi av Terraform-filer.
- **Variabelhåndtering**: Bruk av variabler for å definere kilde- og backup-kataloger.
- **Datohåndtering**: Genererer tidsstempelet for filnavn for å holde oversikt over sikkerhetskopier.
- **Looping**: Itererer gjennom filer med spesifikke endelser (`.tf`) for å utføre kopiering.

# Azure / Terraform
Enkel infrastruktur ment for å lære Syntax og dokumentasjon av Terraform og Azure.

- Lage Linux VM
- Custom Script lastes ned på ny VMs
- ACL regler som filtrerer tilgang til VM via IP
- Lage privat adresserom og public IP addresse
- Laget subnett
- Bruk av variabler for å skjule sensitiv data fra main.tf

# SpotifyAPI

Fritidsprosjekt for å leke med Web API’er. Program som requester informasjon fra Spotify angående artister og deres top 10 sanger.  

- OAuth 2.0 authorization (credential code flow)
- Web API GET/POST
- JSON
- Datahåndtering
- Authentication & Authorization
 
# Maximus Cup Arrrangement
Skoleprosjekt i faget Programvareutvikling. Lar brukeren oprette og oppdatere turneringer.

- Scrum
- C++
- Prosjekt/Gruppearbeid
- UML
- Universal design principles
- Software testing, user participation, prototyping
- Cmake
  



