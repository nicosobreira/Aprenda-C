# Estruturas de Repetição

São usadas para **repetir** partes do código, baseado em uma condição.

Antes de aprendermos as estruturas de repetição em si, vamos ver como o usuário pode digitar informações para o programa.

## scanf I

Primeiro, mostrarei o código que lê um inteiro do usuário, depois o analizaremos:

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

> As funções `printf` e `scanf` possui muitos formatadores, como o `%d`, em comum, mas existem alguns diferentes. Pesquise qual formatador é necessário antes de usar!

Depois utilizamos desse `&` (chamado de "e") junto ao nome de uma variável para indicar que o valor da entrada do usuário deve ser armazenado nessa variável.
Nos veremos o que esse símbolo realmente significa mais para frente, por hora, pense nele como a forma com que a função `scanf` muda o valor da variável `numero` para o valor de entrada do usuário.

Antes de recebermos a entrada em si, temos que dizer qual informação queremos que o usuário digite. Para isso, usamos do `printf`.
Diferente do que vinhamos fazendo, nos não colocamos o `\n` no final da string, mas sim um espaço. Isso é porque queremos mover o cursor do usuário para frente do dois pontos. Faça as seguintes modificações no código, e veja o que acontece:

- Retire esse espaço final, e execute o programa.
- Depois, coloque um `\n` no final da mensagem.
- E por último, remova a mensagem completamente.

## while

Agora, vamos criar um programa que pergunte por uma senha ao usuário. **Enquanto** a senha que o usuário digitar for diferente da senha correta, o programa vai continuar perguntando por uma nova senha. No entanto, no momento em que as senhas forem iguais, o programa irá sair do *loop*, do inglês "repetição", e continuar.

> Importe o header `stdio`, declare a função `main` e coloque o `return 0`. Escreva o código dentro da função `main`.

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

> Saiba que se você pressionar a tecla "CTRL" junto a tecla "c" você sairá forçadamente do programa .

Agora, remova a linha `scanf("%d", &tentativa);` do código, e rode o programa para ver o que acontece. O programa compila, mas quando roda nunca para!

### Loop infinito

A estrutura de repetição *while* verifica se a condição é verdadeira no **começo** de cada *loop*. Primeiro, o *while* vai verificar se o valor inicial da variável `tentativa` é diferente do valor da variável `senha`, ou seja, se `0 != 1234`, o que é verdade. Como retiramos a linha do `scanf`, ao final do *loop* o valor da variável `tentativa` **não mudou**, e por isso continua sendo `0`. Sendo assim, na próxima verificação da condição `tentativa != senha`, temos que `0 != 1234`, o que continua sendo verdade.
E assim vai, até nos forçarmos a saída do programa.

Esse é um **erro lógico**, chamado de **loop infinito**, e é causado quando nossa condição sempre é verdadeira.

## for

Para entendermos o por quê da estrutura de repetição *for* existir, vamos criar um contador de 1 até 10 usando o *while*.

``` c
int indice = 1;
while (indice != 10)
{
	printf("Índice atual: %d\n", indice);

	indice++;
}
```

Antes de corrigirmos um erro lógico em nosso contador, vamos ver do que ele é feito:

1. **Inicialização** antes do *while loop*. É a declaração da variável `indice` com o **valor inicial** de `1`.
2. **Condição** dentro do *while*. É quando comparamos o valor atual da variável `indice` com `10`.
3. **Atualização** ao final do *while*. Usamos da sintaxe `indice++` para indicar que estamos incrementando a variável `indice` em um. Essa parte é essencial para impedir um **loop infinito**.

O contador só vai até nove! Para entendermos o por quê disso, vamos verificar o resultado da condição `indice != 10` para todos os valores de `indice`, até que a condição se torne falsa. Lembre-se de que o `printf` só ira mostrar o indice atual se a condição for verdaderia, caso contrário, nada será impresso o no terminal.

| indice | indice != 10            |
| :-:    | :-                      |
| 1      | `1 != 10` => Verdadeiro |
| 2      | `2 != 10` => Verdadeiro |
| 3      | `3 != 10` => Verdadeiro |
| ...    | ...                     |
| 8      | `8 != 10` => Verdadeiro |
| 9      | `9 != 10` => Verdadeiro |
| **10** | `10 != 10` => **Falso** |

Na última linha da tabela, o valor de `indice` é 10. Dessa forma, a condição `10 != 10` é falsa, já que 10 é igual a 10.

Para consertar esse erro, vamos usar da desigualdade **menor ou igual**, escrita como `<=`. O programa ficará assim:

