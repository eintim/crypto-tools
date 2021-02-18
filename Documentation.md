# **Crypto-tools**
###### *von Jonas Eppard, Tim Horlacher und Marcel Alex.*

### Crypto-tools:
* #### Enigma 
* #### Vigenere
* #### DH-Handshake
* #### Caesar



##### Benutzten Libraries: 
Vordefiniert| Sesbstgeschrieben[^1]
    -------------------|-----------------
stdio.h |clearInputBuffer.h
string.h |readFileInString.h
stdlib.h |readString.h
ctype.h|readOneChar.h
-|writeStringInFile.h

#### Beschreibung Enigma [^2]
...
#### Beschreibung Vigenere [^3]
>Das Unterprogramm basiert auf der Gleichnamigen  Vigenere-Chiffre-Verschlüsselung.\
>Zuerst wird abgefragt ob der Benutzer eine Nachricht verschlüsseln oder entschlüsseln will,  \
dannach wird er gefragt ob er den Input von einer Datei lesen will (wenn nicht ist die Stdin als Standart
definiert) und nach dem Buchstaben zum ver/entschlüsseln gefragt.\
Der Output wird je nach Angabe des Benutzers in einer Datei gespeichert oder in der Console ausgegeben.

#### Beschreibung DH-Handshake [^4]
...
#### Beschreibung Caesar [^5]
>Das Unterprogramm Caesar bassiert auf der Gleichnamigen Caesar-Verschlüsselung.\
Zuerst wird abgefragt ob der Benutzer eine Nachricht verschlüsseln oder entschlüsseln will,  \
dannach wird er gefragt ob er den Input von einer Datei lesen will (wenn nicht ist die Stdin als Standart
definiert) und nach dem Dezimalen Schlüssel zum ver/entschlüsseln gefragt.\
Der Output wird je nach Angabe des Benutzers in einer Datei gespeichert oder in der Console ausgegeben.
> 
>[^1]:https://github.com/eintim/crypto-tools/tree/main/src/lib
>[^2]:https://github.com/eintim/crypto-tools/blob/main/src/enigma/enigma.c
>[^3]:https://github.com/eintim/crypto-tools/blob/main/src/vigenere/vigenere.c
>[^4]: 
>[^5]:https://github.com/eintim/crypto-tools/blob/main/src/caesar/caesar.c
