# 🧮 Mini-Projeto --- Calculadora em C (com Interface em Raylib)

## 📘 Descrição

Este repositório contém uma **calculadora em C com 28 operações**, agora
integrada a uma **interface gráfica desenvolvida com Raylib** para a
disciplina *Introdução à Programação -- UFG (2025/2)*.

O programa inclui:

-   🎨 **Interface gráfica completa** usando Raylib
-   🖱️ **Botões interativos** para iniciar a calculadora
-   🎧 **Suporte a música e áudio**
-   🧮 Implementação de **todas as 28 operações matemáticas e lógicas**
    exigidas

------------------------------------------------------------------------

# 🔗 Repositório

👉 GitHub: **https://github.com/juliacoit/Mini-Projeto-IP**

------------------------------------------------------------------------

# 🚀 Como Executar o Programa

## 1️⃣ Instalar Raylib

### **Windows (MinGW)**

Baixe a versão pré-compilada da raylib:

https://github.com/raysan5/raylib/releases/latest

Use a pasta:

    raylib-<versão>/raylib/mingw-w64

E coloque em algum local fixo, por exemplo:

    C:/raylib/

Estrutura esperada:

    C:/raylib/include/raylib.h
    C:/raylib/lib/libraylib.a

------------------------------------------------------------------------

## 2️⃣ Configurar o VS Code (opcional)

Crie a pasta:

    .vscode/

E dentro dela coloque:

### `.vscode/tasks.json`

``` json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Compilar",
            "type": "shell",
            "command": "gcc *.c -o Main.exe -I C:/raylib/include -L C:/raylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm",
            "group": "build",
            "problemMatcher": []
        }
    ]
}
```

Aperte **Ctrl + Shift + B** para compilar.

------------------------------------------------------------------------

## 3️⃣ Compilar manualmente

``` sh
gcc *.c -o Main.exe \
    -I C:/raylib/include \
    -L C:/raylib/lib \
    -lraylib -lopengl32 -lgdi32 -lwinmm
```

------------------------------------------------------------------------

## 4️⃣ Executar

``` sh
./Main.exe
```

------------------------------------------------------------------------

# 🧠 Operações Implementadas (28 funções)

### ➕ Operações Aritméticas

Soma (+), Subtração (-), Multiplicação (\*), Divisão (/), Resto (%),
Potência (\~), Fatorial (!), Média (M)

### 🧩 Operações Bit a Bit

AND (&), OR (\|), XOR (\^), Shift Right (\>\>), Shift Left (\<\<)

### 📏 Intervalos

Somatório (S), Produtório (P)

### 🔍 Comparações

min, max, abs, ==, !=, \<, \>, \<=, \>=

### 🔐 Booleanas

&&, !&, \|\|, !\|

------------------------------------------------------------------------

# 👥 Integrantes

-   **Aryan Douglas Rodrigues** --- @AryanDouglas01\
-   **Clara Bertão** --- @clarabertao\
-   **Eduarda Campos** --- @EduardaCCampos\
-   **Júlia Coité** --- @juliacoit\
-   **Paulo Vitor Vieira** --- @Paulim16\
-   **Pedro Lukas Santos** --- @pedro-lukas-git\
-   **Sarah Godinho** --- @Sarocaa

------------------------------------------------------------------------

# 📌 Distribuição de Tarefas

(Conteúdo completo conforme solicitado.)

------------------------------------------------------------------------

# 🏁 Conclusão

Este projeto combina programação em C, raylib, lógica matemática e
interface gráfica, criando um produto completo e interativo.
