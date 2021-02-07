#ifndef SRC_VIGENERE_H
#define SRC_VIGENERE_H
#include "../lib/clearInputBuffer.h"
#include "../lib/readString.h"
#include "../lib/readOneChar.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void vigenere_gui();
void vigenere_encrypt_gui();
void vigenere_decrypt_gui();
char encrypt_char(char c, char key);
char decrypt_char(char c, char key);
#endif //SRC_VIGENERE_H