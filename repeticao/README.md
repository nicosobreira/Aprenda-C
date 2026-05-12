# Estruturas de Repetição

São usadas para **repetir** partes do código, baseado em uma condição.

Antes de aprendermos as estruturas de repetição, vamos ver como o usuário pode interagir melhor com nossos programas.

## scanf

Até agora, nos apenas mostramos informações para os usuários, mas veremos um jeito de pedir informações a eles.

Primeiro mostrarei o código para isso, depois vamos analiza-lo.

``` c
#include <stdio.h>

int main()
{
    int numero = 0;

    printf("Digite um número, por favor: ");
    scanf("%d", &numero);

    printf("O seu número mais 2 vale %d.\n", numero + 2);

    return 0;
}
```

A entrada do usuário é feita por meio da função `scanf`, que assim como a função `printf`, é declarada no header `stdio`.
O primeiro argumento da função é uma string, que indica que tipo de informação queremos que o usuário digite. Nesse caso, como a variável `numero` é um `int`, usamos `%d`.

Depois utilizamos desse `&` junto ao nome de uma variável para indicar a onde devemos armazenar o valor da entrada do usuário.
Nos veremos o que esse símbolo realmente significa mais para frente, por hora, pense nele como a forma que a função `scanf` usa para mudar o valor da variável `numero` para o valor de entrada do usuário.

Antes de recebermos a entrada em si, temos que dizer qual informação queremos que o usuário digite. Para isso, usamos do `printf`.
Diferente do que vinhamos fazendo, nos não colocamos o `\n` no final da string, mas sim um espaço. Isso é porque queremos mover o cursor do usuário a frente do dois pontos. Faça as seguintes modificações no código, e veja o que acontece:

- Retire esse espaço final, e veja a saída;
- Depois, coloque um `\n` no final da mensagem;
- E por último, remova a mensagem completamente.

## while

...

## for

## do while
