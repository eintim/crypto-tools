#ifndef CAESAR
#define CAESAR 0
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../lib/readString.h"
#include "../lib/readOneChar.h"
#include "../lib/clearInputBuffer.h"
#include "../lib/readFileInString.h"
#include "../lib/writeStringInFile.h"
struct inputStruct{
    char *message;
    int key;
    char *filename;
};
void caesar_gui();
int input(struct inputStruct *pointer);
void caesar_encrypt();
void caesar_decrypt();
int output(int mode ,struct inputStruct *pointer );
#endif // !CAESAR