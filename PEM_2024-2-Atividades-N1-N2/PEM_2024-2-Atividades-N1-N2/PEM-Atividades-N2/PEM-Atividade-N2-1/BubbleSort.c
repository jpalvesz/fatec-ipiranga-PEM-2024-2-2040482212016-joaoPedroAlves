/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: *************
* Data - 04/10/2024                                             * 
* Autor: João Pedro Lima Alves*
*--------------------------------------------------------*/

#include <stdio.h>

#define MAX 100 // Definindo um tamanho máximo para o array

// Função para solicitar a entrada de números
void lerNumeros(int array[], int n) {
    printf("Digite %d números:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}

// Função para exibir o array
void exibirArray(int array[], int n) {
    printf("Array original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Função para implementar o Bubble Sort
void bubbleSort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Troca os elementos
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Função principal
int main() {
    int n;
    int array[MAX];

    printf("Digite a quantidade de números que deseja inserir (max %d): ", MAX);
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Número inválido! Deve ser entre 1 e %d.\n", MAX);
        return 1;
    }

    lerNumeros(array, n); // Ler os números
    exibirArray(array, n); // Exibir o array original
    bubbleSort(array, n); // Ordenar o array
    printf("Array ordenado:\n");
    exibirArray(array, n); // Exibir o array ordenado

    return 0;
}