// RA: 2040482222053 - Milena Sayuri Hayakawa

#include <stdio.h>

// Exercício 01 — Operadores de Referência, Desreferenciação e Aritmética de Ponteiros
// Parte A — Troca com ponteiros (operadores & e *)

void trocar(int *a, int *b)
{
    *a = *a + *b; // Soma os dois valores e guarda em 'a'
    *b = *a - *b; // Subtrai o novo valor de 'a' pelo 'b' original para achar o 'a' original
    *a = *a - *b; // Subtrai o novo 'a' pelo novo 'b' para achar o 'b' original
}

int main()
{
    int x = 15;
    int y = 42;

    printf("Antes da troca:\n");
    printf("x = %d (Endereco: %p)\n", x, &x); // &x pega o endereco de memoria da variavel x
    printf("y = %d (Endereco: %p)\n", y, &y); // &y pega o endereco de memoria da variavel y

    trocar(&x, &y); // Passa os endereços das variáveis para a função

    printf("\nDepois da troca:\n");
    printf("x = %d (Endereco: %p)\n", x, &x); // &x pega o endereco de memoria da variavel x
    printf("y = %d (Endereco: %p)\n", y, &y); // &y pega o endereco de memoria da variavel y

    return 0;
}