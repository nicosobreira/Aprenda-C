# Variáveis

As variáveis são valores **armazenados** na **memória do computador**, usados para **guardar** algum dado para uso futuro. Elas nos permitem guardar informações bem diferentes, como a idade de uma pessoa, o preço de um produto e se um usuário está logado ou não em um sistema.
Os valores são, respectivamente: um número inteiro, um número real e um valor que só pode ser verdadeiro ou falso.
Lembra que em [O que é C?](./linguagem-c.md) vimos que o computador só lida com zeros e uns? Como o computador guarda dados tão diferentes entre si, se ele só entende 0 e 1?

A verdade é que o computador interpreta os zeros e uns da maneira que nós, programadores, mandamos. Tomemos o número binário `#!c 0100 0011` como exemplo. Quando o computador olha para ele, não tem a menor ideia do que ele significa.
Para a máquina, a sequência `#!c 0100 0011` é apenas um dado bruto. No entanto, se nós mandarmos o computador interpretar isso como um número inteiro, o valor é 67. Ao final do módulo, veremos que esse mesmo binário representa um outro tipo de informação: uma letra.

## Declaração

Declarar a variável nada mais é do que mostrar para o computador qual é o nome e tipo da informação que queremos armazenar.

Para declarar uma variável do tipo inteiro (`#!c int`) em C, escrevemos:

```c
int numero;
```

Dentro da função `main` fica assim:

```c
int main(void)
{
    int numero;

    return 0;
}
```

O `#!c int` mostra ao computador que o valor armazenado na variável de nome `numero` é do tipo **inteiro**.

Ao longo do módulo, veremos mais tipos. Alguns deles são:

```c title="Letra"
char letra;
```

```c title="Número real"
double real;
```

## Atribuição

Para **alterar o valor** de uma variável usamos o igual (`#!c =`), que na programação significa **atribuição**.
A seguir nós **inicializamos** a variável `numero` com o valor `#!c 10`:

```c
int numero = 10;
```

**Depois que declaramos** uma variável, podemos alterar o seu valor novamente sem repetir o tipo. Como no código a seguir, que cria a variável `idade` - com valor inicial `#!c 18`, e a muda para `#!c 10`.

```c
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

Representa um número inteiro, como `#!c -1`, `#!c -3`, `#!c 0` e `#!c 1`.

```c
int idade = 18;
```

Para exibirmos o valor da variável `idade`, usaremos a função `#!c printf`, declarada em `#!c stdio.h`.

A função `#!c printf` pode receber mais de um argumento, separados por ",". O primeiro já sabemos que é o texto que queremos imprimir, os outros são **valores que serão substituídos no texto**. Esses valores são indicados dentro do texto com o símbolo de porcentagem (`%`) seguido por uma ou mais letras que indicam o **tipo desse valor**. Esses valores podem estar **armazenados em variáveis** ou **colocados diretamente** no `#!c printf`. Veja os dois exemplos a seguir, um imprime o valor `#!c 10` e o outro, o valor armazenado na variável `idade`:

```c title="Direto"
#include <stdio.h>

int main(void)
{
    printf("Valor direto (10): %d\n", 10);

    return 0;
}
```

```c title="Variável"
#include <stdio.h>

int main(void)
{
    int idade = 18;

    printf("Valor da variável idade: %d\n", idade);

    return 0;
}
```

O caractere ao lado do `%` representa o tipo do valor que será impresso. Nesse caso, usamos o `d` (de *decimal*) para indicar que o valor a ser impresso é um `#!c int`, seja ele escrito diretamente ou guardado em uma variável.

Retire o `#!c %d` e veja a saída do programa:

```c title="Código"
#include <stdio.h>

int main(void)
{
    int idade = 18;

    printf("Idade: \n", idade);

    return 0;
}
```

```console title="Mensagem do compilador"
$ gcc -o main main.c
main.c: In function ‘main’:
main.c:7:12: warning: too many arguments for format [-Wformat-extra-args]
    7 |     printf("Idade: \n", idade);
      |            ^~~~~~~~~~~
```

```console title="Saída do programa"
$ ./main
Idade:
```

