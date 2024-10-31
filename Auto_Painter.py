#Skript som åpner Paint
#Skriver Noe gøy
#Ment for å lære PyautoGUI som brukes for å automatisere pc mus og tastatur.

import pyautogui
import time

skjermbredde, skjermhøyde = pyautogui.size() #Legger x og y verdine til skjermstørrelsene.
print(skjermbredde, skjermhøyde) #Størrelse på skjerm vises

musX, musY = pyautogui.position() #Legger inn x og y verdiene til pc musen når programmet kjøres
print(musX, musY) #Viser x og y verdiene til pc musen på skjermen.

pyautogui.moveTo(24,1065) # Windows knappen nede til venstre
pyautogui.click() #Trykker på windowsknappen
pyautogui.typewrite('Paint\n',interval=0.5) #Skriver Paint i søkebaren, '\n' brukes for enter


# Nå kan vi begynne å tegne. 
# Bruk pyautogui.moveTo for å velge en ny posisjon uten noe standpunkt. 
# Bruk pyautogui.move for å bevege fra det stedet du allerede er.

