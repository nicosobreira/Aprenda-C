# Variáveis I

Para entendermos as variáveis em C, primeiro precisamos destrinchar a frase: "O computador só entende 0 e 1". Essa frase diferencia o modo com que os humanos e as máquinas interpretam informações. Enquanto nós temos uma consciência, a máquina está limitada a lidar com níveis baixos e altos de voltagem para representar informações, 0 e 1 respectivamente.

Entender que no final das contas toda a informação que passa pelo computador é representada na forma de 0 e 1 explica o porque precisamos declarar o tipo das variáveis.

Tomamos o binário `0011 0101` como exemplo, se o computador olhar apenas para esse binário, ele não tem a menor ideia do que ele significa.
Para a máquina, a sequência 0011 0101 é apenas um dado bruto. No entanto:

- Se o computador interpretar isso como um número inteiro, o valor é 53.

- Mas, se ele interpretar isso usando algum tipo de lógica de conversão, como por exemplo usando uma tabela que mapeia números para caracteres, o valor pode mudar. Por exemplo, se o computador usar o binário `0011 0101` (ou o número 53 em decimal) como um índice na Tabela de Conversão ASCII, o binário passa a representar o carácter '5'. (Não se preocupe se não tenha entendido, mais para frente iremos voltar nesse exemplo)

Mas como o computador sabe como interpretar o binário de tal maneira? É exatamente aí que entra a necessidade de declarar o tipo da variável na linguagem C.

## Declaração

Declarar o tipo da variável nada mais é do que mostrar para o computador como um binário deve ser chamado (nome) e como teve ser interpretado (tipo).

No *Flávia Script* usamos da seguinte sintaxe para declarar uma variável chamada numero do tipo inteiro:

```
var numero: inteiro;
```

Já em C, usamos:

``` c
int numero;
```

Esse `int` mostra para o computador que o valor armazenado na variável de nome `numero` é do tipo inteiro.

Note que o código a seguir também é válido:

``` c
int palavra;
```

O nome da variável mudou de `numero` para `palavra`, mas o seu tipo continua sendo `int`. O computador não consegue inferir essa mudança semântica do nome, por isso pense bem nos nomes de suas variáveis.

## Atribuição

No *Flávia Script*, para mudarmos o valor de uma variável, usamos da seguinte notação para dizer que uma variável inteira chamada `numero` recebe uma copia de 10: `numero <- 10;`.

Em C usamos outra sintaxe:

``` c
int numero = 10;
```

Depois que declaramos uma variável, podemos mudar o seu valor novamente, fazendo:

``` c
numero = 2;
```

Em [Variáveis II](./variaveis-2.md), veremos quando não é possível mudar o valor de uma variável já declarada.

## Tipos Primitivos

São os tipos de variáveis que são definidas por padrão pela linguagem.

### int

Representa um número inteiro.

``` c
int idade = 18;
```

Para exibirmos o valor da variável `idade`, usaremos a função `printf`, declarada em `stdio.h`.
A função `printf` pode receber mais de um argumento, separados por ",". O primeiro já sabemos que é uma string, mas os outros podem ser variáveis de qualquer tipo primitivo e são usados para imprimir os valores das variáveis no terminal.

Por exemplo, no código abaixo estamos imprimindo o valor da variável `idade` do tipo inteiro:

``` c
#include <stdio.h>

int main()
{
    int idade = 18;

    printf("Idade: %d\n", idade);

    return 0;
}
```

Esse `%` é o padrão adotado pelas funções `printf` e `scanf` para lidar com os diferentes tipos de variáveis que podem ser exibidas e lidas. Ele indica que o valor a ser imprimido vem de uma variável.
O `d` cria uma promessa do tipo da variável que será imprimida. Nesse caso, usamos o `d` para indicar que estamos passando uma variável do tipo `int`.

### float / double

Tanto o `float` quanto o `double` representam números reais. Ambos utilizam do padrão IEEE 754 para a representação em binário.

