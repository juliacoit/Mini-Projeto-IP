#include<stdio.h>
#include<stdlib.h>
#include "Sarah.h"

int resto(int a, int b) {
    return a % b;
}

long long int potencia(int a, int b) {
    long long int pot = 1;
    int i;

    if (b == 0) return 1;

    for (i = 0; i < b; i++) {
        pot *= a;
    }
    return pot;
}

long long int fatorial(int a) {
    long long int fat = 1;
    int i;

    if (a < 0) return 0; 

    for (i = a; i > 1; i--) {
        fat *= i;
    }
    return fat;
}

double media(int a, int b) {
    return (a + b) / 2.0;
}