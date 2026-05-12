# Estruturas de Repetição

São usadas para **repetir** partes do código, baseado em uma condição.

Antes de apredermos as estruturas de repetição, vamos ver como o usuário pode interagir melhor com nossos programas.

## scanf

Até agora, nos apenas mostramos informações para os usuários, mas agora vamos ver um jeito de pedir informações deles.

Primeiro mostrarei o código para isso, depois vamos analiza-lo.

``` c
#include <stdio.h>

int main()
{
    int numero = 0;
    printf("Digite um número, por favor: ");
    scanf("%d", &numero);

    printf("Você digitou o número %d.\n", numero);

    return 0;
}
```

## while

## for

## do while