Esse padrão divide um binário com 32 ou 64 bits em três partes, são elas:
- Sinal, 0 para positivo e 1 para negativo.
- Expoente, expoente da notação científica.
- Mantissa, valor em notação científica.

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

Para imprimir o valor da média, vamos usar o `%f` em ambos:

``` c
// Esse "barra barra" é um comentário. Ele é ignorado pelo compilador.
// Vou pular a declaração do main e o #include, mas você precisa colocar!
printf("Média Float: %f", media_f);
printf("Média Double: %f", media_d);
```

O `printf` interpreta o `float` e `double` como reais em sua implementação interna, por isso utilizamos do mesmo símbolo `f` para ambos. Rode o comando e veja o resultado: ele é seguido por um monte de zeros!

Dependendo do tipo da variável que passamos para o `printf` nos podemos formatar como o valor será exibido. Por exemplo, para exibirmos apenas duas casas depois da vírgula, usamos:

``` c
printf("Média: %.2f", media_f);
```

Até podemos colocar sem vírgula com:

``` c
printf("Média: %.0f", media_d);
```

#### Qual tipo usar?

Se você estiver trabalhando em um projeto para computadores modernos (64 bits), prefira o `double`, já que ele apresenta uma maior precisão por um custo desprezível de performance.

### char

Representa um único carácter, como uma letra do alfabeto ou uma pontuação.

``` c
char caracter = 'a';
```

Ao invés de usarmos aspas duplas, usamos as aspas simples, mas por quê? Veremos isso com mais detalhes em [Strings](../variaveis/string.md), mas já pincelando, a linguagem C diferencia um único carácter de uma string com o uso das aspas simples.

Tá lembrado no começo do capítulo, quando discutimos como o binário `0011 0101` (ou 53 em decimal) pode ser interpretado de formas diferentes? Agora veremos na prática com o código a seguir:

``` c
char cinco = '5';

printf("Carácter: %c\n", cinco);

printf("Índice:   %d\n", cinco);
```

Primeiro, declaramos um carácter em uma variável chamada `cinco`. Depois, usamos o `%c` para imprimir o carácter no terminal. Mas fazemos algo esquisito depois: imprimimos a variável `cinco` como um `int`?! Por que o código funciona, e por que ele exibe 53?

Isso se deve ao modo como os carácteres funcionam em C. Por debaixo dos panos, o tipo `char` é um número binário de 8 bits, que é traduzido para um carácter por meio da [Tabela de Conversão ASCII](https://www.ime.usp.br/~kellyrb/mac2166_2015/tabela_ascii.html) apenas no momento em que será exibido.

Se você abrir essa tabela, notará duas coisas: o *código ASCII* do carácter '5' é 53; e que não existem carácteres acentuados. Isso se deve ao fato da Tabela ASCII ter sido criada pra a língua inglesa, por isso eles não colocaram acentos nela. Isso explica o porque os acentos podem estar meio esquisitos quando exibidos.

### bool

Os valores booleanos são aqueles que podem ser ou **verdadeiro** (1) ou **falso** (0), mas nunca os dois ao mesmo tempo. São usados principalmente para estabelecer condições.

``` c
#include <stdbool.h>

bool estou_feliz = false;
```

Diferente dos outros tipos primitivos, para declararmos uma variável booleana, precisamos primeiro importar sua definição na Biblioteca Padrão, com o `#include <stdbool.h>`.
O motivo de precisarmos usar um `include` para usar esse tipo ficará claro em [Condicionais](../condicional/README.md)

Nós também não temos como imprimir um `bool` do mesmo jeito temos fazendo. Isso se deve ao fato da função `printf` não definir em sua implementação uma maneira de converter o `bool` para uma string, ou seja, não definir um código como `d` para tal. Mas nós veremos em [Condicionais](../condicional/README.md) um jeito de fazer isso.

Chamamos os estados **verdadeiro** e **falso** de `true` e `false`, respectivamente.

