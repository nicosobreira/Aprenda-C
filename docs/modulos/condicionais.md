# Condicionais

As estruturas condicionais nos possibilitam **avaliar condições** e executar diferentes códigos dependendo de seus resultados. Para deixar essa explicação mais clara, vamos pensar em um exemplo do dia a dia: será que eu devo levar o meu guarda-chuva ao sair de casa? Ao avaliarmos essa pergunta, primeiro pensamos se irá chover ou não no dia. **Se** chover, então pegamos o guarda-chuva, **senão** deixamos ele em casa.

## if e else

Para resolvermos o nosso problema do guarda-chuva, vamos escrever um programa que irá fazer essa decisão! Primeiro iremos declarar uma variável do tipo `#!c bool`, chamada `vai_chover`; damos o valor `#!c true` para ela. Depois iremos implementar essa lógica do **"se e senão"**.

!!! atenção

    Não se esqueça de importar a definição do tipo `#!c bool` com o header `<stdbool.h>`.

```c
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    bool vai_chover = true;

    if (vai_chover)
    {
        printf("Vai chover!\n");
        printf("É melhor levar o guarda-chuva.\n");
    }
    else
    {
        printf("Deixe o guarda-chuva em casa, não irá chover hoje.\n");
    }

    return 0;
}
```

As palavras `#!c if` e `#!c else` são traduções diretas para o "se" e "senão".
Com isso em mente, lemos esse código da seguinte forma: **se** o valor armazenado na variável `vai_chover` for `#!c true`, **então** execute tudo entre as chaves abaixo do `#!c if`, senão, execute tudo entre as chaves abaixo do `#!c else`.

Mude o valor da variável `vai_chover` para `#!c false` e veja como a saída muda.

<!-- TODO: Reestruturação de Condicionais:
 Problema: hoje o módulo não está muito amigável para um iniciante na programação. Fazer as seguintes mudanças
1. Falar do `#!c if` e deixar claro que ele serve para **alterar o fluxo** do código a partir de uma **condição**.
2. A partir de um exemplo que mostra uma mensagem parabenizando o aluno - inicialmente utilizando somente a nota, (1) introduzir a ideia de operações booleanas (&&, || e !) com a introdução de uma nova variável chamada `se_esforcou` e (2) `#!c if` aninhado. + Ordem das condições importa
3. Trazer o exemplo das temperaturas para mostrar como as condições vão sendo alteradas dentro do `if else`.
4. Mover a seção sobre negação para Boas Práticas em Funções.
5. Na seção de Boas Práticas falar do `#!c if` sem {}
-->

### Operações Relacionais

Agora vamos pensar em outro exemplo: notificar um aluno se ele passou ou está de recuperação em uma matéria.
Esse exemplo vai nos ajudar a trabalhar as chamadas **operações relacionais**, as operações como "menor que" ($\lt$) e "maior ou igual" ($\ge$) da matemática.

Na maioria das escolas, o aluno precisa tirar **6 ou mais** para passar, caso contrário ele reprova ou fica de recuperação. Usamos a operação **"maior ou igual"** (`#!c >=`) da matemática para transmitir essa ideia. No código a seguir declaramos uma variável do tipo `#!c double` que representa a nota do aluno e verificamos se ele passou ou não:

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

Da mesma forma que podemos pensar que o aluno *passa* na matéria ao tirar **6 ou mais**, pensar que o aluno *reprova* ao tirar **menos que 6** também é válido. Usamos o **"menor que"** (`#!c <`) para alterar a lógica do código, mas mantendo o mesmo resultado:

```c
#include <stdio.h>

int main(void)
{
    double nota = 5.0;

    if (nota < 6.0)
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

Fiz essa mudança para mostrar o operador "menor que", mas ela também serve para mostrar que certas operações relacionais possuem uma equivalência entre si.

Ainda temos a operação de **igualdade**, representada com **dois sinais de igual**, ou seja, `#!c ==`. Vamos exibir uma mensagem especial para o aluno que tire 10 - adicionando um **novo `#!c if`**:

```c hl_lines="15-18"
#include <stdio.h>

int main(void)
{
    double nota = 5.0;

    if (nota < 6.0)
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

O professor da turma quer incentivar os alunos que ficaram de recuperação, deixando claro que eles podiam ter tirado `#!c 0`! Em C, usamos a operação de **desigualdade** ($\ne$), escrita como `#!c !=`, para transmitir essa ideia:

