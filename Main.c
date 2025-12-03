#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raylib.h"

// includes originais
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

// telas
typedef enum {
    TELA_INTRO = -1,
    TELA_MENU_CATEGORIAS = 0,
    TELA_MENU_OPERACOES,
    TELA_INPUT_A,
    TELA_INPUT_B,
    TELA_RESULTADO
} Tela;


// variáveis globais de input
char inputBuffer[20] = {0};
int contaInput = 0;

// =====================================================================
// FUNÇÃO GENÉRICA DE BOTÃO
// =====================================================================
int DesenharBotao(Rectangle rect, const char* texto) {
    Vector2 mousePoint = GetMousePosition();
    int clicado = 0;
    Color corAtual = COR_BOTAO_PADRAO;

    if (CheckCollisionPointRec(mousePoint, rect)) {
        corAtual = COR_BOTAO_HOVER;
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) corAtual = COR_BOTAO_CLICK;
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) clicado = 1;
    }

    DrawRectangleRec(rect, corAtual);
    DrawRectangleLinesEx(rect, 2, DARKGRAY);

    int textWidth = MeasureText(texto, 20);
    DrawText(texto, rect.x + (rect.width - textWidth) / 2,
             rect.y + (rect.height - 20) / 2, 20, COR_TEXTO);

    return clicado;
}

// =====================================================================
// NUMPAD
// =====================================================================
int DesenharNumpad(float startX, float startY) {
    const char* teclas[12] = {
        "7","8","9",
        "4","5","6",
        "1","2","3",
        "-","0","DEL"
    };

    float size = 60, gap = 10;

    for (int i = 0; i < 12; i++) {
        float x = startX + (i % 3) * (size + gap);
        float y = startY + (i / 3) * (size + gap);
        Rectangle r = {x, y, size, size};

        if (DesenharBotao(r, teclas[i])) {
            if (strcmp(teclas[i], "DEL") == 0) {
                if (contaInput > 0) {
                    contaInput--;
                    inputBuffer[contaInput] = '\0';
                }
            } else {
                if (contaInput < 10) {
                    inputBuffer[contaInput] = teclas[i][0];
                    inputBuffer[contaInput + 1] = '\0';
                    contaInput++;
                }
            }
        }
    }

    Rectangle okBtn = { startX, startY + 4*(size+gap),
                        size*3 + gap*2, 50 };

    return DesenharBotao(okBtn, "CONFIRMAR");
}

