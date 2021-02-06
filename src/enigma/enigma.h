//
// Created by Jonas on 03.02.2021.
//

#ifndef SRC_ENIGMA_H
#define SRC_ENIGMA_H
#include "../lib/clearInputBuffer.h"
#include "../lib/readString.h"
#include "../lib/readOneChar.h"
#include <malloc.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <cstring>
void enigma_gui();
void enigma_encrypt_gui();
void enigma_decrypt_gui();
int getNumberOfChar(char c);
#endif //SRC_ENIGMA_H
