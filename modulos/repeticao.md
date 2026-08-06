# Estruturas de Repetição

São usadas para **repetir** partes do código, baseado em uma condição.

Para entendermos suas utilidades, vamos ver como o usuário pode interagir melhor com o nosso programa, lendo sua entrada.

## scanf I

Primeiro, mostrarei o código que lê um inteiro do usuário, depois o analisaremos:

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

> As funções `printf` e `scanf` possuem muitos formatadores, como o `%d`, em comum, mas existem alguns diferentes. Pesquise qual formatador é necessário antes de usar!

Depois utilizamos desse `&` (chamado de "e") junto ao nome de uma variável para indicar que o valor da entrada do usuário deve ser armazenado nessa variável.
Veremos o que esse símbolo realmente significa mais para frente, por ora, pense nele como a forma com que a função `scanf` muda o valor da variável `numero` para o valor de entrada do usuário.

Antes de recebermos a entrada em si, temos que dizer qual informação queremos que o usuário digite. Para isso, usamos do `printf`.
Diferente do que vínhamos fazendo, não colocamos o `\n` no final da string, mas sim um espaço. Isso é porque queremos mover o cursor do usuário para frente dos dois pontos. Faça as seguintes modificações no código, e veja o que acontece:

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

### Loop infinito

Saiba que se você pressionar a tecla "CTRL" junto a tecla "c" você sairá forçadamente do programa.

Agora, remova a linha `scanf("%d", &tentativa);` do código, e rode o programa para ver o que acontece. O programa compila, mas quando roda nunca para!

A estrutura de repetição `while` verifica se a condição é verdadeira no **começo** de cada *loop*. Primeiro, o `while` vai verificar se o valor inicial da variável `tentativa` é diferente do valor da variável `senha`, ou seja, se `0 != 1234`, o que é verdade. Como retiramos a linha do `scanf`, ao final do *loop* o valor da variável `tentativa` **não mudou**, e por isso continua sendo `0`. Sendo assim, na próxima verificação da condição `tentativa != senha`, temos que `0 != 1234`, o que continua sendo verdade.
E assim vai, até forçarmos a saída do programa usando `CTRL + c`.

Esse é um **erro lógico**, chamado de **loop infinito**, e é causado quando nossa condição sempre é verdadeira.

## for

Para entendermos o porquê da estrutura de repetição `for` existir, vamos criar um contador de 1 até 10 usando o `while`.

``` c
int indice = 1;
while (indice != 10)
{
	printf("Índice atual: %d\n", indice);

	indice++;
}
```

Antes de corrigirmos um erro lógico em nosso contador, vamos ver do que ele é feito:

1. **Inicialização** antes do `while` *loop*. É a declaração da variável `indice` com o **valor inicial** de `1`.
2. **Condição** dentro do `while`. É quando comparamos o valor atual da variável `indice` com `10`.
3. **Atualização** ao final do `while`. Usamos da sintaxe `indice++` para indicar que estamos incrementando a variável `indice` em um. Essa parte é essencial para impedir um **loop infinito**. Note que poderíamos ter usado `indice += 1` também.

O erro está aqui: o contador só vai até nove! Para entendermos o porquê disso, vamos verificar o resultado da condição `indice != 10` para todos os valores de `indice`, até que a condição se torne falsa. Lembre-se de que o `printf` só irá **mostrar o índice** atual **se a condição for verdadeira**, caso contrário, nada será impresso no terminal.

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

Lemos o `while` da seguinte maneira: enquanto o `indice` for **menor ou igual** a 10 imprima o índice atual e incremente a variável `indice` em 1.

Agora, vamos ver um jeito mais simples de escrever essa mesma lógica, usando um `for` *loop*. Essa estrutura de repetição junta a  **inicialização**, a **condição** e o **incremento** em uma única linha, facilitando a leitura e eliminando erros, como esquecer de incrementar o índice ao final do *loop*.
O mesmo programa acima pode ser escrito nesse novo formato:

``` c
for (int indice = 1; indice <= 10; indice++)
{
	printf("Índice atual: %d\n", indice);
}
```

Por último, vamos criar um programa que imprime a tabuada de um número.

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

E agora, vamos criar o *loop* que vai exibir a tabuada.

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