```c hl_lines="11-18"
#include <stdio.h>

int main(void)
{
    double nota = 5.0;

    if (nota < 6.0)
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

#### "E"

O professor percebeu que os alunos estão indo muito mal na prova. Ele decidiu usar a frequência às aulas como outro fator que faz o aluno passar na matéria.
A taxa de frequência vai de 0 a 10, e segue a seguinte lógica: se o aluno tirou menos que 6, mas possui frequência maior ou igual a 9, ele passa, do contrário ele reprova. Criamos uma nova variável também do tipo `#!c double` chamada `frequencia` e a usamos da seguinte forma:

```c hl_lines="11"
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    double nota = 5.0;
    double frequencia = 10.0;

    if (nota < 6.0)
    {
        if (frequencia >= 9.0)
        {
            printf("Você passou!\n");
        }
        else
        {
            printf("Você reprovou...\n");
        }
    }
    else
    {
        printf("Você passou!\n");
    }

    return 0;
}
```

Note que temos que repetir duas vezes a mensagem `"Você passou!"`. A linguagem C nos oferece os chamados **operadores booleanos**, que são operações que resultam em apenas `#!c true` ou `#!c false` a partir de uma **relação lógica**. Nesse caso, a relação lógica é o "E", ou seja, para o aluno **reprovar** é necessário que: *ele tire menos que 6* **e** *tenha frequência menor que 9*. Escrevemos essa operação como `#!c &&`:

```c hl_lines="9"
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    double nota = 5.0;
    double frequencia = 10.0;

    if (nota < 6.0 && frequencia < 9.0)
    {
        printf("Você reprovou...\n");
    }
    else
    {
        printf("Você passou!\n");
    }

    return 0;
}
```

Basta que uma dessas condições seja falsa para que o aluno passe na matéria, ou seja, basta que sua nota seja maior ou igual a 6 **ou** sua frequência seja maior ou igual a 9 para que ele passe. A tabela a seguir, chamada de **tabela-verdade**, deixa clara essa relação. A coluna **Resultado** indica o que é passado para o `#!c if`:

| `#!c nota < 6.0` | `#!c frequencia < 9.0` | **Resultado** |
| :-: | :-: | :- |
| **`#!c true`** | **`#!c true`** | **`#!c true`** |
| `#!c true` | `#!c false` | `#!c false` |
| `#!c false` | `#!c true` | `#!c false` |
| `#!c false` | `#!c false` | `#!c false` |

#### "OU"

No parágrafo anterior, vimos que se o aluno tiver *nota maior ou igual a 6* **ou** *frequência maior ou igual a 9* ele **passa**. O C possui o operador "OU", escrito como `#!c ||`, que traz essa ideia:

```c hl_lines="9"
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    double nota = 5.0;
    double frequencia = 10.0;

    if (nota >= 6.0 || frequencia >= 9.0)
    {
        printf("Você passou!\n");
    }
    else
    {
        printf("Você reprovou...\n");
    }

    return 0;
}
```

Basta que uma condição seja verdadeira para que o resultado seja verdadeiro:

| `#!c nota >= 6.0` | `#!c frequencia >= 9.0` | **Resultado** |
| :-: | :-: | :- |
| **`#!c true`** | **`#!c true`** | **`#!c true`** |
| **`#!c true`** | **`#!c false`** | **`#!c true`** |
| **`#!c false`** | **`#!c true`** | **`#!c true`** |
| `#!c false` | `#!c false` | `#!c false` |

---

O professor percebeu uma melhora nas notas dos alunos e decidiu fazer uma excursão para o cinema. O problema é que o cinema é muito novo e eles ainda não têm um sistema de **verificação de meia-entrada**. Tem direito a pagar meia entrada:

- Idosos com 60 anos ou mais.
- Crianças com até 12 anos.
- E estudantes (na escola ou faculdade).

Com o que vimos até agora, crie um programa que resolva esse problema antes de continuar.

??? resposta

    Basta usarmos o "OU" duas vezes, combinando as três condições:

    ```c hl_lines="9"
    #include <stdio.h>
    #include <stdbool.h>

    int main(void)
    {
        int idade = 10;
        bool esta_estudando = true;

        if (idade >= 60 || idade <= 12 || esta_estudando)
        {
            printf("Você paga meia!\n");
        }
        else
        {
            printf("Você paga inteira!\n");
        }

        return 0;
    }
    ```

À medida que fazemos mais verificações, é interessante darmos um **nome** para elas. Podemos criar três variáveis do tipo `#!c bool` chamadas `eh_idoso`, `eh_crianca` e `tem_meia` e usar no código:

```c
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int idade = 10;
    bool esta_estudando = true;

    bool eh_idoso = idade >= 60;
    bool eh_crianca = idade <= 12;

    bool tem_meia = eh_idoso || eh_crianca || esta_estudando;

    if (tem_meia)
    {
        printf("Você paga meia!\n");
    }
    else
    {
        printf("Você paga inteira!\n");
    }

    return 0;
}
```

