//
// Created by Jonas on 03.02.2021.
//

#include "enigma.h"


void enigma_gui(){
    char c;
    printf("Enigma Menu\n");
    do {
        printf("-> ");
        c = tolower(readOneChar(stdin));
        switch (c) {
            case 'd':
                //Todo Decrypt
                break;
            case 'e':
                enigma_encrypt_gui();
                break;
            case 'q':
                printf("Leaving Enigma...\n");
                break;
            case 'h':
                printf("Help:\n");
                printf("\t [d]ecrypt \t- decrypt some data\n");
                printf("\t [h]elp \t- show this menu\n");
                printf("\t [e]ncrypt \t- encrypt some data\n");
                printf("\t [q]uit \t- leave this application\n");
                break;
            default:
                printf("Enter Valid char (h/H) for Help!\n");
                break;
        }
    }while(c!='q');
}

void enigma_encrypt_gui(){
    char c;
    printf("Enigma Encrypt\n");
    printf("Read from file?(y,N) ");
    c = tolower(readOneChar(stdin));
    char * input_str;
    if (tolower(c) == 'y'){ //Read input string from file
        printf("Enter filename: ");
        char * filename;
        filename = readString(stdin, -1);
        FILE* my_file = fopen(filename, "r");
        if (my_file == NULL){
            printf("%s", strerror(errno));
        }
        input_str = malloc(sizeof (char));
        input_str[0] = '\0';
        char tmp;
        unsigned int len = 0;
        while ((tmp = getc(my_file) )!= EOF){
            input_str = realloc(input_str, (len+2)*sizeof(char));
            input_str[len] = tmp;
            input_str[len+1] = '\0';
            len++;
        }
        fclose(my_file);
        free(filename);
    }
    else{
        printf("Enter Text:\n");
        input_str = readString(stdin, -1);
    }
    printf("Enter key format = (iii c c c *(cc )\n");
    printf("First 3 integer in range 1-5\n");
    printf("Each char only one in the pairs at the end\n");
    char * key;
    key = readString(stdin, -1);
    int rotors[3];
    for (int i = 0; i < 3; ++i) {       //Read which rotors are used
        rotors[i] = (int) key[i] - 48;
    }
    int offset[3];
    for (int i = 4; i < 9; i+=2) {      //Read offset of rotors
        offset[i] = getNumberOfChar(key[i]);
    }
    int replaceChars[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    for (int i = 10; i < strlen(key); ++i) {    //Read keypairs
        int valueFirstLetter = getNumberOfChar(key[i]);
        int valueSecondLetter = getNumberOfChar(key[i+1]);
        replaceChars[valueFirstLetter] = valueSecondLetter;
        replaceChars[valueSecondLetter] = valueFirstLetter;
    }
    //TODO

    free(key);
    free(input_str);
}

int getNumberOfChar(char c){
    return (c - 'A')%32;
}