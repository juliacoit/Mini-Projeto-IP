#include "Paulo_Vitor.h"

long long int somatorio(int a, int b){
    int i;
    long long int soma = 0;
    for(i = a;i <= b;i++) soma += i;
    return soma;
}

long long int produtorio(int a, int b){
    int i;
    long long int produto = 1;
    for(i = a;i <= b;i++) produto *= i;
    return produto;
}

int minimo(int a, int b){
    if(a <= b) return a;
    else if(b <= a) return b;   
}

int maximo(int a, int b){
    int max;
    if(a >= b) max=a;
    else if(b >= a) max=b;
    return max;
}
