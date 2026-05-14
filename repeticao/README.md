# Estruturas de Repetição

São usadas para **repetir** partes do código, baseado em uma condição.

Antes de aprendermos as estruturas de repetição em si, vamos ver como o usuário pode digitar informações para o programa.

## scanf

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

> As funções `printf` e `scanf` possui muitos formatadores, como o `%d`, em comum, mas existem algumas diferenças. Pesquise qual formatador é necessário antes de usar!

Depois utilizamos desse `&` (chamado de "e") junto ao nome de uma variável para indicar que o valor da entrada do usuário deve ser armazenado nessa variável.
Nos veremos o que esse símbolo realmente significa mais para frente, por hora, pense nele como a forma com que a função `scanf` muda o valor da variável `numero` para o valor de entrada do usuário.

Antes de recebermos a entrada em si, temos que dizer qual informação queremos que o usuário digite. Para isso, usamos do `printf`.
Diferente do que vinhamos fazendo, nos não colocamos o `\n` no final da string, mas sim um espaço. Isso é porque queremos mover o cursor do usuário a frente do dois pontos. Faça as seguintes modificações no código, e veja o que acontece:

- Retire esse espaço final, e veja a saída;
- Depois, coloque um `\n` no final da mensagem;
- E por último, remova a mensagem completamente.

## while

Para aprendermos a estrutura de repetição *while* (do inglês "enquanto"), vamos criar um programa que pergunte pela senha para proseguir. **Enquanto** a senha que o usuário digitar for diferente da senha correta, o programa vai continuar perguntando por uma nova senha. No entanto, no momento em que as senhas forem iguais, o programa ira sair do *loop* e continuar até o `return 0`.

> Importe o header `stdio`, declare a função `main` e coloque o `return 0` no final.

``` c
const int senha = 1234;
int tentativa = 0;

while (tentativa != senha)
{
	printf("Digite a senha de 4 dígitos: ");
	scanf("%d", &tentativa);

	if (tentativa != senha)
	{
		printf("Você digitou a senha errada!\n");
	}
}

printf("A senha está correta!\n");
```

> Para o próximo exemplo, saiba que se você precionar a tecla "CTRL" junto a tecla "c", você sairá do programa.

Agora, remova a linha `scanf("%d", &tentativa);` do código, e rode o programa para ver o que acontece. O programa compila, mas nunca para!

### Loop infinito

O motivo desse erro está na verificação da condição `tentativa != senha`.
A estrutura de repetição *while* verifica se a condição é verdadeira no **começo** de cada *loop* e ao **final** dele, após a execução de todo o código entre chaves. Primeiro, o *while* vai verificar se o valor inicial da variável `tentativa` é diferente do valor da variável `senha`, ou seja, `0 != 1234`, o que é verdade. Dessa forma, se inicia o *loop*. Como retiramos a linha do `scanf`, ao final do *loop*, o valor da variável `tentativa` não mudou, e por isso continua sendo `0`. Portanto, na próxima vez que o *while* verificar a condição, teremos que `0 != 1234`, e assim por diante.

Esse erro é chamado de **loop infinito**, e é causado quando não atualizamos as variáveis usadas na condição.

## for

Para enterdemos o por quê da estrutura de repetição *for* existir, vamos criar uma calculadora de tabuadas usando o *while*.

> Importe o header `stdio`, declare a função `main` e coloque o `return 0` no final. Escreva o código dentro da função `main`.

Primeiro, vamos perguntar ao usuário um numero para saber sua tabuada.

``` c
int numero = 0;
printf("Digite um número para saber sua tabuada: ");
scanf("%d", &numero);
```

Depois, vamos criar um **contador** de 1 até 10, usando um *while loop*. 

> A condição do contador está errada! Vamos ver como arrumar logo em seguida.

``` c
int indice = 1;
while (indice != 10)
{
	// Operações

	indice++;
}
```

O contador é contruído a partir de três partes, são elas:

1. **Inicialização** antes do *while loop*. É a declaração da variável `indice` com o **valor inicial** de `1`.
2. **Condição** dentro do *while*. É quando comparamos o valor atual da variável `indice` com `10`.
3. **Atualização** ao final do *while*. Usamos da sintaxe `indice++` para indicar que estamos incrementando a variável `indice` por um. Essa parte é essêncial para impedir um **loop infinito**.

Troque o comentário `// Operações` por esse `printf`: `printf("Índice atual: %d\n", indice);` e rode o programa. O contador vai até nove!


## do while
