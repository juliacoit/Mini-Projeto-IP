#include <stdio.h>
#include <math.h>
#include "Clara.h"

int valor_absoluto(int A);
int igual(int A, int B);
int diferente(int A, int B);
int maior_que(int A, int B);

int valor_absoluto(int A) {
    return (int)sqrt(A * A);   
}

int igual(int A, int B) {
    return (A == B);           
}

int diferente(int A, int B) {
    return (A != B);           
}

int maior_que(int A, int B) {
    return (A > B);            
}
