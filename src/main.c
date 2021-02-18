#include "headers.h"

int main(int argc, char *argv[]){
    int o;
    if (argc == 2){
        o = argv[1][1];
        switch (o)
        {
            case 'e':
               // enigma_gui();
                break;
            case 'v':
               // vigenere_gui();
                break;
            case 'c':
                caesar_gui();
                break;
            default:
                break;
        }
    }

    printf("  /$$$$$$                                  /$$                     /$$$$$$$$                  /$$          \n"
" /$$__  $$                                | $$                    |__  $$__/                 | $$          \n"
"| $$  \\__/  /$$$$$$  /$$   /$$  /$$$$$$  /$$$$$$    /$$$$$$          | $$  /$$$$$$   /$$$$$$ | $$  /$$$$$$$\n"
"| $$       /$$__  $$| $$  | $$ /$$__  $$|_  $$_/   /$$__  $$         | $$ /$$__  $$ /$$__  $$| $$ /$$_____/\n"
"| $$      | $$  \\__/| $$  | $$| $$  \\ $$  | $$    | $$  \\ $$         | $$| $$  \\ $$| $$  \\ $$| $$|  $$$$$$ \n"
"| $$    $$| $$      | $$  | $$| $$  | $$  | $$ /$$| $$  | $$         | $$| $$  | $$| $$  | $$| $$ \\____  $$\n"
"|  $$$$$$/| $$      |  $$$$$$$| $$$$$$$/  |  $$$$/|  $$$$$$/         | $$|  $$$$$$/|  $$$$$$/| $$ /$$$$$$$/\n"
" \\______/ |__/       \\____  $$| $$____/    \\___/   \\______/          |__/ \\______/  \\______/ |__/|_______/\n"
"                     /$$  | $$| $$\n"
"                    |  $$$$$$/| $$\n"
"                     \\______/ |__/\n\n");

    printf("Help:\n");
    printf("\t [c]aesar \t- use caesar\n");
    printf("\t [e]nigma \t- use enigma\n");
    printf("\t [v]igenere \t- use vigenere\n");
    printf("\t [h]elp \t- show this menu\n");
    printf("\t [q]uit \t- leave this application\n");
    char c;
    do {
        printf("-> ");
        c = tolower(readOneChar(stdin));
        switch (c) {
            case 'e':
          //      enigma_gui();
                break;
            case 'v':
             //   vigenere_gui();
                break;
            case 'c':
                caesar_gui();
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