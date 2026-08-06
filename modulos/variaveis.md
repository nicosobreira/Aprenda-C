# Variáveis I

As variáveis servem para **armazenar** valores na **memória do computador**. Elas nos permitem guardar informações bem diferentes, como: idade de uma pessoa, preço de um produto e se um usuário está logado ou não.
O primeiro é um número inteiro, o outro tem casas depois da vírgula, e o último só pode ser verdadeiro ou falso.
Lembra que em [O que é C?](../intro/linguagem-c.md) vimos que o computador só lida com zeros e uns? Mas como o computador guarda dados tão diferentes entre si, se ele só entende 0 e 1?

A verdade é que o computador interpreta os zeros e uns da maneira que nós, programadores, mandamos. Tomamos o número binário `0100 0011` como exemplo. Quando o computador olha para o binário, ele não tem a menor ideia do que ele significa.
Para a máquina, a sequência `0100 0011` é apenas um dado bruto. No entanto, se nós mandarmos o computador interpretar isso como um número inteiro, o valor é 67. Ao final do módulo, veremos que esse mesmo binário representa um outro tipo de informação: uma letra.

## Declaração

Declarar a variável nada mais é do que mostrar para o computador como um número binário deve ser chamado (nome), como teve ser interpretado (tipo) e qual é o seu tamanho - essa ultima parte fica para um próximo módulo.

<!-- TODO: Fazer um link com o módulo futuro sobre o tamanho das variáveis. -->

Para declarar uma variável em C, escrevemos:

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
A seguir nós **inicializamos** a variável `numero` com o valor `10`:

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

Para exibirmos o valor da variável `idade`, usaremos a função `printf`, que precisa do `#include <stdio.h>` para ser usada.

A função `printf` pode receber mais de um argumento, separados por ",". O primeiro já sabemos que é um texto, mas os outros podem ser variáveis de qualquer tipo primitivo e são usados para imprimir os valores das variáveis no terminal.

No código abaixo, imprimimos o valor da variável `idade`:

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

Nós também podemos fazer **operações aritméticas** entre variáveis e números. São elas:

- **Soma**: `int resultado = 20 + 10`
- **Subtração**: `int resultado = 1 - 10`
- **Multiplicação**: `int resultado = 5 * 20`
- **Divisão**: `int resultado = 8 / 2`
- **Módulo**, dá o resultado do **resto da divisão**: `int resto_1 = 9 % 2`

Nós também usamos parênteses `( )` para indicar a ordem de importância das operações.

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

Dependendo do tipo da variável que passamos para o `printf` nós podemos mudar como o valor será exibido. Por exemplo, para exibirmos apenas duas casas depois da vírgula, usamos:

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

Tá lembrado no começo do capítulo, quando discutimos como o binário `0100 0011` (ou 67 em decimal) pode ser interpretado de formas diferentes? Agora veremos na prática com o código a seguir:

``` c
char letra_C = 'C';

printf("Carácter: %c\n", letra_C);

printf("Índice:   %d\n", letra_C);
```

Primeiro, declaramos uma variável do tipo `char` chamada `letra_C`. Depois, usamos o `%c` para imprimir o carácter no terminal. Mas fazemos algo esquisito em seguida: imprimimos a variável `letra_C` como um `int`?! Por que o código funciona, e por que ele exibe 67?

