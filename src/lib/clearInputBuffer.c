//
// Created by Jonas on 03.02.2021.
//

#include "clearInputBuffer.h"
void clearInputBuffer(FILE* stream){
    char c;
    while ((c = fgetc(stream)) != '\n' && c != EOF){}
}