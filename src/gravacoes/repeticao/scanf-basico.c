#include <stdio.h>

int main(void)
{
    int entrada = 0;

    printf("Digite um número inteiro: ");
    int sucessos = scanf("%d", &entrada);

    printf("[%d entradas lidas com sucesso]\n", sucessos);

    printf("A entrada mais dois vale: %d\n", entrada + 2);

    return 0;
}
