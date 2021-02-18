#ifndef SRC_VIGENERE_H
#define SRC_VIGENERE_H
#include "../lib/clearInputBuffer.h"
#include "../lib/readString.h"
#include "../lib/readOneChar.h"
#include "../lib/readFileInString.h"
#include "../lib/writeStringInFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void vigenere_gui();
void vigenere_encrypt_gui();
void vigenere_decrypt_gui();
void vigenere_encrypt(char* message, char* key);
void vigenere_decrypt(char* message, char* key);
char encrypt_char(char c, char key);
char decrypt_char(char c, char key);
#endif //SRC_VIGENERE_H