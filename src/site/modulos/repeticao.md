# Estruturas de Repetição

Em [Estruturas Condicionais](./condicionais.md), nosso código decidia **se** um bloco rodava ou não, mas cada bloco ainda rodava **no máximo uma vez**. Agora pense em somar os números de 1 a 100, ou perguntar uma senha até o usuário acertar - **sem saber de antemão** quantas vezes isso vai acontecer. Copiar e colar o mesmo `printf` cem vezes não é prático, e muito menos escrever um `if` para cada tentativa de senha.

As **estruturas de repetição** resolvem esse problema: elas executam um bloco de código **repetidas vezes**, enquanto uma condição continuar verdadeira.

## `#!c while`

A sintaxe do `#!c while` é parecida com a do `#!c if`, só que o bloco roda **repetidas vezes**, e não apenas uma:

```c
while (condição)
{
    // Roda enquanto "condição" for verdadeira.
}
```

Vamos começar com o seguinte problema: uma pessoa quer saber em **quantos meses** sua poupança **duplica de valor**. Essa poupança funciona no regime de **Juros Compostos**.

??? pergunta "Esqueceu como calcular Juros Compostos? Aqui está uma revisão!"

    Em uma aplicação de Juros Compostos, você deposita um valor inicial, representado pela letra $C$, que **rende** a cada período (como um mês) de acordo com uma taxa, representada pela letra $i$. A ideia central é que **o rendimento de um mês passa a fazer parte do valor que rende no mês seguinte** - por isso o nome "composto": o juros também gera juros.

    Vamos pensar em uma aplicação de valor inicial R\$ 100 e taxa de 50% por mês. No primeiro mês, o valor rende 50% de R\$ 100, ou seja, R\$ 50, totalizando R\$ 150. Mas, no segundo mês, a taxa de 50% não incide mais sobre os R\$ 100 originais, e sim sobre os **R\$ 150 acumulados**, totalizando R\$ 225 - e assim por diante.

    Chamando de $M$ o valor acumulado **até certo mês**, podemos escrever essa ideia da seguinte forma, onde cada mês depende apenas do valor acumulado no **mês anterior**:

    $$
    \begin{aligned}
    M_0 &= 100 \\
    M_1 &= M_0 \times (1 + 0,5) = \textbf{150} \\
    M_2 &= M_1 \times (1 + 0,5) = \textbf{225} \\
    M_3 &= M_2 \times (1 + 0,5) = \textbf{337,5} \\
    \end{aligned}
    $$

    Se expandirmos essa repetição para $t$ meses, chegamos à fórmula fechada dos Juros Compostos:

    $$
    M = C(1 + i)^t
    $$

    Repare que essa fórmula já **é** uma repetição: $(1 + i)^t$ nada mais é do que multiplicar $(1 + i)$ por si mesmo $t$ vezes. Em breve veremos como o `#!c while` nos permite calcular esse valor **passo a passo**, mês a mês, sem precisar dessa fórmula fechada.

O valor inicial é de R\$ 1000, armazenado na variável `arrecadado`, e ele varia a uma taxa de 10% ao mês (variável `taxa`). O dobro do valor inicial está em `meta`, e a quantidade de meses em `meses`:

```c
#include <stdio.h>

int main(void)
{
    double taxa = 0.1;

    double arrecadado = 1000.0;
    double meta = arrecadado * 2.0;

    int meses = 0;

    // ...

    printf("Demorou %d meses para dobrar!\n", meses);

    return 0;
}
```

Repare que inicializamos `meses` com `#!c 0`, já que ainda não passou nenhum mês e, portanto, `arrecadado` armazena o **valor inicial** da aplicação.

Mas como calculamos essa quantidade de meses? É aqui que o `#!c while` entra: ele executa um bloco de código **enquanto** uma condição for verdadeira e, assim que ela se torna falsa, o `#!c while` termina e o programa continua. Nesse problema, queremos continuar atualizando `arrecadado` **enquanto** seu valor for **menor que** a `meta`. Lendo em português: "enquanto o valor arrecadado for menor que a meta, continue atualizando". O código, **sem a atualização**, fica assim:

```c hl_lines="12-17"
#include <stdio.h>

int main(void)
{
    double taxa = 0.1;

    double arrecadado = 1000.0;
    double meta = arrecadado * 2.0;

    int meses = 0;

    while (arrecadado < meta)
    {
        // ...

        printf("Mês %d: R$ %.2f\n", meses, arrecadado);
    }

    printf("Demorou %d meses para dobrar!\n", meses);

    return 0;
}
```

Para atualizar o valor arrecadado, fazemos a seguinte operação: `#!c arrecadado = arrecadado * (1.0 + taxa)`, ou seja, o valor arrecadado **antigo** é multiplicado pelo fator de aumento (`#!c (1.0 + taxa)`) e guardado de volta na mesma variável. Como essa atualização ocorre **por mês**, incrementamos a variável `meses` da seguinte forma: `#!c meses = meses + 1`. No código final, fica assim:

```c linenums="1"
#include <stdio.h>

int main(void)
{
    double taxa = 0.1;

    double arrecadado = 1000.0;
    double meta = arrecadado * 2.0;

    int meses = 0;

    while (arrecadado < meta)
    {
        arrecadado = arrecadado * (1.0 + taxa);
        meses = meses + 1;

        printf("Mês %d: R$ %.2f\n", meses, arrecadado);
    }

    printf("Demorou %d meses para dobrar!\n", meses);

    return 0;
}
```

