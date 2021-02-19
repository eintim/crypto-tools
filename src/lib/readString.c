//
// Created by Jonas on 03.02.2021.
//
#include <malloc.h>
#include <stdio.h>

char * readString(FILE* stream, unsigned int maxLen){
    int c; //akt char
    char* str =malloc(sizeof(char));
    str[0]='\0';
    for (int i = 0; (unsigned int)i < maxLen && ((c = fgetc(stream))!= '\n')&& c != EOF; ++i) {
        str = realloc(str, (i+2)* sizeof(char));   //expand size of Memory area
        str[i] = c;                                     //write char
        str[i+1]='\0';                                  //Add '\0' for end of string
    }
    return str;
}