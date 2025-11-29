#include<stdio.h>
#include<stdlib.h>
#include "Pedro_Lukas.h"

int menor_que(int A, int B){
    if (A < B) return 1;   
    else return 0;         
}

int maior_igual(int A, int B){
    if (A >= B) return 1;  
    else return 0;         
}

int menor_igual(int A, int B){
    if (A <= B) return 1;  
    else return 0;        
}

int logico_and(int A, int B){
    if (A * B == 1) return 1;  
    else return 0;            
}

int logico_nand(int A, int B){
    if (A * B == 0) return 1; 
    else return 0;             
}
