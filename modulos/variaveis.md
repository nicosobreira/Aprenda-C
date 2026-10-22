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

A verdade é que o computador interpreta os zeros e uns da maneira que nós, programadores, mandamos. Tomamos o número binário `0100 0011` como exemplo. Quando o computador olha para o binário, ele não tem a menor ideia do que significa.
Para a máquina, a sequência `0100 0011` é apenas um dado bruto. No entanto, se nós mandarmos o computador interpretar isso como um número inteiro, o valor é 67. Ao final do módulo, veremos que esse mesmo binário representa um outro tipo de informação: uma letra.

## Declaração

Declarar a variável nada mais é do que mostrar para o computador qual é o nome e tipo da informação que queremos armazenar.

Para declarar uma variável do tipo inteiro (`int`) em C, escrevemos:

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
char letra;
```

- **Número real** (com casas depois da vírgula):

``` c
double real;
```

## Atribuição

Para **alterar o valor** de uma variável usamos o igual (`=`).
A seguir nós **inicializamos** a variável `numero` com o valor `10`:

``` c
int numero = 10;
```

**Depois que declaramos** uma variável, podemos alterar o seu valor novamente, sem repetir o tipo, como no código a seguir, que cria a variável `idade` - com valor inicial 18 - e a muda para 10.

``` c
int main(void)
{
    int idade = 18;

    idade = 10;

    return 0;
}
```

## Tipos Primitivos

São os tipos de variáveis definidos por padrão pela linguagem.

Nesse módulo, veremos esses tipos **sem muitos detalhes**. No entanto, no módulo [Memória I](./memoria-1.md), veremos como o computador interpreta esses valores de verdade.

### int

Representa um número inteiro, como `-1`, `-3`, `0` e `1`.

```c
int idade = 18;
```

Para exibirmos o valor da variável `idade`, usaremos a função `printf`.

A função `printf` pode receber mais de um argumento, separados por ",". O primeiro já sabemos que é o texto que queremos imprimir, os outros são **valores que serão substituídos no texto**. Esses valores são indicados dentro do texto com um único símbolo de porcentagem (`%`) seguido por uma ou mais letras que indicam o **tipo desse valor**. Esses valores podem estar **armazenados em variáveis** ou **colocados diretamente** no `printf`. Veja os dois exemplos a seguir, um imprime o valor `10` e o outro, o valor armazenado na variável `idade`:

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

O caractere ao lado do `%` representa o tipo do valor que será impresso. Nesse caso, usamos o `d` para indicar que estamos passando o valor de uma variável do tipo `int`.

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

O programa compila, mas o GCC nos dá um `warning` na linha 7, coluna 12 de `main.c`, nos avisando que estamos passando muitos argumentos para a função `printf`. A solução é colocar o `%d` no texto, não importa onde:

``` c
#include <stdio.h>

int main(void)
{
    int idade = 18;

    printf("I%ddade: \n", idade);

    return 0;
}
```

A saída será `I18dade:`, o que é estranho, mas mostra que o `%d` pode ficar em qualquer posição do texto.

Também podemos passar quantos argumentos quisermos para a função `printf`, desde que cada um tenha o seu `%` correspondente:

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
#include <stdio.h>

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
#include <stdio.h>

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
#include <stdio.h>

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
#include <stdio.h>

int main(void)
{
    int a = 12;
    int b = a / -3;

    int resultado = a / b;

    return 0;
}
```

> Também podemos imprimir os resultados **direto** no `printf`:
> ``` c
> printf("resultado = %d\n", 2 + 4);
> ```

A divisão de inteiros (`int`) em C funciona um pouco diferente do que você possa imaginar. Quando os números dividem **sem sobrar resto**, a divisão funciona como esperado (como no exemplo acima), mas caso a divisão tenha números depois da vírgula, ela é **truncada**, isto é, todos os números **"depois da vírgula" são ignorados** e apenas a parte inteira é considerada. Veja o resultado de `7 / 2`:

``` c
#include <stdio.h>

int main(void)
{
    printf("7 dividido por 2 vale %d\n", 7 / 2);

    return 0;
}
```

O resultado é `3` e não `3,5`. A linguagem C define o tipo do resultado das operações aritméticas a partir dos **tipos** dos números usados. Nesse caso, como `7` e `2` são do **tipo inteiro**, o resultado também é um inteiro - mas como não é possível representar números depois da vírgula com inteiros, o resultado é truncado.
Não falamos que a divisão é "*arredondada*", mas sim **truncada**. Isso quer dizer que mesmo em divisões muito pequenas, como `1 / 100`, os números depois da vírgula são ignorados.

Ainda temos o operador **Módulo**, também chamado de "**resto da divisão**". Veja o código a seguir:

