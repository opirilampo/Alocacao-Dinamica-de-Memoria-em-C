# Gestão Dinâmica de Matrizes em C

Este projeto de portfólio apresenta um programa em C que possui foco em Alocação dinâmica de memória e permite ao usuário alocar, realocar e liberar memória dinamicamente para matrizes, além de preencher e exibir seus valores.

## Funcionalidades

- **Alocar Matriz:** Função que aloca memória para uma matriz bidimensional.
- **Realocar Matriz:** Função que realoca a memória da matriz para um novo tamanho, preservando os dados existentes.
- **Liberar Matriz:** Função que libera a memória alocada para a matriz.
- **Preencher Matriz:** Função que permite ao usuário preencher a matriz com valores inteiros.
- **Exibir Matriz:** Função que exibe os valores da matriz.
- **Verificar Realocação Negativa:** Função que verifica se a realocação negativa de linhas ou colunas irá resultar na exclusão da matriz.
- **Validar Entrada:** Função que valida a entrada do usuário para garantir que seja um número inteiro.

## Estrutura do Código

O código está organizado em várias funções para modularidade e clareza:

1. **alocarMatriz:** Aloca memória para a matriz de acordo com as linhas e colunas especificadas.
2. **realocarMatriz:** Realoca a memória da matriz para um novo tamanho, preservando os dados existentes e alocando novas linhas e colunas, se necessário.
3. **mecnProsseguir:** Valida a resposta do usuário para continuar ou não (s/n).
4. **liberarMatriz:** Libera a memória alocada para a matriz, evitando vazamentos de memória.
5. **preencherMatriz:** Permite ao usuário preencher a matriz com valores inteiros.
6. **mecnConfInt:** Valida a entrada do usuário, garantindo que seja um número inteiro.
7. **repreencherMatriz:** Preenche a matriz realocada com novos valores, caso a matriz tenha sido expandida.
8. **exibirMatriz:** Exibe os valores da matriz na tela.
9. **mecnRealocarNegativo:** Verifica se a realocação negativa de linhas ou colunas resultará na exclusão da matriz.

## Como Usar

1. **Clone o Repositório**: Clone este repositório para sua máquina local.
    ```bash
    git clone https://github.com/opirilampo/Alocacao-Dinamica-de-Memoria-em-C.git
    ```

2. **Navegue para o Diretório**: Entre no diretório do projeto.
    ```bash
    cd Alocacao-Dinamica-de-Memoria-em-C
    ```

3. **Compile o Código**: Utilize um compilador de C para compilar o código. Certifique-se de ter um compilador de C instalado, como o GCC.
    ```bash
    gcc -o matriz run.c
    ```

4. **Execute o Programa**: Execute o executável gerado.
    ```bash
    ./matriz
    ```

5. **Interaja com o Programa**:
    - **Passo 1**: O programa solicitará o número de linhas da matriz. Digite um número inteiro maior ou igual a 1 e pressione Enter.
    - **Passo 2**: O programa solicitará o número de colunas da matriz. Digite um número inteiro maior ou igual a 1 e pressione Enter.
    - **Passo 3**: Preencha os valores da matriz conforme solicitado pelo programa.
    - **Passo 4**: O programa exibirá a matriz preenchida.
    - **Passo 5**: Você será perguntado se deseja realocar a matriz. Digite 's' para sim ou 'n' para não.
        - Se sim, o programa solicitará o número de linhas e colunas a serem realocadas. Insira os valores conforme instruído.
        - O programa verificará se a realocação resultará na exclusão da matriz. Se sim, você será perguntado se deseja continuar.
        - Se a matriz for realocada, você poderá preencher os novos elementos da matriz e visualizar a matriz atualizada.

6. **Finalizar**: O programa liberará a memória alocada e será encerrado.

## Exemplo de Uso

O programa solicitará que o usuário informe o número de linhas e colunas, preencha os valores da matriz, e escolha se deseja realocar a matriz. Caso a matriz seja realocada, o usuário poderá preencher os novos elementos e visualizar a matriz atualizada.

