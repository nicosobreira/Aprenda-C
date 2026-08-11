#include <stdio.h>

int main(void)
{
    const int quantidade_notas = 5;
    int notas[5] = {10, 8, 7, 9, 6};

    int soma = 0;

    for (int i = 0; i < quantidade_notas; i++)
    {
        soma += notas[i];
    }

    double media = (double)soma / quantidade_notas;

    printf("A soma das notas é: %d\n", soma);
    printf("A média da turma é: %.2f\n", media);

    int valores[] = {10, 20, 30, 40, 50, 60};
    int quantidade_elementos = sizeof(valores) / sizeof(valores[0]);
    printf("Quantidade de elementos: %d\n", quantidade_elementos);

    return 0;
}
