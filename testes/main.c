#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    entrar_na_festa(true);

    return 0;
}

void entrar_na_festa(bool tem_convite)
{
    if (!tem_convite)
    {
        printf("Você não tem convite! Rala!\n");
        return;
    }

    printf("Seja bem-vindo!\n");
}
