#include <stdbool.h>
#include <stdio.h>

int leia(void);

double leia(void);

int main(void)
{
    printf("Digite sua idade.");
    int idade = leia();

    printf("A sua idade é: %d.\n", idade);
}

int leia(void)
{
    return 0;
}

double leia(void)
{
    return 0.0;
}
