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