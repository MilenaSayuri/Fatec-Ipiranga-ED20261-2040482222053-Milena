// RA: 2040482222053 - Milena Sayuri Hayakawa

#include <stdio.h>

// Parte A — Implementação

void hanoi(int n, char origem, char destino, char auxiliar)
{
    // Caso base
    if (n == 1)
    {
        printf("Move disco 1 de %c para %c\n", origem, destino);
        return;
    }

    // Caso recursivo
    hanoi(n - 1, origem, auxiliar, destino);
    printf("Move disco %d de %c para %c\n", n, origem, destino);
    hanoi(n - 1, auxiliar, destino, origem);
}

int main()
{
    printf("--- Parte A: Torres de Hanoi ---\n");
    hanoi(3, 'A', 'C', 'B'); // Teste basico exigido na implementacao
    return 0;
}