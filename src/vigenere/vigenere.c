#include "vigenere.h"

int main(){
    vigenere_gui();

    return 0;
}

void vigenere_gui(){
    char c;
    printf("Vigenere Menu\n");
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

void vigenere_encrypt_gui(){
    char* plaintext;
    char* keyphrase;
    printf("Vigenere Encrypt\n");
    //Todo Read From File

    printf("Enter Text:\n");
    plaintext = readString(stdin, -1);
    printf("Enter Key:\n");
    keyphrase = readString(stdin, -1);

    //Encrypt
    for (int i = 0, j = 0; (unsigned)i < strlen(plaintext); i++, j++)
    {
        if((unsigned)j > strlen(keyphrase)-1)
            j = 0;

        plaintext[i] = encrypt_char(plaintext[i],keyphrase[j]);
    }
    
    printf("%s\n", plaintext);
}

void vigenere_decrypt_gui(){
    char* message;
    char* keyphrase;
    printf("Vigenere Decrypt\n");
    //Todo Read From File

    printf("Enter Text:\n");
    message = readString(stdin, -1);
    printf("Enter Key:\n");
    keyphrase = readString(stdin, -1);

    //Decrypt
    for (int i = 0, j = 0; (unsigned)i < strlen(message); i++, j++)
    {
        if((unsigned)j > strlen(keyphrase)-1)
            j = 0;

        message[i] = decrypt_char(message[i],keyphrase[j]);
    }
    
    printf("%s\n", message);
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