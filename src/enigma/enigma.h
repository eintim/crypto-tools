//
// Created by Jonas on 03.02.2021.
//

#ifndef SRC_ENIGMA_H
#define SRC_ENIGMA_H
#include "../lib/clearInputBuffer.h"
#include "../lib/readString.h"
#include "../lib/readOneChar.h"
#include "../lib/readFileInString.h"
#include "../lib/writeStringInFile.h"
#include <malloc.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>
void enigma_gui();
void enigma(char * string, const int rotors[3], int offset[3], const int replaceChar[26]);
int getNumberOfChar(const char c);
int indexOfElement(int * array, int element, int len);
#endif //SRC_ENIGMA_H
