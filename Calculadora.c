#include<stdio.h>
#include<stdlib.h>

void soma (int a, int b);
void subtracao (int a, int b);
void multiplicacao (int a, int b);
void divisao (int a, int b);

int main(){
    int operacao, saida;
    int a, b;

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
            case 1:
                scanf("%d %*c %d", &a,&b);
                soma(a, b);
                break;

            case 2:
                scanf("%d %*c %d", &a,&b);
                subtracao(a, b);
                break;

            case 3:
                scanf("%d %*c %d", &a,&b);
                multiplicacao(a, b);
                break;

            case 4:
                scanf("%d %*c %d", &a,&b);
                divisao(a, b);
                break;

            default:
                printf("Opção invalida! Tente novamente.\n");
        }


    }
    return 0;
}

void soma (int a, int b){
    printf("%d + %d = %d\n", a, b, a + b);
    
}

void subtracao (int a, int b){
    printf("%d - %d = %d\n", a, b, a - b);

}

void multiplicacao (int a, int b){
    printf("%d * %d = %d\n", a, b, a * b);

}

void divisao (int a, int b){
    if(b != 0){
        printf("%d / %d = %.2lf\n", a, b, (double)a / b);
    } else {
        printf("Divisao invalida! Nao e possivel dividir por zero. Tente outra operacao\n");
    }


}
