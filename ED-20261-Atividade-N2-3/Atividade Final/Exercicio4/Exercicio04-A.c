// RA: 2040482222053 - Milena Sayuri Hayakawa

#include <stdio.h>

// Exercício 04 — Busca Binária Recursiva e Potenciação Rápida
//  Parte A: Busca Binaria

int buscaBinaria(int *vet, int inicio, int fim, int alvo, int *chamadas)
{
    (*chamadas)++;

    //                      CASO BASE: O espaco de busca se esgotou
    // Se o inicio ultrapassou o fim, entao foi varrido a sub-arvore de busca possivel e o elemento nao esta no vetor, e encerra a recursao
    if (inicio > fim)
        return -1;

    int meio = inicio + (fim - inicio) / 2;

    //                      CASO BASE: Elemento encontrado
    // Se o valor no indice meio for o alvo, encontramos o dado, encerra a recursao
    if (vet[meio] == alvo)
        return meio;

    //                      CASOS RECURSIVO: Dividir para conquistar
    // Se o valor do meio for maior que o alvo, o alvo obrigatoriamente esta na metade esquerda do vetor (porque esta ordenado)
    if (vet[meio] > alvo)
        return buscaBinaria(vet, inicio, meio - 1, alvo, chamadas);

    // Se nao o alvo obrigatoriamente esta na metade direita
    else
        return buscaBinaria(vet, meio + 1, fim, alvo, chamadas);
}

int main()
{
    int dados[] = {2, 5, 8, 12, 16, 23, 38, 45, 72, 91};
    int chamadas;
    int resultado;

    printf("--- Busca Binaria Recursiva ---\n");

    chamadas = 0;
    resultado = buscaBinaria(dados, 0, 9, 38, &chamadas);
    printf("Busca por 38 (Presente) : Indice %2d | Chamadas recursivas: %d\n", resultado, chamadas);

    chamadas = 0;
    resultado = buscaBinaria(dados, 0, 9, 50, &chamadas);
    printf("Busca por 50 (Ausente)  : Indice %2d | Chamadas recursivas: %d\n", resultado, chamadas);

    chamadas = 0;
    resultado = buscaBinaria(dados, 0, 9, 2, &chamadas);
    printf("Busca por 2  (Primeiro) : Indice %2d | Chamadas recursivas: %d\n", resultado, chamadas);

    return 0;
}