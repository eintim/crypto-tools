//
// Created by Jonas on 03.02.2021.
//

#include "enigma.h"


void enigma_gui() {
    //Hello Promt
    printf("Enigma I:\n");

    int c;  //Char for Input

    //Read Input for en-/decryption
    char *input_str = NULL;   //String for Data to be encrypted
    do {    //Loop until valid Input
        //Read if Encrypt file
        printf("Read Text from file?(y,N) ");
        c = tolower(readOneChar(stdin));

        if (tolower(c) == 'y') { //Read input string from file
            //Read filename
            printf("Enter filename: ");
            char *filename;
            filename = readString(stdin, -1);

            //read File
            input_str = readFileInString(filename, -1);

            free(filename);
        } else {
            //Input String via commandline
            printf("Enter Text:\n");
            input_str = readString(stdin, -1);
        }
    } while (input_str == NULL);

    //Read Key
    printf("Enter key format = (iii c c c *(cc )\n");
    printf("First 3 integer in range 1-5\n");
    printf("Each char only one in the pairs at the end\n");


    char *key;
    key = readString(stdin, -1);
    int rotors[3];
    for (int i = 0; i < 3; ++i) {       //Read which rotors are used
        rotors[i] = (int) key[i] - 49;  //Conversion from char '1' to 0 and so on
    }
    int offset[3];
    for (int i = 0; i < 3; ++i) {      //Read offset of rotors
        offset[i] = getNumberOfChar(key[2 * i + 4]);       //conversion from char to int in range 26
    }
    //Read all the replaced Chars Error on input will not be detected!
    int replaceChars[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
                            25};
    for (int i = 1; 3 * i + 11 < strlen(key); ++i) {    //Read keypairs
        int valueFirstLetter = getNumberOfChar(key[3 * i + 10]);
        int valueSecondLetter = getNumberOfChar(key[3 * i + 11]);
        replaceChars[valueFirstLetter] = valueSecondLetter;
        replaceChars[valueSecondLetter] = valueFirstLetter;
    }
    free(key);  //string of key not needed

    //En-/decrypt message
    enigma(input_str, rotors, offset, replaceChars);

    //Output
    printf("Write Output to file? (y/N): ");
    c = tolower(readOneChar(stdin));
    if (c == 'y') { //Write in File
        printf("Input Filename:\n");
        char *filename = readString(stdin, -1);
        int error = writeStringInFile(input_str, filename, "w");
        if (error) {
            printf("Something went wrong!");
        }
        free(filename);
    } else {
        printf("%s\n", input_str);  //print output
    }
    //free all allocated pointers
    free(input_str);
}

int getNumberOfChar(const char c) {//Get Value 0-25 to represent Char
    return (c - 'A') % 32;
}

void enigma(char *string, const int rotors[3], int offset[3],
                    const int replaceChar[26]) {    //Manipulates string must be terminated with '\0'
    //walzen stores Information on Encryption
    int walzen[6][26] = {
            {4,  10, 12, 5,  11, 6,  3,  16, 21, 25, 13, 19, 14, 22, 24, 7,  23, 20, 18, 15, 0,  8,  1,  17, 2,  9},
            {0,  9,  3,  10, 18, 8,  17, 20, 23, 1,  11, 7,  22, 19, 12, 2,  16, 6,  25, 13, 15, 24, 5,  21, 14, 4},
            {1,  3,  5,  7,  9,  11, 2,  15, 17, 19, 23, 21, 25, 13, 24, 4,  8,  22, 6,  0,  10, 12, 20, 18, 16, 14},
            {4,  18, 14, 21, 15, 25, 9,  0,  24, 16, 20, 8,  17, 7,  23, 11, 13, 5,  19, 6,  10, 3,  2,  12, 22, 1},
            {21, 25, 1,  17, 6,  8,  19, 24, 20, 15, 18, 3,  13, 7,  11, 23, 0,  22, 12, 9,  16, 14, 5,  4,  2,  10},
            {24, 17, 20, 7,  16, 18, 11, 3,  15, 23, 13, 6,  14, 10, 12, 8,  4,  1,  5,  25, 2,  22, 21, 9,  0,  19}
    };

    for (int i = 0; string[i] != '\0'; ++i) {
        if (isalpha(string[i])) {
            //Rotate Weels
            offset[0] += 1;
            offset[1] += offset[0] / 26;
            offset[2] += offset[1] / 26;
            offset[2] %= 26;
            offset[1] %= 26;
            offset[0] %= 26;

            //Detect Lowercase
            int lowerCaseOffset = 0;
            if (islower(string[i])) {
                lowerCaseOffset = 32;
            }

            //Translate to int for Encryption
            int akt = getNumberOfChar(string[i]);

            //Replace Chars
            akt = replaceChar[akt];

            //Path forward
            for (int j = 0; j < 3; ++j) {
                akt = walzen[rotors[j]][(akt + offset[j]) % 26];
            }

            //Reflector
            akt = walzen[5][akt];

            //Path back
            for (int j = 2; j >= 0; --j) {
                akt = indexOfElement(walzen[rotors[j]], (akt), 26) - offset[j];
                if (akt < 0) {
                    akt += 26;
                }
            }

            akt = replaceChar[akt];                     //Char replacement
            string[i] = 'A' + akt + lowerCaseOffset;    //Int to string conversion
        }
    }
}

int indexOfElement(int *array, int element, int len) {
    for (int i = 0; i < len; ++i) {
        if (array[i] == element) {
            return i;
        }
    }
    return -1;
}