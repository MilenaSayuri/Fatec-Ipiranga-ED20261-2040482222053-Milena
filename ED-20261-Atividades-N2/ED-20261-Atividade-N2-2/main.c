#include <stdio.h>
#include <stdlib.h>

struct No
{
    int valor;
    int altura;
    struct No *esq;
    struct No *dir;
};

int calcularAltura(struct No *n)
{
    if (n == NULL)
        return -1;

    int h_filho_esq = calcularAltura(n->esq);
    int h_filho_dir = calcularAltura(n->dir);

    // Versao operador ternário
    // return 1 + ((h_filho_esq > h_filho_dir) ? h_filho_esq : h_filho_dir);

    if (h_filho_esq > h_filho_dir)
        return 1 + h_filho_esq;
    else
        return 1 + h_filho_dir;
}

int obterFB(struct No *n)
{
    if (n == NULL)
        return 0;

    return calcularAltura(n->esq) - calcularAltura(n->dir);
}

int main()
{
    struct No *no20 = (struct No *)malloc(sizeof(struct No));
    struct No *no10 = (struct No *)malloc(sizeof(struct No));
    struct No *no5 = (struct No *)malloc(sizeof(struct No));
    struct No *no2 = (struct No *)malloc(sizeof(struct No));

    no20->valor = 20;
    no20->esq = no10;
    no20->dir = NULL;
    no10->valor = 10;
    no10->esq = no5;
    no10->dir = NULL;
    no5->valor = 5;
    no5->esq = no2;
    no5->dir = NULL;
    no2->valor = 2;
    no2->esq = NULL;
    no2->dir = NULL;

    int h_no_20 = calcularAltura(no20);
    int fb_20 = obterFB(no20);

    printf("Altura do No 20: %d\n", h_no_20);
    printf("Fator de Balanceamento (fb_20): %d\n", fb_20);

    if (fb_20 > 1 || fb_20 < -1)
        printf("Resultado: Desbalanceado!\n");

    return 0;
}