/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: *************
* Data - 25/10/2024                                             * 
* Autor: João Pedro Lima Alves*
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    char descricao[100];
    float preco;
    int quantidade;
} Produto;

void inserirProduto(Produto produtos[], int *cont);
void listarProdutos(Produto produtos[], int cont);
void comprarProduto(Produto produtos[], int cont);
void bubbleSort(Produto produtos[], int cont);

int main() {
    Produto produtos[MAX_PRODUTOS];
    int cont = 0;
    int opcao;

    do {
        printf("\nLoja de Produtos Eletrônicos\n");
        printf("1. Inserir Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Comprar Produto\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirProduto(produtos, &cont);
                break;
            case 2:
                listarProdutos(produtos, cont);
                break;
            case 3:
                comprarProduto(produtos, cont);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

void inserirProduto(Produto produtos[], int *cont) {
    if (*cont >= MAX_PRODUTOS) {
        printf("Estoque cheio! Não é possível adicionar mais produtos.\n");
        return;
    }

    Produto p;
    p.id = *cont + 1;
    printf("Nome do Produto: ");
    scanf(" %[^\n]", p.nome);
    printf("Descrição do Produto: ");
    scanf(" %[^\n]", p.descricao);
    printf("Preço Unitário: ");
    scanf("%f", &p.preco);
    printf("Quantidade em Estoque: ");
    scanf("%d", &p.quantidade);

    produtos[*cont] = p;
    (*cont)++;
    printf("Produto inserido com sucesso!\n");
}

void listarProdutos(Produto produtos[], int cont) {
    if (cont == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    bubbleSort(produtos, cont);

    printf("\n--- Lista de Produtos ---\n");
    for (int i = 0; i < cont; i++) {
        printf("ID: %d\n", produtos[i].id);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Descrição: %s\n", produtos[i].descricao);
        printf("Preço: %.2f\n", produtos[i].preco);
        printf("Quantidade: %d\n\n", produtos[i].quantidade);
    }
}

void comprarProduto(Produto produtos[], int cont) {
    if (cont == 0) {
        printf("Nenhum produto disponível para compra.\n");
        return;
    }

    int id, quantidade;
    printf("Informe o ID do produto que deseja comprar: ");
    scanf("%d", &id);

    if (id < 1 || id > cont) {
        printf("Produto Inexistente.\n");
        return;
    }

    Produto p = produtos[id - 1]; 

    printf("Quantidade desejada: ");
    scanf("%d", &quantidade);

    if (quantidade > p.quantidade) {
        printf("Quantidade em estoque insuficiente. Disponível: %d\n", p.quantidade);
    } else {
        produtos[id - 1].quantidade -= quantidade; // Atualiza a quantidade no estoque
        printf("Compra realizada com sucesso! Você comprou %d unidades de %s.\n", quantidade, p.nome);
    }
}
void bubbleSort(Produto produtos[], int cont) {
    for (int i = 0; i < cont - 1; i++) {
        for (int j = 0; j < cont - i - 1; j++) {
            if (strcmp(produtos[j].nome, produtos[j + 1].nome) > 0) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}