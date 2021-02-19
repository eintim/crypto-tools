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
Bei welcher jeder Buchstabe des Textes, im Alphabet um den gleichen Wert verschoben wird 

![Funktionsweiße](https://upload.wikimedia.org/wikipedia/commons/thumb/2/2b/Caesar3.svg/330px-Caesar3.svg.png "Bildlichen darstellung der Funktionsweiße")

##### Verwendung
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
Öffentliche Werte: ```P(Primzahl)``` und ```G(G < P)```\
Geheime Werte: ```a(a < P)``` und ```b(b < P)```\
Hierbei gilt zu beachtet das es keine Input-Validation gibt!\
Danach wird für jede Seite (a und b) ein öffentlicher Schlüssel berechnet.\
Dieser Schlüssel wird dann den jeweils anderen "zugeschickt".\
Mithilfe dieses Schlüssel kann nun jede Partei einen geheimen Schlüssel errechnen\
und dieser wird dann Ausgegeben. Aufgrund des Diffie-Hellmanns Verfahren haben beide Parteien nun\
den selben geheimen Schlüssel.\
#### Entwickler-Dokumentation
Das Programm liest die Eingaben aus dem Stream stdin nacheinander ein und berechnet daraus die passenden Schlüssel.\
Die Funktion pMod ist für die Berechnung der Schlüssel zuständig. Dahinter steckt die Formel ```res=a^b mod n```\
Um überläufe zu vermeiden wird intern der Datentyp ```long long``` verwendet.
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

### [Libs]
#### clearInputBuffer
Diese Funktion ließt den kompletten Input-Buffer bis zu einem ```EOF``` oder Linefeed. Diese Funktion wurde 
geschreben da ```fflush()``` in ANSI C nur auf Outputstreams definiert ist und nicht auf Input Streams.
Die Funktion wurde mit ```getc()``` implementiert und hat kein Return Value.
#### readFileInString
Diese Funktion öffnet ein File ließt es komplett in einen String, schließt das file wieder und gibt den String zurück.
Dabei wird dynamisch Speicher angefordert um sicherzustellen, dass der String in das dazugehörige Chararray passt.
Das File wird mit ```fopen``` geöffnet, mit ```fgetc``` gelesen und mit ```fclose``` wieder geschlossen.
Die Funktion gibt daraufhin ein Pointer auf den Speicherplatz mit dem gelesenen String zurück.
#### readOneChar
ReadOneChar ließt den gesammten Inputstream gibt allerdings nur den ersten Charakter zurück. Durch das lesen
des gesamten Streams wird dieser wieder in einen definierten zustand verlassen.
#### readString
Diese Funktion ließt eine komplette Zeile aus dem gegebenen Input-Stream. Dabei wird dynamisch Speicher allokiert und 
ein Pointer auf den Beginn des Strings übergeben, der String ist terminiert.
#### writeStringInFile
Diese Funktion öffnet eine Datei und schreibt den gegebenen String mithilfe von ```fputc``` hinein.
Dabei kann durch den Funktionsaufruf bestimmt werden ob der String angehängt werden soll oder die Datei
überschreiben werden soll.
Ausßerdem muss sichergegangen werden das der String terminiert ist.

[Libs]:https://github.com/eintim/crypto-tools/tree/main/src/lib
[Selbstgeschrieben]:https://github.com/eintim/crypto-tools/tree/main/src/lib
[Enigma]:https://github.com/eintim/crypto-tools/blob/main/src/enigma
[Vigenere]:https://github.com/eintim/crypto-tools/blob/main/src/vigenere
[DH-Handshake]:https://github.com/eintim/crypto-tools/blob/main/src/diffiehellman
[Caesar]:https://github.com/eintim/crypto-tools/blob/main/src/caesar
[RSA]:https://github.com/eintim/crypto-tools/tree/main/src/rsa

