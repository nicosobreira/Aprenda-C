#include <stdio.h>

int main(void)
{
    int numeros[3];
    const int total = sizeof(numeros) / sizeof(int);

    printf("Endereço da lista total: %p\n", (void *)&total);

    for (int i = 0; i < total; i++)
    {
        printf("&numeros[%d] = %p\n", i, (void *)&numeros[i]);
        scanf("%d", &numeros[i]);
    }

    return 0;
}
