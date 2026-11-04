# Condicionais

As condicionais são estruturas que nos possibilitam avaliar condições e executar diferentes códigos dependendo de seus resultados. Para deixar essa explicação mais clara, vamos pensar em um exemplo do dia a dia: será que eu devo levar o meu guarda chuva ao sair de casa? Ao avaliarmos essa pergunta, primeiro pensamos se irá chover ou não no dia. **Se** chover, então pegamos o guarda chuva, **senão** deixamos ele em casa.

## if e else

Para resolvermos o nosso problema do guarda chuva, vamos escrever um programa que irá fazer essa decisão! Primeiro iremos declarar uma variável do tipo `#!c bool`, chamada `vai_chover`; damos o valor `#!c true` para ela. Depois iremos implementar essa lógica do **"se e senão"**.

!!! atenção

    Não se esqueça de importar a definição do tipo `#!c bool` com o header `<stdbool.h>`.

```c
#include <stdbool.h>
#include <stdio.h>

int main()
{
    bool vai_chover = true;

    if (vai_chover)
    {
        printf("Vai chover!\n");
        printf("É melhor levar o guarda chuva.\n");
    }
    else
    {
        printf("Deixe o guarda chuva em casa, não irá chover hoje.\n");
    }

    return 0;
}
```

As palavras `#!c if` e `#!c else` são traduções diretas para o "se" e "senão".
Com isso em mente, lemos esse código da seguinte forma: **se** o valor armazenado na variável `vai_chover` for `#!c false`, **então** execute tudo entre as chaves abaixo do `#!c if`, senão execute tudo entre as chaves abaixo do `#!c else`.

Mude o valor da variável `vai_chover` para `#!c false` e veja como a saída muda.

<!-- TODO: Restrutuação de Condicionais:
 Problema: hoje o módulo não está muito amigável para um iniciante na programação. Fazer as seguintes mudanças
1. Falar do `#!c if` e deixar claro que ele serve para **alterar o fluxo** do código a partir de uma **condição**.
2. A partir de um exemplo que mostra uma mensagem parabenizando o aluno - inicialmente utilizando somente a nota, (1) introduzir a ideia de operações booleanas (&&, || e !) com a introdução de uma nova variável chamada `se_esforcou` e (2) `#!c if` aninhado. + Ordem das condições importa
3. Trazer o exemplo das temperaturas para mostrar como as condições vão sendo alteradas dentro do `if else`.
4. Mover a seção sobre negação para Boas Práticas em Função.
5. Na seção de Boas Práticas falar do `#!c if` sem {}
-->

### Operações Relacionais

Agora vamos pensar em outro exemplo: notificar a um aluno se ele passou ou está de recuperação em uma matéria.
Esse exemplo vai nos ajudar a trabalhar as chamadas **operações relacionais**, as operações "menor igual" ($\le$) e "maior que" ($\gt$) da matemática.

Na maioria das escolas, o aluno precisa tirar **6 ou mais** para passar, caso contrário ele reprova ou fica de recuperação. Usamos da operação **"maior ou igual"** (`#!c >=`) da matemática para transmitir essa ideia. No código a seguir declaramos uma variável do tipo `#!c double` que representa a nota do aluno e verificamos se ele passou ou não:

```c
#include <stdio.h>

int main(void)
{
    double nota = 5.0;

    if (nota >= 6.0)
    {
        printf("Você passou!\n");
    }
    else
    {
        printf("Ficou de recuperação :(\n");
    }

    return 0;
}
```

Da mesma forma que podemos pensar que o aluno passa ao tirar **6 ou mais**, pensar que o aluno *reprova* ao tirar **menos que 6** também em válido. Veja como ao usarmos o operador **"menor que"** (`#!c <`), alteramos a lógica do código, mas deixando intacto o resultado:

```c
#include <stdio.h>

int main(void)
{
    double nota = 5.0;

    if (nota < 6.0))
    {
        printf("Ficou de recuperação :(\n");
    }
    else
    {
        printf("Você passou!\n");
    }

    return 0;
}
```

Essa mudança foi feita por minha parte para mostrar o operador "menor que", mas ela também serve para mostrar que certas operações booleanas possuem uma equivalência entre si.

Temos a operação de igualdade, representada com **dois símbolos de igual**, ou seja, `#!c ==`. Vamos exibir uma mensagem especial para o aluno, caso ele tire 10 - adicionando um **novo `#!c if`**:

```c hl_lines="15-18"
#include <stdio.h>

int main(void)
{
    double nota = 5.0;

    if (nota < 6.0))
    {
        printf("Ficou de recuperação :(\n");
    }
    else
    {
        printf("Você passou!\n");

        if (nota == 10.0)
        {
            printf("E parabéns por tirar 10!\n");
        }
    }

    return 0;
}
```

