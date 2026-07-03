#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    const int primeira_opcao = 1;
    const int ultima_opcao = 3;

    double saldo = 1000.0;

    printf("--- OPÇÕES ---\n");
    printf("1. Ver Saldo\n");
    printf("2. Depositar\n");
    printf("3. Sair\n");
    printf("\n");

    double caixa_esta_ligado = true;
    while (caixa_esta_ligado)
    {
        int opcao;

        bool leitura_valida = false;
        do
        {
            printf("> ");

            int r = scanf("%d", &opcao);
            if (r != 1)
            {
                while (getchar() != '\n')
                {
                }

                printf("Digite um número inteiro!\n");
            }
            else if (opcao < primeira_opcao)
            {
                printf("Digite um número maior ou igual a %d!\n", primeira_opcao);
            }
            else if (opcao > ultima_opcao)
            {
                printf("Digite um número menor ou igual a %d!\n", ultima_opcao);
            }
            else
            {
                leitura_valida = true;
            }
        } while (!leitura_valida);

        if (opcao == 1)
        {
            printf("Seu saldo é de R$ %.2f\n", saldo);
        }
        else if (opcao == 2)
        {
            printf("\n");
            printf("Deseja depositar quanto? [Digite 0 para sair]\n");

            double deposito;

            bool leitura_valida = false;
            do
            {
                printf("> ");

                int r = scanf("%lf", &deposito);
                if (r != 1)
                {
                    while (getchar() != '\n')
                    {
                    }

                    printf("Digite um número real!\n");
                }
                else if (deposito < 0)
                {
                    printf("Digite um número positivo!\n");
                }
                else
                {
                    leitura_valida = true;
                }
            } while (!leitura_valida);

            saldo += deposito;
        }
        else if (opcao == 3)
        {
            caixa_esta_ligado = false;
        }

        printf("\n");
    }

    printf("Até mais!\n");

    return 0;
}
