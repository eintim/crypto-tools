//
// Created by Jonas on 03.02.2021.
//

#include "clearInputBuffer.h"
void clearInputBuffer(FILE* stream){ //Problem there musst be a '\n' in stream
    char c;
    while ((c = getc(stream)) != '\n' && c != EOF){}
}