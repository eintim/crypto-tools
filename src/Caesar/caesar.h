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
void caesar_gui();
void caesar_encrypt();
void caesar_decrypt();
struct inputStruct input();
#endif // !CAESAR