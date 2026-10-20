<p align="center">
  <a href="./linguagem-c.md">← O que é C?</a>
  &nbsp;|&nbsp;
  <a href="../exercicios/variaveis.md">Exercícios: Variáveis →</a>
</p>

---

# Variáveis

As variáveis servem para **armazenar** valores na **memória do computador**. Elas nos permitem guardar informações bem diferentes, como: idade de uma pessoa, preço de um produto e se um usuário está logado ou não.
O primeiro é um número inteiro, o outro tem casas depois da vírgula, e o último só pode ser verdadeiro ou falso.
Lembra que em [O que é C?](./linguagem-c.md) vimos que o computador só lida com zeros e uns? Mas como o computador guarda dados tão diferentes entre si, se ele só entende 0 e 1?

A verdade é que o computador interpreta os zeros e uns da maneira que nós, programadores, mandamos. Tomamos o número binário `0100 0011` como exemplo. Quando o computador olha para o binário, ele não tem a menor ideia do que ele significa.
Para a máquina, a sequência `0100 0011` é apenas um dado bruto. No entanto, se nós mandarmos o computador interpretar isso como um número inteiro, o valor é 67. Ao final do módulo, veremos que esse mesmo binário representa um outro tipo de informação: uma letra.

## Declaração

Declarar a variável nada mais é do que mostrar para o computador como um número binário deve ser chamado (nome) e como teve ser interpretado (tipo).

Para declarar uma variável em C, escrevemos:

``` c
    int numero;
```

Dentro da função `main` fica assim:

``` c
int main(void)
{
    int numero;

    return 0;
}
```

O `int` mostra ao computador que o valor armazenado na variável de nome `numero` é do tipo **inteiro**.

Ao longo do módulo, veremos ainda mais tipos, alguns deles são:

- **Letra**:
``` c
char letra
```

- **Número real** (com casas depois da vírgula):
``` c
double real;
```

## Atribuição

Para **alterar o valor** de um variável usamos do igual (`=`).
A seguir nós **inicializamos** a variável `numero` com o valor `10`:

``` c
int numero = 10;
```

**Depois que declaramos** uma variável, alteramos o seu valor novamente sem usar falar o tipo da variável, como no código a seguir, que cria uma variável `idade` - com valor inicial de 18 - e muda para 10.

``` c
int main(void)
{
    int idade = 18;

    idade = 10;

    return 0;
}
```

## Tipos Primitivos

São os tipos de variáveis que são definidas por padrão pela linguagem.

Nesse módulo, veremos esses tipos **sem muitos detalhes**. No entanto, no módulo [Memória I](./memoria-1.md), veremos como o computador interpreta esses valores de verdade.

### int

Representa um número inteiro, como `-1`, `-3`, `0` e `1`.

```c
int idade = 18;
```

Para exibirmos o valor da variável `idade`, usaremos a função `printf`, que precisa do `#include <stdio.h>` para ser usada.

A função `printf` pode receber mais de um argumento, separados por ",". O primeiro já sabemos que é o texto que queremos imprimir, os outros são **valores que serão substituídas no texto**. Esses valores são indicadas dentro do texto com um único símbolo de porcentagem (`%`) seguidas por uma ou mais letras que indicam o **tipo desse valor**. Esses valores podem estar **armazenados em variáveis** ou **colocados diretamente** no `printf`. Veja os dois exemplos a seguir, um imprime o valor `10` e o outro o valor armazenado na variável `idade`:

``` c
#include <stdio.h>

int main(void)
{
    printf("Valor direto (10): %d\n", 10);

    return 0;
}
```

```c
#include <stdio.h>

int main(void)
{
    int idade = 18;

    printf("Valor da variável idade: %d\n", idade);

    return 0;
}
```

O caractere ao lado do `%` representa o tipo do valor que será impressa. Nesse caso, usamos o `d` para indicar que estamos passando o valor de uma váriavel do tipo `int`.

Retire o `%d` e veja a saída do programa:

- **Código**:

``` c
#include <stdio.h>

int main(void)
{
    int idade = 18;

    printf("Idade: \n", idade);

    return 0;
}
```

- **Mensagem do compilador**:

```
$ gcc -o main main.c
main.c: In function ‘main’:
main.c:7:12: warning: too many arguments for format [-Wformat-extra-args]
    7 |     printf("Idade: \n", idade);
      |            ^~~~~~~~~~~
```

- **Saída do programa**:

```
$ ./main
Idade:
```

