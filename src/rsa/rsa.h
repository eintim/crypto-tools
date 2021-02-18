//
// Created by Jonas on 10.02.2021.
//

#ifndef TEST_RSA_H
#define TEST_RSA_H
#include "../lib/clearInputBuffer.h"
#include "../lib/readString.h"
#include "../lib/readOneChar.h"
#include "../lib/readFileInString.h"
#include "../lib/writeStringInFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
void rsa_gui();
void rsa_decrypt_gui();
void rsa_encrypt_gui();
void rsa_keygeneration_gui();
void rsa_calculate_keypair(unsigned long long int p, unsigned long long int q);
void rsa_get_factors(unsigned long long int number, unsigned long long int * f1, unsigned long long int * f2);
char * rsa_encrypt(const char * string, const unsigned long long exponent, const unsigned long long mod);
char * rsa_decrypt(const char * string, const unsigned long long exponent, const unsigned long long mod);
unsigned long long pow_mod(const unsigned long long base, const unsigned long long exponent, const unsigned long long mod);
#endif //TEST_RSA_H