Vimos que esse código lê um número inteiro do usuário. Mas o que acontece se o usuário acidentalmente digitar um número real (com vírgula) ou uma letra?

Primeiro, tente digitar esses casos, depois veremos uma explicação.

### O valor de retorno do scanf

Se a entrada do usuário for algo diferente de um número inteiro, o resultado é `2`. Contudo, algo interessante acontece se substituirmos o valor inicial da variável `numero` por outro, como por exemplo `4`. Agora o resultado é `6`, ou seja, `4 + 2`.

Caso a leitura do `scanf` falhar, a variável `numero` não é alterada. Com essa informação já poderíamos pensar em validar a entrada do usuário: se o valor inicial continuar o mesmo, então peça outra entrada para o usuário. Mas existe um jeito ainda melhor de fazer a verificação.

Até agora, ignoramos o **valor de retorno** da função `scanf`. Esse valor é do tipo `int` e indica o número de **leituras bem-sucedidas**, isso é, o **total de variáveis que foram alteradas** pela função.

Vamos ver esse valor no código a seguir:

``` c
printf("Digite um número, por favor: ");
int resultado = scanf("%d", &numero);

printf("Resultado do scanf: %d", resultado);
```

Se o usuário digitar um número inteiro, o `resultado` vale `1`, caso contrário, o `resultado` vale `0`. Com essa informação, podemos usar de um **retorno antecipado** para sair da função `main`, caso o usuário não tenha digitado um número:

``` c
int main(void)
{
    int numero = 0;

    printf("Digite um número, por favor: ");
    int resultado = scanf("%d", &numero);

    if (resultado != 1)
    {
        printf("Digite um número da próxima vez!\n");
        return 1;
    }

    printf("O seu número mais 2 vale %d.\n", numero + 2);

    return 0;
}
```

---

Ao invés de sair do programa, podemos utilizar de um `while` *loop* para ler um número novamente.

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

Por exemplo, se você digitar a letra `A` e depois `Enter`, o buffer de entrada vai ficar parecido com isso: \[`A`, `\n`\], como uma **fila de espera**, aguardando ser lida. O papel da função `scanf` é ler esse buffer até encontrar um `\n`. Quando isso acontece, essa parte do buffer é convertida para o formatador. Caso a conversão dê certo o buffer de entrada é esvaziado, mas se der errado, o buffer **não é esvaziado**, isso é, **ele continua o mesmo**.

No código acima, caso digitemos `A` e `Enter`, o `scanf` funcionaria assim:

1. Vai ler o buffer até o `\n`;
2. Erro! O valor `A` não é um inteiro, nenhuma conversão foi um sucesso, retorna `0`;
3. A mensagem avisando o erro ao usuário é exibida;
4. O buffer ainda possui o `A`, a conversão falha e a mensagem é exibida;

Para limpar esse buffer, vamos usar a função `getchar`, declarada no header `stdio`. Essa função navega pelo buffer de entrada e limpa um caractere de cada vez. Seu valor de retorno é justamente esse caractere que acabou de ser limpo.

Portanto, **enquanto** o valor de retorno do `getchar` for diferente de `\n`, o buffer ainda precisa ser limpo:

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

A última versão do código usando o `getchar` junto ao `while` *loop* para validar a entrada do usuário é funcional, mas apresenta problemas em sua construção. Vamos tentar usar uma estratégia similar para limitar a entrada do usuário entre 0 e 10, para valores de notas, por exemplo.

Para tal, vamos juntar os possíveis erros de entrada em **uma única linha**, usando o operador lógico **OU**. Caso **qualquer uma das condições** seja verdadeira, o `while` *loop* vai continuar.

> Usamos o `%lf` porque a variável `nota` é do tipo `double`. Pode ser lido como **l**ong **f**loat, do inglês "float longo". Se nota fosse `float` usaríamos `%f`.

``` c
double nota;
printf("Digite uma nota: ");

while (scanf("%lf", &nota) != 1 || nota < 0.0 || nota > 10.0)
{
	while (getchar() != '\n')
	{
	}

	printf("Digite novamente: ");
}

printf("Parabéns por tirar %g!\n", nota);
```

> É importante salientar que a **ordem das condições** importa! Em C elas são lidas da esquerda para a direita.