O program compila, mas o GCC nos dá um `warning` na linha 7, coluna 12 de `main.c`, nos avisando que estamos passando muitos argumentos para a função `printf`. A solução é colocar o `%d` no texto, não importa a onde:

``` c
#include <stdio.h>

int main(void)
{
    int idade = 18;

    printf("%dIdade: \n", idade);

    return 0;
}
```

A função `printf` não possui um limite de quantos argumentos pode receber:

``` c
#include <stdio.h>

int main(void)
{
    int a = 1;
    int b = 2;

    printf("a e b valem %d e %d, respectivamente.\n", a, b);
    return 0;
}
```

### Operações

Também podemos fazer operações aritméticas **entre variáveis e números**, como nos exemplos a seguir:

> Para ver a variável `resultado` não se esqueça de usar o `#include <stdio.h>` e `printf`!

- **Soma** (`+`):

``` c
int main(void)
{
    int a = 3;
    int b = a + 1;

    int resultado = a + b;

    return 0;
}
```

- **Subtração** (`-`):

``` c
int main(void)
{
    int x = -1;
    int y = x + 2;

    int resultado = x - y;

    return 0;
}
```

- **Multiplicação** (`*`):

``` c
int main(void)
{
    int u = -2;
    int v = u * 0;

    int resultado = u * v;

    return 0;
}
```

- **Divisão** (`/`):

``` c
int main(void)
{
    int a = 12;
    int b = a / -3;

    int resultado = a / b;

    return 0;
}
```

A divisão de inteiros (`int`) em C funciona um pouco diferente do que você possa imaginar. Quando os números dividem **sem sobrar resto**, a divisão funciona como esperado (como no exemplo acima), mas caso a divisão tenha números depois da vírgula, ela é **truncada**, isso é, todos os números **"depois da vírgula" são ignorados** e apenas a parte inteira é considerada. Veja o resultado de `7 / 2`:

``` c
#include <stdio.h>

int main(void)
{
    printf("7 dividido por 2 vale %d\n", 7 / 2);

    return 0;
}
```

> Não falamos que a divisão é "*arrendondada*", mas sim **truncada**. Isso quer dizer que mesmo em divisões muito pequenas, como `1 / 100`, os números depois da vírgula são ignorados.

O resultado é `3` e não `3,5`. Vamos entender em [Memória I](./memoria-1.md) como o `int` é representado em binário, e com isso o por que da divisão ser truncada.

Ainda temos o operador **Módulo**, também chamado de "**resto da divisão**". Veja o código a seguir:

> Para imprimir o símbolo de porcentagem ("%") usando o printf, usamos **duas porcentagens**, dessa forma: `%%`

``` c
#include <stdio.h>

int main(void)
{
    dividendo = 4;
    divisor = 2;

    quociente = dividendo / divisor;
    resto = dividendo % divisor;

    printf("O valor do quociente é: %d\n", quociente);

    printf("O valor do resto é: %d\n", resto);

    return 0;
}
```

O quociente da divisão de 4 por 2 é 2, enquanto o resto é zero, ou seja, $2 \times 2 + 0 = 4$.

Agora, troque o dividendo por `7` e veja o resultado.

O quociente da divisão de 7 por 2 é 3, enquanto o resto é 1, ou seja, $2 \times 3 + 1 = 7$.

<!--
#### Representação binária

> Entender o sistema binário é um pouco confuso no início, o importante é você **notar as similaridades com o sistema decimal**. Ao invés de representar um número de 10 maneiras diferentes (com 10 dígitos), usamos apenas 2 (`0` ou `1`).

No sistema decimal, podemos representar o zero da seguinte maneira `0000`. Agora vamos começar a contar até o nove:

```
0000
0001
0002
...
0009
```

O que acontece depois do `9`? Não existe um único dígito que representa o dez. Então o dígito da direita **volta para `0`** e o da esquerda **aumenta em 1**:

```
0009
0010   <- o "vai um"
```

Você já faz isso desde a escola, só nunca precisou pensar no mecanismo. O mesmo vale depois do `99`, que vira `100`.

No binário, o mecanismo é **idêntico**, a única diferença é que cada dígito só vai até `1`. Vamos contar com 4 dígitos:

```
0000  ->  0
0001  ->  1
0010  ->  2   <- acabou o 1, então "vai um"
0011  ->  3
0100  ->  4   <- "vai um" duas vezes seguidas
0101  ->  5
0110  ->  6
0111  ->  7
1000  ->  8
```

