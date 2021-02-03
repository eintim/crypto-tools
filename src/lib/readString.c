//
// Created by Jonas on 03.02.2021.
//
#include <malloc.h>
#include <stdio.h>

char * readString(FILE* stream, unsigned int maxLen){
    int c;
    char* str =malloc(sizeof(char));
    str[0]='\0';
    for (int i = 0; i < maxLen && ((c = fgetc(stream))!= '\n'); ++i) {
        str = realloc(str, (i+2)* sizeof(char));
        str[i] = c;
        str[i+1]='\0';
    }
    return str;
}