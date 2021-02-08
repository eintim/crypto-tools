
#include "caesar.h"

void caesar_gui() {



    char *message;

    int key;
    int i;


    printf("Enter a message to encrypt: ");//funktion des ausgabetypens impelmentieren TODO
    message = readString(stdin, -1);//funktion des eingabetypes impelmentieren TODO
    printf("Enter key: ");//funktion des ausgabetypens impelmentieren TODO
    scanf("%d", &key);
    key = key%26;

    for (i = 0; message[i] != '\0'; ++i) {


        if (message[i] >= 'a' && message[i] <= 'z') {

            message[i] = message[i] + key;
            message[i] = (message[i] - 'a'+26) % 26 + 'a';


        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] + key;
            message[i] = (message[i] - 'A'+26) % 26 + 'A';

        }
    }

    printf("Encrypted message: %s", message);//funktion des ausgabetypens impelmentieren TODO
    free(message);

}
