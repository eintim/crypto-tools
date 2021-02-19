//
// Created by Jonas on 03.02.2021.
//

#include "readFileInString.h"
char * readFileInString(char * filepath, unsigned int maxLen){//Reads the file and returns read string
    FILE * file;
    file = fopen(filepath, "r");
    if (file==NULL){
        printf("Error while reading File '%s': %s\n",filepath, strerror(errno));
        return NULL;
    }
    char * str;
    str = malloc(sizeof(char));
    str[0] = '\0';
    char tmp;
    for (int i = 0; (unsigned int)i < maxLen && ((tmp = fgetc(file)) != EOF); ++i) {
        str = realloc(str, (i+2)* sizeof(char));
        str[i] = tmp;
        str[i+1]= '\0';
    }
    fclose(file);
    return str;
}
