# **Crypto-tools**
###### *von Jonas Eppard, Tim Horlacher und Marcel Alex.*

### Crypto-tools:
* #### Enigma 
* #### Vigenere
* #### DH-Handshake
* #### Caesar



##### Benutzten Libraries: 
Vordefiniert | Sesbstgeschrieben[^1]
------------ | -----------------
stdio.h      | clearInputBuffer.h
string.h     | readFileInString.h
stdlib.h     | readString.h
ctype.h      | readOneChar.h
math.h       | writeStringInFile.h
erno.h       |

#### Beschreibung Enigma [^2]
> Das Unterprogramm basiert auf der Gleichnamigen Enigma Maschine des II Weltkrieges.\
> Zuerst wird der Benutzer gefragt, ob er den Input von einer Datei lesen will, (wenn nicht ist die Stdin als Standard
> definiert) wird der entsprechende Schlüssel eingelesen und der Input mit dem Enigma-Prinzipe Ver/entschlüsselt.\
> Der Output wird je nach Angabe des Benutzers in einer Datei gespeichert oder in der Konsole ausgegeben. 

#### Beschreibung Vigenere [^3]
> Das Unterprogramm basiert auf der Gleichnamigen  Vigenere-Chiffre-Verschlüsselung.\
> Zuerst wird abgefragt ob der Benutzer eine Nachricht verschlüsseln oder entschlüsseln will,  \
> danach wird er gefragt ob er den Input von einer Datei lesen will (wenn nicht ist die Stdin als Standard
> definiert) und nach dem Buchstaben zum ver/entschlüsseln gefragt.\
> Der Output wird je nach Angabe des Benutzers in einer Datei gespeichert oder in der Konsole ausgegeben.

#### Beschreibung DH-Handshake [^4]
> Zuerst werde zwei öffentliche Schlüssel abgefragt, dann kann man zwei geheime Schlüssel festlegen.\
> Anhand der öffentlichen Schlüssel werden neue Schlüsse errechnet welche den Benutzern weitergegeben werden,
> ohne den geheimen Schlüssel des jeweils anderen zu kennen.

#### Beschreibung Caesar [^5]
> Das Unterprogramm Caesar basiert auf der Gleichnamigen Caesar-Verschlüsselung.\
> Zuerst wird abgefragt ob der Benutzer eine Nachricht verschlüsseln oder entschlüsseln will,  \
> danach wird er gefragt ob er den Input von einer Datei lesen will (wenn nicht ist die Stdin als Standard
> definiert) und nach dem Dezimalen Schlüssel zum ver/entschlüsseln gefragt.\
> Der Output wird je nach Angabe des Benutzers in einer Datei gespeichert oder in der Konsole ausgegeben.
> 
>[^1]:https://github.com/eintim/crypto-tools/tree/main/src/lib
>[^2]:https://github.com/eintim/crypto-tools/blob/main/src/enigma/enigma.c
>[^3]:https://github.com/eintim/crypto-tools/blob/main/src/vigenere/vigenere.c
>[^4]:https://github.com/eintim/crypto-tools/blob/main/src/diffiehellman/diffiehellman.c
>[^5]:https://github.com/eintim/crypto-tools/blob/main/src/caesar/caesar.c
