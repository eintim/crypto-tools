# **Crypto-tools**
###### *von Jonas Eppard, Tim Horlacher und Marcel Alex.*

Crypto-Tools ist ein Programm, dass verschiede Cryptographische Verfahren beherscht.
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

### [Caesar]
#### Benutzer-Beschreibung
Das Unterprogramm Caesar basiert auf der Gleichnamigen Caesar-Verschlüsselung.\
Zuerst wird abgefragt ob der Benutzer eine Nachricht verschlüsseln oder entschlüsseln will,\
danach wird dem Benutzer  die Möglichkeit gegeben den zu Ver/entschlüsselnden Text aus einer Datei zu lesen oder selbst einzugeben.\
Daraufhin wird die Zahl zum ver/entschlüsseln abgefragt.\
Der Output wird je nach Angabe des Benutzers in einer Datei gespeichert oder in der Konsole ausgegeben.

#### Benutzer-Beschreibung

### [DH-Handshake]
### Benutzer-Beschreibung
Zuerst werde zwei öffentliche Schlüssel abgefragt, dann kann man zwei geheime Schlüssel festlegen.\
Anhand der öffentlichen Schlüssel werden neue Schlüsse errechnet welche, \
den Benutzern weitergegeben werden,
ohne den geheimen Schlüssel des jeweils anderen zu kennen.

#### Entwickler-Dokumentation

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
Die Entschlüsselung funktioniert exakt gleich, da das Verfahren der Enigma Symetrisch ist.\
*Es ist zu Beachten das es **KEINE** Input-Validation gibt!*
#### Entwickler-Dokumentation
Das Enigma Programm liest seine Eingaben mithilfe der Libary Funktionen ein. Die Eigenschaften der Schlüssel werden in Arrays gespeichert um leichtes zugreifen zu ermöglichen.
Die Vertauschung der Buchstaben ist durch einen Lookup-table implementiert. Die Verschlüsselung selber beruht darauf
das die Verdrahtung eines Rotors in einem Array gespeichert ist und so das neue Zwischenergebnis einfach an dem Index
des Aktuellen Ergibnisses steht. Hierbei ist zu beachten, dass nach der UKW der Index der Aktuellen Zahl benötigt wird.
Hierzu wird durch die Liste iteriert bis das Element gefunden ist.

### [RSA]
#### Benutzer-Beschreibung
Die RSA Verschlüsselung basirt auf der komplexität eine Zahl zu faktorisieren. Dabei wird FolenderMaßen Verschlüsselt:\
```cypher = (Message)^publicKey mod N; Message = (cypher)^privateKey mod N```
##### Verwendung
Das Menü der RSA Verschlüsselung kann mit der Eingabe 'r' erreicht werden. Dort kann man über die Eingabe 'g' ein Key-Paar generieren. 
dazu braucht das Programm 2 Primzahlen, diese müssen vom benutzer eingegeben werden.
genrieren. Dieses gibt einem Dann mehrere Möglichkeiten ein Paar zu wählen, dabie ist darauf zu achten das ein Paar verwendet 
wird und nicht public und private key aus unterschiedlichen Spalten, dies führt zu Fehlern. Außerdem muss die Basis N notiert werden.
Mit diesen Informationen kann dann mit 'e' eine Nachricht verschlüsselt werden und mit 'd' eine Nachricht wieder Entschlüsselt.
Hierbei muss einfach nur den Angaben in der Konsole folge geleistet werden.\
*Es ist zu Beachten das es **KEINE** Input-Validation gibt!*
#### Entwickler-Dokumentation
In der Implementation von RSA ist zu bedenken, dass es zu großen Hochzahlen mit großen basen kommt, daher wurde eine Funktion implementiert,
die schnell eine Hochzahl in einer Restklasse berechnen kann, dazu wird Rekursiv vorgegangen und dadurch ist die komplexität
nahe an der Komplexitätsklasse ```O(log n)```. Außerdem muss aus dem String eine Zahl gemacht werden und dann zum schreiben in die Konsole,
oder eine Datei aus der Zahl ein String, dazu wurde ```sprintf``` verwendet. Diese Funktion ermöglicht es eine Ausgabe in ein 
CharArray zu speichern. Dabei können die Formatierungszeichen von ```printf``` verwendet werden.
Um aus einem String eine Zahl zu machen wurde ```strtollu``` verwendet, diese Funktion kann aus einem String in einen ```unsigned long long``` konvertieren.
```unsigned long long``` wurde verwendet um RSA mit grösmöglichen Zahlen sicherzustellen. Die Genauchigkeit eines ```double``` wäre in dieser
Anwendung nicht ausreichend gewesen.

### [Vigenere]
#### Benutzer-Beschreibung
Das Unterprogramm basiert auf der Gleichnamigen  Vigenere-Chiffre-Verschlüsselung.\
Zuerst wird abgefragt ob der Benutzer eine Nachricht verschlüsseln oder entschlüsseln will,\
danach wird dem Benutzer  die Möglichkeit gegeben den zu Ver/entschlüsselnden Text aus einer Datei zu lesen oder selbst einzugeben.\
Daraufhin wird der Buchstaben zum ver/entschlüsseln abgefragt.\
Der Output wird je nach Angabe des Benutzers in einer Datei gespeichert oder in der Konsole ausgegeben.

#### Entwickler-Dokumentation





[Selbstgeschrieben]:https://github.com/eintim/crypto-tools/tree/main/src/lib
[Enigma]:https://github.com/eintim/crypto-tools/blob/main/src/enigma
[Vigenere]:https://github.com/eintim/crypto-tools/blob/main/src/vigenere
[DH-Handshake]:https://github.com/eintim/crypto-tools/blob/main/src/diffiehellman
[Caesar]:https://github.com/eintim/crypto-tools/blob/main/src/caesar
[RSA]:https://github.com/eintim/crypto-tools/tree/main/src/rsa