O programa compila, mas o GCC nos dá um `warning` na linha 7, coluna 12 de `main.c`, nos avisando que estamos passando muitos argumentos para a função `#!c printf`. A solução é colocar o `%d` no texto. Ele pode ficar em qualquer posição, como no exemplo a seguir:

```c
#include <stdio.h>

int main(void)
{
    int idade = 18;

    printf("I%ddade: \n", idade);

    return 0;
}
```

!!! atenção

    A saída será `I18dade:`, o que é estranho, mas mostra que o `%d` é só um espaço reservado que o `#!c printf` troca pelo valor. O correto aqui seria `"Idade: %d\n"`.

Também podemos passar quantos argumentos quisermos para a função `#!c printf`, desde que cada um tenha o seu `%` correspondente:

```c
#include <stdio.h>

int main(void)
{
    int a = 1;
    int b = 2;

    printf("a e b valem %d e %d, respectivamente.\n", a, b);

    return 0;
}
```

!!! dica

    Para exibir o símbolo de porcentegem ("%") faça `%%`. Como no exemplo a seguir:

```c
#include <stdio.h>

int main(void)
{
    printf("Porcentagem %d%%\n", 20);

    return 0;
}
```

### Operações

Fazemos operações aritméticas **entre variáveis e números** da seguinte forma:

- **Soma** (`+`):

```c
#include <stdio.h>

int main(void)
{
    int a = 3;
    int b = a + 1;

    int resultado = a + b;

    printf("resultado = %d\n", resultado);

    return 0;
}
```

- **Subtração** (`-`):

```c
#include <stdio.h>

int main(void)
{
    int x = -1;
    int y = x + 2;

    int resultado = x - y;

    printf("resultado = %d\n", resultado);

    return 0;
}
```

- **Multiplicação** (`*`):

```c
#include <stdio.h>

int main(void)
{
    int u = -2;
    int v = u * 0;

    int resultado = u * v;

    printf("resultado = %d\n", resultado);

    return 0;
}
```

- **Divisão** (`/`):

```c
#include <stdio.h>

int main(void)
{
    int a = 12;
    int b = a / -3;

    int resultado = a / b;

    printf("resultado = %d\n", resultado);

    return 0;
}
```

!!! dica

    Também podemos imprimir os resultados **direto** no `#!c printf`:
    ```c
    printf("resultado = %d\n", 2 + 4);
    ```

A divisão de inteiros (`#!c int`) em C funciona um pouco diferente do que você possa imaginar. Quando os números dividem **sem sobrar resto**, a divisão funciona como esperado (como no exemplo acima), mas caso a divisão tenha dígitos depois da vírgula, ela é **truncada**, isto é, todos os dígitos **depois da vírgula são descartados** e apenas a parte inteira é mantida. Veja o resultado de `#!c 7 / 2`:

```c
#include <stdio.h>

int main(void)
{
    printf("7 dividido por 2 vale %d\n", 7 / 2);

    return 0;
}
```

Ele é `#!c 3`, e não `#!c 3.5`. A linguagem C define o tipo do resultado das operações aritméticas a partir dos **tipos** dos números usados. Nesse caso, como `#!c 7` e `#!c 2` são do **tipo inteiro**, o resultado também é um inteiro. Como os inteiros não representam frações, a parte depois da vírgula é descartada.
Dizemos que a divisão é **truncada**, e não "*arredondada*". Isso quer dizer que `#!c 99 / 100` vale `#!c 0`, mesmo que o valor real, `#!c 0.99`, esteja bem perto de `#!c 1`. Nos números negativos o descarte também é em direção ao zero: `#!c -7 / 2` vale `#!c -3`, e não `#!c -4`.

Ainda temos o operador **Módulo**, também chamado de "**resto da divisão**". Veja o código a seguir:

```c
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

Agora, troque o dividendo por `#!c 7` e veja o resultado.

O quociente da divisão de 7 por 2 é 3, enquanto o resto é 1, ou seja, $2 \times 3 + 1 = 7$.