Isso não é obrigatório, mas fazer isso deixa claro o que cada condição faz.

#### "NÃO"

Repare que nas duas últimas seções escrevemos a mesma regra de duas formas: "reprova" com `#!c &&` e "passa" com `#!c ||`. Uma é **o contrário** da outra, e o C tem um operador para isso: o "NÃO", escrito como `#!c !`, que **inverte** um valor booleano, ou seja, `#!c true` vira `#!c false` e vice-versa.

Usando o `#!c !`, podemos guardar a condição de aprovação em uma variável e tratar a reprovação como "**não** passou":

```c hl_lines="9-11"
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    double nota = 5.0;
    double frequencia = 10.0;

    bool passou = nota >= 6.0 || frequencia >= 9.0;

    if (!passou)
    {
        printf("Você reprovou...\n");
    }
    else
    {
        printf("Você passou!\n");
    }

    return 0;
}
```

Em uma tabela-verdade fica:

| `#!c passou` | `#!c !passou` |
| :-: | :-: |
| `#!c true` | `#!c false` |
| `#!c false` | `#!c true` |


Isso nos dá um jeito de provar que as duas versões são equivalentes. Negar um "OU" é o mesmo que negar cada condição e trocar por "E":

```c
!(nota >= 6.0 || frequencia >= 9.0)   // não passou
nota < 6.0 && frequencia < 9.0        // equivalente: nota baixa E frequência baixa
```

O contrário também vale: negar um "E" vira "OU" com cada condição negada. Isso é conhecido como **Leis de De Morgan**. Não precisa decorar: se tiver dúvida, monte a tabela-verdade e compare.

!!! nota

    Teste o programa com as quatro combinações de `nota` (acima e abaixo de 6) e `frequencia` (acima e abaixo de 9) e confirme que as duas formas sempre dão o mesmo resultado.

---

Por fim, o professor precisa organizar o **acesso à biblioteca da escola**. As regras são as seguintes:

- Podem **retirar livros** as pessoas que estejam matriculadas ou que sejam professoras.
- Mas ninguém pode retirar livros se tiver **algum livro atrasado**.
- Para **entrar** na biblioteca é preciso ser aluno ou funcionário **e** ter feito o cadastro.

Com o que vimos até agora, crie um programa que resolva a retirada de livros antes de continuar. Use as variáveis:

```c
bool esta_matriculado = true;
bool eh_professor = false;
bool tem_livro_atrasado = false;
```

!!! dica

    Atenção à **precedência** dos operadores: o `#!c &&` é avaliado antes do `#!c ||`. Use parênteses para deixar a ordem explícita.

??? resposta

    Precisamos combinar um "OU" (matriculado ou professor) com um "NÃO" (não ter livro atrasado) usando um "E". Repare nos **parênteses**: sem eles, o `#!c &&` seria avaliado antes do `#!c ||` e a regra mudaria.

    ```c hl_lines="10"
    #include <stdio.h>
    #include <stdbool.h>

    int main(void)
    {
        bool esta_matriculado = true;
        bool eh_professor = false;
        bool tem_livro_atrasado = false;

        if ((esta_matriculado || eh_professor) && !tem_livro_atrasado)
        {
            printf("Você pode retirar livros!\n");
        }
        else
        {
            printf("Você não pode retirar livros.\n");
        }

        return 0;
    }
    ```

    Teste o programa mudando os valores das três variáveis e confira se o resultado bate com o que você esperava.

À medida que as regras crescem, vale **dar nome** a cada parte, como fizemos com `tem_meia`:

```c
bool tem_vinculo = esta_matriculado || eh_professor;
bool pode_retirar = tem_vinculo && !tem_livro_atrasado;
```

#### Boa prática

Prefira nomes **positivos** para variáveis booleanas (`passou`, e não `nao_passou`). Com o nome negativo, `#!c !nao_passou` vira uma "dupla negação", difícil de ler.

## else if

Com o que vimos até agora, tente resolver o seguinte problema: qual tipo de roupa devo vestir hoje? Ao avaliarmos essa pergunta, temos que levar em consideração a temperatura média ao longo do dia e que cada indivíduo decide o que é "quente" e "frio".

Para resolver esse problema, vamos criar um programa que declara duas variáveis constantes do tipo `double` chamadas `temp_baixa` e `temp_alta`, que vão determinar as faixas de temperatura que você considera como frias e quentes, no meu caso são 13 °C e 32 °C. Depois, vamos criar outra variável do tipo `double` chamada `temperatura`, que armazenará a temperatura média no dia.

```c
#include <stdio.h>

int main(void)
{
    const double temp_baixa = 13.0;
    const double temp_alta = 32.0;

    double temperatura = 25.2;

    // ...

    return 0;
}
```

