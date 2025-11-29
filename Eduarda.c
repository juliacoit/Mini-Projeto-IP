#include "Eduarda.h"

int soma(int a, int b){
    return a + b;
}

int subtracao(int a, int b){
    return a - b;
}

int multiplicacao(int a, int b){
    return a * b;
}

double divisao(int a, int b){
    if (b != 0){
        return (double)a / b;
    } else {
        return 0.0;
    }
}