Isso se deve ao modo como os carácteres funcionam em C. Por debaixo dos panos, o tipo `char` é um número binário de 1 byte, que é **traduzido para um carácter** por meio da [Tabela de Conversão ASCII](https://www.ime.usp.br/~kellyrb/mac2166_2015/tabela_ascii.html) apenas no momento em que será exibido.

> O valor de 1 byte na **esmagadora maioria** dos dispositivos é 8 bits.

Se você abrir essa tabela, notará duas coisas: o *código ASCII* do carácter `C` é 67; e que não existem carácteres acentuados. Isso se deve ao fato da Tabela ASCII ter sido criada pra a língua inglesa, por isso eles não colocaram acentos nela. Isso explica o por quê os acentos podem estar meio esquisitos quando exibidos.

Ao invés de usarmos aspas duplas, usamos as aspas simples, mas por quê? Veremos isso com mais detalhes em [Strings](./string.md), mas já pincelando, a linguagem C diferencia um único carácter de um texto - conjunto de caracteres - com o uso das aspas simples.


### bool

Os valores booleanos são aqueles que podem ser ou **verdadeiro** ou **falso**, mas nunca os dois ao mesmo tempo. São usados principalmente para estabelecer condições.

``` c
#include <stdbool.h>

bool estou_feliz = false;
```

Diferente dos outros tipos primitivos, para declararmos uma variável booleana, precisamos primeiro importar sua definição na Biblioteca Padrão, com o `#include <stdbool.h>`.
O motivo disso ficará claro em [Condicionais](../condicional/README.md)

Nós também não temos como imprimir um `bool` do mesmo jeito temos fazendo. Isso se deve ao fato da função `printf` não definir em sua implementação uma maneira de converter o `bool` para uma string, ou seja, não definir um código como `d` para tal. Mas nós veremos em [Condicionais](../condicional/README.md) um jeito de fazer isso.

Chamamos os estados **verdadeiro** e **falso** de `true` e `false`, respectivamente.

## Regras de Nomenclatura

Essas regras são válidas para todos **identificadores** da linguagem C, não somente para nomes de variáveis.


- São permitidos os seguintes caracteres: letras (minúsculas e maiúsculas), dígitos (de 0 a 9) e o sublinhado (`_`), também chamado de *underline*.
- Não é permitido começar com um dígito. Exemplos de identificadores errados: `1pessoa` e `02_vida`.
- Não é permitido ter acento. Exemplo: `cabeça`.
- A linguagem C diferencia letras minúsculas das maiúsculas. Por exemplo, as variáveis `Vida`, `vida` e `VIDA` como coisas diferentes.
- Você não pode usar **palavras reservadas** da linguagem. Palavras como `int`, `double`, `return`, `if`, `while` e `char` são proibidas de serem usadas como nomes de variáveis ou funções.

## Variáveis Constantes

<!-- FIX: Usar um exemplo da área de um círculo para provar que as constantes facilitam alterar múltiplos valores uma só vez. -->

São variáveis que, ao serem declaradas, não podem mudar de valor.

Por exemplo, vamos declarar a variável `pi`, com o valor aproximado da constante.

> Não se esqueça de importar `#include <stdio.h>` e declarar a função `main`!

``` c
const double pi = 3.14;

printf("Pi vale aproximadamente %f\n", pi);
```

Vamos tentar aumentar o valor da aproximação do `pi` **após** a declaração da variável:

``` c
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
Ela fala que ocorreu um erro ao atribuir algum valor à uma variável *read-only*, do inglês "apenas de leitura", chamada `pi`. Esse erro é uma garantia do compilador de que não podemos alterar variáveis constantes.

Se amanhã nós precisarmos aumentar a precisão da constante `pi`, isso é, aumentar o número de casas depois da vírgula, nós só precisamos alterar em **um lugar** - se não usássemos constantes, teríamos que procurar cada caso com o valor `3.14` e trocá-lo. Por exemplo, para atualizar a constante:

``` c
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

### Valores Mágicos

Outra vantagem das variáveis constantes é dar um **nome claro** a **um valor** "solto". No código a seguir, vamos calcular a conta final de 4 amigos em um restaurante?

``` c
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

Esses valores "soltos" são chamados de **valores mágicos**. Eles diminuem muito a clareza do nosso código. Uma solução é usar duas variáveis constantes chamadas `taxa_servico` e `preco_reserva` para deixar claro as suas funções no código:

``` c
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