Por fim, para a operação de *desigualdade* ($\ne$), o professor da turma quer incentivar os alunos que ficaram de recuperação, deixando claro que eles podiam ter tirado 0! Em C, escrevemos esta operação como `#!c !=`:

```c hl_lines="11-18"
#include <stdio.h>

int main(void)
{
    double nota = 5.0;

    if (nota < 6.0))
    {
        printf("Ficou de recuperação :(\n");

        if (nota != 0.0)
        {
            printf("Mas podia ter sido 0 ;)\n");
        }
        else
        {
            printf("...\n");
        }
    }
    else
    {
        printf("Você passou!\n");

        if (nota == 10.0)
        {
            printf("E parabéns por tirar 10!\n");
        }
    }

    return 0;
}
```

### Operações Booleanas

Agora o professor tem um problema um pouco diferente: ele percebeu que seus alunos andam **desmotivados** e quer mostrar uma mensagem motivacional dependendo do **esforço** e **nota** dos alunos.
A nota ainda é uma variável do tipo `#! double`, já o esforço é uma `#!c bool` - que é `#!c true` se o aluno se esforçou e `#!c false` caso contrário.

``` c
#include <stdio.h>
#include <stdbool.h> // (1)!

int main(void)
{
    double nota = 5.0;
    bool se_esforcou = false; // (1)!

    return 0;
}
```

1.  Não se esqueça de incluir o `stdbool.h` para usar o tipo `bool`.

Se o aluno tirou menos que 6, mas se esforçou, o professor quer encorajar o aluno a estudar mais, caso contrário, uma mensagem mais direta é exibida. Para exibir a mensagem encorajadora, o aluno precisa *tirar menos que 6* **e** *ter se esforçado*; primeiro, vamos resolver esse problema com **dois `#!c if`** da seguinte forma:

```c hl_lines="9-15"
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    double nota = 5.0;
    bool se_esforcou = false;

    if (nota < 6.0)
    {
        if (se_esforcou)
        {
            printf("Na próxima você consegue!\n");
        }
    }
    else
    {
        printf("Você precisa se esforçar mais!\n");
    }

    return 0;
}
```

Mas, a linguagem C nos oferece os chamados **operadores booleanos**. Eles geram os valores `#!c true` ou `#!c false` a partir de uma relação lógica. Nesse exemplo a relação lógica é o `E`, que só é verdadeiro (`#!c true`) se a nota for menor que 6 **e** o aluno se esforçou. Em C, o símbolo que representa o `E` é o `#!c &&`; no código fica assim:

```c hl_lines="9"
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    double nota = 5.0;
    bool se_esforcou = false;

    if (nota < 6.0 && se_esfocou)
    {
        printf("Na próxima você consegue!\n");
    }
    else
    {
        printf("Você precisa se esforçar mais...\n");
    }

    return 0;
}
```

## else if

Agora, vamos pensar em outro problema do dia a dia: qual tipo de roupa devo vestir hoje? Ao avaliarmos essa pergunta, temos que levar em consideração a temperatura média ao longo do dia e que cada indivíduo decide o que é "quente" e "frio".

<!-- FIX: Esse paragrafo fala e fala, mas para alguém que está tendo o primeiro contato é muito confuso. Preciso explicar os operadores de comparação antes. -->
Para resolver esse problema, vamos criar um programa que declara duas variáveis constantes do tipo `double` chamadas `temp_baixa` e `temp_alta`, que vão determinar as faixas de temperatura que você considera como frias e quentes, no meu caso são 13ºC e 32ºC. Depois, vamos criar outra variável do tipo `double` chamada `temperatura`, que armazenará a temperatura média no dia. Para decidirmos qual tipo de roupa é melhor levar, vamos usar de **operadores de comparação**, o "maior que" (`>`) e o "menor que" (`<`) da matemática, junto a dois condicionais.

```c
#include <stdio.h>

int main()
{
    const double temp_baixa = 13.0;
    const double temp_alta = 32.0;

    double temperatura = 25.2;

    if (temperatura > temp_alta)
    {
        printf("Hoje vai fazer muito calor!\n");
        printf("Use uma regata e se hidrate.\n");
    }
    else if (temperatura < temp_baixa)
    {
        printf("Hoje vai fazer frio!\n");
        printf("É melhor levar o casaco e passar hidratante.\n");
    }
    else
    {
        printf("Hoje o clima está perfeito!\n");
        printf("Uma camisa já basta.\n");
    }

    return 0;
}
```

> Não precisamos importar `stdbool.h`, isso por que não usamos o tipo `#!c bool` em nenhum momento.

