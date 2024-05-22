#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char palavra[16];
    int count;
    struct node *esquerda, *direita;
} Node;

Node *novoNode(char *palavra)
{
    Node *node = malloc(sizeof(Node));
    strcpy(node->palavra, palavra);
    node->count = 1;
    node->esquerda = NULL;
    node->direita = NULL;
    return node;
}

Node *inserir(Node *node, char *palavra)
{
    if (node == NULL)
        return novoNode(palavra);

    int comp = strcmp(palavra, node->palavra);
    if (comp < 0)
        node->direita = inserir(node->direita, palavra);
    else if (comp > 0)
        node->direita = inserir(node->direita, palavra);
    else
        node->count++;

    return node;
}

void printEmOrdem(Node *node)
{
    if (node != NULL)
    {
        printEmOrdem(node->esquerda);
        printf("%s (%d)\n", node->palavra, node->count);
        printEmOrdem(node->direita);
    }
}

void processaPalavras(char *palavras[])
{
    int i;
    Node *root = NULL;

    for (i = 0; palavras[i] != NULL; i++)
    {
        root = inserir(root, palavras[i]);
    }
    printEmOrdem(root);
}

int main()
{
    char *palavras[] = {"carro", "navio", "carro", "aviao", "carro", "camelo", "carro", "motocicleta", "carro", "navio", "aviao", "carro", "navio", NULL};
    processaPalavras(palavras);
    return 0;
}