#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "Aryan.h"
#include "Clara.h"
#include "Eduarda.h"
#include "Julia.h"
#include "Paulo_Vitor.h"
#include "Pedro_Lukas.h"
#include "Sarah.h"



int main(){
    int operacao, saida;
    int a, b;
    int resultado_int, resultado_ll,resultado_double;

    while(1){

        printf("=================================================================================\n");
        printf("                                 SUPER CALCULADORA\n");
        printf("=================================================================================\n");


        printf("                                Escolha a categoria:\n");

        printf("1) Funcoes Matematicas Basicas\n");
        printf("2) Funcoes Matematicas Avancadas\n");
        printf("3) Operacoes Bit a Bit\n");
        printf("4) Intervalos e Comparacoes\n");
        printf("5) Comparacoes Simples\n");
        printf("6) Comparacoes Logicas\n");
        printf("7) Booleanas\n");
        printf("Digite 0 para sair.\n");
   
        printf(">> ");
        scanf("%d", &operacao);

        if (operacao == 0) {
            printf("Tem certeza que deseja sair? Confirme digitando 0 novamente:\n>> ");
            scanf("%d", &saida);

            if (saida == 0) {
                printf("Encerrando...\n");
                break;
            } else {
                printf("Saida cancelada! Voltando ao menu...\n\n");
                continue;
            }
        }
        if (operacao < 1 || operacao > 7) {
            printf("Desculpe, opaoo invalida. Tente novamente!\n\n");
            continue;
        }


        printf("\n=============================== ESCOLHA A OPERACAO ===============================\n");

        switch (operacao) {

            case 1:
                printf("1) Soma (+)\n");
                printf("2) Subtracao (-)\n");
                printf("3) Multiplicacao (*)\n");
                printf("4) Divisao (/)\n");
                break;

            case 2:
                printf("5) Resto (%%)\n");
                printf("6) Potencia (~)\n");
                printf("7) Fatorial (!)\n");
                printf("8) Media (M)\n");
                break;

            case 3:
                printf("9) AND (&)\n");
                printf("10) OR (|)\n");
                printf("11) XOR (^)\n");
                printf("12) Shift >>\n");
                printf("13) Shift <<\n");
                break;

            case 4:
                printf("14) Somatorio\n");
                printf("15) Produtorio\n");
                printf("16) Minimo\n");
                printf("17) Maximo\n");
                break;

            case 5:
                printf("18) Absoluto\n");
                printf("19) Igualdade (==)\n");
                printf("20) Diferenca (!=)\n");
                printf("21) Maior que (>))\n");
                break;

            case 6:
                printf("22) Menor que (<)\n");
                printf("23) Maior ou igual (>=)\n");
                printf("24) Menor ou igual (<=)\n");
                printf("25) AND logico (&&)\n");
                printf("26) NAND (!&)\n");
                break;

            case 7:
                printf("27) OR logico (||)\n");
                printf("28) NOR (!|)\n");
                break;
        }


        printf("Digite a operacao desejada:\n>> ");
        scanf("%d", &saida);

        
        switch (saida) {

            case 1: // soma
                scanf("%d + %d", &a, &b);
                resultado_int = soma(a, b);
                break;

            case 2: // subtracao
                scanf("%d - %d", &a, &b);
                resultado_int = subtracao(a, b);
                break;

            case 3: // multiplicacao
                scanf("%d * %d", &a, &b);
                resultado_int = multiplicacao(a, b);
                break;

            case 4: // divisao
                scanf("%d / %d", &a, &b);
                resultado_double = divisao(a, b);
                break;

            case 5: // resto
                scanf("%d %% %d", &a, &b);
                resultado_int = resto(a, b);
                break;

            case 6: // potencia
                scanf("%d ~ %d", &a, &b);
                resultado_ll = potencia(a, b);
                break;

            case 7: // fatorial
                scanf("%d !", &a);
                resultado_ll = fatorial(a);
                break;

            case 8: // media
                scanf("%d M %d", &a, &b);
                resultado_double = media(a, b);
                break;

            case 18: // valor absoluto
                scanf("%d abs", &a);
                resultado_int = valor_absoluto(a);
                break;

            case 19: // igualdade
                scanf("%d == %d", &a, &b);
                resultado_int = igual(a, b);
                break;

            case 20: // diferença
                scanf("%d != %d", &a, &b);
                resultado_int = diferente(a, b);
                break;

            case 21: // maior que
                scanf("%d > %d", &a, &b);
                resultado_int = maior_que(a, b);
                break;

            case 22: // menor que
                scanf("%d < %d", &a, &b);
                resultado_int = menor_que(a, b);
                break;

            case 23: // maior ou igual
                scanf("%d >= %d", &a, &b);
                resultado_int = maior_igual(a, b);
                break;

            case 24: // menor ou igual
                scanf("%d <= %d", &a, &b);
                resultado_int = menor_igual(a, b);
                break;

            case 25: // AND lógico
                scanf("%d && %d", &a, &b);
                resultado_int = logico_and(a, b);
                break;

            case 26: // NAND lógico
                scanf("%d !& %d", &a, &b);
                resultado_int = logico_nand(a, b);
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }


    }
    return 0;
}





