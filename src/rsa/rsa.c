//
// Created by Jonas on 10.02.2021.
//

#include "rsa.h"
#define FORMAT_STR(string) "%0"string"d"

void rsa_gui(){
    char c;
    printf("RSA Menu\n");
    do {
        printf("-> ");
        c = tolower(readOneChar(stdin));
        switch (c) {
            case 'd':
                rsa_decrypt_gui();
                break;
            case 'e':
                rsa_encrypt_gui();
                break;
            case 'g':
                rsa_keygeneration_gui();
                break;
            case 'q':
                printf("Leaving RSA...\n");
                break;
            case 'h':
                printf("Help:\n");
                printf("\t [d]ecrypt \t- decrypt some data\n");
                printf("\t [e]ncrypt \t- encrypt some data\n");
                printf("\t [g]enerate \t- generate Keypair\n");
                printf("\t [h]elp \t- show this menu\n");
                printf("\t [q]uit \t- leave this application\n");
                break;
            default:
                printf("Enter Valid char (h/H) for Help!\n");
                break;
        }
    }while(c!='q');
}

void rsa_decrypt_gui(){
    //Hello Promt
    printf("RSA decrypt:\n");

    int c;  //Char for Input

    //Read Input for en-/decryption
    char *input_str = NULL;   //String for Data to be encrypted
    do {    //Loop until valid Input
        //Read if Encrypt file
        printf("Read Text from file?(y,N) ");
        c = tolower(readOneChar(stdin));

        if (tolower(c) == 'y') { //Read input string from file
            //Read filename
            printf("Enter filename: ");
            char *filename;
            filename = readString(stdin, -1);

            //read File
            input_str = readFileInString(filename, -1);

            free(filename);
        } else {
            //Input String via commandline
            printf("Enter Text:\n");
            input_str = readString(stdin, -1);
        }
    } while (input_str == NULL);

    //Read Private Key
    printf("Enter Private key:\n");
    char * privateKeyStr;
    privateKeyStr = readString(stdin, -1);
    long int privateKey = strtol(privateKeyStr, NULL, 0); //Transform from String to int

    //Read Base
    printf("Base:\n");
    char * baseStr;
    baseStr = readString(stdin, -1);
    long int base = strtol(baseStr, NULL, 0); //Transform from String to int

    rsa_decrypt(input_str, privateKey, base);

    free(input_str);
}

void rsa_encrypt_gui(){
    //Hello Promt
    printf("RSA encrypt:\n");

    int c;  //Char for Input

    //Read Input for en-/decryption
    char *input_str = NULL;   //String for Data to be encrypted
    do {    //Loop until valid Input
        //Read if Encrypt file
        printf("Read Text from file?(y,N) ");
        c = tolower(readOneChar(stdin));

        if (tolower(c) == 'y') { //Read input string from file
            //Read filename
            printf("Enter filename: ");
            char *filename;
            filename = readString(stdin, -1);

            //read File
            input_str = readFileInString(filename, -1);

            free(filename);
        } else {
            //Input String via commandline
            printf("Enter Text:\n");
            input_str = readString(stdin, -1);
        }
    } while (input_str == NULL);

    //Read Private Key
    printf("Enter Public key:\n");
    char * privateKeyStr;
    privateKeyStr = readString(stdin, -1);
    long int privateKey = strtol(privateKeyStr, NULL, 0); //Transform from String to int

    //Read Base
    printf("Enter Base:\n");
    char * baseStr;
    baseStr = readString(stdin, -1);
    long int base = strtol(baseStr, NULL, 0); //Transform from String to int

    char * output = rsa_encrypt(input_str, privateKey, base);

    printf("%s\n", output);
    free(output);
    free(input_str);
}

char * rsa_decrypt(const char * string, const unsigned long long exponent, const unsigned long long mod){
    return EXIT_FAILURE;
}

void rsa_keygeneration_gui(){

}

char * rsa_encrypt(const char * string, const unsigned long long exponent, const unsigned long long mod){ //manipulates string
    //Get size of on char after encryption
    int charlen = (int) ceil(log10(mod));

    char * str_charlen = malloc((ceil(log10(charlen)) + 5) * sizeof(char));
    sprintf(str_charlen, "%%0%dd ", charlen); //Convert int to Formatstring to allow converion to Int with int leading zeros

    //Main Encrypt loop
    char * output = malloc(((charlen+1) * strlen(string)+1) * sizeof(char)); //Output String
    unsigned long long current; //Current value for encryption
    for (int i = 0; i < strlen(string); ++i) {
        int len = 0;
        unsigned long long c = (unsigned long long) string[i];
        current = pow_mod(c, exponent, mod); //Encryption
        len = sprintf(output+i*(charlen+1), str_charlen, current); //Convvert int to String
        if (len != (charlen+1)){
            printf("Error while encoding '%c' got %d", string[i], current);
            return EXIT_FAILURE;
        }
    }
    output[strlen(output)-1] = '\0';
    free(str_charlen);
    return output;
}

unsigned long long pow_mod(const unsigned long long base, const unsigned long long exponent, const unsigned long long mod){
    if (exponent == 0){
        return 1;
    }
    else if (exponent == 1){
        return (base%mod);
    }
    else if (exponent % 2 == 0){
        int result = pow_mod(base, exponent / 2, mod);
        return ((result*result)%mod);
    }
    else{
        int result = pow_mod(base, (exponent-1) / 2, mod);
        return ((((result*result)%mod)*base)%mod);
    }
}