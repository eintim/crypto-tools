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
Das Unterprogramm basiert auf der Gleichnamigen  Vigenere-Chiffre-Verschlüsselung.\
Zuerst wird abgefragt ob der Benutzer eine Nachricht verschlüsseln oder entschlüsseln will,\
danach wird dem Benutzer  die Möglichkeit gegeben den zu Ver/entschlüsselnden Text aus einer Datei zu lesen oder selbst einzugeben.\
Daraufhin wird der Buchstaben zum ver/entschlüsseln abgefragt.\
Der Output wird je nach Angabe des Benutzers in einer Datei gespeichert oder in der Konsole ausgegeben.

#### Entwickler-Dokumentation

### [DH-Handshake]
### Benutzer-Beschreibung
Zuerst werde zwei öffentliche Schlüssel abgefragt, dann kann man zwei geheime Schlüssel festlegen.\
Anhand der öffentlichen Schlüssel werden neue Schlüsse errechnet welche, \
den Benutzern weitergegeben werden,
ohne den geheimen Schlüssel des jeweils anderen zu kennen.


#### Entwickler-Dokumentation

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
Nach dem, durch die Selbstgeschriebene Bibliotheksfunktion :```readOneChar.h```, Entschieden wurde ob ent/verschlüsselt werden soll \
und ob der Benutzer von einer Datei lesen will, liest das Programm ``Caesar.c`` in der Unterfunktion:``input()`` seinen zu ent/verschlüsselnden Text und den gewünschten Schlüssel ein.\
Dies geschieht für den Text mithilfe der Selbstgeschriebene Bibliotheksfunktion :`` readString.h`` oder ``readFileInString.h``.\
Da der Schlüssel mithilfe der Funktion ``scanf();`` eingelesen wurde und das Element nicht im Buffer stehen Bleiben soll,\
wird dieser mithilfe der selbstgeschriebene Bibliotheksfunktion : ``clearInputBuffer.h`` gereinigt.\
Der Text, der Name der Datei und Schlüssel werden in einem Struct :``inputStruct``, durch einen Pointer übergeben.\
Mit dem Inhalt diese Pointers werden nun die Operationen ``caesar_decrypt()`` oder ``caesar_encrypt()`` durchgeführt, \
in welchen die einzelnen Character des Übergebenen Textes um den Schlüssel erhöht oder verringert werden.\
Äquivalent zur Eingabe fragt die Funktion ``output()`` wie der ver/entschlüsselte Text ausgegeben werden soll und gibt ihn aus.

[Selbstgeschrieben]:https://github.com/eintim/crypto-tools/tree/main/src/lib
[Enigma]:https://github.com/eintim/crypto-tools/blob/main/src/enigma/enigma.c
[Vigenere]:https://github.com/eintim/crypto-tools/blob/main/src/vigenere/vigenere.c
[DH-Handshake]:https://github.com/eintim/crypto-tools/blob/main/src/diffiehellman/diffiehellman.c
[Caesar]:https://github.com/eintim/crypto-tools/blob/main/src/caesar/caesar.c
          