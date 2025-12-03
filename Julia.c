#include<stdio.h>
#include<stdlib.h>
#include "Julia.h"

int logico_or (int a, int b){
    if (a + b >= 1) return 1;
    else return 0;
}
int logico_nor (int a, int b){
    if (a + b == 0) return 1;
    else return 0;
}

