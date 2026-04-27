# Variáveis Primitivas

Para entendermos as variáveis em C, primeiro precisamos destrinchar a frase: "O computador só entende 0 e 1". Essa frase diferencia o modo com que os humanos e as máquinas interpretam informações. Enquanto nós temos uma consciência, a máquina está limitada a lidar com níveis baixos e altos de voltagem para representar informações, 0 e 1 respectivamente.

Pode parecer loucura ir tão fundo só para entender o que é uma variável, mas entender que no final das contas toda a informação que passa pelo computador é representada na forma de 0 e 1 explica o porque precisamos declarar o tipo das variáveis.

Tomamos o binário `0011 0101` como exemplo, se o computador olhar apenas para esse binário, ele não tem a menor ideia do que ele significa.
Para a máquina, a sequência 0011 0101 é apenas um dado bruto. No entanto:

- Se o computador interpretar isso como um número inteiro, o valor é 53.

- Mas, se ele interpretar isso usando algum tipo de lógica de conversão, como por exemplo usando uma tabela que mapeia números para caracteres, o valor pode mudar. Por exemplo, se ele usar o binário `0011 0101` (ou o número 53 em decimal) como um índice na Tabela de Conversão ASCII, o binário passa a representar o carácter '5'.

Mas como o computador sabe como interpretar um binário? É exatamente aí que entra a necessidade de declarar o tipo da variável na linguagem C.

## Declaração

Declarar o tipo da variável nada mais é do que mostrar para o computador como um binário deve ser chamado (nome) e como teve ser interpretado (tipo). Vejamos um exemplo:

No *Flávia Script* usamos da seguinte sintaxe para declarar uma variável chamada numero do tipo inteiro:

```
var numero: inteiro;
```

Já em C, usamos:

```c
int numero;
```

Esse `int` mostra para o computador que o valor armazenado na variável de nome `numero` é do tipo inteiro.

Note que o código a seguir também é válido:

```c
int palavra;
```

O nome da variável mudou de `numero` para `palavra`, mas o seu tipo continua sendo `int`. O computador não consegue inferir essa mudança semântica do nome, por isso pense bem nos nomes de suas variáveis.

## Atribuição

No *Flávia Script*, para mudarmos o valor de uma variável, usamos da seguinte notação para dizer que uma variável inteira chamada `numero` recebe 10 `numero <- 10;`.

Em C usamos outra sintaxe:

```c
int numero = 10;
```

O símbolo de "=" é traduzido para "->".

## Tipos Primitivos

São os tipos de variáveis que são definidas pela linguagem por padrão
São alguns tipos:

### Inteiro

```c
int idade = 18;
```

Ainda não vimos que a função `printf` declarada em `stdio.h` pode receber mais de um argumento, separados por ",". O primeiro já sabemos que é uma string, mas os outros podem ser variáveis de qualquer tipo primitivo e são usados para imprimir os valores das variáveis.

Por exemplo, no código abaixo estamos imprimindo uma idade:

```c
#include <stdio.h>

int main()
{
    int idade = 18;

    printf("Idade: %d\n", idade);

    return 0;
}
```

Esse `%` é o padrão adotado pelas funções `printf` e `scanf` para lidar com os diferentes tipos de variáveis que podem ser exibidas e lidas. Ele indica que o valor a ser imprimido vem de uma variável. Como no caso não existe nenhum `%` antes desse `%d`, o `%d` irá substituir o valor da primeira variável passada como argumento. O `d` cria uma promessa para a função `printf` que a primeira variável dos argumentos será do tipo inteiro.

### Real

Para a representação de valores reais em binário, a linguagem C utiliza do padrão IEEE 754.

Esse padrão divide um binário em três partes, são elas:
- Sinal, 0 para positivo e 1 para negativo;
- Expoente;
- Mantissa;

#### Single Point Precision

São usados 32 bits para armazenar o valor do número real.
Em C esse tipo é chamado de `float`.

```c
float media_f = 6.72;
```

Note que usamos o ponto ao invés da vírgula para separar as casas decimais.

#### Double Point Precision

Ao invés de 32 bits, são usados 64 bits.
Em C esse tipo é chamado de `double`.

```c
double media_d = 3.2;
```

#### Printf

Para imprimir o valor da média, vamos usar do `%f` em ambos:

```c
// Esse "barra barra" é um comentário. Ele é ignorado pelo compilador.
// Vou pular a declaração do main e o #include, mas você precisa colocar!
printf("Média Float: %f", media_f);
printf("Média Double: %f", media_d);
```

O `printf` interpreta o `float` e `double` como reais em sua implementação interna, por isso utilizamos do mesmo símbolo `f` para ambos. Rode o comando e veja o resultado, ele é seguido por um monte de zeros!

Dependendo do tipo da variável que passamos para o `printf` nos podemos formatar como o valor será exibido. Por exemplo, para exibirmos apenas duas casas depois da vírgula:

```c
printf("Média: %.2f", media_f);
```

Até podemos colocar nenhuma, se quisermos, com:

```c
printf("Média: %.0f", media_d);
```

#### Qual tipo usar?

Se você estiver trabalhando em um projeto para computadores modernos, prefira o `double`, já que ele apresenta uma maior precisão por um custo baixo.

### Carácter

...


### Boolean

...

