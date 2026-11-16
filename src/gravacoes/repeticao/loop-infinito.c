#include <stdio.h>

int main(void)
{
    double taxa = 0.1;

    double arrecadado = 1000.0;
    double meta = arrecadado * 2.0;

    int meses = 0;

    while (arrecadado < meta)
    {
        // ...

        meses = meses + 1;

        printf("Mês %d: R$ %.2f\n", meses, arrecadado);
    }

    printf("Demorou %d meses para dobrar!\n", meses);

    return 0;
}
