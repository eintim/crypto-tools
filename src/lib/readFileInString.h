//
// Created by Jonas on 03.02.2021.
//

#ifndef SRC_READFILEINSTRING_H
#define SRC_READFILEINSTRING_H
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <malloc.h>
char * readFileInString(char * filepath, unsigned int maxLen);
#endif //SRC_READFILEINSTRING_H
