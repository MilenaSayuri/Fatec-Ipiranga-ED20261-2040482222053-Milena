// RA: 2040482222053 - Milena Sayuri Hayakawa

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *esq;
    struct No *dir;
} No;

No *inserir(No *raiz, int valor)
{
    if (raiz == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->dado = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    if (valor < raiz->dado)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->dado)
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

int alturaNo(No *no)
{
    if (no == NULL)
        return -1;

    int alt_esquerda = alturaNo(no->esq);
    int alt_direita = alturaNo(no->dir);

    if (alt_esquerda > alt_direita)
        return alt_esquerda + 1;
    else
        return alt_direita + 1;
}

int profundidadeNo(No *raiz, int valor, int prof)
{
    if (raiz == NULL)
        return -1;

    if (raiz->dado == valor)
        return prof;

    if (valor < raiz->dado)
        return profundidadeNo(raiz->esq, valor, prof + 1);
    else
        return profundidadeNo(raiz->dir, valor, prof + 1);
}

int grauNo(No *no)
{
    if (no == NULL)
        return 0;

    int grau = 0;

    if (no->esq != NULL)
        grau++;
    if (no->dir != NULL)
        grau++;

    return grau;
}

void liberarArvore(No *raiz)
{
    if (raiz != NULL)
    {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

int main()
{
    No *raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++)
    {
        raiz = inserir(raiz, valores[i]);
    }

    printf("--- Parte B: Consultas Estruturais ---\n\n");

    printf("a) Altura dos nos:\n");
    printf("   No 50: Altura %d\n", alturaNo(raiz));

    No *aux = NULL;

    aux = raiz->esq;
    printf("   No 30: Altura %d\n", alturaNo(aux));

    aux = raiz->dir;
    printf("   No 70: Altura %d\n", alturaNo(aux));

    aux = raiz->esq->esq;
    printf("   No 20: Altura %d\n", alturaNo(aux));

    aux = raiz->esq->esq->esq;
    printf("   No 10: Altura %d\n", alturaNo(aux));

    printf("\nb) Profundidade dos nos:\n");
    printf("   No 50: Profundidade %d\n", profundidadeNo(raiz, 50, 0));
    printf("   No 30: Profundidade %d\n", profundidadeNo(raiz, 30, 0));
    printf("   No 70: Profundidade %d\n", profundidadeNo(raiz, 70, 0));
    printf("   No 45: Profundidade %d\n", profundidadeNo(raiz, 45, 0));
    printf("   No 10: Profundidade %d\n", profundidadeNo(raiz, 10, 0));

    printf("\nc) Grau de cada no:\n");
    printf("   No 50: Grau %d\n", grauNo(raiz));
    printf("   No 30: Grau %d\n", grauNo(raiz->esq));
    printf("   No 70: Grau %d\n", grauNo(raiz->dir));
    printf("   No 20: Grau %d\n", grauNo(raiz->esq->esq));
    printf("   No 40: Grau %d\n", grauNo(raiz->esq->dir));
    printf("   No 60: Grau %d\n", grauNo(raiz->dir->esq));
    printf("   No 80: Grau %d\n", grauNo(raiz->dir->dir));
    printf("   No 10: Grau %d\n", grauNo(raiz->esq->esq->esq));
    printf("   No 25: Grau %d\n", grauNo(raiz->esq->esq->dir));
    printf("   No 45: Grau %d\n", grauNo(raiz->esq->dir->dir));
    printf("   No 65: Grau %d\n", grauNo(raiz->dir->dir->esq));

    printf("\nd) Altura total da arvore: %d\n", alturaNo(raiz));

    liberarArvore(raiz);
    return 0;
}