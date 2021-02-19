# **Crypto-tools**
###### *von Jonas Eppard, Tim Horlacher und Marcel Alex.*

Crypto-Tools ist ein Programm, dass verschiede Cryptographische Schiffren beherscht.
## Crypto-tools:
* #### Caesar
* #### DH-Handshake
* #### Enigma 
* #### RSA
* #### Vigenere


### Benutzten Libraries: 
Vordefiniert | [Selbstgeschrieben]
------------ | -----------------
stdio.h      | clearInputBuffer.h
string.h     | readFileInString.h
stdlib.h     | readString.h
ctype.h      | readOneChar.h
math.h       | writeStringInFile.h
erno.h       |


### [Enigma]
#### Benutzer-Beschreibung
Die Enigma-Verschlüsselung beruht auf der Enigma Maschine wie sie im Zweiten Weltkrieg 1945 von den Deutschen 
verwendet wurde. Dabei sind die Rotoren I-V Implementiert und die UKW B.
##### Verwendung
Das Programm kann in dem Menü durch die Eingabe 'e' aufgerufen werden. \
Daraufhin ist der zu verschlusselner Text anzugeben bzw. eine Datei mit dem Text.\
Daraufhin wird der Schlüssel eingegeben. Ein Schlüssel der Enigma Maschiene besteht aus 3 Zahlen,
welche die verwendeten Rotoren angeben, 3 Buchstaben welche die Anfangsstellung der Rotoren angibt
und einer Liste an Buchstaben welche zunächst ersetzt werden, bevor die Buchstaben durch die Walzen laufen.
Ein Schlüssel hat somit folgendes Format: ```III c c c *(cc )``` mit ```I : Int``` und ```c: Char```.
Die Entschlüsselung funktioniert exakt gleich, da das Verfahren der Enigma Symetrisch ist.
#### Entwickler-Dokumentation
//TODO


### [Vigenere]
#### Benutzer-Beschreibung
Bei der Vigenère-Verschlüsselung handelt es sich um ein Substitutionsverfahren.\
Dazu wird der Klartext in Einzelzeichen zerlegt und durch Geheimtextzeichen substituiert.\
Die Geheimtextzeichen werden durch ein Kennwort über das Vigenère-Quadrat ausgewählt.\
Dabei hebt sich Vigenere von einer monoalphabetischen Substitutionsmethode wie Caesar ab,\
da mehrere Alphabete verwendet werden.
##### Verwendung
Das Programm kann im Hauptmenü durch die Eingabe 'v' aufgerufen werden.\
Daraufhin wird man dazu aufgefordert zwischen Ent-/Verschlüsslung ('d' oder 'e') zu wählen.\
Anschließend ist die zu ent-/verschlüssende Nachricht zu einzugeben.\
Ggf. kann diese Nachricht auch aus einer Datei eingelesen werden.\
Danach wird der Schlüssel abgefragt. Dabei besteht der Schlüssel aus einem beliebig langen Wort.\
Allerdings werden nur Buchstaben beachtet. (Groß/Kleinschreibung spielt keine Rolle)\
Danach wird das ent-/verschlüssende Wort ausgegeben.
#### Entwickler-Dokumentation
Das Programm liest die Eingaben über eine der Libary Funktionen ein. Nachricht und Schlüssel werden jeweils in Arrays\
gespeichert um leichter darauf zugreifen zu können. Danach werden die einzelnen Buchstaben durch den errechnetet Geheimbuchstabe substituiert.\
Hierbei wird nach jedem verschüsselten Buchstaben auch ein Zeichen im Schlüssel weitergesprungen.\
Sollte dabei der Schlüssel vor der Nachricht zuende sein wird der Zähler des Schlüssel wieder resetet.

### [DH-Handshake]
#### Benutzer-Beschreibung
Der Diffie-Hellmann Key Exchange ermöglicht zwei Kommunikationspaartnern über eine öffentliche/abhörbare Leitung\
einen gemeinsamen geheimen Schlüssel zu vereinbaren. Verschiedene Varianten dieses Verfahrens\
werden heute für Sicherheitsprotokolle im Internet verwendet.\
Zuerst werde zwei öffentliche Schlüssel abgefragt, dann kann man zwei geheime Schlüssel festlegen.\
Anhand der öffentlichen Schlüssel werden neue Schlüsse errechnet welche, \
den Benutzern weitergegeben werden, ohne den geheimen Schlüssel des jeweils anderen zu kennen.
##### Verwendung
Im Programm wird der Benutzer dazu aufgefordert 4 Zahlenwerte festzulegen.\
```Öffentliche Werte: P(Primzahl) und G (G < P)
Geheime Werte: a(a < P) und b(b < P)```
Hierbei gilt zu beachtet das es keine Input-Validation gibt!\
Danach wird für jede Seite (a und b) ein öffentlicher Schlüssel berechnet.\
Dieser Schlüssel wird dann den jeweils anderen "zugeschickt".\
Mithilfe dieses Schlüssel kann nun jede Partei einen geheimen Schlüssel errechnen\
und dieser wird dann Ausgegeben. Aufgrund des Diffie-Hellmanns Verfahren haben beide Parteien nun\
den selben geheimen Schlüssel.\
#### Entwickler-Dokumentation
Das Programm liest die Eingaben aus dem Stream stdin nacheinander ein und berechnet daraus die passenden Schlüssel.\
Die Funktion pMod ist für die Berechnung der Schlüssel zuständig. Dahinter steckt die Formel ```res=a^b mod n```\
Um überläufe zu vermeiden wird intern der Datentyp ```long long``` verwendet\

### [Caesar]
#### Benutzer-Beschreibung
Das Unterprogramm Caesar basiert auf der Gleichnamigen Caesar-Verschlüsselung.\
Bei welcher jeder Buchstabe des Textes, im Alphabet um den gleichen Wert verschoben wird 

![Funktionsweiße](https://upload.wikimedia.org/wikipedia/commons/thumb/2/2b/Caesar3.svg/330px-Caesar3.svg.png "Bildlichen darstellung der Funktionsweiße")

#### Verwendung
Das Programm kann in dem Menü durch die Eingabe 'c' aufgerufen werden. \
Zuerst wird abgefragt ob der Benutzer eine Nachricht verschlüsseln oder entschlüsseln will,\
danach wird dem Benutzer  die Möglichkeit gegeben den zu Ver/entschlüsselnden Text aus einer Datei zu lesen oder selbst einzugeben.\
Daraufhin wird die Zahl als Integer, welche den Schlüssel darstellt abgefragt.\
Der Output wird je nach Angabe des Benutzers in einer Datei gespeichert oder in der Konsole ausgegeben.

#### Entwickler-Dokumentation
//TODO

[Selbstgeschrieben]:https://github.com/eintim/crypto-tools/tree/main/src/lib
[Enigma]:https://github.com/eintim/crypto-tools/blob/main/src/enigma/enigma.c
[Vigenere]:https://github.com/eintim/crypto-tools/blob/main/src/vigenere/vigenere.c
[DH-Handshake]:https://github.com/eintim/crypto-tools/blob/main/src/diffiehellman/diffiehellman.c
[Caesar]:https://github.com/eintim/crypto-tools/blob/main/src/caesar/caesar.c
          