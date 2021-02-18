#include "caesar.h"
void caesar_gui()
{
    char c;
    printf("caesar Menu\n");
    do {
        printf("-> ");
        c = tolower(readOneChar(stdin));
        switch (c) {
            case 'd':
                caesar_decrypt();
                break;
            case 'e':
                caesar_encrypt();
                break;
            case 'q':
                printf("Leaving caesar...\n");
                break;
            case 'h':
                printf("Help:\n");
                printf("\t [d]ecrypt \t- decrypt some data\n");
                printf("\t [e]ncrypt \t- encrypt some data\n");
                printf("\t [h]elp \t- show this menu\n");
                printf("\t [q]uit \t- leave this application\n");
                break;
            default:
                printf("Enter Valid char (h/H) for Help!\n");
                break;
        }
    }while(c!='q');
}
void caesar_encrypt()
{

    int mode = 0;
    struct inputStruct inputv;
    struct inputStruct *pointer = &inputv;


    if (input(pointer) == 0) {
        for (int i = 0; inputv.message[i] != '\0'; ++i) {


            if (inputv.message[i] >= 'a' && inputv.message[i] <= 'z') {

                inputv.message[i] = inputv.message[i] + inputv.key;
                inputv.message[i] = (inputv.message[i] - 'a' + 26) % 26 + 'a';


            } else if (inputv.message[i] >= 'A' && inputv.message[i] <= 'Z') {
                inputv.message[i] = inputv.message[i] + inputv.key;
                inputv.message[i] = (inputv.message[i] - 'A' + 26) % 26 + 'A';

            }
        }
        if (output(mode, pointer) == 0)
        {
            printf("Thanks!\n");
        }

    }

}
void caesar_decrypt() {
    int mode = 1;
    struct inputStruct inputv;
    struct inputStruct *pointer = &inputv;


    if (input(pointer) == 0) {

        for (int i = 0; inputv.message[i] != '\0'; ++i) {


            if (inputv.message[i] >= 'a' && inputv.message[i] <= 'z') {

                inputv.message[i] = inputv.message[i] - inputv.key;
                inputv.message[i] = (inputv.message[i] - 'a' + 26) % 26 + 'a';


            } else if (inputv.message[i] >= 'A' && inputv.message[i] <= 'Z') {
                inputv.message[i] = inputv.message[i] - inputv.key;
                inputv.message[i] = (inputv.message[i] - 'A' + 26) % 26 + 'A';

            }

        }
        if (output(mode, pointer) == 0)
        {
            printf("Thanks!\n");
        }


    }
}
int input(struct inputStruct *pointer ){
    char c;
    struct inputStruct messageKey;

        printf("read from file? (y,N) ");
        c = tolower(readOneChar(stdin));
        if(c == 'y'){

            printf("Enter filename:\n");
            messageKey.filename = readString(stdin, -1);
            messageKey.message = readFileInString(messageKey.filename, -1);
            if(messageKey.message == NULL)
            {
                return 1;
            }
        }
        else{

            printf("Enter message: \n");
            messageKey.message = readString(stdin, -1);
        }
        printf("Enter key: \n");
        scanf("%d", &messageKey.key);
        clearInputBuffer(stdin);
        messageKey.key %= 26; // same as  messageKey.key = messageKey.key%26;
        *pointer = messageKey;
         return 0;
}
int output(int mode ,struct inputStruct *pointer)
{
    char c;
    printf("write in file? (y,n) \n");
    c = tolower(readOneChar(stdin));
    if(c == 'y'){
        printf("Enter the filename \n");
        pointer->filename =  readString(stdin, -1);
        if(pointer->message == NULL){
            return 1;
        }

        writeStringInFile("\n",pointer->filename,"a");
        writeStringInFile(pointer->message,pointer->filename,"a");
        free(pointer->message);
    }
    else{
        if(mode == 1)
        {
            printf("Encrypted message: %s\n", pointer->message);
            free(pointer->message);
        }
        else if(mode == 0){
            printf("Decrypted message: %s\n", pointer->message);
            free(pointer->message);
        }

    }
    return 0;
}