//
// Created by Jonas on 06.02.2021.
//

#include "writeStringInFile.h"

int writeStringInFile(char * string, char * filename){
    FILE * file = fopen(filename, "w");
    if (file == NULL){
        printf("Error accured while writing file '%s': %s", filename, strerror(errno));
        return errno
    }
    else{
        for (int i = 0; string[i] != '\0' ; ++i) {
            fputc(string[i], file);
        }
        return 0;
    }
}