Essa é a saída do programa:

```console hl_lines="10"
$ ./main
Mês 1: R$ 1100.00
Mês 2: R$ 1210.00
Mês 3: R$ 1331.00
Mês 4: R$ 1464.10
Mês 5: R$ 1610.51
Mês 6: R$ 1771.56
Mês 7: R$ 1948.72
Mês 8: R$ 2143.59
Demorou 8 meses para dobrar!
```

Damos o nome de **iteração** cada vez que o código dentro do `#!c while` é executado. Na tabela a seguir, está descrito a relação entre cada iteração do `#!c while` e: o valor `arrecadado` antes da iteração; se `arrecadado` é menor que a `meta`; o valor atualizado de `arrecadado`; e o mês.

| Iteração | `arrecadado` (antes) | `#!c arrecadado < meta` ? | **`arrecadado` (depois)** | meses |
| :-: | :-: | :-: | :-: | :-: |
| 1 | `#!c 1000.0` | Sim, `#!c 1000.0 < 2000.0` | `#!c 1100.0` | 1 |
| 2 | `#!c 1100.0` | Sim, `#!c 1100.0 < 2000.0` | `#!c 1210.0` | 2 |
| 3 | `#!c 1210.0` | Sim, `#!c 1210.0 < 2000.0` | `#!c 1331.0` | 3 |
| ... | ... | ... | ... | ... |
| 7 | `#!c 1610.51` | Sim, `#!c 1610.51 < 2000.0` | `#!c 1948.72` | 7 |
| 8 | `#!c 1948.72` | Sim, `#!c 1948.72 < 2000.0` | **`#!c 2143.59`** | 8 |
| - | `#!c 2143.59` | **Não, `#!c 2143.59 < 2000.0`!** | **fim do loop (nada executado)** | 8 |

### Loop infinito

<!-- Explicar o que é um loop infinito. -->

## for

Para entendermos o porquê da estrutura de repetição `for` existir, vamos criar um contador de 1 até 10 usando o `while`.

```c
int indice = 1;
while (indice != 10)
{
 printf("Índice atual: %d\n", indice);

 indice++;
}
```

Antes de corrigirmos um erro lógico em nosso contador, vamos ver do que ele é feito:

1. **Inicialização** antes do `while` _loop_. É a declaração da variável `indice` com o **valor inicial** de `1`.
2. **Condição** dentro do `while`. É quando comparamos o valor atual da variável `indice` com `10`.
3. **Atualização** ao final do `while`. Usamos da sintaxe `indice++` para indicar que estamos incrementando a variável `indice` em um. Essa parte é essencial para impedir um **loop infinito**. Note que poderíamos ter usado `indice += 1` também.

O erro está aqui: o contador só vai até nove! Para entendermos o porquê disso, vamos verificar o resultado da condição `indice != 10` para todos os valores de `indice`, até que a condição se torne falsa. Lembre-se de que o `printf` só irá **mostrar o índice** atual **se a condição for verdadeira**, caso contrário, nada será impresso no terminal.

| indice | indice != 10            |
| :----: | :---------------------- |
|   1    | `1 != 10` => Verdadeiro |
|   2    | `2 != 10` => Verdadeiro |
|   3    | `3 != 10` => Verdadeiro |
|  ...   | ...                     |
|   8    | `8 != 10` => Verdadeiro |
|   9    | `9 != 10` => Verdadeiro |
| **10** | `10 != 10` => **Falso** |

Na última linha da tabela, o valor de `indice` é 10. Dessa forma, a condição `10 != 10` é falsa, já que 10 é igual a 10.

Para consertar esse erro, vamos usar da desigualdade **menor ou igual**, escrita como `<=`. O programa ficará assim:

```c
int indice = 1;
while (indice <= 10)
{
 printf("Índice atual: %d\n", indice);

 indice++;
}

return 0;
```

Lemos o `while` da seguinte maneira: enquanto o `indice` for **menor ou igual** a 10 imprima o índice atual e incremente a variável `indice` em 1.

Agora, vamos ver um jeito mais simples de escrever essa mesma lógica, usando um `for` _loop_. Essa estrutura de repetição junta a **inicialização**, a **condição** e o **incremento** em uma única linha, facilitando a leitura e eliminando erros, como esquecer de incrementar o índice ao final do _loop_.
O mesmo programa acima pode ser escrito nesse novo formato:

```c
for (int indice = 1; indice <= 10; indice++)
{
 printf("Índice atual: %d\n", indice);
}
```

Por último, vamos criar um programa que imprime a tabuada de um número.

Primeiro, vamos criar uma variável global chamada `total`, que armazenará o total de números da tabuada, que são `10`.

> Escreva o código dentro da função `main`. Não se esqueça de importar o header `stdio` e retornar `0` ao final de `main`.

```c
const int total = 10;
```

Depois, vamos perguntar ao usuário de qual número será a tabuada.

```c
int numero = 0;
printf("Digite um número para saber sua tabuada: ");
scanf("%d", &numero);
```

E agora, vamos criar o _loop_ que vai exibir a tabuada.

```c
for (int indice = 1; indice <= total; indice++)
{
 int resultado = numero * indice;
 printf("%d x %d = %d\n", numero, indice, resultado);
}
```

