// RA: 2040482222053 - Milena Sayuri Hayakawa

#include <stdio.h>

// Exercício 01 — Operadores de Referência, Desreferenciação e Aritmética de Ponteiros
// Parte B — Aritmética de ponteiros em um vetor

int main()
{
    int v[] = {10, 20, 30, 40, 50};
    int tamanho = sizeof(v) / sizeof(*v); //*v equivale ao primeiro elemento do vetor, então sizeof(*v) é o tamanho de um elemento
    int soma = 0;

    // v é equivalente a &v[0]
    int *inicio = v;              // Ponteiro aponta para o primeiro elemento
    int *fim = v + (tamanho - 1); // Ponteiro aponta para o último elemento
    int *ptr;

    // a) Imprima cada elemento e seu endereço
    printf("Elementos e enderecos:\n");
    for (ptr = inicio; ptr <= fim; ptr++)
        printf("Valor: %d | Endereco: %p\n", *ptr, ptr);
    // *ptr desreferencia o ponteiro para acessar o valor
    // ptr (sem *) fornece o endereco

    // b) Calcular e imprimir a soma
    for (ptr = inicio; ptr <= fim; ptr++)
        soma += *ptr; // *ptr desreferencia para somar o valor apontado
    printf("\nSoma total: %d\n", soma);

    // c) Inverter o vetor in-place
    int *p1 = inicio;
    int *p2 = fim;
    // &v[0] obtem endereço do primeiro elemento (equivalente a v)
    // &v[tamanho-1] obtem endereço do ultimo elemento (equivalente a v + 4)

    while (p1 < p2)
    {
        // *p1 desreferencia para acessar o valor apontado por p1
        // *p2 desreferencia para acessar o valor apontado por p2
        *p1 = *p1 + *p2;
        *p2 = *p1 - *p2;
        *p1 = *p1 - *p2;
        p1++; // p1++ incrementa o ponteiro (move para próxima posicao)
        p2--; // p2-- decrementa o ponteiro (move para posição anterior)
    }

    printf("\nVetor invertido:\n");
    for (ptr = inicio; ptr <= fim; ptr++)
    {
        printf("%d ", *ptr); // *ptr desreferencia para exibir cada valor
    }
    printf("\n");

    return 0;
}