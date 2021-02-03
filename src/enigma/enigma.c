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
            printf(strerror(errno));
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
        printf("Enter Text to encrypt:\n");
        input_str = readString(stdin, -1);
    }

    //TODO
    free(input_str);
}