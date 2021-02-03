//
// Created by Jonas on 03.02.2021.
//

#include "readOneChar.h"

void readOneChar(FILE * stream) {//This reads the first char and read to the next '\n'
    char c = '\0';
    char tmp;
    while ((tmp = getc(stream)) !='\n'){
        if (c == '\0'){
            c = tmp;
        }
    }
    return c;
}