``` c
#include <stdio.h>

int main(void)
{
    int dividendo = 4;
    int divisor = 2;

    int quociente = dividendo / divisor;
    int resto = dividendo % divisor;

    printf("O valor do quociente é: %d\n", quociente);

    printf("O valor do resto é: %d\n", resto);

    return 0;
}
```

O quociente da divisão de 4 por 2 é 2, enquanto o resto é zero, ou seja, $2 \times 2 + 0 = 4$.

Agora, troque o dividendo por `7` e veja o resultado.

O quociente da divisão de 7 por 2 é 3, enquanto o resto é 1, ou seja, $2 \times 3 + 1 = 7$.

Por fim, usamos os parênteses `()` para indicar quais operações devem ser executadas primeiro. Veja como a saída muda entre os exemplos, mesmo que eles tenham os mesmos números:

``` c
#include <stdio.h>

int main(void)
{
    int resultado = (12 - 4) * 10;

    printf("resultado = %d\n", resultado);

    return 0;
}
```

``` c
#include <stdio.h>

int main(void)
{
    int resultado = 12 - 4 * 10;

    printf("resultado = %d\n", resultado);

    return 0;
}
```

A ordem das operações segue as mesmas regras da matemática:

1. São resolvidas as operações dos parênteses mais internos até chegar aos externos.
2. A multiplicação, a divisão e o módulo são feitos da esquerda para a direita, sem prioridade entre si.
3. Por último, a soma e a subtração, também da esquerda para a direita.

### float / double

Tanto o `float` quanto o `double` representam números reais, aqueles com casas depois da vírgula. A principal diferença é no **nível de precisão** entre os tipos: o `double` é mais preciso que o `float`. Enquanto o tipo `float` consegue representar, aproximadamente, 7 dígitos decimais, o `double` representa cerca de 15.

Essa maior precisão tem um custo: o tipo `double` precisa de mais espaço do que o `float`, mas na *maioria das vezes* esse custo é desprezível. Em [Memória I](./memoria-1.md) veremos como esses tipos são representados, com isso você conseguirá avaliar quando usar um ou outro. Ao longo do guia vamos usar o `double`.

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

O `printf` interpreta o `float` e `double` como reais, por isso utilizamos do mesmo símbolo `f` para ambos. Rode o comando e veja o resultado: ele é seguido por um monte de zeros!

Podemos mudar como o valor será exibido alterando o formatador. Por exemplo, para exibirmos apenas duas casas depois da vírgula, usamos:

```c
printf("Média Float: %.2f\n", media_f);
```

Também podemos arredondar o número com:

```c
printf("Média Double: %.0f\n", media_d);
```

Também existem outros formatadores para `float` e `double`. Caso você queira ignorar os zeros desnecessários (que ficam à direita do número), use o `%g`. Esse formatador apenas mostrará o mínimo possível; se o valor for `15.00`, usando o `%g`, será exibido apenas `15`.

#### Operações

Podemos usar as mesmas operações que vimos, só temos que tomar um cuidado. Tente prever qual é a saída do programa:

``` c
#include <stdio.h>

int main(void)
{
    double resultado = 7 / 2;

    printf("resultado = %f\n", resultado);

    return 0;
}
```

Como estamos usando o `double`, o resultado esperado é `3.5`, mas recebemos `3.000000` novamente; o motivo é a mesma regra que já vimos: o tipo do resultado das operações aritméticas é o mesmo dos números usados. Por padrão, quando não colocamos um ponto (`.`), o número é interpretado como um `int`. Veja como a saída sai corretamente quando usamos `.0`:

``` c
#include <stdio.h>

int main(void)
{
    double resultado = 7.0 / 2.0;

    printf("resultado = %f\n", resultado);

    return 0;
}
```

### Bits e o sistema binário

Antes de continuarmos, precisamos entender por que o binário `0100 0011` vale 67. Para isso, vamos entender como se **conta** só com zeros e uns.

#### Por que binário?

O computador é feito de circuitos que diferenciam com segurança **dois estados**: tensão alta ou baixa, ligado ou desligado. Distinguir dez estados diferentes (um por dígito decimal) é muito mais difícil e propenso a erros.

A solução é usar um sistema com somente dois dígitos, chamado de **binário**. Chamamos esses dígitos de **bit**, do inglês *binary digit*.

#### Contando em decimal e em binário

> Entender o sistema binário é um pouco confuso no início, o importante é você **notar as similaridades com o sistema decimal**. Ao invés de 10 símbolos por dígito (`0` a `9`), usamos apenas 2 (`0` e `1`).

Vamos contar em **decimal** com 4 dígitos:

```
0008
0009
0010   <- o dígito da direita volta para 0 e o da esquerda aumenta em 1
```

