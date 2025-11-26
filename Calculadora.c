#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void soma (int a, int b);
void subtracao (int a, int b);
void multiplicacao (int a, int b);
void divisao (int a, int b);
void resto (int a, int b);
void potencia (int a, int b);
void fatorial (int a);
void media (int a, int b);
void valor_absoluto(int A);
void diferente(int A, int B);
void igual(int A, int B);
void maior_que(int A, int B);
void menor_que(int A, int B);
void maior_igual(int A, int B);

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
            //soma
                scanf("%d %*c %d", &a,&b);
                soma(a, b);
                break;

            case 2:
            //subtracao
                scanf("%d %*c %d", &a,&b);
                subtracao(a, b);
                break;

            case 3:
            //multiplicacao
                scanf("%d %*c %d", &a,&b);
                multiplicacao(a, b);
                break;

            case 4:
            //divisao
                scanf("%d %*c %d", &a,&b);
                divisao(a, b);
                break;
            
            case 5:
            //resto
                scanf("%d %*c %d", &a,&b);
                resto(a, b);
                break;
            case 6:
            // potencia
                scanf("%d %*c %d", &a,&b);
                potencia(a, b);
                break;
            case 7:
            // fatorial
                scanf("%d %*c", &a);
                fatorial(a);
                break;
            case 8:
            // media
                scanf("%d %*c %d", &a,&b);
                media(a, b);
                break;

            case 18: 
            //valor absoluto
                scanf("%d", &a);
                valor_absoluto(a);
                break;

            case 19:
            //igualdade
                scanf("%d%d", &a, &b);
                igual(a, b);
                break;

            case 20:
            //diferença
                scanf("%d%d", &a, &b);
                diferente(a,b);
                break;

            case 21: 
            //maior que
                scanf("%d%d", &a, &b);
                maior_que(a, b);
                break;

            case 22:
            // menor que
                scanf("%d < %d", &a, &b);
                menor_que(a, b);
                break;

            case 23:
            // maior ou igual
                scanf("%d >= %d", &a, &b);
                maior_igual(a, b);
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
        printf("%d / %d = %.3lf\n", a, b, (double)a / b);
    } else {
        printf("Divisao invalida! Nao e possivel dividir por zero. Tente outra operacao\n");
    }
}
void resto (int a, int b){
    int resto;
    resto = a%b;
    printf("%d %% %d = %d\n", a, b, resto);
}
void potencia (int a, int b){
    int i=1;
    long long int pot;
    pot = a;
    while (i!=b){
        pot *= a;
        i++;
    }
    if(b==0) printf("%d ~ %d = 1\n", a, b);
    else printf("%d ~ %d = %lld\n", a, b, pot);
}
void fatorial (int a){
    int i;
    long long int fat = 1;
    for(i=a; i>1; i--){
        fat *= i;
    }
    printf("%d! = %d\n", a, fat);
}
void media (int a, int b){
    int sum;
    double M;
    sum = a + b;
    M = sum / 2.0;
    printf("%d M %d = %.3lf\n", a, b, M);
}
void valor_absoluto(int A){
    int valor;
    
    valor= sqrt(A*A);
    printf("%d\n", valor);
}
void igual(int A, int B){
    if(A==B) printf("SIM\n");
    else printf("NAO\n");
}
void diferente(int A, int B){
	if(A!=B) printf("SIM\n");
	else printf("NAO\n");
}
void maior_que(int A, int B){
    if(A>B) printf("SIM\n");
    else printf("NAO\n");
}

void menor_que(int A, int B){
    if(A < B) printf("SIM\n");
    else printf("NAO\n");
}

void maior_igual(int A, int B) {
    if(A >= B) printf("SIM\n");
    else printf("NAO\n");
}