Por fim, usamos os parênteses `()` para indicar quais operações devem ser executadas primeiro. Veja como a saída muda entre os exemplos, mesmo que eles tenham os mesmos números:

```c title="Com parênteses"
#include <stdio.h>

int main(void)
{
    int resultado = (12 - 4) * 10;

    printf("resultado = %d\n", resultado);

    return 0;
}
```

```c title="Sem parênteses"
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

Tanto o `#!c float` quanto o `#!c double` representam números reais, aqueles com casas depois da vírgula. A principal diferença é no **nível de precisão** entre os tipos: o `#!c double` é mais preciso que o `#!c float`. Enquanto o tipo `#!c float` consegue representar, aproximadamente, 7 dígitos decimais, o `#!c double` representa cerca de 15.

Essa maior precisão tem um custo: o tipo `#!c double` precisa de mais espaço do que o `#!c float`, mas na *maioria das vezes* esse custo é desprezível. Em [Memória I](./memoria-1.md) veremos como esses tipos são representados, com isso você conseguirá avaliar quando usar um ou outro. Ao longo do guia vamos usar o `#!c double`.

Declaramos o `#!c float` da seguinte forma:

```c
float media_f = 6.72f;
```

Colocamos o `#!c f` no final para indicar que o número é um `#!c float`. Também podemos usar o `#!c F`. Sem ele, o `#!c 6.72f` seria um `#!c double`, que o compilador converteria para `#!c float` automaticamente: funciona, mas é melhor deixar a intenção clara.

Já o `#!c double`:

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

Para o `#!c printf`, ambos os tipos usam o mesmo formatador, já que o `#!c float` é convertido automaticamente em `#!c double` ao ser passado para a função. Rode o programa e veja o resultado: o valor vem seguido de zeros, pois o `#!c %f` mostra, por padrão, 6 casas depois da vírgula.

Podemos mudar como o valor será exibido alterando o formatador. Por exemplo, para exibirmos apenas duas casas depois da vírgula, usamos:

```c
printf("Média Float: %.2f\n", media_f);
```

Também podemos arredondar o número **apenas na exibição** (o valor guardado na variável não muda):

```c
printf("Média Double: %.0f\n", media_d);
```

Também existem outros formatadores para `#!c float` e `#!c double`. Caso você queira ignorar os zeros desnecessários (aqueles que ficam à direita, depois da vírgula), use o `#!c %g`. Esse formatador apenas mostrará o mínimo possível; se o valor for `#!c 15.00`, usando o `#!c %g`, será exibido apenas `#!c 15`.

!!! info

    Por padrão, o `#!c %g` mostra no máximo 6 dígitos significativos: `#!c 3.14159265` é exibido como `#!c 3.14159`. Para números muito grandes ou muito pequenos ele também pode usar notação científica, como `#!c 1e+06` para `#!c 1000000.0`.

#### Operações

Podemos usar as mesmas operações que vimos, só temos que tomar um cuidado. Tente prever qual é a saída do programa:

```c
#include <stdio.h>

int main(void)
{
    double resultado = 7 / 2;

    printf("resultado = %f\n", resultado);

    return 0;
}
```

Como estamos usando o `#!c double`, o resultado esperado é `#!c 3.5`, mas recebemos `#!c 3.000000` novamente; o motivo é a mesma regra que já vimos: o tipo do resultado depende dos tipos dos números usados, **e não** do tipo da variável que o recebe. Primeiro o computador divide `#!c 7 / 2` como inteiros, obtendo `#!c 3`, e só depois converte esse `#!c 3` para `#!c double` ao guardá-lo na variável. Por padrão, um número sem ponto (`.`) é interpretado como `#!c int`, e um número com ponto, como `#!c double`. Veja como a saída sai corretamente quando usamos `.0`:

```c
#include <stdio.h>

int main(void)
{
    double resultado = 7.0 / 2.0;

    printf("resultado = %f\n", resultado);

    return 0;
}
```

!!! atenção

    O operador módulo (`%`) só funciona com inteiros. Tente `7 % 2.0` e o GCC dará o erro `invalid operands to binary %`.

### Bits e o sistema binário

