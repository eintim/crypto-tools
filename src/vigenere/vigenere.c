#include "vigenere.h"

void vigenere_gui(){
    char c;
    printf("Vigenere Menu\n");
    printf("The Vigenère cipher is a method of encrypting alphabetic text by using a series of interwoven Caesar ciphers, based on the letters of a keyword.\nIt employs a form of polyalphabetic substitution.\n\n");
    do {
        printf("-> ");
        c = tolower(readOneChar(stdin));
        switch (c) {
            case 'd':
                vigenere_decrypt_gui();
                break;
            case 'e':
                vigenere_encrypt_gui();
                break;
            case 'q':
                printf("Leaving Vigenere...\n");
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

void vigenere_encrypt_gui(){
    char* message;
    char* keyphrase;
    printf("Vigenere Encrypt\n");
    do {    //Loop until valid Input
        //Read if Encrypt file
        printf("Read Text from file?(y,N) ");
        char c = tolower(readOneChar(stdin));

        if (tolower(c) == 'y') { //Read input string from file
            //Read filename
            printf("Enter filename: ");
            char *filename;
            filename = readString(stdin, -1);

            //read File
            message = readFileInString(filename, -1);

            free(filename);
        } else {
            //Input String via commandline
            printf("Enter Text:\n");
            message = readString(stdin, -1);
        }
    } while (message == NULL);
    printf("Enter Key:\n");
    keyphrase = readString(stdin, -1);

    //Encrypt
    vigenere_encrypt(message, keyphrase);


    //Output
    printf("Write Output to file? (y/N): ");
    char c = tolower(readOneChar(stdin));
    if (c == 'y') { //Write in File
        printf("Input Filename:\n");
        char *filename = readString(stdin, -1);
        int error = writeStringInFile(message, filename, "w");
        if (error) {
            printf("Something went wrong!");
        }
    } else {
        printf("%s\n", message);  //print output
    }
    //free all allocated pointers
    free(message);
}

void vigenere_decrypt_gui(){
    char* message;
    char* keyphrase;
    printf("Vigenere Decrypt\n");
    do {    //Loop until valid Input
        //Read if Encrypt file
        printf("Read Text from file?(y,N) ");
        char c = tolower(readOneChar(stdin));

        if (tolower(c) == 'y') { //Read input string from file
            //Read filename
            printf("Enter filename: ");
            char *filename;
            filename = readString(stdin, -1);

            //read File
            message = readFileInString(filename, -1);

            free(filename);
        } else {
            //Input String via commandline
            printf("Enter Text:\n");
            message = readString(stdin, -1);
        }
    } while (message == NULL);
    printf("Enter Key:\n");
    keyphrase = readString(stdin, -1);

    //Decrypt
    vigenere_decrypt(message, keyphrase);
    
    //Output
    printf("Write Output to file? (y/N): ");
    char c = tolower(readOneChar(stdin));
    if (c == 'y') { //Write in File
        printf("Input Filename:\n");
        char *filename = readString(stdin, -1);
        int error = writeStringInFile(message, filename, "w");
        if (error) {
            printf("Something went wrong!");
        }
    } else {
        printf("%s\n", message);  //print output
    }
    //free all allocated pointers
    free(message);
}

void vigenere_encrypt(char* message, char* key){
    for (int i = 0, j = 0; (unsigned)i < strlen(message); i++, j++)
    {
        if((unsigned)j > strlen(key)-1)
            j = 0;

        message[i] = encrypt_char(message[i],key[j]);
    }
}

void vigenere_decrypt(char* message, char* key){
    for (int i = 0, j = 0; (unsigned)i < strlen(message); i++, j++)
    {
        if((unsigned)j > strlen(key)-1)
            j = 0;

        message[i] = decrypt_char(message[i],key[j]);
    }
}

char encrypt_char(char c, char key){

    if(islower(c))
        return (((c - 'a') + (tolower(key) - 'a')) % 26) + 'a';

    if(isupper(c))
        return (((c - 'A') + (tolower(key) -'a')) % 26) + 'A';
    
    return c;
}

char decrypt_char(char c, char key){

    if(islower(c))
        return (((c - 'a') - (tolower(key) - 'a') + 26) % 26) + 'a';

    if(isupper(c))
        return (((c - 'A') - (tolower(key) -'a') + 26) % 26) + 'A';
    
    return c;
}