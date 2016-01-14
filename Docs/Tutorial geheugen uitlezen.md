#Het maken van een Light Emitting Ammocounter

###!!!WARNING: GEHEUGEN UITLEZEN KAN EEN ONLINE BAN TRIGGEREN!!!

#Voorbereinde stap om een ban te voorkomen:
Volg de volgende stappen:  
<img src="http://u.cubeupload.com/Thovex/6.png">  
<img src="http://u.cubeupload.com/Thovex/7.png">  
<img src="http://u.cubeupload.com/Thovex/8.png">  
Als je dit succesvol heb voltooid dan krijg je de volgende melding als je de game op start:  
<img src="http://u.cubeupload.com/Thovex/9.png">

#Stap 1: Downloads!
Download het programma: [CheatEngine](http://mirror3.cheatengine.org/download/d1/CheatEngine65.exe)  

#Stap 2: Start counter-Strike.

#Stap 3: Gebruiken van CheatEngine
Open het programma, klik op het knipperende knopje linksbovenin. Genaamd "Select a process to open". En kies csgo.exe
<img src="http://u.cubeupload.com/Thovex/51510.png">  
Vervolgens join je een game sessie in counter-strike. 
We hebben 2 geheugen adressen nodig om te voltooien wat wij willen. De current ammo en ammoclip size.
Om deze te vinden kijken we wat ons momenteel aantal kogels is.  
<img src="http://u.cubeupload.com/Thovex/11.png">
In ons geval is dit 20 en de max clipsize is ook 20. Wij doen een eerste zoek in CheatEngine op het nummertje 20.
<img src="http://u.cubeupload.com/Thovex/62912.png">  
Dit geeft ons een aantal nummer 20's in een lijst, alles waar wij niks aan hebben. We schieten een keer in het spel.
Nu hebben we 19/20 ammo. We doen nu een tweede search.
<img src="http://u.cubeupload.com/Thovex/13.png">  
Hier zien we een betere lijst. Ons ammo adres is altijd de eerste van deze tweede search.
<img src="http://u.cubeupload.com/Thovex/14.png">  
Waarom? Omdat programmeren. Het geheugen adres is dus: 064EC5D4. De ammo die de speler over heeft is altijd hetzelfde
adres maar dan +4 aan het einde. Dus 064EC5D8. De clipsize is erg moeilijk om te vinden maar dit gaat op dezelfde
manier als dit. Het enige probleem is dat de clipsize af en toe een ander adres pakt.

#Stap 4: Het gebruiken van het geheugen adres
Je vervolgt de code tutorial verder om dit toe te passen. [volgende code](Tutorial digital code.md).
