#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct fila
{
    int valor;
    struct fila *prox;
} Fila;

Fila *enfileira(Fila *fila, int valor)
{
    Fila *novo = malloc(sizeof(Fila));
    if (novo == NULL)
        return NULL;

    novo->valor = valor;
    novo->prox = NULL;

    if (fila == NULL)
        return novo;

    Fila *aux = fila;
    while (aux->prox != NULL)
        aux = aux->prox;

    aux->prox = novo;
    return fila;
}

Fila *desenfileira(Fila *fila)
{
    if (fila == NULL)
    {
        printf("Erro: Fila Vazia\n");
        exit(1);
    }

    Fila *temp = fila;
    fila = fila->prox;
    free(temp);

    return fila;
}

int vazia(Fila *fila)
{
    return fila == NULL ? 1 : 0;
}

void mostra(Fila *fila)
{
    if (fila == NULL)
    {
        printf("Erro: Fila Vazia\n");
        exit(1);
    }
    Fila *aux = fila;
    while (aux != NULL)
    {
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
}

void mostraInverso(Fila *fila)
{
    Fila *pilha = NULL;
    Fila *aux = fila;

    while (aux != NULL)
    {
        Fila *novo = malloc(sizeof(Fila));
        if (novo == NULL)
        {
            printf("Erro: Falha na alocação de memória\n");
            exit(1);
        }
        novo->valor = aux->valor;
        novo->prox = pilha;
        pilha = novo;

        aux = aux->prox;
    }

    while (pilha != NULL)
    {
        printf("%d\n", pilha->valor);
        Fila *temp = pilha;
        pilha = pilha->prox;
        free(temp);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Fila *fila = NULL;

    fila = enfileira(fila, 0);
    fila = enfileira(fila, 2);
    fila = enfileira(fila, 4);
    fila = enfileira(fila, 6);
    fila = enfileira(fila, 8);
    fila = enfileira(fila, 10);

    fila = desenfileira(fila);
    fila = desenfileira(fila);

    printf("Fila:\n");
    mostra(fila);
    printf("\nFila Inversa:\n");
    mostraInverso(fila);

    if (vazia(fila) == 1)
        printf("\nA fila está vazia!\n");
    else
        printf("\nA fila não está vazia!\n");

    while (fila != NULL)
    {
        Fila *temp = fila;
        fila = fila->prox;
        free(temp);
    }

    getchar();
    return 0;
}