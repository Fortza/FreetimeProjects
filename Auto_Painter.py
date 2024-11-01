#Skriver Noe gøy
#Ment for å lære PyautoGUI som brukes for å automatisere pc mus og tastatur.

import pyautogui
import time 


#Åpner Paint

pyautogui.press('winleft')
pyautogui.moveTo(148,1053, 1) # Windows knappen nede til venstre, bruk 1 sekund på bevegelsen.
pyautogui.click() #Trykker på windowsknappen
pyautogui.typewrite('Paint\n',interval=0.5) #Skriver Paint i søkebaren, '\n' brukes for enter


# Nå kan vi begynne å tegne. 
# Bruk pyautogui.moveTo for å velge en ny posisjon uten noe standpunkt. 
# Bruk pyautogui.dragTo for å bevege med venstre klikk nede.

pyautogui.moveTo(805, 189, 0.5) #Beveg til fargebøtte
pyautogui.click() #Trykk på fargebøtta

pyautogui.moveTo(1456, 181, 0.5) #Velg Blå
pyautogui.click() #Trykk på fargebøtta


pyautogui.moveTo(1012, 420, 0.5) #Beveg deg til midten av skjermen
pyautogui.click() #Bruk fargen på skjermen


pyautogui.moveTo(1389, 182, 0.5) #Beveg til Gul farge
pyautogui.click() #Trykk på farge

pyautogui.moveTo(868, 189, 0.5) #Beveg til Pensel
pyautogui.click() #Trykk på Pensel

pyautogui.moveTo(616, 418, 0.5) #Gjør klar for å male 
pyautogui.dragTo(672, 421, 0.5)


pyautogui.moveTo(613,355,0.5)
pyautogui.dragTo(613, 486,0.5)

pyautogui.moveTo(672,353,0.5)
pyautogui.dragTo(677,486,0.5) # H er ferdig


pyautogui.moveTo(754,353,0.5) #Move to E starting position:)
pyautogui.dragTo(754,486,0.5)

pyautogui.moveTo(754,353,0.5)
pyautogui.dragTo(842,353,0.5)

pyautogui.moveTo(754,416,0.5)
pyautogui.dragTo(842,416,0.5)

pyautogui.moveTo(754,483,0.5)
pyautogui.dragTo(840,483,0.5) # E ferdig

pyautogui.moveTo(904,350,0.5) # Move to I starting posistion
pyautogui.dragTo(1011,350,0.5)

pyautogui.moveTo(951,350,0.5) 
pyautogui.dragTo(946,480,0.5)

pyautogui.moveTo(904,481,0.5) 
pyautogui.dragTo(1010,481,0.5)

pyautogui.moveTo(830,188,0.5) #Tekst box
pyautogui.click()
pyautogui.moveTo(609,558,0.5)

pyautogui.typewrite('aaaa Ansett meg, Takk !:D',interval=0.5)

pyautogui.moveTo(961,602,0.5)
pyautogui.click()