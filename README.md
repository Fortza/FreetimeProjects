
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


### Overvaaking.sh
Dette skriptet overvåker mappen det befinner seg i for filendringer de siste 24 timene, og kopierer endrede filer til en egen backup-mappe. Det oppretter også en loggfil i backup-mappen med tidsstemplet informasjon om når filene ble sikkerhetskopiert, med fargekoding som hjelper brukeren å se hvor nylig endringene skjedde.

- **Mappemonitorering**: Overvåker filer i gjeldende mappe for endringer innenfor de siste 24 timene.
- **Backup-funksjonalitet**: Kopierer modifiserte filer til en dedikert backup-mappe med tidsstemplet filnavn.
- **Loggføring**: Oppretter en loggfil med informasjon om sikkerhetskopierte filer, fargekodet basert på hvor nylig endringene ble gjort:
- **Feilhåndtering**: Sikrer at backup-mappen eksisterer før kopiering, og unngår å sikkerhetskopiere skriptet selv.
- - 🟢 Grønn: Filer endret innen de siste 30 minuttene.
  - 🟡 Gul: Filer endret for mer enn 30 minutter, men mindre enn en time siden.
  - 🔴 Rød: Filer endret for mer enn en time, men mindre enn 24 timer siden.
- **Feilhåndtering**: Sikrer at backup-mappen eksisterer før kopiering, og unngår å sikkerhetskopiere skriptet selv.

### Skrivebord_cleanup.py
Automatiserer prosessen med å holde skrivebordet ryddig ved å flytte spesifikke filtyper til bestemte mapper, og sender en melding på Discord når oppgaven er utført.

- **Filorganisering**: Flytter .docx-filer til en Docs-mappe og .pdf-filer til en PDF-mappe på en backup-lokasjon.
- **Oppretting av mapper**: Oppretter mapper automatisk hvis de ikke finnes.
- **Varsling via Discord**: Sender en melding til Discord med en liste over filene som ble flyttet.

### Terraform_Backup.sh
Dette skriptet tar en sikkerhetskopi av Terraform-filer fra en kildeplassering og lagrer dem i en angitt backup-katalog. Skriptet oppretter backup-katalogen hvis den ikke allerede eksisterer, og legger til tidsstempel i filnavnene for å unngå overskriving.

- **Backup-håndtering**: Automatiserer prosessen med å ta sikkerhetskopi av Terraform-filer.
- **Variabelhåndtering**: Bruk av variabler for å definere kilde- og backup-kataloger.
- **Datohåndtering**: Genererer tidsstempelet for filnavn for å holde oversikt over sikkerhetskopier.
- **Looping**: Itererer gjennom filer med spesifikke endelser (`.tf`) for å utføre kopiering.

# Azure / Terraform
Enkel infrastruktur ment for å lære Syntax og dokumentasjon av Terraform og Azure.

- Lage Linux VM med public IP-adresse og privat subnett
- Installerer Docker og kjører en enkel Flask-applikasjon for å simulere en webapplikasjon
- Kopierer Git-repositorium til VM for å hente Flask-applikasjonen
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
  



