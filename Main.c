#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raylib.h"

// Seus includes originais (mantenha eles na pasta)
#include "Aryan.h"
#include "Clara.h"
#include "Eduarda.h"
#include "Julia.h"
#include "Paulo_Vitor.h"
#include "Pedro_Lukas.h"
#include "Sarah.h"

// cores
#define COR_BOTAO_PADRAO LIGHTGRAY
#define COR_BOTAO_HOVER SKYBLUE
#define COR_BOTAO_CLICK BLUE
#define COR_TEXTO DARKGRAY

// structs
typedef enum {
    TELA_MENU_CATEGORIAS = 0,
    TELA_MENU_OPERACOES,
    TELA_INPUT_A,
    TELA_INPUT_B,
    TELA_RESULTADO
} Tela;

// variaveis
char inputBuffer[20] = { 0 };
int contaInput = 0;

// --- FUNÇÃO AUXILIAR PARA CRIAR BOTÕES ---
// Retorna 1 (true) se o botão for clicado, 0 (false) caso contrário
int DesenharBotao(Rectangle rect, const char* texto) {
    Vector2 mousePoint = GetMousePosition();
    int clicado = 0;
    Color corAtual = COR_BOTAO_PADRAO;

    // Verifica se o mouse está dentro do retângulo
    if (CheckCollisionPointRec(mousePoint, rect)) {
        corAtual = COR_BOTAO_HOVER;
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            corAtual = COR_BOTAO_CLICK;
        }
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            clicado = 1;
        }
    }

    // Desenha o botão
    DrawRectangleRec(rect, corAtual);
    DrawRectangleLinesEx(rect, 2, DARKGRAY); // Borda
    
    // Centraliza o texto
    int textWidth = MeasureText(texto, 20);
    DrawText(texto, rect.x + (rect.width - textWidth) / 2, rect.y + (rect.height - 20) / 2, 20, COR_TEXTO);

    return clicado;
}

