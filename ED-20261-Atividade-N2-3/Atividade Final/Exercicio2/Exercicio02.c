// RA: 2040482222053 - Milena Sayuri Hayakawa

#include <stdio.h>

// Exercício 02 — Ponteiro com Array e Passagem de Ponteiro em Funções

float calcularMedia(float *vet, int n)
{
    float soma = 0;
    float *ptr = vet;
    for (int i = 0; i < n; i++)
    {
        soma += *ptr;
        ptr++;
    }
    return soma / n;
}

void encontrarExtremos(float *vet, int n, float *maior, float *menor)
{
    float *ptr = vet;
    *maior = *ptr;
    *menor = *ptr;

    for (int i = 0; i < n; i++)
    {
        if (*ptr > *maior)
            *maior = *ptr;
        if (*ptr < *menor)
            *menor = *ptr;
        ptr++;
    }
}

void normalizar(float *vet, int n)
{
    float maior, menor;
    encontrarExtremos(vet, n, &maior, &menor);

    float *ptr = vet;
    for (int i = 0; i < n; i++)
    {
        *ptr = *ptr / maior;
        ptr++;
    }
}

void imprimirVetor(float *vet, int n, const char *titulo)
{
    printf("%s: ", titulo);
    float *ptr = vet;
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", *ptr);
        ptr++;
    }
    printf("\n");
}

int main()
{
    float notas[] = {7.5f, 3.2f, 9.8f, 6.0f, 5.5f, 8.1f};
    int n = sizeof(notas) / sizeof(notas[0]);
    float maior, menor;

    imprimirVetor(notas, n, "Vetor Original");

    printf("Media: %.2f\n", calcularMedia(notas, n));

    encontrarExtremos(notas, n, &maior, &menor);
    printf("Maior valor: %.2f | Menor valor: %.2f\n", maior, menor);

    normalizar(notas, n);
    imprimirVetor(notas, n, "Vetor Normalizado");

    /*
                * Por que a funcao normalizar alterou o vetor original?

     * Foi passado o endereco de memoria inicial do vetor(ponteiro) para a funcao e
     * qualquer modificacao feita usando a desreferenciacao(*ptr) altera diretamente
     * o dado armazenado na memoria principal e nao uma copia local da variavel
     */

    return 0;
}