> Cada dígito de um número binário é chamado de **bit**, do inglês *binary digit* ("dígito binário").

No decimal, o número `345` significa `3 × 100 + 4 × 10 + 5 × 1`. Cada posição tem um **peso**, que é uma potência de 10:

|            | Centena | Dezena | Unidade |
| :-:        | :-:     | :-:    | :-:     |
| **Peso**   | 100     | 10     | 1       |
| **Dígito** | 3       | 4      | 5       |

Logo, `3 × 100 + 4 × 10 + 5 × 1 = 345`.

No binário, os pesos são potências de **2**, da direita para a esquerda. Veja quanto o binário `0101` vale em decimal:

|            | 8 vezes | 4 vezes | 2 vezes | 1 vez |
| :-:        | :-:     | :-:     | :-:     | :-:   |
| **Peso**   | 8       | 4       | 2       | 1     |
| **Dígito** | 0       | 1       | 0       | 1     |

Logo, `0 x 8 + 1 x 4 + 0 x 2 + 1 x 1 = 5`.

Isso mostra por que `0101` vale 5. Para binários maiores a lógica é a mesma; veja o binário `0100 0011`, ele possui os pesos `128, 64, 32, 16, 8, 4, 2, 1`, e os bits ligados são o `64`, o `2` e o `1`. Logo, em decimal esse binário vale: `64 + 2 + 1 = 67`.

> Para converter um número binário em decimal, **some os pesos das posições onde há `1`**. Pratique: quanto vale `0000 1010`? E `0001 0000`?

Com 4 dígitos decimais, vamos de `0000` até `9999`, ou seja, $10^4 = 10 000$ números. Com 4 bits, temos $2^4 = 16$ números, de `0000` (0) até `1111` (15). Em geral, **n bits representam $2^n$ valores diferentes**.

Um `int` em C é representado com pelo menos 16 bits, mas nenhum deles representa números quebrados, apenas inteiros.

Não existe uma posição com peso "meio", então um `int` **não tem como guardar uma fração**. Quando o C divide dois `int`, o resultado é apenas o **quociente** e o resto é descartado:

``` c
printf("%d\n", 1 / 2); // 0
```
-->

### float / double

Tanto o `float` quanto o `double` representam números reais, aqueles com casas depois da vírgula. A única diferença é no **nível de precisão** entre os tipos: o `double` é mais preciso que o `float`. Enquanto o tipo `float` consegue representar, aproximadamente, 7 dígitos decimais, o `double` representa 14.

Essa maior precisão tem um custo, o tipo `double` precisa de mais espaço do que o `float`, mas na prática na *maioria da vezes* esse curto é desprezível. Em [Memória I](./memoria-1.md) veremos como esses tipos são representados, com isso você conseguirá avaliar quando usar um ou outro. Ao longo do curso vamos usar o `double`.

Declaramos o `float` da seguinte forma:

```c
float media_f = 6.72f;
```

Temos que colocar esse `f` no final para indicar que o número é um `float`. Também podemos usar o `F`.

Já o `double`:

```c
double media_d = 3.2;
```

#### Printf

Para imprimir o valor da média, vamos usar o `%f` em ambos:

> Declare a função main e importe o _header_ `stdio`.

```c
#include <stdio.h>

int main(void)
{
    float media_f = 6.72f;
    double media_d = 3.2;

    printf("Média Float: %f\n", media_f);
    printf("Média Double: %f\n", media_d);

    return 0;
}
```

O `printf` interpreta o `float` e `double` como reais em sua implementação interna, por isso utilizamos do mesmo símbolo `f` para ambos. Rode o comando e veja o resultado: ele é seguido por um monte de zeros!

Dependendo do tipo da variável que passamos para o `printf` nós podemos mudar como o valor será exibido. Por exemplo, para exibirmos apenas duas casas depois da vírgula, usamos:

```c
printf("Média: %.2f\n", media_f);
```

Até podemos arrendondar o número com:

```c
printf("Média: %.0f\n", media_d);
```

Também existem outros formatadores para `float` e `double`. Caso você queira ignorar os zeros desnecessários (que ficam a esquerda do número), use o `%g`. Esse formatador apenas mostrará o mínimo possível; se o valor for `15.00`, usando o `%g`, será exibido apenas `15`.

### char

Representa um único caractere. Declaramos da seguinte forma:

```c
char caractere = 'a';
```

Tá lembrado no começo do capítulo, quando discutimos como o binário `0100 0011` (ou 67 em decimal) pode ser interpretado de formas diferentes? Agora veremos na prática com o código a seguir:

```c
#include <stdio.h>

int main(void)
{
    char letra_C = 'C';

    printf("Caractere: %c\n", letra_C);

    printf("Índice: %d\n", letra_C);

    return 0;
}
```

Primeiro, declaramos uma variável do tipo `char` chamada `letra_C`. Depois, usamos o `%c` para imprimir o caractere no terminal. Mas fazemos algo esquisito em seguida: imprimimos a variável `letra_C` como um `int`?! Por que o código funciona, e por que ele exibe 67?

Isso se deve ao modo como os caracteres funcionam em C. Por debaixo dos panos, o tipo `char` é um número binário de 8 bits, que é **traduzido para um caractere** por meio da [Tabela de Conversão ASCII](https://www.ime.usp.br/~kellyrb/mac2166_2015/tabela_ascii.html) apenas no momento em que será exibido.

Se você abrir essa tabela, notará duas coisas: o _código ASCII_ do caractere `C` é 67; e que não existem caracteres acentuados. Isso se deve ao fato da Tabela ASCII ter sido criada pra a língua inglesa, por isso eles não colocaram acentos nela. Para usar acentos, são usados mais de 8 bits, por isso não é possível armazenar um carácter acentuado da seguinte forma:

- **Código**:

``` c
#include <stdio.h>

int main(void)
{
    char com_acento = 'á';

    printf("Tentando mostrar um acento: %c\n", com_acento);

    return 0;
}
```

- **Mensagem do compilador**:

```
$ gcc -o main main.c
main.c: In function ‘main’:
main.c:5:23: warning: multi-character character constant [-Wmultichar]
    5 |     char com_acento = 'á';
      |                       ^~~
main.c:5:23: warning: overflow in conversion from ‘int’ to ‘char’ changes value from ‘50081’ to ‘-95’ [-Woverflow]
```

- **Saída do programa**:

```
$ ./main
Tentando mostrar um acento: �
```

Existem duas partes para explicar o
O programa até executa, mas o compilador nos avisa na linha 5, coluna 23, que estamos usando um carácter de "muitos caracteres" (`multi-character character`). Por enquanto, não conhecemos a linguagem bem o bastante para entender esse aviso, em [Strings](./strings.md) voltaremos para esse caso.


### bool

Os valores booleanos são aqueles que podem ser ou **verdadeiro** ou **falso**, mas nunca os dois ao mesmo tempo. São usados principalmente para estabelecer condições.

```c
#include <stdbool.h>

bool estou_feliz = false;
```

Diferente dos outros tipos primitivos, para declararmos uma variável booleana, precisamos primeiro importar sua definição na Biblioteca Padrão, com o `#include <stdbool.h>`.
O motivo disso ficará claro em [Condicionais](./condicionais.md)

Nós também não temos como imprimir um `bool` do mesmo jeito que vínhamos fazendo. Isso se deve ao fato da função `printf` não definir em sua implementação uma maneira de converter o `bool` para uma string, ou seja, não definir um código como `d` para tal. Mas nós veremos em [Condicionais](./condicionais.md) um jeito de fazer isso.

Chamamos os estados **verdadeiro** e **falso** de `true` e `false`, respectivamente.

## Regras de Nomenclatura

Os nomes que damos aos elementos do código, como *variáveis* e *funções*, são chamados formalmente de **identificadores**. Eles possuem essas seguintes regras:

- São permitidos os seguintes caracteres: letras (minúsculas e maiúsculas), dígitos (de 0 a 9) e o sublinhado (`_`), também chamado de _underline_.
- **Não é permitido** espaços, use o sublinhado, como em `soma_total`.
- **Não é permitido** começar com um dígito. Exemplos de identificadores errados: `1pessoa` e `02_vida`.
- **Não é permitido** ter acento, como em `int café`. Use `cafe` ao invés disso.
- A linguagem C diferencia letras minúsculas das maiúsculas. Por exemplo, as variáveis `Vida`, `vida` e `VIDA` como coisas diferentes.
- Você não pode usar **palavras reservadas** da linguagem. Palavras como `int`, `double`, `return`, `if`, `while` e `char` são proibidas de serem usadas como nomes de variáveis ou funções.

## Variáveis Constantes

São variáveis que, ao serem declaradas, não podem mudar de valor.

Por exemplo, vamos declarar a variável `pi`, com o valor aproximado da constante.

> Não se esqueça de importar `#include <stdio.h>` e declarar a função `main`!

```c
const double pi = 3.14;

printf("Pi vale aproximadamente %f\n", pi);
```

Vamos tentar aumentar o valor da aproximação do `pi` **após** a declaração da variável:

```c
const double pi = 3.14;

pi = 3.14159;

printf("Pi vale aproximadamente %f\n", pi);
```

Recebemos o seguinte erro de compilação:

```
$ gcc -o main main.c
main.c: In function ‘main’:
main.c:8:8: error: assignment of read-only variable ‘pi’
    8 |     pi = 3.14159;
      |        ^

```

É a segunda linha da saída do comando que nos interessa: `error: assignment of read-only variable ‘pi’`.
Ela fala que ocorreu um erro ao atribuir algum valor à uma variável _read-only_, do inglês "apenas de leitura", chamada `pi`. Esse erro é uma garantia do compilador de que não podemos alterar variáveis constantes.

Se amanhã nós precisarmos aumentar a precisão da constante `pi`, isso é, aumentar o número de casas depois da vírgula, nós só precisamos alterar em **um lugar** - se não usássemos constantes, teríamos que procurar cada caso com o valor `3.14` e trocá-lo. Por exemplo, para atualizar a constante:

```c
const double pi = 3.1415926;

printf("Pi vale aproximadamente %f\n", pi);
```

## Boas práticas

### Nomenclatura

Evite nomes misteriosos para as suas variáveis. Em vez de `int p;`, use `int pontuacao;`. O nome da variável deve transmitir parte da sua função dentro do código.

Evite o encurtamento dos nomes, como escrever `int v_final;` ao invés de `int valor_final;`. Quando você nomeia bem o seu código, mesmo que demore um pouco mais para digitar, daqui a um mês, quando precisar mudar o código de novo, os nomes mais claros te ajudaram a relembrar a lógica do código. Por isso, não se prenda a regra de apenas 8 caracteres!

Ao longo do guia, veremos ainda mais casos de como melhorar a sua nomenclatura. Enquanto estava aprendendo a programar, achava difícil pensar em bons nomes para as coisas. Se você se sente assim, recomendo utilizar Inteligência Artificial para ter ideias de como nomear.

### Inicialização

Sempre que declarar uma variável, é recomendado que você inicialize ela com um valor padrão. Como `0` ou `1` para o tipo `int`. Escreva esse programa e **rode ele mais de uma vez**:

```c
#include <stdio.h>

int main(void)
{
    int numero;

    printf("número = %d\n", numero);
    return 0;
}
```

Você verá que a variável `numero` armazena valores aleatórios. O motivo disso ficará claro em [Memoria I](./memoria-1.md), por ora, sempre inicialize suas variáveis para evitar usar valores aleatórios acidentalmente.

### Valores Mágicos

Outra vantagem das variáveis constantes é dar um **nome claro** a **um valor** "solto". No código a seguir, vamos calcular a conta final de 4 amigos em um restaurante?

```c
int main(void)
{
    int pessoas = 4;
    double conta = 120.0;

    double total = conta + conta * 0.1 + pessoas * 15.0;

    printf("O total foi R$ %.2f\n", total);
    return 0;
}
```

Você saberia dizer o que os valores `0.1` e `15.0` representam? Pelo contexto talvez você consiga adivinhar, mas só depois de gastar um tempo decifrando o código. No caso, eles representam a **taxa de serviço** e o **preço da reserva por pessoa**, respectivamente.

Esses valores "soltos" são chamados de **valores mágicos**. Eles diminuem muito a clareza do nosso código. Uma solução é usar duas variáveis constantes chamadas `taxa_servico` e `preco_reserva` para deixar claras as suas funções no código:

```c
int main(void)
{
    const double taxa_servico = 0.1;
    const double preco_reserva = 15.0;

    int pessoas = 4;
    double conta = 120.0;

    double total = conta + conta * taxa_servico + pessoas * preco_reserva;

    printf("O total foi R$ %.2f\n", total);
    return 0;
}
```

Agora, conseguimos ler o cálculo da variável `total` da seguinte forma: o total é a soma da conta, com a taxa de serviço e as reservas de cada pessoa. E de novo, se precisarmos diminuir a taxa de serviço, por exemplo, só precisamos mudar em um lugar só.

---

<p align="center">
  <a href="./linguagem-c.md">← O que é C?</a>
  &nbsp;|&nbsp;
  <a href="../exercicios/variaveis.md">Exercícios: Variáveis →</a>
</p>
