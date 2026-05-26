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
    int h_no_atual;

    // Versao operador ternário
    // return 1 + ((h_filho_esq > h_filho_dir) ? h_filho_esq : h_filho_dir);

    if (h_filho_esq > h_filho_dir)
        h_no_atual = 1 + h_filho_esq;
    else
        h_no_atual = 1 + h_filho_dir;

    printf("No %d: 1 + max(esq:%d, dir:%d) = %d\n", 
            n->valor, h_filho_esq, h_filho_dir, h_no_atual);

    return h_no_atual;
}

int obterFB(struct No *n)
{
    if (n == NULL)
        return 0;

    printf("\n--- Calculo do FB do No %d ---\n", n->valor);
    
    int h_esq = calcularAltura(n->esq);
    
    int h_dir = calcularAltura(n->dir);
    
    int fb_no = h_esq - h_dir;

    printf("\nFB = %d - (%d) = %d\n", h_esq, h_dir, fb_no);
    printf("---------------------------------------\n");

    return fb_no;
}

int main()
{

    struct No *no30 = (struct No *)malloc(sizeof(struct No));
    struct No *no20 = (struct No *)malloc(sizeof(struct No));
    struct No *no10 = (struct No *)malloc(sizeof(struct No));
    struct No *no5 = (struct No *)malloc(sizeof(struct No));
    struct No *no2 = (struct No *)malloc(sizeof(struct No));

    no30->valor = 30;
    no30->esq = NULL;
    no30->dir = NULL;

    no20->valor = 20;
    no20->esq = no10;
    no20->dir = no30;

    no10->valor = 10;
    no10->esq = no5;
    no10->dir = NULL;

    no5->valor = 5;
    no5->esq = no2;
    no5->dir = NULL;

    no2->valor = 2;
    no2->esq = NULL;
    no2->dir = NULL;

    int fb_20 = obterFB(no20);

    if (fb_20 > 1 || fb_20 < -1)
        printf("Resultado: No %d esta Desbalanceado!\n", no20->valor);
    else
        printf("Resultado: No %d esta Balanceado!\n", no20->valor);

    return 0;
}
