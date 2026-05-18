# Estruturas de Repetição

São usadas para **repetir** partes do código, baseado em uma condição.

Antes de aprendermos as estruturas de repetição em si, vamos ver como o usuário pode digitar informações para o programa.

## scanf I

Primeiro mostrarei o código para isso, depois vamos analizá-lo.

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
Diferente do que vinhamos fazendo, nos não colocamos o `\n` no final da string, mas sim um espaço. Isso é porque queremos mover o cursor do usuário à frente do dois pontos. Faça as seguintes modificações no código, e veja o que acontece:

- Retire esse espaço final, e veja a saída;
- Depois, coloque um `\n` no final da mensagem;
- E por último, remova a mensagem completamente.

## while

Para aprendermos a estrutura de repetição *while* (do inglês "enquanto"), vamos criar um programa que pergunte pela senha para proseguir. **Enquanto** a senha que o usuário digitar for diferente da senha correta, o programa vai continuar perguntando por uma nova senha. No entanto, no momento em que as senhas forem iguais, o programa ira sair do *loop* e ira continuar.

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

> Saiba que se você precionar a tecla "CTRL" junto a tecla "c" você sairá forçadamente do programa .

Agora, remova a linha `scanf("%d", &tentativa);` do código, e rode o programa para ver o que acontece. O programa compila, mas nunca para!

### Loop infinito

O motivo desse erro está na verificação da condição `tentativa != senha`.
A estrutura de repetição *while* verifica se a condição é verdadeira no **começo** de cada *loop* e ao **final** dele, após a execução de todo o código entre chaves. Primeiro, o *while* vai verificar se o valor inicial da variável `tentativa` é diferente do valor da variável `senha`, ou seja, `0 != 1234`, o que é verdade. Dessa forma, se inicia o *loop*. Como retiramos a linha do `scanf`, ao final do *loop* o valor da variável `tentativa` não mudou, e por isso continua sendo `0`. Portanto, na próxima vez que o *while* verificar a condição, teremos que `0 != 1234`, e assim por diante.

Esse erro é chamado de **loop infinito**, e é causado quando nossa condição sempre é verdadeira.

## for

Para entendermos o por quê da estrutura de repetição *for* existir, vamos criar um contador de 1 até 10 usando o *while*.

> A condição do contador está errada! Vamos ver como arrumar logo em seguida.

``` c
int indice = 1;
while (indice != 10)
{
	printf("Índice atual: %d\n", indice);

	indice++;
}
```

Antes de corrigirmos o erro do contador, vamos ver quais são suas partes:

1. **Inicialização** antes do *while loop*. É a declaração da variável `indice` com o **valor inicial** de `1`.
2. **Condição** dentro do *while*. É quando comparamos o valor atual da variável `indice` com `10`.
3. **Atualização** ao final do *while*. Usamos da sintaxe `indice++` para indicar que estamos incrementando a variável `indice` por um. Essa parte é essêncial para impedir um **loop infinito**.

O contador só vai até nove! Para entendermos o por quê disso, vamos verificar o resultado da condição `indice != 10` para todos os valores de `indice`, até que a condição se torne falsa. Lembre-se de que o `printf` só ira mostrar o indice atual se a condição for verdaderia, caso contrário, nada será imprimido no terminal.

| indice | indice != 10 |
| :-:    | :-           |
| 1      | Verdadeiro   |
| 2      | Verdadeiro   |
| 3      | Verdadeiro   |
| ...    | ...          |
| 8      | Verdadeiro   |
| 9      | Verdadeiro   |
| **10** | **Falso**    |

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

Agora, vamos ver um jeito mais simples de escrever essa mesma lógica, usando um *for loop*. Essa estrutura de repetição junta a  **inicialização**, a **condição** e o **incremento** em uma única linha, facilitando a leitura e eliminando erros como esquecer de incrementar ao final do *loop*. O mesmo programa acima pode ser escrito nesse novo formato:

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
        printf("%d x %d = %d", numero, indice, resultado);
        printf("\n");
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

Nos vimos que esse código lê um número inteiro do usuário. Mas o que acontece se o usuário acidentalmente digitar um número real ou uma letra?

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

Se o usuário digitar um número inteiro, o `resultado` vale `0`, caso contrário, o `resultado` vale `1`. Com essa informação, podemos usar de um **retorno antecipado** para sair da função `main`, caso o usuário não tenha digitado um número:

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

A primeira vista, esse código deve funcionar. Digite valores válidos e inválidos, e veja o que acontece.

Se não digitarmos um número inteiro, caímos em um **loop infinito**. Para entendermos esse erro, vamos ver como a entrada do usuário entra para a função `scanf`.

### Buffer de entrada

TODO: explicar o que é um buffer de entrada.

## do while

TODO: Exemplo final

``` c
#include <stdbool.h>
#include <stdio.h>

// 1. Fazer a leitura dentro do main para uma nota
// 2. Criar uma função que leia entre min e max para uma nota
// 3. Explicar porque se deve criar uma nova função
// 4. Refatorar o código

double leia_double(void);
double leia_double_entre(double min, double max);

int main(void)
{
    const double nota_minima = 0;
    const double nota_maxima = 10;

    printf("Digite a nota do aluno: ");
    double nota = leia_double_entre(nota_minima, nota_maxima);

    printf("A nota é: %g", nota);
    return 0;
}

double leia_double(void)
{
    do
    {
        double numero = 0;
        int falhas = scanf("%lf", &numero);

        // A função `scanf` retorna o número de leituras bem sucedidas.
        // Como estamos lendo apenas um único valor, o esperado é 1.
        printf("Falha: %d", falhas);
        if (falhas != 1)
        {
            printf("Digite um número: ");

            double c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }

            continue;
        }

        return numero;
    } while (true);
}

double leia_double_entre(double min, double max)
{
    do
    {
        double numero = leia_double();

        if (numero < min)
        {
            printf("Digite um número maior que %g: ", min);
        }
        else if (numero > max)
        {
            printf("Digite um número menor que %g: ", max);
        }
        else
        {
            return numero;
        }
    } while (true);
}
```
