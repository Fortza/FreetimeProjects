# Bruker Python 3.9 som base image
FROM python:3.9-slim

# Sett dir inne i containeren
WORKDIR /app

# Kopier requirements.txt først for å installere nødvendige Python-pakker
# COPY requirements.txt /app/

# Kopier applikasjonsfilene til containeren
COPY . /app

# Installer nødvendige Python-pakker
RUN pip install --no-cache-dir Flask

# Åpne port 5000 for applikasjonen
EXPOSE 5000

# Kommandoen for å starte Flask-applikasjonen
CMD ["python", "hei_fra_docker_VM.py"]

