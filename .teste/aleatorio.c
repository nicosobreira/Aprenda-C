#include <stdio.h>  // Para o printf
#include <stdlib.h> // Para o rand e srand

int main(void)
{
    srand(50);

    int aleatorio = rand();

    printf("O número aleatório é: %d\n", aleatorio);

    return 0;
}
