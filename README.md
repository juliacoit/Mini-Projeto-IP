# 🧮 Mini-Projeto — Calculadora Científica & Bitwise (C + Raylib)

![Language](https://img.shields.io/badge/Language-C-blue)
![Library](https://img.shields.io/badge/Library-Raylib-red)
![Course](https://img.shields.io/badge/UFG-Introdução%20à%20Programação-green)

## 📘 Descrição

Este repositório contém uma **calculadora modular em C**, integrada a uma **interface gráfica moderna desenvolvida com Raylib**. O projeto foi desenvolvido para a disciplina *Introdução à Programação — UFG (2025/2)*.

O diferencial deste projeto é a **Experiência de Usuário (UX)** adaptativa e a organização modular do código.

### ✨ Destaques da Nova Versão

* 🎨 **Interface Gráfica Completa:** Menu interativo, botões responsivos e design limpo.
* 🧠 **Input Contextual Inteligente:** O programa adapta as perguntas ao usuário.
    * *Ex:* Na Potenciação, pede "Base" e "Expoente".
    * *Ex:* Na Divisão, pede "Dividendo" e "Divisor".
* 💻 **Modo Bitwise Dedicado:**
    * Ao selecionar operações lógicas (AND, OR, XOR), o teclado muda automaticamente para **Binário (0, 1, DEL)**.
    * Conversão automática de binário para decimal e exibição em Hexadecimal.
* 🎧 **Áudio:** Música de fundo integrada (*Escape From the City 8-bit*).

---

# 🚀 Como Executar o Programa

### Pré-requisitos
* Compilador GCC (MinGW no Windows).
* Biblioteca [Raylib](https://github.com/raysan5/raylib/releases) instalada.

## 1️⃣ Configuração (Windows/MinGW)

Certifique-se de que a Raylib está na pasta padrão:
`C:/raylib/`
* `C:/raylib/include/raylib.h`
* `C:/raylib/lib/libraylib.a`

## 2️⃣ Compilando pelo VS Code

Crie o arquivo `.vscode/tasks.json` na raiz do projeto:

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Compilar Calculadora",
            "type": "shell",
            "command": "gcc *.c -o Main.exe -I C:/raylib/include -L C:/raylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm",
            "group": "build",
            "problemMatcher": []
        }
    ]
}

```
**Opção B: Compilar pelo VS Code**
Use o atalho `Ctrl` + `Shift` + `B` (requer configuração do `tasks.json` incluído nas instruções de aula).

---

# 🧮 Operações Implementadas (28 Funções)

O código foi modularizado, onde cada integrante ficou responsável por um conjunto de operações (arquivos `.h`):

### 1. Aritmética Básica & Avançada

| Operação | Símbolo | Descrição |
| :--- | :---: | :--- |
| Soma, Subtração, Multiplicação, Divisão | `+` `-` `*` `/` | Operações fundamentais |
| Resto | `%` | Módulo da divisão |
| Potência | `^` | Base elevada ao expoente |
| Fatorial | `!` | Fatorial de N |
| Média | `M` | Média aritmética |

### 2. Bitwise (Manipulação de Bits)
> *Possui teclado binário exclusivo na interface*

| Operação | Descrição |
| :--- | :--- |
| **AND, OR, XOR** | Lógica bit a bit (com conversão binária automática) |
| **Shift Left (<<)** | Deslocamento de bits para esquerda |
| **Shift Right (>>)** | Deslocamento de bits para direita |

### 3. Estatística & Intervalos
* **Somatório (Σ):** Soma de um intervalo definido.
* **Produtório (Π):** Produto de um intervalo definido.

### 4. Lógica & Comparação
* **Comparadores:** Mínimo, Máximo, Absoluto, Igual, Diferente, Maior, Menor.
* **Booleanas:** `AND`, `NAND`, `OR`, `NOR`.

---

# 👥 Integrantes do Grupo

| Membro | GitHub | Responsabilidade Principal |
| :--- | :--- | :--- |
| **Aryan Douglas** | [@AryanDouglas01](https://github.com/AryanDouglas01) | Bitwise & Lógica de Shift |
| **Clara Bertão** | [@clarabertao](https://github.com/clarabertao) | Funções Avançadas |
| **Eduarda Campos** | [@EduardaCCampos](https://github.com/EduardaCCampos) | Interface & Lógica Booleana |
| **Júlia Coité** | [@juliacoit](https://github.com/juliacoit) | Interface Gráfica, Integração & UX, Comparadores lógicos|
| **Paulo Vitor** | [@Paulim16](https://github.com/Paulim16) | Intervalos & Estatística |
| **Pedro Lukas** | [@pedro-lukas-git](https://github.com/pedro-lukas-git) | Operações Básicas |
| **Sarah Godinho** | [@Sarocaa](https://github.com/Sarocaa) | Comparadores Lógicos |

---

# 🔗 Repositório Oficial
👉 **[Acesse no GitHub](https://github.com/juliacoit/Mini-Projeto-IP)**

---
*UFG - 2025/2*