``` c
int indice = 1;
while (indice <= 10)
{
	printf("Índice atual: %d\n", indice);

	indice++;
}

return 0;
```

Lemos o *while* da seguinte maneira: enquanto o `indice` for **menor ou igual** a 10 imprima o índice atual e incremente a variável `indice`.

Agora, vamos ver um jeito mais simples de escrever essa mesma lógica, usando um *for loop*. Essa estrutura de repetição junta a  **inicialização**, a **condição** e o **incremento** em uma única linha, facilitando a leitura e eliminando erros, como esquecer de incrementar o indice ao final do *loop*.
O mesmo programa acima pode ser escrito nesse novo formato:

``` c
for (int indice = 1; indice <= 10; indice++)
{
	printf("Índice atual: %d\n", indice);
}
```

Para finalizar, vamos criar um programa que imprime a tabuada de um número.

Primeiro, vamos criar uma variável global chamada `total`, que armazenará o total de números da tabuada, que são `10`.

> Escreva o código dentro da função `main`. Não se esqueça de importar o header `stdio` e retornar `0` ao final de `main`.

``` c
const int total = 10;
``` 

Depois, vamos perguntar ao usuário de qual número será a tabuada.

``` c
int numero = 0;
printf("Digite um número para saber sua tabuada: ");
scanf("%d", &numero);
```

E agora, vamos criar o loop que vai exibir a tabuada.

``` c
    for (int indice = 1; indice <= total; indice++)
    {
        int resultado = numero * indice;
        printf("%d x %d = %d\n", numero, indice, resultado);
    }
```

## scanf II

Vamos retomar o primeiro exemplo do uso do `scanf`

> Aqui eu vou escrever apenas o conteúdo da função `main`.

``` c
int numero = 0;

printf("Digite um número, por favor: ");
scanf("%d", &numero);

printf("O seu número mais 2 vale %d.\n", numero + 2);
```

Nos vimos que esse código lê um número inteiro do usuário. Mas o que acontece se o usuário acidentalmente digitar um número real (com vírgula) ou uma letra?

Primeiro, tente digitar esses casos, depois veremos uma explicação.

## O valor de retorno

Se a entrada do usuário for algo diferente de um número inteiro, o resultado é `2`. Contudo, algo interessante acontece se substituirmos o valor inicial da variável `numero` por outro, como por exemplo `4`. Agora o resultado é `6`, ou seja, `4 + 2`.

Caso a leitura do `scanf` falhar, a variável `numero` não é alterada. Com essa informação nos já poderiamos pensar em validar a entrada do usuário: se o valor inicial continuar o mesmo, então peça outra entrada para o usuário. Mas existe um jeito ainda melhor de fazer a verificação.

Até agora, nos ignoramos o **valor de retorno** da função `scanf`. Esse valor é do tipo `int` e indica o número de **leituras bem sucedidas**, isso é, o **total de variáveis que foram alteradas** pela função.

Vamos ver esse valor no código a seguir:

``` c
printf("Digite um número, por favor: ");
int resultado = scanf("%d", &numero);

printf("Resultado do scanf: %d", resultado);
```

Se o usuário digitar um número inteiro, o `resultado` vale `1`, caso contrário, o `resultado` vale `0`. Com essa informação, podemos usar de um **retorno antecipado** para sair da função `main`, caso o usuário não tenha digitado um número:

``` c
int numero = 0;

printf("Digite um número, por favor: ");
int resultado = scanf("%d", &numero);

if (resultado != 1)
{
	printf("Digite um número da próxima vez!");
	return 1;
}

printf("O seu número mais 2 vale %d.\n", numero + 2);
```

---

Ao invés de sair do programa, podemos utilizar de um *while loop* para ler um número novamente.

``` c
int numero = 0;
printf("Digite um número: ");

while(scanf("%d", &numero) != 1)
{
	printf("Digite um número inteiro: ");
}
```

À primeira vista, esse código deve funcionar. Digite valores válidos e inválidos, e veja o que acontece.

Se não digitarmos um número inteiro, caímos em um **loop infinito**. Para entendermos esse erro, vamos ver como a entrada do usuário entra na função `scanf`.

### Buffer de entrada

Quando você digita algo no terminal e aperta `Enter`, o que você digitou não vai direto para a variável. Primeiro, esses dados vão para uma área de memória temporária chamada **buffer de entrada**, conhecida em C como *stdin* (apelido para *standard input*).

