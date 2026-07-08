# Variáveis I

> São usadas para **armazenar** valores.

Para entendermos as variáveis em C, primeiro precisamos destrinchar a frase: "O computador só entende 0 e 1". Essa frase diferencia o modo com que os humanos e as máquinas interpretam informações. Enquanto nós temos uma consciência, a máquina está limitada a lidar com níveis baixos e altos de voltagem para representar informações, 0 e 1 respectivamente.

Entender que no final das contas toda a informação que passa pelo computador é representada na forma de 0 e 1 explica o por quê precisamos declarar o tipo das variáveis.

Tomamos o binário `0011 0101` como exemplo. Quando o computador olha para o binário, ele não tem a menor ideia do que ele significa.
Para a máquina, a sequência `0011 0101` é apenas um dado bruto. No entanto, se nos mandarmos o computador interpretar isso como um número inteiro, o valor é 53.

É por isso que demos que deixar claro para o computador como a informação deve ser processada a partir dos **tipos**.

## Declaração

Declarar a variável nada mais é do que mostrar para o computador como um número binário deve ser chamado (nome) e como teve ser interpretado (tipo).

Em C, usamos:

``` c
int numero;
```

O `int` mostra ao computador que o valor armazenado na variável de nome `numero` é do tipo inteiro.

Note que o código a seguir também é válido:

``` c
int palavra;
```

O nome da variável mudou de `numero` para `palavra`, mas o seu tipo continua sendo `int`. O computador não consegue inferir essa mudança semântica do nome.

## Atribuição

Para **alterar o valor** de um variável usamos do `=`.
A seguir nos **inicializamos** a variável `numero` com o valor `10`:

``` c
int numero = 10;
```

**Depois que declaramos** uma variável, podemos mudar o seu valor novamente, fazendo:

``` c
numero = 2;
```

O valor da variável `numero` deixa de ser `10` e passa a ser `2`.

## Tipos Primitivos

São os tipos de variáveis que são definidas por padrão pela linguagem.

Nesse módulo, veremos esses tipos **sem muitos detalhes**. No entanto, no módulo [Memória 1](../memoria/um.md), veremos como o computador interpreta esses valores de verdade.

### int

Representa um número inteiro, como `-1`, `-3`, `0` e `1`.

``` c
int idade = 18;
```

Para exibirmos o valor da variável `idade`, usaremos a função `printf`, declarada em `<stdio.h>`.

A função `printf` pode receber mais de um argumento, separados por ",". O primeiro já sabemos que é um texto, mas os outros podem ser variáveis de qualquer tipo primitivo e são usados para imprimir os valores das variáveis no terminal.

No código abaixo imprimimos o valor da variável `idade`:

``` c
#include <stdio.h>

int main()
{
    int idade = 18;

    printf("Idade: %d\n", idade);

    return 0;
}
```

Esse `%` é o padrão adotado pela função `printf` para lidar com os diferentes tipos de variáveis que podem ser exibidas. Ele indica que o valor a ser imprimido vem de uma variável de um tipo específico.
O carácter ao lado do `%` representa o tipo da variável que será imprimida. Nesse caso, usamos o `d` para indicar que estamos passando uma variável do tipo `int`.

#### Operações

Nos também podemos fazer **operações aritméticas** entre variáveis e números. São elas:

- **Soma**: `int resultado = 20 + 10`
- **Subtração**: `int resultado = 1 - 10`
- **Multiplicação**: `int resultado = 5 * 20`
- **Divisão**: `int resultado = 8 / 2`
- **Módulo**, dá o resultado do **resto da divisão**: `int resto_1 = 9 % 2`

Nos também usamos parênteses `( )` para indicar a ordem de importância das operações.

### float / double

Tanto o `float` quanto o `double` representam números reais, aqueles com casas depois da vírgula.

O tipo `float` usa menos bits representar um número real, e por isso apresentam menor precisão.

```c
float media_f = 6.72;
```

Já o `double` apresenta uma maior precisão, por usar mais bits.

```c
double media_d = 3.2;
```

#### Printf

Para imprimir o valor da média, vamos usar o `%f` em ambos:

> Declare a função main e importe o *header* `stdio`.

``` c
printf("Média Float: %f", media_f);
printf("Média Double: %f", media_d);
```

O `printf` interpreta o `float` e `double` como reais em sua implementação interna, por isso utilizamos do mesmo símbolo `f` para ambos. Rode o comando e veja o resultado: ele é seguido por um monte de zeros!

Dependendo do tipo da variável que passamos para o `printf` nos podemos mudar como o valor será exibido. Por exemplo, para exibirmos apenas duas casas depois da vírgula, usamos:

``` c
printf("Média: %.2f", media_f);
```

Até podemos arrendondar o número com:

``` c
printf("Média: %.0f", media_d);
```

Também existem outros formatadores para `float` e `double`. Caso você queira ignorar os zeros desnecessários (que ficam a esquerda do número), use o `%g`. Esse formatador apenas mostrará o mínimo possível; se o valor for `15.00`, usando o `%g`, será exibido apenas `15`.

#### Qual tipo usar: float ou double?

Se você estiver trabalhando em um projeto para computadores modernos (64 bits), prefira o `double`, já que ele apresenta uma maior precisão por um custo desprezível de performance.

### char

Representa um único carácter, como uma letra do alfabeto ou um sinal de pontuação.

``` c
char caracter = 'a';
```