// --- FUNÇÃO PARA O TECLADO NUMÉRICO VIRTUAL ---
// Retorna 1 se o usuário apertou "OK" (Enter)
int DesenharNumpad(float startX, float startY) {
    // Layout do Numpad
    const char* teclas[12] = { "7", "8", "9", "4", "5", "6", "1", "2", "3", "-", "0", "DEL" };
    
    int okPressionado = 0;
    float btnSize = 60;
    float gap = 10;

    for (int i = 0; i < 12; i++) {
        float x = startX + (i % 3) * (btnSize + gap);
        float y = startY + (i / 3) * (btnSize + gap);
        Rectangle btnRect = { x, y, btnSize, btnSize };

        if (DesenharBotao(btnRect, teclas[i])) {
            if (strcmp(teclas[i], "DEL") == 0) {
                // Apagar último caractere
                if (contaInput > 0) {
                    contaInput--;
                    inputBuffer[contaInput] = '\0';
                }
            } else {
                // Adicionar número ou sinal
                if (contaInput < 10) {
                    inputBuffer[contaInput] = teclas[i][0];
                    inputBuffer[contaInput+1] = '\0';
                    contaInput++;
                }
            }
        }
    }

    // Botão OK Grande abaixo do numpad
    Rectangle okRect = { startX, startY + 4 * (btnSize + gap), (btnSize * 3) + (gap * 2), 50 };
    if (DesenharBotao(okRect, "CONFIRMAR")) {
        okPressionado = 1;
    }
    
    return okPressionado;
}

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Calculadora Visual Raylib");
    SetTargetFPS(60);

    Tela telaAtual = TELA_MENU_CATEGORIAS;
    int categoria = 0;
    int operacao = 0;
    int a = 0, b = 0;
    
    // Resultados
    int res_int = 0;
    long long res_ll = 0;
    double res_double = 0.0;
    int tipoResultado = 0; 
    char textoFinal[100] = "";

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // ================== TELA 1: CATEGORIAS ==================
        if (telaAtual == TELA_MENU_CATEGORIAS) {
            DrawText("ESCOLHA A CATEGORIA:", 50, 40, 30, DARKBLUE);
            
            const char* categorias[] = {
                "1. Basicas", "2. Avancadas", "3. Bit a Bit", 
                "4. Intervalos", "5. Comp. Simples", "6. Comp. Logicas", "7. Booleanas"
            };

            for(int i = 0; i < 7; i++) {
                Rectangle btn = { 50, 100 + (i * 60), 300, 50 };
                if (DesenharBotao(btn, categorias[i])) {
                    categoria = i + 1;
                    telaAtual = TELA_MENU_OPERACOES;
                }
            }
        }

        // ================== TELA 2: OPERAÇÕES ==================
        else if (telaAtual == TELA_MENU_OPERACOES) {
            DrawText("ESCOLHA A OPERACAO:", 50, 40, 30, DARKBLUE);
            
            // Botão Voltar
            if (DesenharBotao((Rectangle){650, 500, 100, 40}, "Voltar")) {
                telaAtual = TELA_MENU_CATEGORIAS;
                categoria = 0;
            }

            // Define quais botões mostrar baseado na categoria
            // Aqui simplifiquei para mostrar listas dinâmicas
            int inicio = 0, fim = 0;
            char* nomesOps[10]; 
            // Precisaria mapear nomes para IDs reais. Vou usar IDs genéricos para o exemplo funcionar.
            
            // Exemplo simplificado de mapeamento (ajuste conforme seus headers)
            if(categoria == 1) { // Básicas
                if(DesenharBotao((Rectangle){50, 100, 200, 50}, "Soma (+)")) { operacao = 1; goto PROXIMO; }
                if(DesenharBotao((Rectangle){50, 160, 200, 50}, "Subtracao (-)")) { operacao = 2; goto PROXIMO; }
                if(DesenharBotao((Rectangle){50, 220, 200, 50}, "Multiplicacao (*)")) { operacao = 3; goto PROXIMO; }
                if(DesenharBotao((Rectangle){50, 280, 200, 50}, "Divisao (/)")) { operacao = 4; goto PROXIMO; }
            }
            else if (categoria == 2) { // Avançadas
                 if(DesenharBotao((Rectangle){50, 100, 200, 50}, "Resto (%)")) { operacao = 5; goto PROXIMO; }
                 if(DesenharBotao((Rectangle){50, 160, 200, 50}, "Potencia (~)")) { operacao = 6; goto PROXIMO; }
                 if(DesenharBotao((Rectangle){50, 220, 200, 50}, "Fatorial (!)")) { operacao = 7; goto PROXIMO; }
                 if(DesenharBotao((Rectangle){50, 280, 200, 50}, "Media (M)")) { operacao = 8; goto PROXIMO; }
            }
            // ... Adicione os outros else if para categorias 3, 4, 5, 6, 7 aqui ...
            else {
                DrawText("Adicione os botoes das outras", 50, 100, 20, GRAY);
                DrawText("categorias no codigo...", 50, 130, 20, GRAY);
                // Exemplo genérico para não travar
                if(DesenharBotao((Rectangle){50, 200, 200, 50}, "Teste Absoluto")) { operacao = 18; goto PROXIMO; }
            }

            goto RENDER_END; // Pula o bloco PROXIMO se nada foi clicado

            PROXIMO:
                memset(inputBuffer, 0, sizeof(inputBuffer));
                contaInput = 0;
                telaAtual = TELA_INPUT_A;
        }

        // ================== TELA 3: INPUT A ==================
        else if (telaAtual == TELA_INPUT_A) {
            DrawText("DIGITE O VALOR DE A:", 400, 50, 20, BLACK);
            
            // Caixa de texto visual
            DrawRectangle(400, 80, 200, 50, LIGHTGRAY);
            DrawText(inputBuffer, 410, 90, 40, MAROON);

            // Desenha Numpad na esquerda
            if (DesenharNumpad(100, 100)) {
                // Clicou em CONFIRMAR
                if (contaInput > 0 || inputBuffer[0] == '\0') {
                    a = atoi(inputBuffer);
                    memset(inputBuffer, 0, sizeof(inputBuffer));
                    contaInput = 0;
                    
                    if (operacao == 7 || operacao == 18) { // Unários (Fatorial, Abs)
                        goto CALCULAR_AGORA;
                    } else {
                        telaAtual = TELA_INPUT_B;
                    }
                }
            }
        }

        // ================== TELA 4: INPUT B ==================
        else if (telaAtual == TELA_INPUT_B) {
            DrawText(TextFormat("Valor A definido: %d", a), 400, 50, 20, DARKGREEN);
            DrawText("DIGITE O VALOR DE B:", 400, 100, 20, BLACK);
            
            DrawRectangle(400, 130, 200, 50, LIGHTGRAY);
            DrawText(inputBuffer, 410, 140, 40, MAROON);

            if (DesenharNumpad(100, 100)) {
                if (contaInput > 0 || inputBuffer[0] == '\0') {
                    b = atoi(inputBuffer);
                    goto CALCULAR_AGORA;
                }
            }
        }

        // ================== LÓGICA DE CÁLCULO E TELA FINAL ==================
        else if (telaAtual == TELA_RESULTADO) {
            DrawText("RESULTADO:", 50, 50, 40, DARKBLUE);
            DrawText(textoFinal, 50, 120, 40, BLACK);
            
            DrawText(TextFormat("Operacao ID: %d | A: %d | B: %d", operacao, a, b), 50, 200, 20, GRAY);

            if (DesenharBotao((Rectangle){50, 300, 200, 60}, "Novo Calculo")) {
                telaAtual = TELA_MENU_CATEGORIAS;
                categoria = 0;
                operacao = 0;
            }
            if (DesenharBotao((Rectangle){300, 300, 200, 60}, "Sair")) {
                break;
            }
        }

        // Bloco de salto para cálculo (gambiarra organizada para centralizar o switch)
        if (0) {
            CALCULAR_AGORA:
            tipoResultado = 0; 
            switch (operacao) {
                case 1: res_int = soma(a, b); break;
                case 2: res_int = subtracao(a, b); break;
                case 3: res_int = multiplicacao(a, b); break;
                case 4: res_double = divisao(a, b); tipoResultado = 2; break;
                case 5: res_int = resto(a, b); break;
                case 6: res_ll = potencia(a, b); tipoResultado = 1; break;
                case 7: res_ll = fatorial(a); tipoResultado = 1; break;
                case 8: res_double = media(a, b); tipoResultado = 2; break;
                // ... adicione os outros casos aqui ...
                case 18: res_int = valor_absoluto(a); break;
                default: res_int = 0; break;
            }

            if (tipoResultado == 0) sprintf(textoFinal, "%d", res_int);
            else if (tipoResultado == 1) sprintf(textoFinal, "%lld", res_ll);
            else sprintf(textoFinal, "%.2f", res_double);
            
            telaAtual = TELA_RESULTADO;
        }

        RENDER_END:
        EndDrawing();
    }

    CloseWindow();
    return 0;
}