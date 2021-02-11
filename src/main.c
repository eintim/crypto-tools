#include "headers.h"

int main(int argc, char *argv[]){
    int o;
    while ((o = getopt(argc, argv, "evc")) != -1)
    {
        switch (o)
        {
            case 'e':
                enigma_gui();
                break;
            case 'v':
                vigenere_gui();
                break;
            case 'c':
                //TODO caeser_gui();
                break;
            default:
                break;
        }
    }
    
        printf(R"EOF(
  /$$$$$$                                  /$$                     /$$$$$$$$                  /$$          
 /$$__  $$                                | $$                    |__  $$__/                 | $$          
| $$  \__/  /$$$$$$  /$$   /$$  /$$$$$$  /$$$$$$    /$$$$$$          | $$  /$$$$$$   /$$$$$$ | $$  /$$$$$$$
| $$       /$$__  $$| $$  | $$ /$$__  $$|_  $$_/   /$$__  $$         | $$ /$$__  $$ /$$__  $$| $$ /$$_____/
| $$      | $$  \__/| $$  | $$| $$  \ $$  | $$    | $$  \ $$         | $$| $$  \ $$| $$  \ $$| $$|  $$$$$$ 
| $$    $$| $$      | $$  | $$| $$  | $$  | $$ /$$| $$  | $$         | $$| $$  | $$| $$  | $$| $$ \____  $$
|  $$$$$$/| $$      |  $$$$$$$| $$$$$$$/  |  $$$$/|  $$$$$$/         | $$|  $$$$$$/|  $$$$$$/| $$ /$$$$$$$/
 \______/ |__/       \____  $$| $$____/    \___/   \______/          |__/ \______/  \______/ |__/|_______/ 
                     /$$  | $$| $$                                                                         
                    |  $$$$$$/| $$                                                                         
                     \______/ |__/                                                                         
        )EOF");

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