#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    double nota = 5.0;
    bool se_esforcou = false;

    if (nota < 6.0 && se_esforcou)
    {
        printf("Na próxima você consegue!\n");
    }
    else
    {
        printf("Você precisa se esforçar mais!\n");
    }

    return 0;
}
