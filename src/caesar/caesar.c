#include "caesar.h"

 struct inputStruct
{
    char *message;
    int key;
    int mode;

};

void caesar_gui()
{
    char c;
    printf("Caesar Menu\n");
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
                printf("Leaving Caesar...\n");
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


    struct inputStruct inputv;
    struct inputStruct *pointer = &inputv;
    pointer->mode = 0;
    input(pointer);

    for (int i = 0; inputv.message[i] != '\0'; ++i)
    {


        if (inputv.message[i] >= 'a' && inputv.message[i] <= 'z')
        {

            inputv.message[i] = inputv.message[i] + inputv.key;
            inputv.message[i] = (inputv.message[i] - 'a'+26) % 26 + 'a';


        }

        else if (inputv.message[i] >= 'A' && inputv.message[i] <= 'Z')
        {
            inputv.message[i] = inputv.message[i] + inputv.key;
            inputv.message[i] = (inputv.message[i] - 'A'+26) % 26 + 'A';

        }
    }

    printf("Encrypted message: %s\n", inputv.message);
    free(inputv.message);


}

void caesar_decrypt()
{

    struct inputStruct inputv;
    struct inputStruct *pointer = &inputv;
    pointer->mode = 0;

    input(pointer);
    for (int i = 0; inputv.message[i] != '\0'; ++i)
    {


        if (inputv.message[i] >= 'a' && inputv.message[i] <= 'z')
        {

            inputv.message[i] = inputv.message[i] - inputv.key;
            inputv.message[i] = (inputv.message[i] - 'a'+26) % 26 + 'a';


        }

        else if (inputv.message[i] >= 'A' && inputv.message[i] <= 'Z')
        {
            inputv.message[i] = inputv.message[i] - inputv.key;
            inputv.message[i] = (inputv.message[i] - 'A'+26) % 26 + 'A';

        }

    }
    printf("Decrypted message: %s\n", inputv.message);
    free(inputv.message);


}


struct inputStruct input(struct inputStruct *pointer )
{
    char c;
    int *filename;
    struct inputStruct messageKey;
    printf("work with files ?(y,n) \n");
    c = tolower(readOneChar(stdin));
    if (c == 'y')
    {
        free(c);
        printf("read from file? (y,n) \n");
        c = tolower(readOneChar(stdin));
        if(c == 'y')
        {
            printf("write the filename:");
            filename = readString(stdin, -1);
            messageKey.message = readFileInString(filename, -1);
        }
    }
    else if(c == 'n') {
        printf("Enter your message\n");
        messageKey.message = readString(stdin, -1);
        printf("Enter key: ");
        scanf("%d", &messageKey.key);
        clearInputBuffer(stdin);
        messageKey.key %= 26; // same as  messageKey.key = messageKey.key%26;
        *pointer = messageKey;
    }
}
