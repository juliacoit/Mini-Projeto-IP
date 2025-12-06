# 🧮 Mini-Projeto — Calculadora em C (com Interface Gráfica)

![Language](https://img.shields.io/badge/Language-C-blue)
![Library](https://img.shields.io/badge/Library-Raylib-red)
![Course](https://img.shields.io/badge/UFG-Introdução%20à%20Programação-green)

## 📘 Descrição

Este repositório contém o **Mini-Projeto** desenvolvido para a disciplina de *Introdução à Programação (IP)* da **Universidade Federal de Goiás (UFG) - 2025/2**.

O objetivo foi desenvolver um programa em C que implementasse **28 operações** matemáticas, lógicas e de manipulação de bits. O grupo utilizou a "livre criatividade" permitida nas instruções para ir além do terminal básico, implementando uma **Interface Gráfica (GUI)** completa utilizando a biblioteca **Raylib**.

### ✨ Diferenciais Implementados
* **Interface Gráfica:** Substitui o loop de console "0 0" por uma aplicação visual interativa.
* **Modularização:** Código organizado em múltiplos arquivos, com a `main` controlando o fluxo e exibição.
* **UX Aprimorada:**
    * **Teclado Binário:** Para as funções 8 a 12 (Bitwise) e 25 a 28 (Booleanas), a interface oferece inputs específicos (0 e 1).
    * **Feedback Visual:** As entradas mudam de nome conforme a operação (ex: "Dividendo/Divisor" ou "Base/Expoente").

---

# 🚀 Como Executar

Conforme as instruções, o código fonte está disponível, mas para facilitar a correção e o uso, disponibilizamos o executável.

### ▶️ Execução Rápida (Windows)
1. **Baixe o Repositório** (Botão `<> Code` -> `Download ZIP`).
2. Extraia a pasta.
3. Execute o arquivo **`Main.exe`**.
   * *Não é necessário instalar bibliotecas externas para apenas rodar o programa.*

### 🛠️ Compilação (Para Desenvolvedores)
Para compilar o código fonte (`.c`), é necessário ter o **GCC** e a biblioteca **Raylib** configurada (MinGW).

**Comando de compilação (Terminal):**
```powershell
gcc *.c -o Main.exe -I C:/raylib/include -L C:/raylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm
```
---

# 🔗 Link do Projeto
Todo o desenvolvimento e versionamento foi realizado na plataforma GitHub, conforme as instruções.

👉 **[Acesse o Projeto Aqui](https://github.com/users/juliacoit/projects/1)**

---
# 🧮 Lista de Operações Implementadas

O programa implementa rigorosamente as 28 funções solicitadas nas instruções, divididas por categorias:

### 1. Aritmética Básica & Avançada
| Nº | Operação | Símbolo | Exemplo |
| :--- | :--- | :---: | :--- |
| 1 | Soma | `+` | `1 + 2 = 3` |
| 2 | Subtração | `-` | `5 - 9 = -4` |
| 3 | Multiplicação | `*` | `9 * 5 = 45` |
| 4 | Divisão | `/` | `9 / 4 = 2.250` |
| 5 | Resto | `%` | `5 % 8 = 5` |
| 6 | Potência | `~` | `9 ~ 2 = 81` |
| 7 | Fatoração | `!` | `6 ! = 720` |
| 13 | Média | `M` | `5 M 9 = 7.000` |

### 2. Bitwise (Manipulação de Bits)
*Entradas tratadas como inteiros, operados bit a bit.*
| Nº | Operação | Símbolo | Descrição |
| :--- | :--- | :---: | :--- |
| 8 | AND bit a bit | `&` | `13 & 7 = 5` |
| 9 | OR bit a bit | `\|` | `13 \| 7 = 15` |
| 10 | XOR bit a bit | `^` | `13 ^ 7 = 10` |
| 11 | Shift à direita | `>>` | `8 >> 2 = 2` |
| 12 | Shift à esquerda | `<<` | `2 << 3 = 16` |

### 3. Intervalos
*O primeiro número é o início e o segundo é o fim do intervalo.*
| Nº | Operação | Símbolo | Descrição |
| :--- | :--- | :---: | :--- |
| 14 | Somatório | `S` | Soma de todos os números no intervalo |
| 15 | Produtório | `P` | Produto de todos os números no intervalo |

### 4. Comparações
*Saída: 1 (SIM) ou 0 (NÃO), exceto min/max/abs.*
| Nº | Operação | Símbolo | Descrição |
| :--- | :--- | :---: | :--- |
| 16 | Mínimo | `min` | Menor valor entre dois números |
| 17 | Máximo | `max` | Maior valor entre dois números |
| 18 | Valor Absoluto | `abs` | Módulo do número (positivo) |
| 19 | Igualdade | `==` | Verifica se A é igual a B |
| 20 | Diferença | `!=` | Verifica se A é diferente de B |
| 21 | Maior que | `>` | Verifica se A > B |
| 22 | Menor que | `<` | Verifica se A < B |
| 23 | Maior ou Igual | `>=` | Verifica se A >= B |
| 24 | Menor ou Igual | `<=` | Verifica se A <= B |

### 5. Operações Booleanas
*Entradas obrigatórias: 0 ou 1. Saída: 1 (SIM) ou 0 (NÃO).*
| Nº | Operação | Símbolo | Exemplo |
| :--- | :--- | :---: | :--- |
| 25 | AND Lógico | `&&` | `1 && 0 = NAO` |
| 26 | NAND Lógico | `!&` | `1 !& 0 = SIM` |
| 27 | OR Lógico | `\|\|` | `1 \|\| 0 = SIM` |
| 28 | NOR Lógico | `!\|` | `1 !\| 0 = NAO` |

---

# 👥 Integrantes do Grupo

| Membro | GitHub | Responsabilidade |
| :--- | :--- | :--- |
| **Aryan Douglas** | [@AryanDouglas01](https://github.com/AryanDouglas01) | Bitwise & Shifts |
| **Clara Bertão** | [@clarabertao](https://github.com/clarabertao) | Funções Avançadas |
| **Eduarda Campos** | [@EduardaCCampos](https://github.com/EduardaCCampos) | Operações Básicas & Interface |
| **Júlia Coité** | [@juliacoit](https://github.com/juliacoit) | Interface Gráfica, Comparadores Lógicos |
| **Paulo Vitor** | [@Paulim16](https://github.com/Paulim16) | Intervalos & Estatística |
| **Pedro Lukas** | [@pedro-lukas-git](https://github.com/pedro-lukas-git) | Booleanas |
| **Sarah Godinho** | [@Sarocaa](https://github.com/Sarocaa) | Comparadores Lógicos |

---

# 🔗 Repositório Oficial
Todo o desenvolvimento e versionamento foi realizado na plataforma GitHub, conforme as instruções.

👉 **[Acesse o Repositório Aqui](https://github.com/juliacoit/Mini-Projeto-IP)**

---

*UFG - Instituto de Informática - 2025/2*
