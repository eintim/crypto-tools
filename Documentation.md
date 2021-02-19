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

#### Benutzer-Beschreibung Enigma 
> Das Unterprogramm basiert auf der Gleichnamigen Enigma Maschine des II Weltkrieges.\
> Der Benutzer hat die Möglichkeit aus eine Datei zu lesen oder den Text selbst einzugeben,\
> danach wird der entsprechende Schlüssel eingelesen und der Input mit dem Enigma-Prinzipe Ver/entschlüsselt.\
> Der Output wird je nach Angabe des Benutzers in einer Datei gespeichert oder in der Konsole ausgegeben. 

#### Entwickler-Dokumentation Enigma [^2]
>

#### Benutzer-Beschreibung Vigenere 
> Das Unterprogramm basiert auf der Gleichnamigen  Vigenere-Chiffre-Verschlüsselung.\
> Zuerst wird abgefragt ob der Benutzer eine Nachricht verschlüsseln oder entschlüsseln will,\
> danach wird dem Benutzer  die Möglichkeit gegeben den zu Ver/entschlüsselnden Text aus einer Datei zu lesen oder selbst einzugeben.\
> Daraufhin wird der Buchstaben zum ver/entschlüsseln abgefragt.\
> Der Output wird je nach Angabe des Benutzers in einer Datei gespeichert oder in der Konsole ausgegeben.

#### Entwickler-Dokumentation Vigenere [^3]
>

#### Benutzer-Beschreibung DH-Handshake 
> Zuerst werde zwei öffentliche Schlüssel abgefragt, dann kann man zwei geheime Schlüssel festlegen.\
> Anhand der öffentlichen Schlüssel werden neue Schlüsse errechnet welche den Benutzern weitergegeben werden,
> ohne den geheimen Schlüssel des jeweils anderen zu kennen.

#### Entwickler-Dokumentation DH-Handshake [^4]
>

#### Benutzer-Beschreibung Caesar 
> Das Unterprogramm Caesar basiert auf der Gleichnamigen Caesar-Verschlüsselung.\
> Zuerst wird abgefragt ob der Benutzer eine Nachricht verschlüsseln oder entschlüsseln will,\
> danach wird dem Benutzer  die Möglichkeit gegeben den zu Ver/entschlüsselnden Text aus einer Datei zu lesen oder selbst einzugeben.\
> Daraufhin wird die Zahl zum ver/entschlüsseln abgefragt.\
> Der Output wird je nach Angabe des Benutzers in einer Datei gespeichert oder in der Konsole ausgegeben.

#### Entwickler-Dokumentation Caesar [^5]
>
>
>[^1]:https://github.com/eintim/crypto-tools/tree/main/src/lib
>[^2]:https://github.com/eintim/crypto-tools/blob/main/src/enigma/enigma.c
>[^3]:https://github.com/eintim/crypto-tools/blob/main/src/vigenere/vigenere.c
>[^4]:https://github.com/eintim/crypto-tools/blob/main/src/diffiehellman/diffiehellman.c
>[^5]:https://github.com/eintim/crypto-tools/blob/main/src/caesar/caesar.c
        