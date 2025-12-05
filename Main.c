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
// BINARY PAD (APENAS 0 e 1)
// =====================================================================
int DesenharBinPad(float startX, float startY) {
    const char* teclas[3] = { "1", "0", "DEL" };
    
    // Botões maiores para preencher o espaço
    float width = 80;
    float height = 60;
    float gap = 15;

    // Desenha 1 e 0 lado a lado
    for (int i = 0; i < 2; i++) {
        Rectangle r = { startX + i * (width + gap), startY, width, height };
        if (DesenharBotao(r, teclas[i])) {
            if (contaInput < 19) { // Limite do buffer
                inputBuffer[contaInput] = teclas[i][0];
                inputBuffer[contaInput + 1] = '\0';
                contaInput++;
            }
        }
    }

    // Botão DEL embaixo
    Rectangle delBtn = { startX, startY + height + gap, (width * 2) + gap, height };
    if (DesenharBotao(delBtn, "DEL")) {
        if (contaInput > 0) {
            contaInput--;
            inputBuffer[contaInput] = '\0';
        }
    }

    // Botão CONFIRMAR bem embaixo
    Rectangle okBtn = { startX, startY + (height + gap) * 2, (width * 2) + gap, 50 };
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
            DrawText("Ciência da Computação: UFG",       100, 270, 24, Fade(DARKGRAY, alpha));
            DrawText("2025/2",                            100, 310, 24, Fade(DARKGRAY, alpha));
            DrawText("Prof: Gustavo",                     100, 350, 24, Fade(DARKGRAY, alpha));

            
            Rectangle btnStart = { 280, 400, 240, 70 };
            DrawRectangleRounded(btnStart, 0.3f, 10, RED);
            DrawRectangleRoundedLines(btnStart, 0.3f, 10, BLACK);
            
            int w = MeasureText("INICIAR", 32);
            DrawText("INICIAR", btnStart.x + (btnStart.width - w)/2,
                     btnStart.y + 18, 32, WHITE);
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
                if (DesenharBotao((Rectangle){50,100,200,50},"Desloca Bits >"))
                    operacao = 9;
                else if (DesenharBotao((Rectangle){50,160,200,50},"Desloca Bits <"))
                    operacao = 10;
                else if (DesenharBotao((Rectangle){50,220,200,50},"XOR Bitwise"))
                    operacao = 11;
                else if (DesenharBotao((Rectangle){50,280,200,50},"OR Bitwise"))
                    operacao = 12;
                else if (DesenharBotao((Rectangle){50,340,200,50},"AND Bitwise"))
                    operacao = 13;
                 else goto SKIP;
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
            
            char perguntaA[50] = "Digite o valor de A:"; 

            switch(operacao) {
                case 4: case 5: strcpy(perguntaA, "Digite o Dividendo:"); break; // Divisão/Resto
                case 6:         strcpy(perguntaA, "Digite a Base:"); break;      // Potência
                case 14: case 15: strcpy(perguntaA, "Inicio do Intervalo:"); break; // Somatório/Produtório
                
                // Bitwise
                case 9: case 10: case 11: case 12: case 13:
                     strcpy(perguntaA, "Valor em Binario:"); 
                     break;
            }

            DrawText(perguntaA, 400, 50, 20, BLACK);
            
             if (categoria == 3) DrawText("(Use 0 e 1)", 400, 70, 15, DARKGRAY);

            DrawRectangle(400, 90, 200, 50, LIGHTGRAY);
            DrawText(inputBuffer, 410, 100, 40, MAROON);

            int confirmou = 0;
            if (categoria == 3) confirmou = DesenharBinPad(100, 100);
            else confirmou = DesenharNumpad(100, 100);

            if (confirmou) {
                if (categoria == 3) a = (int)strtol(inputBuffer, NULL, 2);
                else a = atoi(inputBuffer);

                memset(inputBuffer, 0, sizeof(inputBuffer));
                contaInput = 0;
                
                if (operacao == 7 || operacao == 18) goto CALCULO; 
                telaAtual = TELA_INPUT_B;
            }
        }

        // ================================================================
        // Entrada de B
        // ================================================================
        else if (telaAtual == TELA_INPUT_B) {
            
            // Mostra o valor de A escolhido anteriormente
            DrawText(TextFormat("A: %d", a), 400, 50, 20, DARKGREEN);
            if (categoria == 3) DrawText(TextFormat("(Hex: %X)", a), 500, 50, 20, GRAY);

            // --- 1. Define o Texto da Pergunta B ---
            char perguntaB[50] = "Digite o valor de B:"; // Padrão

            switch(operacao) {
                case 4:         strcpy(perguntaB, "Digite o Divisor:"); break;    // Divisão
                case 5:         strcpy(perguntaB, "Dividir por:"); break;         // Resto
                case 6:         strcpy(perguntaB, "Digite o Expoente:"); break;   // Potência
                case 8:         strcpy(perguntaB, "Segunda Nota/Valor:"); break;  // Média
                
                // Bitwise - Deslocamento
                case 9:         strcpy(perguntaB, "Deslocar p/ Direita:"); break;
                case 10:        strcpy(perguntaB, "Deslocar p/ Esquerda:"); break;
                
                // Bitwise - Lógica
                case 11: case 12: case 13:
                                strcpy(perguntaB, "Mascara (Binario):"); break;

                // Intervalos
                case 14: case 15: strcpy(perguntaB, "Fim do Intervalo:"); break;
            }
            
            // --- 2. Desenha o Texto ---
            DrawText(perguntaB, 400, 100, 20, BLACK);

            // --- 3. Define lógica de teclado (Binario vs Decimal) ---
            int usarTecladoBinario = 0;
            if (categoria == 3 && (operacao >= 11 && operacao <= 13)) {
                usarTecladoBinario = 1;
            }
            
            // Dica visual extra para deslocamento
            if (operacao == 9 || operacao == 10) {
                 DrawText("(Qtd de casas)", 400, 125, 15, DARKGRAY);
            }

            DrawRectangle(400, 140, 200, 50, LIGHTGRAY);
            DrawText(inputBuffer, 410, 150, 40, MAROON);

            int confirmou = 0;
            if (usarTecladoBinario) confirmou = DesenharBinPad(100, 100);
            else confirmou = DesenharNumpad(100, 100);

            if (confirmou) {
                 if (usarTecladoBinario) b = (int)strtol(inputBuffer, NULL, 2);
                 else b = atoi(inputBuffer);
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

                case 9: resI = Desloca_Bits_Direita (a, b); break;
                case 10: resI = Desloca_Bits_Esquerda (a, b); break;
                case 11: resI = Xor_Bitwise (a, b); break;
                case 12: resI = Or_Bitwise (a, b); break;
                case 13: resI = And_Bitwise (a, b); break;

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
