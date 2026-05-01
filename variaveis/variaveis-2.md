# Variáveis II

## Regras de Nomenclatura

Essas regras são válidas para toda a linguagem C, não somente para variáveis.

- São permitidos os seguintes caracteres: letras (minúsculas e maiúsculas), dígitos (de 0 a 9) e o sublinhado (`_`), também chamado de *underline*.
- Não é permitido começar com um dígito.
- A linguagem C diferencia letras minúsculas das maiúsculas. Por exemplo, o computador vê as variáveis `Vida`, `vida` e `VIDA` como coisas diferentes.
- Você não pode nomes de comandos internos da linguagem. Palavras como `int`, `return`, `if`, `while` e `char` são proibidas de serem usadas como nomes.

### Boas práticas

Evite nomes misteriosos. Em vez de `int p;`, use `int pontuacao;`. O nome da variável deve conseguir transmitir sua função dentro de seu contexto.

Evite o encurtamento dos nomes, como escrever `int vf;` ao invés de `int valor_final;`. Quando você nomeia bem o seu código, mesmo que demore um pouco mais para digitar agora, daqui a um mês, quando precisar mudar o código denovo, os nomes mais claros te ajudaram a relembrar a lógica do código. Por isso, não se prenda a regra de apenas 8 caracteres!

Ao longo do guia, veremos ainda mais casos de como melhorar a sua nomenclatura. Enquanto estava aprendendo a programar, achava difícil pensar em bons nomes para as coisas. Se você se sente assim, recomendo utilizar Inteligência Artificial para ter ideias de como nomear bem.

## Escopos

Os escopos delimitam a região em nosso código que uma variável fica disponível.

Por exemplo, no programa a seguir, a variável `numero` foi criada no **escopo global**, e portanto, fica disponível tanto para a função `main` quanto para qualquer outra função declarada no mesmo arquivo.

Em um arquivo chamado `main.c`, digite:

``` c
#include <stdio.h>

int numero = 0;

int main()
{
    printf("Numero: %d\n", numero);

    return 0;
}
```

Sempre que declarar uma variável, é recomendado que você inicialize ela com um valor padrão, independente do escopo da variável. Nesse caso, inicializamos a variável `numero` com o valor 0. O motivo disso ficará claro em [Ponteiros](../ponteiros/README.md), por hora sempre inicialize suas variáveis.

Agora, vamos declarar outra função, chamada `retorna_numero`, que retorna uma copia do valor armazenado na variável **global** `numero` e recebe nenhum argumento:

``` c
#include <stdio.h>

int numero = 0;

int retorna_numero()
{
    return numero;
}

int main()
{
    printf("Numero de retorna_numero: %d\n", retorna_numero());

    return 0;
}
```

 Note que declaramos a função `retorna_numero` à cima de `main`. Se declararmos ela em baixo, o compilador não irá saber o que executar quando rodarmos `retorna_numero()` dentro do `printf`. Mude a declaração da função `retorna_numero` para o final e veja o que acontece.

Agora vamos adicionar outra variável chamada `numero`, só que em um lugar diferente do código, e ver como o programa vai se comportar:

``` c
#include <stdio.h>

int numero = 0;

int retorna_numero()
{
    return numero;
}

int main()
{
    int numero = 7;
    printf("Numero de main: %d\n", numero);

    printf("Numero de retorna_numero: %d\n", retorna_numero());

    return 0;
}
```

Quando fazemos, dentro da função `main`, a declaração `int numero = 7;`, estamos criando uma nova **variável local da função `main`** que também se chama `numero`, mas tem o valor de 7. Desse modo, nosso programa possui uma variável global e outra local, ambas com o nome de `numero`, mas como o compilador sabe quando teve usar cada uma?

Isso se deve a uma regra da linguagem C: **a variável do escopo mais interno tem preferência sobra a do escopo mais externo**. O escopo pode ser definido em cima do arquivo, para variáveis globais, ou dentro das **chaves** `{}`, para variáveis locais. Nesse caso, as variáveis locais fazem parte do escopo de suas respectivas funções.

Quando declaramos `int numero = 7;` dentro de `main`, o compilador passa a usar essa variável local no primeiro `printf`. Contudo, no segundo `printf`, usamos o valor de uma função, nesse caso a `retorna_numero`. Olhe bem para a definição de `retorna_numero`, você percebe alguma declaração de uma variável chamada `numero`? Como não estamos declarando nenhuma variável, o compilador usará a variável do escopo global.

