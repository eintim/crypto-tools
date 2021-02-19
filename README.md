```
  /$$$$$$                                  /$$                    /$$$$$$$$                  /$$          
 /$$__  $$                                | $$                   |__  $$__/                 | $$          
| $$  \__/  /$$$$$$  /$$   /$$  /$$$$$$  /$$$$$$    /$$$$$$         | $$  /$$$$$$   /$$$$$$ | $$  /$$$$$$$
| $$       /$$__  $$| $$  | $$ /$$__  $$|_  $$_/   /$$__  $$ /$$$$$$| $$ /$$__  $$ /$$__  $$| $$ /$$_____/
| $$      | $$  \__/| $$  | $$| $$  \ $$  | $$    | $$  \ $$|______/| $$| $$  \ $$| $$  \ $$| $$|  $$$$$$ 
| $$    $$| $$      | $$  | $$| $$  | $$  | $$ /$$| $$  | $$        | $$| $$  | $$| $$  | $$| $$ \____  $$
|  $$$$$$/| $$      |  $$$$$$$| $$$$$$$/  |  $$$$/|  $$$$$$/        | $$|  $$$$$$/|  $$$$$$/| $$ /$$$$$$$/
 \______/ |__/       \____  $$| $$____/    \___/   \______/         |__/ \______/  \______/ |__/|_______/ 
                     /$$  | $$| $$                                                                        
                    |  $$$$$$/| $$                                                                        
                     \______/ |__/                         
```
# Crypto-Tools
Crypto-Tools is a command-line crypto toolkit. Its goal is to show different cryptographic ciphers to help other students.
The project got developed by Jonas Eppard, Marcel Alex and Tim Horlacher

Here are some feature highlights:
- **Caesar**: Encrypt like Julius Caesar
- **Diffie Hellman**: Create a shared key with a friend
- **Enigma**: Encryption Made in Germany. Encrypt like it's 1944
- **RSA**: Use assymmentric cryptography
- **Vigenere**: Encrypt like Caesar, but fancier

## Download
Executables are availible [here](https://github.com/eintim/crypto-tools/releases) on Github.

## Usage
Simply start the executable.
```
./crypto-tools
```
Its also possible to use a shortcut to an specific ciphers
```
./crypto-tools [-c|-d|-e|-r|-v]

Description
  -c Caesar
  -d Diffie Hellman Key Exchange
  -e Enigma
  -r RSA
  -v Vigenere
```
## Build
### On Linux
```
make
```
## License
Crypto-Tools is under the unlicense license. See the [LICENSE](https://github.com/eintim/crypto-tools/blob/main/LICENSE) for more information.
