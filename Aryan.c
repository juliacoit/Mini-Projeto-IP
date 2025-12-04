#include<stdio.h>
#include<stdlib.h>
#include "Aryan.h"

int Desloca_Bits_Direita(int valor, int bits) {
if (bits < 0) return valor;
if (bits >= sizeof(int) * 8) return 0;
return valor >> bits;
}


int Desloca_Bits_Esquerda(int valor, int bits) {
if (bits < 0) return valor;
if (bits >= sizeof(int) * 8) return 0;
return valor << bits;
}


int Xor_Bitwise(int valor, int bits) {
if (bits < 0) return valor;
return valor ^ bits;
}


int Or_Bitwise(int valor, int bits) {
if (bits < 0) return valor;
return valor | bits;
}


int And_Bitwise(int valor, int bits) {
if (bits < 0) return valor;
return valor & bits;
}