O próximo exemplo mostra o que acontece quando declaramos duas variáveis com o mesmo nome no mesmo escopo:

``` c
#include <stdio.h>

int main()
{
    int numero = 7;
    printf("Primeira definição: %d\n", numero);

    int numero = 2;
    printf("Segunda definição: %d\n", numero);

    return 0;
}
```

Tente remover o `int` quando a variável `numero` recebe 2, ou seja, em `int numero = 2;`. Agora, o programa irá compilar e mostrará dois valores distintos.

Esse código não irá compilar devido a uma regra da linguagem C: é permitido a declaração de variáveis com o mesmo nome, contanto que as variáveis fiquem em **escopos diferentes**. Como ambos as variáveis `numero` fazem parte do escopo da função `main`, elas violam a regra.

### Boas Práticas

É recomendado, mas não obrigatório, adicionar o prefixo `g_` para suas variáveis globais. Isso deixa muito claro quais variáveis são globais e quais são locais.

No exemplo a seguir, deixamos claro que estamos incrementando a variável global `g_numero` por 1:

``` c
#include <stdio.h>

int g_numero = 0;

int main()
{
    int numero = 7;

    g_numero = g_numero + 1;

    printf("Numero local: %d\n", numero);

    printf("Numero global: %d\n", g_numero);

    return 0;
}
```

## Constantes

São valores que, ao serem declarados, não podem mudar de valor.

Por exemplo, vamos declarar o valor da constante `pi`.

> Não se esqueça de importar `#include <stdio.h>` e declarar a função `main`!

``` c
const double pi = 3.14;

printf("Pi vale aproximadamente %f\n", pi);
```

Se tentarmos alterar o valor de `pi`, teremos um erro na compilação:

``` c
const double pi = 3.14;

pi = 30.1;

printf("Pi vale aproximadamente %f\n", pi);
```

### Boas práticas

As variáveis constantes são ótimas para eliminar os chamados **valores mágicos**. No exemplo a seguir usamos alguns **números soltos** para calcular o salário de um funcionário. Eles não carregam nenhuma valor por si só, nem o contexto deixa claro suas funções.

> Não esqueça de declarar a função `calcular_salario` a cima de `main` e executar ela antes do `return 0;`!

``` c
double calcular_salario(double horas)
{
    return (horas * 25.5) + (horas * 25.5 * 0.15);
}
```

Agora, dando nomes aos seus valores, seus papéis ficam claros:

``` c
double calcular_salario(double horas)
{
    const double valor_hora = 25.5;
    const double adicional_noturno = 15.0 / 100.0;

    return (horas * valor_hora) + (horas * valor_hora * adicional_noturno);
}
```

Com as novas informações, sabemos que a função `calcular_salario` calcula o sálario por hora mais um bônus de trabalho noturno de 15%.

Você pode estar pensando: será que não poderíamos usar comentários ao invés de constantes? Vamos verificar:

> É comum usarmos `///` ao invés de `//` para comentário que explicam o funcionamento de funções. Esses comentários ficam em cima da definição da função.

``` c
/// Calcula o salário de um funcionario
/// 25.5 => Representa o valor por hora trabalhado
/// 0.15 => Representa o adicional ao trabalho noturno
double calcular_salario(double horas)
{
    return (horas * 25.5) + (horas * 25.5 * 0.15);
}
```

A respota é sim, podemos, mas nesse caso elas não são a melhor opção, por 2 motivos:

1. **Comentários não ajudam na manutenção**. Se decidirmos mudar o valor do adicional noturno de 15% para 10%, teríamos que mudar em dois lugares diferentes. Basta esquecer de mudar uma só vez para criar uma discrepância.
2. **O código autocomentado é mais fluido**. Para interpretarmos a função com comentário, toda vez que nos depararmos com um número, temos que pular para a seção de comentários. Em contra partida, ao usarmos variáveis constantes, a leitura se torna sequencial.

Os comentários são ideias para deixar claro o **por quê** dos valores serem esses, e as variáveis constantes mostram **quais** são esses valores. Sendo assim, a versão final da função seria:

``` c
/// Calcula o salário de um funcionário
/// Valor Hora: Escolha baseada no regulamento xxx
/// Adicional Noturno: Bônus garantido como cortesia
double calcular_salario(double horas)
{
    const double valor_hora = 25.5;
    const double adicional_noturno = 15.0 / 100.0;

    return (horas * valor_hora) + (horas * valor_hora * adicional_noturno);
}
```