Ao invés de usarmos aspas duplas, usamos as aspas simples, mas por quê? Veremos isso com mais detalhes em [Strings](../variaveis/string.md), mas já pincelando, a linguagem C diferencia um único carácter de um texto - conjunto de caracteres - com o uso das aspas simples.

Tá lembrado no começo do capítulo, quando discutimos como o binário `0011 0101` (ou 53 em decimal) pode ser interpretado de formas diferentes? Agora veremos na prática com o código a seguir:

``` c
char cinco = '5';

printf("Carácter: %c\n", cinco);

printf("Índice:   %d\n", cinco);
```

Primeiro, declaramos uma variável do tipo `char` chamada `cinco`. Depois, usamos o `%c` para imprimir o carácter no terminal. Mas fazemos algo esquisito em seguida: imprimimos a variável `cinco` como um `int`?! Por que o código funciona, e por que ele exibe 53?

Isso se deve ao modo como os carácteres funcionam em C. Por debaixo dos panos, o tipo `char` é um número binário de 1 byte, que é **traduzido para um carácter** por meio da [Tabela de Conversão ASCII](https://www.ime.usp.br/~kellyrb/mac2166_2015/tabela_ascii.html) apenas no momento em que será exibido.

> O valor de 1 byte na **esmagadora maioria** dos dispositivos é 8 bits.

Se você abrir essa tabela, notará duas coisas: o *código ASCII* do carácter `5` é 53; e que não existem carácteres acentuados. Isso se deve ao fato da Tabela ASCII ter sido criada pra a língua inglesa, por isso eles não colocaram acentos nela. Isso explica o por quê os acentos podem estar meio esquisitos quando exibidos.

### bool

Os valores booleanos são aqueles que podem ser ou **verdadeiro** (1) ou **falso** (0), mas nunca os dois ao mesmo tempo. São usados principalmente para estabelecer condições.

``` c
#include <stdbool.h>

bool estou_feliz = false;
```

Diferente dos outros tipos primitivos, para declararmos uma variável booleana, precisamos primeiro importar sua definição na Biblioteca Padrão, com o `#include <stdbool.h>`.
O motivo disso ficará claro em [Condicionais](../condicional/README.md)

Nós também não temos como imprimir um `bool` do mesmo jeito temos fazendo. Isso se deve ao fato da função `printf` não definir em sua implementação uma maneira de converter o `bool` para uma string, ou seja, não definir um código como `d` para tal. Mas nós veremos em [Condicionais](../condicional/README.md) um jeito de fazer isso.

Chamamos os estados **verdadeiro** e **falso** de `true` e `false`, respectivamente.

## Regras de Nomenclatura

Essas regras são válidas para todos **identificadores** da linguagem C, não somente para variáveis.

- São permitidos os seguintes caracteres: letras (minúsculas e maiúsculas), dígitos (de 0 a 9) e o sublinhado (`_`), também chamado de *underline*.
- Não é permitido começar com um dígito.
- Não é permitido ter acento
- A linguagem C diferencia letras minúsculas das maiúsculas. Por exemplo, as variáveis `Vida`, `vida` e `VIDA` como coisas diferentes.
- Você não pode usar nomes de comandos internos da linguagem. Palavras como `int`, `double`, `return`, `if`, `while` e `char` são proibidas de serem usadas como nomes de variáveis ou funções.

## Constantes

São valores que, ao serem declarados, não podem mudar de valor.

Por exemplo, vamos declarar o valor aproximado da constante `pi`.

> Não se esqueça de importar `#include <stdio.h>` e declarar a função `main`!

``` c
const double pi = 3.14;

printf("Pi vale aproximadamente %f\n", pi);
```

Se tentarmos alterar o valor de `pi` após sua declaração, teremos um erro na compilação:

``` c
const double pi = 3.14;

pi = 3.14159;

printf("Pi vale aproximadamente %f\n", pi);
```

Usamos variáveis constantes para dar um **nome compreensível**, evitando o uso de comentários. Além disso, se amanhã nos precisarmos aumentar a precisão da constante `pi`, isso é, aumentar o número de casas depois da vírgula, nos só precisamos alterar em **um lugar** - se não usássemos constantes, teríamos que procurar cada caso com o valor `3.14` e trocá-lo.

### Boas práticas

Evite nomes misteriosos para as suas variáveis. Em vez de `int p;`, use `int pontuacao;`. O nome da variável deve transmitir parte da sua função dentro do código.

Evite o encurtamento dos nomes, como escrever `int v_final;` ao invés de `int valor_final;`. Quando você nomeia bem o seu código, mesmo que demore um pouco mais para digitar, daqui a um mês, quando precisar mudar o código de novo, os nomes mais claros te ajudaram a relembrar a lógica do código. Por isso, não se prenda a regra de apenas 8 caracteres!

Ao longo do guia, veremos ainda mais casos de como melhorar a sua nomenclatura. Enquanto estava aprendendo a programar, achava difícil pensar em bons nomes para as coisas. Se você se sente assim, recomendo utilizar Inteligência Artificial para ter ideias de como nomear.

Sempre que declarar uma variável, é recomendado que você inicialize ela com um valor padrão. Como `0` ou `1` para o tipo `int`. Escreva esse programa e **rode ele mais de uma vez**:

``` c
#include <stdio.h>

int main(void)
{
    int numero;

    printf("número = %d\n", numero);
    return 0;
}
```

Você verá que a variável `numero` armazena valores aleatórios. O motivo disso ficará claro em [Ponteiros](../ponteiros/README.md), por ora, sempre inicialize suas variáveis para evitar usar valores aleatórios acidentalmente.
