//
// Created by Jonas on 10.02.2021.
//

#include "rsa.h"
#define FORMAT_STR(string) "%0"string"d"

void rsa_gui(){
    char c;
    printf("RSA Menu\n");
    printf("\nThis RSA only works on each Char to simplify Key generation!\n");
    printf("Otherwise the entered primes musst be huge\n");
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

    char * output = rsa_decrypt(input_str, privateKey, base);
    printf("Write Output in File?(Y/n) ");
    c = tolower(readOneChar(stdin));
    if (c == 'n'){
        printf("%s\n", output);
    }
    else{
        printf("Enter Filename: ");
        char * filename = readString(stdin, -1);
        int result = writeStringInFile(output, filename, "w");
        if (result == 0){
            printf("Succesfully written file '%s'", filename);
        }
        free(filename);
    }
    free(output);
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

    printf("Write Output in File?(Y/n) ");
    c = tolower(readOneChar(stdin));
    if (c == 'n'){
        printf("%s\n", output);
    }
    else{
        printf("Enter Filename: ");
        char * filename = readString(stdin, -1);
        int result = writeStringInFile(output, filename, "w");
        if (result == 0){
            printf("Succesfully written file '%s'", filename);
        }
        free(filename);
    }
    free(output);
    free(input_str);
}

char * rsa_decrypt(const char * string, const unsigned long long exponent, const unsigned long long mod){
    int charlen = (int) ceil(log10(mod));
    char * current = malloc((charlen+1)* sizeof(char));

    int chars_per_encryption = (((int) ceil(log10(mod)))/ 3);

    char * output = malloc(((strlen(string)+1)/charlen)*chars_per_encryption * sizeof(char));

    current[charlen + 1] = '\0';
    unsigned long long currentInt = 0;
    int outIndex = 0;
    for (int i = 0; i < strlen(string); i = i+charlen+1) {
        memcpy(current, string+i, charlen);
        currentInt = strtoull(current, NULL, 10);
        currentInt = pow_mod(currentInt, exponent, mod);
        for (int j = 0; j < chars_per_encryption; ++j) {
            output[outIndex] = currentInt / pow(1000, chars_per_encryption-j-1);
            outIndex++;
        }
    }
    output[outIndex] = '\0';
    return output;
}

void rsa_keygeneration_gui(){

}

char * rsa_encrypt(const char * string, const unsigned long long exponent, const unsigned long long mod){ //manipulates string
    //Get size of on char after encryption
    int charlen = (int) ceil(log10(mod));

    char * str_charlen = malloc((ceil(log10(charlen)) + 5) * sizeof(char));
    sprintf(str_charlen, "%%0%dd ", charlen); //Convert int to Formatstring to allow converion to Int with int leading zeros

    int chars_per_encryption = (((int) ceil(log10(mod)))/ 3);
    //Calculate amount of Space needed
    int space;
    space = ceil(((float)strlen(string)) / chars_per_encryption);
    space = (charlen+1) * space +1;

    //Main Encrypt loop
    char * output = malloc(space* sizeof(char)); //Output String
    output[space-1] = '\0';
    unsigned long long current; //Current value for encryption
    for (int i = 0; i < strlen(string); i += chars_per_encryption) {
        unsigned long long c = 0;
        for (int j = 0; j < chars_per_encryption; ++j) {
            c += ((unsigned long long) string[i+j]) * pow(1000, chars_per_encryption-j-1); //Message to be encrypted
        }
        current = pow_mod(c, exponent, mod); //Encryption

        int len = 0;
        len = sprintf(output+i*(charlen+1), str_charlen, current); //Convvert int to String
        if (len != (charlen+1)){
            printf("Error while encoding '%c' got %d", string[i], current);
            return EXIT_FAILURE;
        }
    }
    output[strlen(output)-1] = '\0'; //Remove ' ' at the end
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