Antes de continuarmos, precisamos entender por que o binário `0100 0011` vale 67. Para isso, vamos entender como se **conta** só com zeros e uns.

#### Por que binário?

O computador é feito de circuitos que diferenciam com segurança **dois estados**: tensão alta ou baixa, ligado ou desligado. Distinguir dez estados diferentes (um por dígito decimal) é muito mais difícil e propenso a erros.

A solução é usar um sistema com somente dois dígitos, chamado de **binário**. Chamamos esses dígitos de **bit**, do inglês *binary digit*.

#### Contando em decimal e em binário

!!! dica

    Entender o sistema binário é um pouco confuso no início, o importante é você **notar as similaridades com o sistema decimal**. Ao invés de 10 símbolos por dígito (`0` a `9`), usamos apenas 2 (`0` e `1`).

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

Na esmagadora maioria dos computadores, um grupo de 8 bits é chamado de **byte**, e consegue representar $2^8 = 256$ valores, de 0 a 255. Guarde esse número, ele vai explicar vários comportamentos do `#!c char`.

> Em [Memória I](./memoria-1.md) veremos como o `#!c int` usa essa mesma ideia, inclusive para representar números negativos.

### char

Representa um único caractere, como uma letra do alfabeto ou um sinal de pontuação.

```c
char caractere = 'a';
```

Lembra do começo do capítulo, quando vimos que o binário `0100 0011` (67 em decimal) pode ser interpretado de formas diferentes? Agora veremos isso na prática:

```c
#include <stdio.h>

int main(void)
{
    char letra_C = 'C';

    printf("Caractere: %c\n", letra_C);
    printf("Código:    %d\n", letra_C);

    return 0;
}
```

Declaramos uma variável do tipo `#!c char` chamada `letra_C` e usamos o `%c` para imprimir o **caractere** no terminal. Em seguida fazemos algo esquisito: imprimimos a mesma variável com o `%d`, como se fosse um `#!c int`. Por que o código funciona, e por que ele exibe `67`?

Por debaixo dos panos, o `#!c char` é só um **número inteiro**. A linguagem C define que ele ocupa **1 byte**, e é isso - na maioria dos computadores, vale 8 bits, ou seja, **256** possíveis valores.

A linguagem C **não sabe** que o número `67` é a letra `C`. Quem faz essa associação é uma **tabela de codificação**. O `%c` diz ao `#!c printf` para enviar o valor ao terminal **como um caractere**, e é o terminal que consulta a sua tabela para desenhar a letra; já o `%d` diz para mostrá-lo como número. Por isso a mesma variável aparece de duas formas.

#### De onde vem a tabela?

A linguagem C **não define** qual tabela deve ser usada. Ela só exige que o `#!c char` seja capaz de representar um conjunto básico de caracteres (letras sem acento, dígitos e pontuação comuns). Quem escolhe a tabela de verdade é o **sistema operacional**, o **terminal** e o **compilador**.

Isso faz sentido pela história. Nos anos 1960, cada fabricante tinha o seu próprio código de caracteres. O **ASCII** (1963) acabou se tornando o mais popular, mas ele só tem 128 caracteres, pensados para o inglês, e por isso não tem acentos. A IBM, por exemplo, usava outra tabela, o EBCDIC, em que a letra `C` **não vale** 67, mas sim **195**. Quando o C foi criado (1972), esses sistemas coexistiam, então a linguagem evitou se prender a uma única tabela. Esse é um dos motivos de ela ter sido tão portável.

Para dar conta de outros idiomas, surgiram tabelas de 8 bits que aproveitavam os valores de 128 a 255 para acentos (como a Latin-1), mas cada país usava uma diferente. O **Unicode** (1991) resolveu isso ao criar **uma única tabela** com os caracteres de praticamente todas as línguas. Hoje, quase todos os sistemas usam o Unicode. A codificação mais comum é o **UTF-8** (Linux, macOS e a web), que mantém os 128 primeiros valores **idênticos ao ASCII**.
Por isso, na prática, `'C'` vale `67` em praticamente qualquer computador moderno.