Você já faz esse "vai um" desde a escola. No binário o mecanismo é **idêntico**, só que o dígito acaba no `1`:

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

#### Pesos das posições

No decimal, o número `345` significa `3 × 100 + 4 × 10 + 5 × 1`. Cada posição tem um **peso**, que é uma potência de 10.

No **binário**, os pesos são potências de **2**, da direita para a esquerda. Veja o binário `0101`:

|            | 8 | 4 | 2 | 1 |
| :-:        | :-: | :-: | :-: | :-: |
| **Dígito** | 0 | 1 | 0 | 1 |

Logo, `0 × 8 + 1 × 4 + 0 × 2 + 1 × 1 = 5`.

Agora podemos resolver a dívida do começo. O binário `0100 0011` tem 8 posições, com pesos `128, 64, 32, 16, 8, 4, 2, 1`:

|            | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |
| :-:        | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| **Dígito** | 0   | 1  | 0  | 0  | 0 | 0 | 1 | 1 |

Os bits ligados são o `64`, o `2` e o `1`, então `64 + 2 + 1 = 67`.

> Para converter um binário em decimal, **some os pesos das posições onde há `1`**.

Pratique: quanto vale `0000 1010`? E `0001 0000`? Como se escreve o `13` em binário?

<details>
<summary>Clique aqui para ver a resposta</summary>

- `0000 1010` = `8 + 2` = **10**.
- `0001 0000` = **16**, só o peso `16` está ligado.
- `13` = `8 + 4 + 1` = `0000 1101`.

</details>

#### Quantos valores cabem em n bits?

Com 4 dígitos decimais vamos de `0000` a `9999`, ou seja, $10^4 = 10\,000$ números. Com 4 bits, temos $2^4 = 16$ números, de `0000` (0) a `1111` (15). Em geral, **n bits representam $2^n$ valores diferentes**.

Um grupo de 8 bits é chamado de **byte**, e consegue representar $2^8 = 256$ valores, de 0 a 255. Guarde esse número, ele vai explicar vários comportamentos do `char`.

> Em [Memória I](./memoria-1.md) veremos como o `int` usa essa mesma ideia, inclusive para representar números negativos.

### char

O `char` é um tipo que representa um único caractere. Declaramos da seguinte forma:

```c
char caractere = 'a';
```

Lembra do começo do capítulo, quando discutimos como o binário `0100 0011` (ou 67 em decimal) pode ser interpretado de formas diferentes? Agora veremos na prática com o código a seguir:

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