// =====================================================================
// MAIN
// =====================================================================
int main(void) {
    const int W = 800, H = 800;
    InitWindow(W, H, "Mini-Projeto-Calculadora");
    InitAudioDevice();
    Music music = LoadMusicStream("Escape From the City 8 Bit Remix - Sonic Adventure 2.mp3");
    PlayMusicStream(music);
    SetTargetFPS(60);

    Tela telaAtual = TELA_INTRO;
    int categoria = 0, operacao = 0;
    int a = 0, b = 0;

    char textoFinal[100] = "";
    int tipoResultado = 0;
    long long resLL = 0;
    double resD = 0.0;
    int resI = 0;

    while (!WindowShouldClose()) {
        UpdateMusicStream(music);
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // ================================================================
        // TELA INTRO – TELA DE BOAS-VINDAS
        // ================================================================
        if (telaAtual == TELA_INTRO) {
        
            static float alpha = 0.0f;
            if (alpha < 1.0f) alpha += 0.01f;   // animação
        
            DrawRectangle(0, 0, W, H, Fade(DARKBLUE, 0.3f));
        
            DrawText("Bem-vindo ao Mini-Projeto de IP!", 60, 140, 28, Fade(BLACK, alpha));
            DrawText("Calculadora em C",                   100, 230, 24, Fade(DARKGRAY, alpha));
            DrawText("Ciência da Computação – UFG",       100, 270, 24, Fade(DARKGRAY, alpha));
            DrawText("2025/2",                            100, 310, 24, Fade(DARKGRAY, alpha));
            DrawText("Prof: Gustavo",                     100, 350, 24, Fade(DARKGRAY, alpha));

            
            Rectangle btnStart = { 280, 400, 240, 70 };
            DrawRectangleRounded(btnStart, 0.3f, 10, RED);
            DrawRectangleRoundedLines(btnStart, 0.3f, 10, BLACK);
            
            int w = MeasureText("INICIAR", 32);
            DrawText("INICIAR", btnStart.x + (btnStart.width - w)/2,
                     btnStart.y + 18, 32, DARKBLUE);
            
            Vector2 mouse = GetMousePosition();
            if (CheckCollisionPointRec(mouse, btnStart)) {
                DrawRectangleRounded(btnStart, 0.3f, 10, Fade(BLUE, 0.4f));
                if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                    telaAtual = TELA_MENU_CATEGORIAS;
                }
            }
        
            EndDrawing();
            continue;
        }


        // ========================= MENU 1 =========================
        if (telaAtual == TELA_MENU_CATEGORIAS) {
            DrawText("ESCOLHA A CATEGORIA:", 50, 40, 30, DARKBLUE);

            const char* nomes[] = {
                "1. Basicas",
                "2. Avancadas",
                "3. Bitwise",
                "4. Intervalos",
                "5. Comparacoes Simples",
                "6. Comparacoes Logicas",
                "7. Booleanas"
            };

            for (int i = 0; i < 7; i++) {
                Rectangle r = {50, 100 + i*60, 300, 50};
                if (DesenharBotao(r, nomes[i])) {
                    categoria = i+1;
                    telaAtual = TELA_MENU_OPERACOES;
                }
            }
        }

        // ========================= MENU 2 =========================
        else if (telaAtual == TELA_MENU_OPERACOES) {
            DrawText("ESCOLHA A OPERACAO:", 50, 40, 30, DARKBLUE);

            if (DesenharBotao((Rectangle){650, 500, 100, 40}, "Voltar")) {
                telaAtual = TELA_MENU_CATEGORIAS;
            }

            // ------------------------- CATEGORIA 1 -------------------------
            if (categoria == 1) {
                if (DesenharBotao((Rectangle){50, 100, 200, 50}, "Soma"))
                    operacao = 1;
                else if (DesenharBotao((Rectangle){50, 160, 200, 50}, "Subtracao"))
                    operacao = 2;
                else if (DesenharBotao((Rectangle){50, 220, 200, 50}, "Multiplicacao"))
                    operacao = 3;
                else if (DesenharBotao((Rectangle){50, 280, 200, 50}, "Divisao"))
                    operacao = 4;
                else goto SKIP;
            }

            // ------------------------- CATEGORIA 2 -------------------------
            else if (categoria == 2) {
                if (DesenharBotao((Rectangle){50,100,200,50},"Resto"))
                    operacao = 5;
                else if (DesenharBotao((Rectangle){50,160,200,50},"Potencia"))
                    operacao = 6;
                else if (DesenharBotao((Rectangle){50,220,200,50},"Fatorial"))
                    operacao = 7;
                else if (DesenharBotao((Rectangle){50,280,200,50},"Media"))
                    operacao = 8;
                else goto SKIP;
            }

            // ------------------------- CATEGORIA 3 -------------------------
            else if (categoria == 3) {
                // parte do aryan
                DrawText("Em desenvolvimento...", 50, 120, 20, DARKGRAY);
                goto SKIP;
            }

            // ------------------------- CATEGORIA 4 -------------------------
            else if (categoria == 4) {
                if (DesenharBotao((Rectangle){50,100,200,50},"Somatorio"))
                    operacao = 14;
                else if (DesenharBotao((Rectangle){50,160,200,50},"Produtorio"))
                    operacao = 15;
                else goto SKIP;
            }

            // ------------------------- CATEGORIA 5 -------------------------
            else if (categoria == 5) {
                if (DesenharBotao((Rectangle){50,100,200,50},"Minimo"))
                    operacao = 16;
                else if (DesenharBotao((Rectangle){50,160,200,50},"Maximo"))
                    operacao = 17;
                else if (DesenharBotao((Rectangle){50,220,200,50},"Abs"))
                    operacao = 18;
                else goto SKIP;
            }

            // ------------------------- CATEGORIA 6 -------------------------
            else if (categoria == 6) {
                if (DesenharBotao((Rectangle){50,100,200,50},"Igual"))
                    operacao = 30;
                else if (DesenharBotao((Rectangle){50,160,200,50},"Diferente"))
                    operacao = 31;
                else if (DesenharBotao((Rectangle){50,220,200,50},"Maior"))
                    operacao = 32;
                else if (DesenharBotao((Rectangle){50,280,200,50},"Menor"))
                    operacao = 33;
                else goto SKIP;
            }

            // ------------------------- CATEGORIA 7 -------------------------
            else if (categoria == 7) {
                if (DesenharBotao((Rectangle){50,100,200,50},"AND"))
                    operacao = 40;
                else if (DesenharBotao((Rectangle){50,160,200,50},"OR"))
                    operacao = 41;
                else if (DesenharBotao((Rectangle){50,220,200,50},"NAND"))
                    operacao = 42;
                else if (DesenharBotao((Rectangle){50,280,200,50},"NOR"))
                    operacao = 43;
                else goto SKIP;
            }

            memset(inputBuffer,0,sizeof(inputBuffer));
            contaInput = 0;
            telaAtual = TELA_INPUT_A;

            SKIP: ;
        }

        // ================================================================
        // Entrada de A
        // ================================================================
        else if (telaAtual == TELA_INPUT_A) {
            DrawText("Digite o valor de A:", 400, 50, 20, BLACK);

            DrawRectangle(400, 80, 200, 50, LIGHTGRAY);
            DrawText(inputBuffer, 410, 90, 40, MAROON);

            if (DesenharNumpad(100, 100)) {
                a = atoi(inputBuffer);
                memset(inputBuffer,0,sizeof(inputBuffer));
                contaInput = 0;

                // Operações unárias
                if (operacao == 7 || operacao == 18) goto CALCULO;

                telaAtual = TELA_INPUT_B;
            }
        }

        // ================================================================
        // Entrada de B
        // ================================================================
        else if (telaAtual == TELA_INPUT_B) {
            DrawText(TextFormat("Valor A: %d", a), 400, 50, 20, DARKGREEN);
            DrawText("Digite o valor de B:", 400, 100, 20, BLACK);

            DrawRectangle(400, 130, 200, 50, LIGHTGRAY);
            DrawText(inputBuffer, 410, 140, 40, MAROON);

            if (DesenharNumpad(100, 100)) {
                b = atoi(inputBuffer);
                goto CALCULO;
            }
        }

        // ================================================================
        // TELA RESULTADO
        // ================================================================
        else if (telaAtual == TELA_RESULTADO) {
            DrawText("RESULTADO:", 50, 50, 40, DARKBLUE);
            DrawText(textoFinal, 50, 120, 40, BLACK);

            if (DesenharBotao((Rectangle){50,300,200,60}, "Novo Calculo"))
                telaAtual = TELA_MENU_CATEGORIAS;

            if (DesenharBotao((Rectangle){300,300,200,60}, "Sair"))
                break;
        }

        // ================================================================
        // BLOCO DE CÁLCULO
        // ================================================================
        if (0) {
            CALCULO:

            tipoResultado = 0;

            switch (operacao) {
                case 1: resI = soma(a,b); break;
                case 2: resI = subtracao(a,b); break;
                case 3: resI = multiplicacao(a,b); break;
                case 4: resD = divisao(a,b); tipoResultado = 2; break;
                case 5: resI = resto(a,b); break;
                case 6: resLL = potencia(a,b); tipoResultado = 1; break;
                case 7: resLL = fatorial(a); tipoResultado = 1; break;
                case 8: resD = media(a,b); tipoResultado = 2; break;

                case 14: resLL = somatorio(a,b); tipoResultado = 1; break;
                case 15: resLL = produtorio(a,b); tipoResultado = 1; break;
                case 16: resI = minimo(a,b); break;
                case 17: resI = maximo(a,b); break;
                case 18: resI = valor_absoluto(a); break;

                case 30: resI = igual(a,b); break;
                case 31: resI = diferente(a,b); break;
                case 32: resI = maior_que(a,b); break;
                case 33: resI = menor_que(a,b); break;

                case 40: resI = logico_and(a,b); break;
                case 41: resI = logico_or(a,b); break;
                case 42: resI = logico_nand(a,b); break;
                case 43: resI = logico_nor(a,b); break;

                default: resI = 0; break;
            }

            if (tipoResultado == 0) sprintf(textoFinal, "%d", resI);
            else if (tipoResultado == 1) sprintf(textoFinal, "%lld", resLL);
            else sprintf(textoFinal, "%.2f", resD);

            telaAtual = TELA_RESULTADO;
        }

        EndDrawing();
    }
    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