??? resposta

    ```c
    #include <stdio.h>

    int main(void)
    {
        const double temp_baixa = 13.0;
        const double temp_alta = 32.0;

        double temperatura = 25.2;

        if (temperatura >= temp_alta)
        {
            printf("Hoje vai fazer muito calor!\n");
            printf("Use uma regata e se hidrate.\n");
        }
        else
        {
            if (temperatura <= temp_baixa)
            {
                printf("Hoje vai fazer frio!\n");
                printf("É melhor levar o casaco e passar hidratante.\n");
            }
            else
            {
                printf("Hoje o clima está perfeito!\n");
                printf("Uma camisa já basta.\n");
            }
        }

        return 0;
    }
    ```

Veja que após cada `#!c else` é necessário aumentar a indentação e adicionar um `#!c if` abaixo.

```c
else
{
    if (temperatura <= temp_baixa)
    {
        // ...
    }
    else
    {
        // ...
    }
}
```

Esse padrão é extremamente frequente na linguagem C, e por isso é comum escrever o `#!c else` e `#!c if` seguidos um do outro, assim:

```c
else if (temperatura <= temp_baixa)
{
    // ...
}
else
{
    // ...
}
```

O chamado `#!c else if` não é uma estrutura condicional nova, mas apenas um `#!c else` seguido de um `#!c if`. Reescrevendo o código, fica assim:

```c
#include <stdio.h>

int main(void)
{
    const double temp_baixa = 13.0;
    const double temp_alta = 32.0;

    double temperatura = 25.2;

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

    return 0;
}
```

Isso elimina os níveis de indentação adicionais, ficando mais claro em qual **faixa de temperatura** cada parte do código está.

!!! nota

    Teste com diversos valores de temperatura, alterando o valor da variável `temperatura`, e veja quais mensagens aparecem.

Note que **depois** de cada verificação que fazemos na variável `temperatura` estamos **limitando** seu valor.

Pense comigo: antes de fazer a **primeira verificação** na linha `#!c if (temperatura >= temp_alta)` o valor de `temperatura` pode ser **qualquer um**: pode ser `#!c -2.0`, `#!c 25.0` ou até algo absurdo como `#!c 1240.0` e `#!c -900.0`; não temos como saber.
É só depois de verificar se `#!c temperatura >= temp_alta` é que podemos indicar uma nova **faixa de temperatura** da variável `temperatura`. Se a `temperatura` for maior ou igual a `#!c 32.0` sabemos que seu valor vai de `#!c 32.0` (incluindo) para cima (como `#!c 35.0` e `#!c 50.0`), **caso contrário** a `temperatura` com toda certeza é menor que `#!c 32.0`.
Com isso, ao chegarmos na **segunda verificação** em `#!c else if (temperatura <= temp_baixa)` temos **certeza** de que a `temperatura` é menor que `#!c 32.0`; e de novo, após verificarmos esta condição, podemos definir uma nova faixa de temperatura para a variável `temperatura`.

O fluxograma deixa essa ideia mais clara:

```mermaid
flowchart LR
    A["Temperatura<br>(-∞, +∞)"] --> B{">= 32?"}
    B -- "Não" --> C["(-∞, 32)"]
    C --> D{"<= 13?"}
    D -- "Não" --> E["(13, 32)"]
```

No código a seguir, vou apenas escrever as possíveis faixas de temperatura **antes** de fazer as verificações, usando comentários e a notação matemática de intervalos, que é uma outra forma de escrever o que acabamos de ver. Não se preocupe se não conhecer essa notação, você pode ignorá-la e ler apenas os textos ao lado nos comentários.

```c
// (-inf, +inf) todos os números reais
if (temperatura >= temp_alta)
{
    printf("Hoje vai fazer muito calor!\n");
    printf("Use uma regata e se hidrate.\n");
}
// (-inf, 32.0) todos os reais menores que 32.0
else if (temperatura <= temp_baixa)
{
    printf("Hoje vai fazer frio!\n");
    printf("É melhor levar o casaco e passar hidratante.\n");
}
// (13.0, 32.0) todos os reais entre 13.0 e 32.0
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

int main(void)
{
    printf("Condição Verdadeira: %d\n", 3 == 3);
    printf("Condição Falsa: %d\n", 1 > 10);

    return 0;
}
```

No primeiro caso, o resultado da condição `#!c 3 == 3` é 1, já que, de fato, 3 é igual a 3. Já no segundo, como 1 não é maior que 10, o resultado é 0.

A linguagem C define o valor `0` como **falso**; qualquer outro valor é verdadeiro. Dessa forma, o tipo `#!c bool` e os valores `#!c true` e `#!c false` são apenas números. Utilizamos esse tipo para trazer clareza em nosso código.
