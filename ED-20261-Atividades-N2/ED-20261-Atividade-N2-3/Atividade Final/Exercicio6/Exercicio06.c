// RA: 2040482222053 - Milena Sayuri Hayakawa

#include <stdio.h>
#include <stdlib.h>

// Utilizando a mesma ABB do Exercício 05

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

// Exercício 06 — Ancestrais, Descendentes e Relatório Completo de um Nó
// Parte A — Funções de parentesco

void imprimirAncestral(No *raiz, int valor)
{
    if (raiz == NULL)
        return;

    if (raiz->dado == valor)
    {
        printf("%d ", raiz->dado);
        return;
    }

    if (valor < raiz->dado)
    {
        printf("%d ", raiz->dado);
        imprimirAncestral(raiz->esq, valor);
    }
    else
    {
        printf("%d ", raiz->dado);
        imprimirAncestral(raiz->dir, valor);
    }
}

void imprimirDescendentes(No *no)
{
    if (no == NULL)
        return;

    imprimirDescendentes(no->esq);

    printf("%d ", no->dado);

    imprimirDescendentes(no->dir);
}

int contarDescendentes(No *no)
{
    if (no == NULL)
        return 0;

    int total = 1;
    total = total + contarDescendentes(no->esq);
    total = total + contarDescendentes(no->dir);

    return total;
}

No *buscarNo(No *raiz, int valor)
{
    if (raiz == NULL)
        return NULL;

    if (raiz->dado == valor)
        return raiz;

    if (valor < raiz->dado)
        return buscarNo(raiz->esq, valor);
    else
        return buscarNo(raiz->dir, valor);
}

// Parte B — Relatorio completo de um no
void relatorioNo(No *raiz, int valor)
{
    No *no = buscarNo(raiz, valor);

    if (no == NULL)
    {
        printf("ERRO: No com valor %d nao existe na arvore!\n", valor);
        return;
    }

    int prof = profundidadeNo(raiz, valor, 0);
    int alt = alturaNo(no);
    int grau = grauNo(no);
    int qtd_desc = contarDescendentes(no) - 1;

    printf("+-----------------------------------+\n");
    printf("| RELATORIO DO NO: %d\n", valor);
    printf("+-----------------------------------+\n");
    printf("| Profundidade : %d\n", prof);
    printf("| Altura       : %d\n", alt);
    printf("| Grau         : %d\n", grau);
    printf("| Ancestrais   : ");
    imprimirAncestral(raiz, valor);
    printf("\n");
    printf("| Descendentes : ");
    imprimirDescendentes(no->esq);
    imprimirDescendentes(no->dir);
    printf("\n");
    printf("| Qtd Descend. : %d\n", qtd_desc);
    printf("+-----------------------------------+\n");
}

int main()
{
    No *raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65};
    int n = sizeof(valores) / sizeof(valores[0]);

    int i;
    for (i = 0; i < n; i++)
    {
        raiz = inserir(raiz, valores[i]);
    }

    // Parte C — Testes sistematicos
    printf("--- TESTES SISTEMATICOS ---\n\n");

    printf("No raiz\n");
    relatorioNo(raiz, 50);
    printf("\n");

    printf("No intermediario (esquerda)\n");
    relatorioNo(raiz, 30);
    printf("\n");

    printf("Folha\n");
    relatorioNo(raiz, 10);
    printf("\n");

    printf("No intermediario (direita)\n");
    relatorioNo(raiz, 70);
    printf("\n");

    printf("No que nao existe\n");
    relatorioNo(raiz, 999);
    printf("\n");

    liberarArvore(raiz);

    return 0;
}