Você concorda que adicionar essa simples checagem já deixou o código mais confuso? Temos que usar vários **OU**s juntos, o que dificulta a leitura. Caso seja preciso adicionar mensagens de erros mais claras, como "Digite um número maior que 0" se `numero` for menor que `0`, teríamos que verificar a condição novamente.

Para resolver esse problema vamos usar outra estrutura de repetição, o **`do while`**. Primeiro vou mostrar a substituição do `while` pelo `do while`, **sem o limite de 0 a 10**:

> Não se esqueça de importar o *header* `stdbool.h`

``` c
printf("Digite uma nota: ");

double nota = 0.0;
bool leitura_valida = false;
do
{
	int resultado = scanf("%lf", &nota);
	if (resultado != 1)
	{
		while (getchar() != '\n')
		{
		}

		printf("Digite um número real: ");
	}
    else
    {
        leitura_valida = true;
    }
} while (!leitura_valida);

printf("Parabéns por tirar %g!\n", nota);
```

Com o `do while(!leitura_valida)`, a validação da entrada do usuário se dá através da *flag* booleana chamada `leitura_valida`. Essa *flag* é uma variável do tipo booleana que começa como `false` e só se torna `true` quando o `scanf` lê um número real com sucesso, momento em que o laço para.

Você pode estar pensando que o código ficou maior, e é verdade. A troca é intencional: ganhamos clareza na estrutura em troca de algumas linhas a mais. Conforme o código crescer, com verificações de intervalo e mensagens de erro específicas, essa clareza vai compensar.
Veja como adicionar o limite entre 0 e 10 ficou mais fácil.

``` c
const double min = 0.0;
const double max = 10.0;

printf("Digite uma nota: ");

double nota = 0.0;
bool leitura_valida = false;
do
{
	int resultado = scanf("%lf", &nota);

	if (resultado != 1)
	{
		while (getchar() != '\n')
		{
		}

		printf("Digite um número real: ");
	}
    else if (nota < min)
	{
		printf("Digite um número maior que %g: ", min);
	}
    else if (nota > max)
	{
		printf("Digite um número menor que %g: ", max);
	}
    else
    {
        leitura_valida = true;
    }
} while (!leitura_valida);

printf("Parabéns por tirar %g!\n", nota);
```

### Retomando o exemplo da senha

Por fim, vamos analisar o nosso primeiro exemplo do uso do `while` e ver como o `do while` é a estrutura de repetição ideal para **leitura de dados**.
Retomando:

``` c
const int senha = 1234;
int tentativa = 0;

while (tentativa != senha)
{
    // ...
}
```

Precisamos criar a variável `tentativa` com o valor `0` apenas para garantir que a condição `0 != 1234` fosse verdadeira e o *loop* **pudesse começar**.

Mas e se a senha real do sistema fosse exatamente `0`? Como o valor inicial da tentativa seria igual à senha, a condição `0 != 0` seria falsa.
O programa simplesmente pularia o *loop* inteiro e diria que a senha está correta sem o usuário ter digitado absolutamente nada!
Poderíamos usar outro valor, como `1` e o programa passaria a funcionar, mas vamos por outro caminho.

O `while` segue a seguinte lógica: "**verificar, depois fazer**", ou seja, ele vai verificar se `tentativa != senha` para aí começar o *loop*.
Mas como estamos lendo uma entrada do usuário, não temos **nada para verificar** no começo do *loop*, é apenas **dentro dele** que a entrada é armazenada na variável `tentativa`.

O `do while` surge como uma forma de **inverter a lógica do while**, ou seja "**fazer, depois verificar**".
O código final fica assim:

> Note que a variável `resultado` foi renomeada para `r`, por simplicidade apenas.

``` c
const int senha = 1234;

int tentativa;
bool leitura_valida = false;
do
{
	printf("Digite a senha de 4 dígitos: ");
	int r = scanf("%d", &tentativa);

	if (r != 1)
	{
		while (getchar() != '\n')
		{
		}

		printf("Você não digitou um inteiro!\n");
	}
    else if (tentativa != senha)
	{
		printf("Você digitou a senha errada!\n");
	}
    else
    {
        leitura_valida = true;
    }
} while (!leitura_valida);

printf("A senha está correta!\n");
```