> O Windows usa internamente outra codificação do Unicode, o UTF-16, e o terminal ainda pode usar tabelas antigas, por isso configuramos o PowerShell para UTF-8 em [Instalando o C](./instalacao.md).

Você pode consultar a [Tabela ASCII](https://www.ime.usp.br/~kellyrb/mac2166_2015/tabela_ascii.html) para ver os valores dos caracteres básicos.

#### Aspas simples

Repare que usamos aspas **simples** (`'C'`) e não aspas duplas. Em C, `'C'` representa **um único caractere** (na prática, seu código numérico), enquanto `"C"` representa um **texto**, isto é, um conjunto de caracteres. Veremos a diferença com mais detalhes em [Strings](./strings.md).

#### E os acentos?

Em UTF-8, apenas os 128 primeiros valores ocupam 1 byte. Caracteres como `ê` e `ç` ocupam **2 bytes ou mais**, então **não cabem em um único `#!c char`**. É por isso que os acentos funcionam dentro de textos (que são conjuntos de `#!c char`), mas dão problemas quando tentamos guardá-los em um `#!c char` sozinho. Veremos isso em [Strings](./strings.md).

#### E o `\n`?

Quando escrevemos `#!c \n`, não temos um caractere `\` seguido de um `n`: a **barra invertida** (`\`) inicia uma **sequência de escape**, que representa **um único caractere** difícil de digitar. O `#!c \n`, por exemplo, é o caractere de **nova linha**, que vale `#!c 10` na tabela ASCII. Ele é um **caractere de controle**: os valores de `#!c 0` a `#!c 31` da tabela não são símbolos visíveis, mas sim **comandos** para o terminal, como quebrar a linha.

Algumas sequências de escape:

| Sequência | Significado               | Valor |
| :-:       | :-                        | :-:   |
| `\n`      | Nova linha                | 10    |
| `\t`      | Tabulação                 | 9     |
| `\0`      | Caractere nulo            | 0     |
| `\\`      | A própria barra invertida | 92    |
| `\'`      | Aspas simples             | 39    |
| `\"`      | Aspas duplas              | 34    |

Nem toda sequência de escape é um caractere de controle: `\\`, `\'` e `\"` representam símbolos visíveis que, sem o escape, teriam outro significado. Teste você mesmo com `printf("%d\n", '\n');`. Veremos o uso do `\0` em [Strings](./strings.md).

#### Operações com `#!c char`

Como o `#!c char` é um número no final das contas, podemos fazer contas com ele. O código a seguir é válido:

```c
#include <stdio.h>

int main(void)
{
    char c = 'C' - 2;

    printf("Caractere: %c\n", c);
    return 0;
}
```

O código anterior calcula `'C' - 2`, ou seja, `67 - 2`, que resulta em `65`, a letra `A` (em tabelas compatíveis com o ASCII, como o UTF-8).

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

!!! info

    Chamamos os estados **verdadeiro** e **falso** de `#!c true` e `#!c false`, respectivamente.

Diferente dos outros tipos primitivos, para declararmos uma variável booleana precisamos primeiro importar sua definição da Biblioteca Padrão, com o `#!c #include <stdbool.h>`. Isso acontece porque, na versão 11 do C (chamada de "C11"), o tipo booleano nativo se chama `_Bool`; o header `#!c stdbool.h` define os nomes `#!c bool`, `#!c true` e `#!c false` para facilitar a leitura. (A partir da versão 23, esses três nomes passam a ser palavras reservadas e o header deixa de ser necessário.)

Podemos imprimir um `#!c bool` com o `%d`:

```c
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    bool estou_feliz = true;

    printf("estou_feliz = %d\n", estou_feliz);

    return 0;
}
```

Aparece `1` para `#!c true` e `0` para `#!c false`, pois, por debaixo dos panos, o `#!c bool` é só um número, assim como o `#!c char` ou `#!c int`. Veremos isso melhor em [Condicionais](./condicionais.md).


## Regras de Nomenclatura

Cada variável ou função que criamos precisa de um **nome**, para que possamos nos referir a ela depois. Esses nomes são chamados formalmente de **identificadores**, e valem para variáveis, funções e, mais para frente, `struct`s, `enum`s e outros elementos.

Para o compilador, o identificador é só uma sequência de caracteres que ele precisa **separar do resto do código**. Se os nomes pudessem ter qualquer símbolo, ele não saberia onde um nome termina e outra coisa começa. As regras existem para tornar essa separação **inequívoca**.

### Caracteres permitidos

Um identificador pode ser formado por:

- Letras **minúsculas** e **maiúsculas** (`a` a `z`, `A` a `Z`);
- **Dígitos** (`0` a `9`); e
- O **sublinhado** (`_`), também chamado de *underscore*.

Isso significa que **espaços** e símbolos como `-`, `+`, `.` e `@` **não** são permitidos. O motivo é simples: todos eles já têm outro significado para o compilador. Veja o que acontece com `-`:

```c
int nota-final = 10;
```

O compilador lê o nome até onde ele é válido, ou seja, `nota`, e então encontra o `-`, que para ele é o operador de **subtração** e não faz parte do nome. Como uma declaração não pode continuar com uma subtração, ele reclama:

```console
$ gcc -o main main.c
main.c: In function ‘main’:
main.c:5:13: error: expected ‘=’, ‘,’, ‘;’, ‘asm’ or ‘__attribute__’ before ‘-’ token
    5 |     int nota-final = 10;
      |             ^
```

> O GCC ainda mostra outros erros em seguida (como `'final' undeclared`), mas o primeiro costuma ser o mais importante.

O mesmo vale para o espaço, que separa uma palavra da outra. Quando precisamos de um nome com mais de uma palavra, usamos o sublinhado: `nota_final`.

Tente compilar esta versão:

```c
int nota final = 10;
```

O GCC vai reclamar de algo parecido com:

```console
$ gcc -o main main.c
main.c: In function ‘main’:
main.c:5:14: error: expected ‘=’, ‘,’, ‘;’, ‘asm’ or ‘__attribute__’ before ‘final’
    5 |     int nota final = 10;
      |              ^~~~~
```

> A mensagem exata muda de acordo com a versão do GCC, mas a ideia é a mesma: ele leu `int nota` como uma declaração completa e não entendeu o que `final` está fazendo ali.

### Não começar com dígito

Um identificador **não pode começar com um dígito**, mas pode ter dígitos nas demais posições. Então `pessoa1` e `vida_2` são válidos, enquanto `1pessoa` e `02_vida` não são.

A razão é a mesma de antes: o compilador precisa saber **logo no primeiro caractere** se está lendo um número ou um nome. Se começa com dígito, ele trata o que vem a seguir como um **número**. Com `1pessoa`, ele lê o `1`, tenta entender o `pessoa` como parte do número (um sufixo, como o `f` de `6.72f`) e falha:

```
main.c:5:9: error: invalid suffix "pessoa" on integer constant
    5 |     int 1pessoa = 5;
      |         ^~~~~~~
```

### Maiúsculas e minúsculas

A linguagem C é ***case-sensitive***, isto é, **diferencia** letras maiúsculas de minúsculas. Os nomes `vida`, `Vida` e `VIDA` são três identificadores **diferentes**:

```c
#include <stdio.h>

int main(void)
{
    int vida = 3;
    int Vida = 10;
    int VIDA = 100;

    printf("%d %d %d\n", vida, Vida, VIDA);

    return 0;
}
```

Isso é uma faca de dois gumes: por um lado, permite diferenciar nomes por convenção; por outro, um simples erro de digitação, como escrever `Vida` quando queríamos `vida`, vira um erro de compilação (ou, pior, o uso de uma variável diferente). Por isso, **evite** nomes que só se diferenciam pelas maiúsculas.

### Acentos e outros caracteres

Os acentos **não fazem parte** da lista de caracteres permitidos. Mesmo assim, o código a seguir pode compilar sem erros, dependendo do compilador:

```c
int café = 3;
```

A explicação está na história. Quando o C foi criado, os computadores usavam tabelas de caracteres **sem acentos**, como o ASCII (que vimos em [char](#char)). Com o Unicode, os padrões mais novos da linguagem (C99 e C11) passaram a permitir **outros caracteres** em identificadores, mas **deixam a decisão para cada compilador**. O GCC, a partir da versão 10, aceita nomes escritos diretamente em UTF-8.

Mas só porque *pode* funcionar, não significa que *deve* ser usado:

- O código fica **menos portável**: outro compilador, ou outra versão do GCC, pode recusá-lo.
- Se o arquivo for salvo em uma **codificação diferente** da esperada pelo compilador (lembra que `ê` ocupa mais de 1 byte em UTF-8?), o nome pode ser lido de forma errada.
- Nem todo teclado facilita digitar acentos, e isso atrapalha quem for ler ou mexer no seu código depois.

Por isso, escreva `cafe` e `pontuacao` mesmo que o seu compilador aceite `café` e `pontuação`.

### Palavras reservadas

Algumas palavras têm um **significado fixo** dentro da linguagem, como `#!c int`, `return`, `if` e `while`. Elas são chamadas de **palavras reservadas** (ou *keywords*) e **não podem** ser usadas como identificadores:

```c
int return = 5;
```

```
main.c:5:9: error: expected identifier or ‘(’ before ‘return’
    5 |     int return = 5;
      |         ^~~~~~
```

O compilador esperava um **nome**, mas encontrou o comando `return`. Veja a lista completa de palavras reservadas do C11:

??? nota "Lista de Palavras Reservadas"

    ```
    auto      break     case      char      const     continue
    default   do        double    else      enum      extern
    float     for       goto      if        inline    int
    long      register  restrict  return    short     signed
    sizeof    static    struct    switch    typedef   union
    unsigned  void      volatile  while
    _Alignas  _Alignof  _Atomic   _Bool     _Complex  _Generic
    _Imaginary          _Noreturn _Static_assert      _Thread_local
    ```

Você não precisa decorar nada disso. Com o tempo, o seu editor vai **colorir** essas palavras de forma diferente das variáveis, e o compilador avisa quando houver conflito.

> Repare que `#!c bool`, `#!c true` e `#!c false` **não estão** na lista: no C11, eles são definidos por `<stdbool.h>`, como vimos em [bool](#bool). Mesmo assim, não use esses nomes para suas variáveis, já que o resultado seria confuso (e um erro caso você inclua o *header*).

### Nomes que parecem permitidos, mas não são uma boa ideia

Existem nomes que o compilador **aceita**, mas que causam problemas por debaixo dos panos.

**Começar com sublinhado.** Nomes que começam com `_` seguido de uma letra maiúscula (como `_Vida`), ou com dois sublinhados (como `__vida`), são **reservados** para o compilador e a Biblioteca Padrão. Usá-los é um *comportamento indefinido*, isto é, o padrão da linguagem não define o que acontece, já que eles podem entrar em conflito com algo que o compilador define por conta própria. Os que começam com `_` e uma letra minúscula também são reservados quando declarados fora de qualquer função. A regra prática é: **não comece nomes com sublinhado**.

**Reutilizar nomes da Biblioteca Padrão.** Nada impede você de criar uma variável chamada `#!c printf` ou `scanf`:

```c
int printf = 5;
```

Dentro de uma função, isso apenas **esconde** a função original (em [Funções](./funcoes.md#escopos) veremos que a variável do escopo mais interno tem preferência), e você não conseguirá mais chamar o `#!c printf` ali: o GCC reclama que `called object ‘printf’ is not a function or function pointer`. Se isso for feito fora de qualquer função, o compilador acusa conflito com a declaração em `<stdio.h>` (`‘printf’ redeclared as different kind of symbol`).

### Tamanho do nome

Existe um limite para o tamanho de um identificador, mas ele é **muito grande**: o padrão do C11 exige que o compilador distinga nomes por pelo menos os **63 primeiros caracteres** (31 para nomes visíveis entre arquivos). Na prática, você nunca vai esbarrar nisso.

Nem sempre foi assim. No C original, dos anos 1970, só os **8 primeiros caracteres** de um nome importavam e, mesmo no C89, nomes visíveis entre arquivos só precisavam ser distintos nos **6 primeiros** (uma limitação dos *linkers* da época). Duas variáveis chamadas `pontuacao_jogador1` e `pontuacao_jogador2` poderiam ser vistas como a **mesma coisa**, já que os primeiros 8 caracteres, `pontuaca`, são iguais! Isso ajuda a explicar por que tantos nomes antigos da Biblioteca Padrão são curtos e enigmáticos, como `strcpy`, `strlen` e `#!c printf`. Hoje esses limites são grandes o bastante para não nos preocuparmos, então não há motivo para economizar letras.

### O nome só existe para humanos

Uma curiosidade: depois que o código é compilado, os nomes das **variáveis locais somem** (a menos que você peça ao compilador para guardá-los para um depurador). O processador não sabe o que é `idade` ou `saldo`; ele trabalha com **endereços de memória** e registradores. O compilador usa os seus identificadores para descobrir quais pedaços do código se referem à mesma variável, e depois os troca por posições na memória.

Ou seja, os nomes são feitos **para humanos**, e o computador se vira sem eles. Isso é uma boa razão para escolhê-los pensando em quem vai ler o código, que pode ser você daqui a um mês.

### Convenções do guia

Além das regras (o que o compilador **exige**), existem as **convenções** (o que a comunidade **recomenda**). Neste guia vamos usar:

- ***snake_case*** para variáveis e funções: todas as letras em minúsculas, com palavras separadas por sublinhado, como em `saldo_final` e `nota_final`;
- Nomes **descritivos em português**, sem acentos nem abreviações misteriosas, como `pontuacao` em vez de `p` ou `pont`; e

Outros projetos usam convenções diferentes, como o *camelCase* (`saldoFinal`). O importante é **escolher uma e ser consistente** em todo o código.

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

```console
$ gcc -o main main.c
main.c: In function ‘main’:
main.c:7:8: error: assignment of read-only variable ‘pi’
    7 |     pi = 3.14159;
      |        ^

```

É a segunda linha da saída do comando que nos interessa: `error: assignment of read-only variable ‘pi’`.
Ela fala que ocorreu um erro ao atribuir algum valor a uma variável _read-only_, do inglês "apenas de leitura", chamada `pi`. Esse erro é uma garantia do compilador de que não podemos alterar variáveis constantes.

Se amanhã nós precisarmos aumentar a precisão da constante `pi`, isto é, aumentar o número de casas depois da vírgula, nós só precisamos alterar em **um lugar** - se não usássemos constantes, e o `pi` fosse usado em dezenas de cálculos, teríamos que procurar cada caso com o valor `3.14` e trocá-lo. Por exemplo, para atualizar a constante:

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

### Inicialização

Sempre que declarar uma variável, é recomendado que você a inicialize com um valor padrão, como `#!c 0` ou `#!c 1` para o tipo `#!c int`. Escreva esse programa e **rode ele mais de uma vez**:

```c
#include <stdio.h>

int main(void)
{
    int numero;

    printf("número = %d\n", numero);

    return 0;
}
```

Você verá que a variável `numero` armazena um valor imprevisível, o chamado **lixo de memória**: o que já estava naquele espaço antes de o programa usá-lo. Em alguns computadores o valor pode se repetir (como `0`), mas isso é coincidência e não pode ser contado. Na verdade, o padrão da linguagem diz que ler uma variável não inicializada é um *comportamento indefinido*. O motivo disso ficará claro em [Memória I](./memoria-1.md), por ora, sempre inicialize suas variáveis para evitar usar valores imprevisíveis acidentalmente.

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

Você saberia dizer o que os valores `#!c 0.1` e `#!c 15.0` representam? Pelo contexto talvez você consiga adivinhar, mas só depois de gastar um tempo decifrando o código. No caso, eles representam a **taxa de serviço** e o **preço da reserva por pessoa**, respectivamente.

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

Agora, conseguimos ler o cálculo da variável `total` da seguinte forma: o total é a conta somada à taxa de serviço (um percentual da conta) e às reservas de cada pessoa. E de novo, se precisarmos diminuir a taxa de serviço, por exemplo, só precisamos mudar em um só lugar.