Primeiro, o programa vai verificar, com o uso do primeiro `#!c if`, se o valor armazenado na variável `temperatura` é maior do que o armazenado em `temp_alta`. Se esse for o caso, então faça as recomendações para o calor, senão verifique se a `temperatura` é menor que `temp_baixa`, com o uso do `else if`. Se a `temperatura` for baixa, então recomende um casaco. Por fim, se a temperatura não está nem muito quente, nem muito frio, então o clima só pode estar perfeito.

Teste com diversos valores de temperatura, alterando o valor da variável `temperatura`, e veja quais mensagens aparecem.

Note que **depois** de cada verificação que fazemos na variável `temperatura` estamos **limitando** seu valor. Pense comigo, antes de fazer a **primeira verificação** na linha `if (temperatura > temp_alta)` o valor de `temperatura` pode ser **qualquer um**: pode ser `-2.0`, `25.0` ou até algo absurdo como `1240.0` e `-900.0`; não temos como saber.
É só depois de verificar se `temperatura > temp_alta` é que podemos indicar uma nova **faixa de temperatura** da variável `temperatura`. Veja, para `temp_alta` valendo `32.0`, se a `temperatura` for maior que `32.0` sabemos que seu valor vai de `32.0` - não incluindo - para cima (como `35.0` e `50.0`), **caso contrário** a `temperatura` com toda certeza é menor ou igual a `32.0`.
Com isso, ao chegarmos na **segunda verificação** em `else if (temperatura < temp_baixa)` temos **certeza** que a `temperatura` é menor ou igual a `32.0`; e denovo, após verificarmos esta condição, podemos definir uma nova faixa de temperatura para a variável `temperatura`.

No código a seguir, vou apenas escrever as possíveis faixas de temperatura **antes** de fazer as verificações, usando comentários e a notação matématica de intervalos, que é uma outra forma de escrever o que acabamos de ver. Não se preocupe se não conhecer essa notação, você pode ignorá-la e ler apenas os textos ao lado nos comentários.

```c
// (-inf, +inf) todos os números reais
if (temperatura > temp_alta)
{
    printf("Hoje vai fazer muito calor!\n");
    printf("Use uma regata e se hidrate.\n");
}
// (-inf, 32.0] todos os reais negativos, nulos e positivos até 32.0
else if (temperatura < temp_baixa)
{
    printf("Hoje vai fazer frio!\n");
    printf("É melhor levar o casaco e passar hidratante.\n");
}
// [13.0, 32.0] todos os reais de 13.0 a 32.0
else
{
    printf("Hoje o clima está perfeito!\n");
    printf("Uma camisa já basta.\n");
}
```

Agora, veja o que acontece com os valores exatos de `temp_baixa` e `temp_alta`. Você percebeu que a mensagem indica um clima perfeito? Como esses pontos indicam as **mudanças de temperatura**, eles devem ser **incluídos** em suas respectivas faixas de temperatura, mas por que este não é o caso?

O problema é que ao final das verificações, no bloco do `#!c else`, a faixa de `temperatura` **incluí** esses valores. O erro está nas **verificações passadas**, que não incluíram os valores de `temp_baixa` e `temp_alta` em suas faixas.

Para corrigir o erro, devemos usar os operadores `>=` e `<=`, lidos como "maior ou igual" e "menor ou igual", respectivamente, nas verificações `#!c if` e `else if`.

> Na escrita do código, vou focar apenas nas mudanças do `#!c if`, mas você deve escrever tudo!

```c
if (temperatura >= temp_alta)
{
    printf("Hoje vai fazer muito calor!\n");
    printf("Use uma regata e se hidrate.\n");
}
else if (temperatura <= temp_baixa)
{
    printf("Hoje vai fazer frio!\n");
    printf("É melhor levar o casaco e passar hidratante.\n");
}
else
{
    printf("Hoje o clima está perfeito!\n");
    printf("Uma camisa já basta.\n");
}
```

## O `#!c bool` por debaixo dos panos

As condições em C sempre resultam em valores numéricos. Vejamos um exemplo:

```c
#include <stdio.h>

int main()
{
    printf("Condição Verdadeira: %d\n", 3 == 3);
    printf("Condição Falsa: %d\n", 1 > 10);

    return 0;
}
```

No primeiro caso, o resultado da condição `#!c 3 == 3` é 1, já que de fato, 3 é igual a 3. Já no segundo, como 1 não é maior que 10, o resultado é 0.

A linguagem C define o valor `0` como **falso**, qualquer outro valor é verdadeiro. Dessa forma, o tipo `#!c bool` e os valores `#!c false` e `#!c false` são apenas números. Utilizamos desse tipo para trazer clareza em nosso código.
