#include "diffiehellman.h"

void diffiehellman_gui(){
    //Public Numbers
    int p;
    int g;

    //Private Keys
    int a;
    int b;

    printf("Diffie-Hellman Key-Exchange.\n");
    printf("Choose public available numbers.\n");
    printf("P (Prime Number):\n");
    scanf("%d", &p);

    printf("G (g < P):\n");
    scanf("%d", &g);

    printf("Each person decides on a private number.\n");
    printf("a (a < P):\n");
    scanf("%d", &a);
    printf("b (b < P):\n");
    scanf("%d", &b);

    //public Keys
    printf("Each person calculates an public key and shares it.\n");
    int aa = pMod(g, a, p);
    int bb = pMod(g, b, p);
    printf("A:%d\tB:%d\n", aa, bb);

    //shared Key
    printf("Shared key gets calculated using each others public key.\n");
    int key_a = pMod(bb, a, p);
    int key_b = pMod(aa, b, p);
    printf("A:%d\tB:%d\n", key_a, key_b);


}



int pMod(int a, int b, int n){
    long long x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
        }
        y = (y*y) % n; // squaring the base
        b = b / 2;
    }
    return x % n;
}