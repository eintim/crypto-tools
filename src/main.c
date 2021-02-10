#include "headers.h"

int main(){
    char c;
    printf("Cryto Tools Menu\n");
    do {
        printf("-> ");
        c = tolower(readOneChar(stdin));
        switch (c) {
            case 'e':
                enigma_gui();
                break;
            case 'v':
                vigenere_gui();
                break;
            case 'c':
                //TODO caeser_gui();
                break;
            case 'q':
                printf("Leaving Crypto Tools...\n");
                break;
            case 'h':
                printf("Help:\n");
                printf("\t [c]aesar \t- use caesar\n");
                printf("\t [e]nigma \t- use enigma\n");
                printf("\t [v]igenere \t- use vigenere\n");
                printf("\t [h]elp \t- show this menu\n");
                printf("\t [q]uit \t- leave this application\n");
                break;
            default:
                printf("Enter Valid char (h/H) for Help!\n");
                break;
        }
    }while(c!='q');
    return 0;
}