Isso se deve ao modo como os caracteres funcionam em C. Por debaixo dos panos, o tipo `char` é um número binário de 1 byte (8 bits), que é usado como um índice na chamada [Tabela ASCII](https://www.ime.usp.br/~kellyrb/mac2166_2015/tabela_ascii.html) apenas no momento em que será exibido.

A tabela ASCII foi usada para **padronizar** como letras e números são representados. No passado, todo mundo concordava que representar as letras como índices em algum tipo de tabela era a melhor forma de armazená-las, já que um texto de 1000 caracteres só ocuparia 1000 bytes (exatamente 1 KB). O único problema era onde cada caractere devia ficar; dispositivos diferentes apresentavam valores distintos para os mesmos caracteres. Com o ASCII, esses valores foram padronizados.

Se você abrir essa tabela, notará duas coisas: o _código ASCII_ do caractere `C` é 67; e que não existem caracteres acentuados. Isso se deve ao fato da Tabela ASCII ter sido criada para a língua inglesa, por isso não possui acentos. Para representar acentos, é necessário usar mais de 8 bits, por isso não é possível armazenar um caractere acentuado em um `char` da seguinte forma:

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

O programa até executa, mas o compilador nos avisa na linha 5, coluna 23, que estamos usando uma constante de caractere com vários caracteres (`multi-character character constant`). Por enquanto, não conhecemos a linguagem bem o bastante para entender esse aviso, em [Strings](./strings.md) voltaremos para esse caso e veremos como armazenar letras acentuadas.

### bool

Os valores booleanos são aqueles que podem ser ou **verdadeiro** ou **falso**, mas nunca os dois ao mesmo tempo. São usados principalmente para estabelecer condições.

```c
#include <stdbool.h>

int main(void)
{
    bool estou_feliz = false;

    return 0;
}
```

Diferente dos outros tipos primitivos, para declararmos uma variável booleana, precisamos primeiro importar sua definição na Biblioteca Padrão, com o `#include <stdbool.h>`.
O motivo disso ficará claro em [Condicionais](./condicionais.md)

Nós também não temos como imprimir um `bool` do mesmo jeito que vínhamos fazendo. Isso se deve ao fato da função `printf` não definir em sua implementação uma maneira de converter o `bool` para uma string, ou seja, não definir um código como `d` para tal. Mas nós veremos em [Condicionais](./condicionais.md) um jeito de fazer isso.

Chamamos os estados **verdadeiro** e **falso** de `true` e `false`, respectivamente.

## Regras de Nomenclatura

Os nomes que damos aos elementos do código, como *variáveis* e *funções*, são chamados formalmente de **identificadores**. Eles seguem estas regras:

- São permitidos os seguintes caracteres: letras (minúsculas e maiúsculas), dígitos (de 0 a 9) e o sublinhado (`_`), também chamado de _underline_.
- **Não são permitidos** espaços, use o sublinhado, como em `soma_total`.
- **Não é permitido** começar com um dígito. Exemplos de identificadores errados: `1pessoa` e `02_vida`.
- **Não é permitido** ter acento, como em `int café`. Use `cafe` ao invés disso.
- A linguagem C diferencia letras minúsculas das maiúsculas. Por exemplo, as variáveis `Vida`, `vida` e `VIDA` são tratadas como coisas diferentes.
- Você não pode usar **palavras reservadas** da linguagem. Palavras como `int`, `double`, `return`, `if`, `while` e `char` são proibidas de serem usadas como nomes de variáveis ou funções.

## Variáveis Constantes

São variáveis que, ao serem declaradas, não podem mudar de valor.

Usamos o `const` seguido pelo tipo para declarar uma variável constante. Veja o exemplo a seguir, que declara o valor da constante `pi`:

```c
#include <stdio.h>

int main(void)
{
    const double pi = 3.14;

    printf("Pi vale aproximadamente %f\n", pi);

    return 0;
}
```

Vamos tentar aumentar o valor da aproximação do `pi` **após** a declaração da variável:

```c
#include <stdio.h>

int main(void)
{
    const double pi = 3.14;

    pi = 3.14159;

    printf("Pi vale aproximadamente %f\n", pi);

    return 0;
}
```

Recebemos o seguinte erro de compilação:

```
$ gcc -o main main.c
main.c: In function ‘main’:
main.c:7:8: error: assignment of read-only variable ‘pi’
    7 |     pi = 3.14159;
      |        ^

```

É a segunda linha da saída do comando que nos interessa: `error: assignment of read-only variable ‘pi’`.
Ela fala que ocorreu um erro ao atribuir algum valor a uma variável _read-only_, do inglês "apenas de leitura", chamada `pi`. Esse erro é uma garantia do compilador de que não podemos alterar variáveis constantes.

Se amanhã nós precisarmos aumentar a precisão da constante `pi`, isto é, aumentar o número de casas depois da vírgula, nós só precisamos alterar em **um lugar** - se não usássemos constantes, teríamos que procurar cada caso com o valor `3.14` e trocá-lo. Por exemplo, para atualizar a constante:

```c
#include <stdio.h>

int main(void)
{
    const double pi = 3.1415926;

    printf("Pi vale aproximadamente %f\n", pi);

    return 0;
}
```

## Boas práticas

### Nomenclatura

Evite nomes misteriosos para as suas variáveis. Em vez de `int p;`, use `int pontuacao;`. O nome da variável deve transmitir parte da sua função dentro do código.

Evite o encurtamento dos nomes, como escrever `int v_final;` ao invés de `int valor_final;`. Quando você nomeia bem o seu código, mesmo que demore um pouco mais para digitar, daqui a um mês, quando precisar mudar o código de novo, os nomes mais claros te ajudarão a relembrar a lógica do código. Por isso, não se prenda à regra de apenas 8 caracteres!

Ao longo do guia, veremos ainda mais casos de como melhorar a sua nomenclatura. Quando estava aprendendo a programar, achava difícil pensar em bons nomes para as coisas. Se você se sente assim, recomendo utilizar Inteligência Artificial para ter ideias de como nomear.

### Inicialização

Sempre que declarar uma variável, é recomendado que você a inicialize com um valor padrão, como `0` ou `1` para o tipo `int`. Escreva esse programa e **rode ele mais de uma vez**:

```c
#include <stdio.h>

int main(void)
{
    int numero;

    printf("número = %d\n", numero);

    return 0;
}
```

Você verá que a variável `numero` armazena valores aleatórios. O motivo disso ficará claro em [Memória I](./memoria-1.md), por ora, sempre inicialize suas variáveis para evitar usar valores aleatórios acidentalmente.

### Valores Mágicos

Outra vantagem das variáveis constantes é dar um **nome claro** a **um valor** "solto". No código a seguir, vamos calcular a conta final de 4 amigos em um restaurante?

```c
#include <stdio.h>

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
#include <stdio.h>

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