Por exemplo, se você digitar a letra `A` e depois `Enter`, o buffer de entrada vai ficar parecido com isso: \[`A`, `\n`\], como uma **fila de espera**, aguardando ser lida. O papel da função `scanf` é ler esse buffer até encontrar um `\n`. Quando isso acontece, essa parte do buffer é convertida para o formatador. Mas, após a leitura, o buffer de entrada **não é esvaziado**, isso é, **ele continua o mesmo**.

No código acima, caso digitemos `A` e `Enter`, o `scanf` funcionaria assim:

1. Vai ler o buffer até o `\n`;
2. Erro! O valor `A` não é um inteiro, nenhuma conversão foi um sucesso, retorna `0`;
3. A mensagem avisando o erro ao usuário é exibida;
4. O buffer ainda possui o `A`, a conversão falha e a mensagem é exibida;

Para limpar esse buffer, nos vamos usar a função `getchar`, declarada no header `stdio`. Essa função navega pelo buffer de entrada e limpa um caracter de cada vez. Seu valor de retorno e justamente esse caracter que acabou de ser limpo.

Portanto, enquanto o valor de retorno do `getchar` for diferente de `\n`, o buffer ainda precisa ser limpo.
Em código fica assim:

``` c
int numero = 0;
printf("Digite um número: ");

while(scanf("%d", &numero) != 1)
{
	while(getchar() != '\n') {}

	printf("Digite um número inteiro: ");
}
```

Uma implicação da não sanitização do buffer de entrada pela função `scanf` é que, mesmo se a entrada for convertida corretamente, o caractere `\n` ainda permanece no buffer.

Felizmente, formatadores de números como o `%d` e `%f` ignoram esses espaços e quebras de linha automaticamente na próxima leitura. No entanto, se a sua próxima leitura for de um caractere único (`%c`), esse `\n` residual será lido por engano. Nesse caso, use um espaço antes do formatador para instruir o `scanf` a ignorar o lixo do buffer: `scanf(" %c", &letra);`.

## do while

A ultima versão do código usando do `getchar` junto ao *while loop* para validar a entrada do usuário é funcional, mas apresenta problemas em sua construção. Vamos tentar usar esse código para limitar esse número entre 0 e 10, para valores de notas de prova, por exemplo.

Para tal, vamos utilizar do **operador lógico OU**. Caso **qualquer das condições** sejam verdadeiras, o *while loop* vai continuar.

``` c
int numero = 0;
printf("Digite um número: ");

while(scanf("%d", &numero) != 1 || numero < 0 || numero > 10)
{
	while(getchar() != '\n') {}

	printf("Digite um número inteiro: ");
}
```

Você concorda que adicionar essa simples checagem já deixou o código mais confuso? Agora, imagine se existissem **ainda mais verificações**!

Para resolver esse problema vamos usar outra estrutura de repetição, o **do while**. Primeiro vou mostrar a substuição do *while* pelo *do while*, sem o limite de 0 a 10.

> Não se esqueça de importar o header <stdbool.h> para o `true`!

``` c
int numero = 0;
printf("Digite um número: ");

do
{
	int resultado = scanf("%d", &numero);
	if (resultado != 1)
	{
		while (getchar() != '\n')
		{
		}

		printf("Erro, digite um número inteiro: ");
		continue;
	}

	break;
} while (true);

printf("O número mais 2 é %d", numero + 2);
```

A principal mudança foi o uso do `do {} while(true);` para continuar a execução enquanto verdadeiro, ou seja, "para sempre". Esse "para sempre" está entre aspas porque utilizamos do comando `break` para **interromper o loop** e continuar a execução do programa. Também usamos do comando `continue` para **interromper a rodada atual**, também chamada de **iteração**, e pular direto para a próxima rodada do *loop*, ou seja, para o `while (true)`, que é sempre verdade.

---

Com essas mudanças feitas, ficou muito mais fácil adicionar o limite entre 0 e 10.
O código fica assim:

``` c
const int min = 0;
const int max = 10;
int numero = 0;

printf("Digite um número entre %d e %d: ", min, max);
do
{
	int resultado = scanf("%d", &numero);

	if (resultado != 1)
	{
		while ((getchar()) != '\n')
		{
		}

		printf("Digite um número inteiro: ");
		continue;
	}

	if (numero < min)
	{
		printf("Digite um número maior que %d: ", min);
		continue;
	}

	if (numero > max)
	{
		printf("Digite um número menor que %d: ", max);
		continue;
	}

	break;
} while (true);

printf("O número mais 2 é %d", numero + 2);
```
