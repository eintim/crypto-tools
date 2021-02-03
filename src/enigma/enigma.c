//
// Created by Jonas on 03.02.2021.
//

#include "enigma.h"
#include <stdio.h>
#include <ctype.h>
#include "../lib/clearInputBuffer.h"

void enigma_gui(){
    char c;
    printf("Enigma\n");
    do {
        c = tolower(getchar());
        switch (c) {
            case 'd':
                //Todo Decrypt
                break;
            case 'e':
                //TODO Encrypt
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
        clearInputBuffer(stdin);
    }while(c!='q');
}

void enigma_encrypt_gui(){
    char c;
    printf("Enigma Encrypt\n");
    printf("Read from file?(y,N) ");
    c = getchar();


}