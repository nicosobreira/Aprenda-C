# Estruturas de Repetição

Como o nome já diz, as estruturas de repetição nos permitem **repetir** blocos de código. Para entender o poder dessas estruturas, vamos entender como **pedir dados ao usuário** enquanto os nosso programas estão sendo executados, mas mais importante como usar dessas estruturas para **validar** as entradas.

## scanf I

Existem alguns jeitos de pedir dados aos usuários em C. O primeiro método que veremos é usando a função `#!c scanf`, declarada no *header* `#!c <stdio.h>`. Quando essa função é executada, o programa para até que o usuário digite a tecla ++enter++, antes disso o usuário deve digitar o que está sendo pedido. Veja o programa a seguir, que pede para o usuário digitar um número inteiro e mostra esse número mais dois:

```c
#include <stdio.h>

int main(void)
{
    int entrada = 0;

    printf("Digite um número inteiro: ");
    int sucesso = scanf("%d", &entrada);

    printf("[%d entradas lidas com sucesso]\n", sucesso);

    printf("A entrada mais dois vale: %d\n", entrada + 2);

    return 0;
}
```

???+ pergunta "Vídeo de Exemplo"
    <video class="so-claro" autoplay loop muted playsinline>
      <source src="../../assets/videos/repeticao/scanf-basico-claro.webm" type="video/webm">
    </video>
    <video class="so-escuro" autoplay loop muted playsinline>
      <source src="../../assets/videos/repeticao/scanf-basico-escuro.webm" type="video/webm">
    </video>

Primeiro declaramos a variável `#!c entrada`, que irá guardar a entrada do usuário. Em seguida, mostramos uma mensagem que deixa claro o que o usuário deve digitar. Depois vem a chamada da função `#!c scanf`, que é dividida nessas partes: o formatador `#!c "%d"`, que indica que um valor inteiro será lido; e `#!c &entrada`, que indica que o valor digitado será armazenado na variável `#!c entrada`.

!!! nota

    Veremos o que é o `#!c &` em [Memória I](./memoria-1.md), por ora leia `#!c &entrada` como o jeito que o `#!c scanf` usa para armazenar o valor que o usuário digitou na variável `entrada`.

O `#!c scanf` ainda retorna um `#!c int` que indica o **total de valores lidos com sucesso**. Ele é útil para identificar possíveis erros de entrada: ao invés de digitar um número válido, digite um carácter, como o `#!c 'z'`, e veja que `sucesso` vai para `#!c 0`, indicando que a leitura falhou. Note que mesmo em caso de falha, o código não é interrompido; o que o `#!c scanf` faz nesse caso é **não alterar** a variável `entrada`, e por isso seu valor continua sendo `#!c 0`.

!!! atenção

    As funções `printf` e `scanf` possuem muitos formatadores, como o `%d`, em comum, mas existem alguns diferentes. Pesquise qual formatador é necessário antes de usar!

Ainda podemos pedir mais de um valor ao usuário. Nos códigos a seguir é usado um espaço (`#!c ' '`) e "x" (`#!c 'x'`) como separadores, respectivamente:

=== "Separador é um `#!c ' '`"

    ```c
    #include <stdio.h>

    int main(void)
    {
        int a = 0;
        int b = 0;

        printf("Digite dois números (separados por espaço): ");
        int sucessos = scanf("%d %d", &a, &b);

        printf("[%d entradas lidas com sucesso]\n", sucessos);

        printf("A soma entre os dois dá: %d\n", a + b);

        return 0;
    }
    ```

    ```console title="Simulação"
    $ gcc -Wall -o main main.c
    $ ./main
    Digite dois números (separados por espaço): 3 2
    [2 entradas lidas com sucesso]
    A soma entre os dois dá: 5

    $ ./main
    Digite dois números (separados por espaço): 3 a
    [1 entradas lidas com sucesso]
    A soma entre os dois dá: 3
    ```

=== "Separador é um `#!c 'x'`"

    ```c
    #include <stdio.h>

    int main(void)
    {
        int a = 0;
        int b = 0;

        printf("Digite dois números (separados por x): ");
        int sucessos = scanf("%dx%d", &a, &b);

        printf("[%d entradas lidas com sucesso]\n", sucessos);

        printf("A soma entre os dois dá: %d\n", a + b);

        return 0;
    }
    ```

    ```console title="Simulação"
    $ gcc -Wall -o main main.c
    $ ./main
    Digite dois números (separados por x): 5x2
    [2 entradas lidas com sucesso]
    A soma entre os dois dá: 7

    $ ./main
    Digite dois números (separados por x): 5 2
    [1 entradas lidas com sucesso]
    A soma entre os dois dá: 5
    ```

Note ainda que não usamos o `#!c '\n'` no `#!c printf` que indica o que o usuário deve digitar, mas sim usamos dois pontos `#!c ':'`. Faça as seguintes alterações e veja como a mensagem sai cada vez mais "esquisita":

1. Retire o dois pontos e espaço no final, e execute o programa.
2. Depois, coloque um `\n` no final da mensagem.
3. E por último, remova a mensagem completamente.

## `#!c do while`

Agora vamos pensar no seguinte problema: para um usuário logar no sistema, ele deve digitar uma senha de 4 dígitos; **enquanto** a senha for incorreta, uma nova senha deve ser pedida, *não existe limites de tentativas*.

Com o que sabemos até agora, tente implementar **uma tentativa** para esse sistema: caso o `#!c scanf` não tenha sucesso em ler a tentativa do usuário, a mensagem `#!c "Erro de digitação!"` aparece, e é retornado `#!c 1` da função `#!c main` (terminando o programa); caso o usuário digite a senha errada, a mensagem `#!c "Senha errada!"` é exibida, e é retornado `#!c 2` da função `#!c main`; do contrário a senha está certa, e a mensagem `#!c "Login feito."` é exibida.
Utilize o código abaixo como base, aqui a variável `#!c senha` é um inteiro:

```c
#include <stdio.h>

int main(void)
{
    const int senha = 1234; // Senha do sistema

    // ...

    return 0;
}
```

??? resposta

    ```c
    #include <stdio.h>

    int main(void)
    {
        const int senha = 1234;  // Senha do sistema

        int tentativa = 0000;  // Tentativa do usuário

        printf("Digite a senha: ");
        int sucesso = scanf("%d", &tentativa);

        if (sucesso != 1)
        {
            printf("Erro de digitação!\n");
            return 1;
        }

        if (tentativa != senha)
        {
            printf("Senha errada!\n");
            return 2;
        }

        printf("Login feito.\n");

        return 0;
    }
    ```

    Você pode ter estranhado a ausência de um `#!c if else`, mas o motivo é simples: como estamos usando um `#!c return`, o programa **acaba** em caso erro.

Mas com o que sabemos até agora, não conseguimos implementar a lógica do "**enquanto**" que o problema está pedindo. Para isso, vamos aprender a estrutura de repetição `#!c do while`.

No código a seguir, é utilizada estrutura de repetição `#!c do while` para **calcular o número de dígitos** de um número. Essa estrutura **executa um código de bloco** até que **alguma condição seja atingida** - essa condição pode ser aquelas [Relacionais](./condicionais.md#operacoes-relacionais) e [Booleanas](./condicionais.md#operacoes-booleanas) que já vimos. No código abaixo, copiamos a variável `#!c numero` para outra, chamada de `temporario` - afim de não interferir no valor original - e fazemos o seguinte: dividimos `#!c temporario` por `#!c 10` **até que** `#!c temporario` se iguale a `#!c 0`; seguido de cada divisão, incrementamos a variável `#!c digitos` por `#!c 1`. Ao final, exibimos o resultado:

```c hl_lines="11-15"
#include <stdio.h>

int main(void)
{
    int numero = 4568; // Teste com: 0, 5, 23, 800 e 4568

    int digitos = 0;

    int temporario = numero;

    do
    {
        temporario = temporario / 10;
        digitos = digitos + 1;
    } while (temporario != 0);

    printf("Número: %d\n", numero);
    printf("Quantidade de dígitos: %d\n", digitos);

    return 0;
}
```

=== "Para `#!c 0`"

| Iteração | m

=== "Para `#!c 5`"

    a

=== "Para `#!c 23`"

    a

=== "Para `#!c 800`"

    a

=== "Para `#!c 4568`"

    a

## scanf II

Vamos retomar o primeiro exemplo do uso do `scanf`

> Aqui eu vou escrever apenas o conteúdo da função `main`.

```c
int numero = 0;

printf("Digite um número, por favor: ");
scanf("%d", &numero);

printf("O seu número mais 2 vale %d.\n", numero + 2);
```

Vimos que esse código lê um número inteiro do usuário. Mas o que acontece se o usuário acidentalmente digitar um número real (com vírgula) ou uma letra?

Primeiro, tente digitar esses casos, depois veremos uma explicação.

### O valor de retorno do scanf

Se a entrada do usuário for algo diferente de um número inteiro, o resultado é `2`. Contudo, algo interessante acontece se substituirmos o valor inicial da variável `numero` por outro, como por exemplo `4`. Agora o resultado é `6`, ou seja, `4 + 2`.

Caso a leitura do `scanf` falhar, a variável `numero` não é alterada. Com essa informação já poderíamos pensar em validar a entrada do usuário: se o valor inicial continuar o mesmo, então peça outra entrada para o usuário. Mas existe um jeito ainda melhor de fazer a verificação.

Até agora, ignoramos o **valor de retorno** da função `scanf`. Esse valor é do tipo `int` e indica o número de **leituras bem-sucedidas**, isso é, o **total de variáveis que foram alteradas** pela função.

Vamos ver esse valor no código a seguir:

```c
printf("Digite um número, por favor: ");
int resultado = scanf("%d", &numero);

printf("Resultado do scanf: %d", resultado);
```

Se o usuário digitar um número inteiro, o `resultado` vale `1`, caso contrário, o `resultado` vale `0`. Com essa informação, podemos usar de um **retorno antecipado** para sair da função `main`, caso o usuário não tenha digitado um número:

```c
int main(void)
{
    int numero = 0;

    printf("Digite um número, por favor: ");
    int resultado = scanf("%d", &numero);

    if (resultado != 1)
    {
        printf("Digite um número da próxima vez!\n");
        return 1;
    }

    printf("O seu número mais 2 vale %d.\n", numero + 2);

    return 0;
}
```

---

Ao invés de sair do programa, podemos utilizar de um `while` _loop_ para ler um número novamente.

```c
int numero = 0;
printf("Digite um número: ");

while(scanf("%d", &numero) != 1)
{
 printf("Digite um número inteiro: ");
}
```

À primeira vista, esse código deve funcionar. Digite valores válidos e inválidos, e veja o que acontece.

Se não digitarmos um número inteiro, caímos em um **loop infinito**. Para entendermos esse erro, vamos ver como a entrada do usuário entra na função `scanf`.

### Buffer de entrada

Quando você digita algo no terminal e aperta `Enter`, o que você digitou não vai direto para a variável. Primeiro, esses dados vão para uma área de memória temporária chamada **buffer de entrada**, conhecida em C como _stdin_ (apelido para _standard input_).

Por exemplo, se você digitar a letra `A` e depois `Enter`, o buffer de entrada vai ficar parecido com isso: \[`A`, `\n`\], como uma **fila de espera**, aguardando ser lida. O papel da função `scanf` é ler esse buffer até encontrar um `\n`. Quando isso acontece, essa parte do buffer é convertida para o formatador. Caso a conversão dê certo o buffer de entrada é esvaziado, mas se der errado, o buffer **não é esvaziado**, isso é, **ele continua o mesmo**.

No código acima, caso digitemos `A` e `Enter`, o `scanf` funcionaria assim:

1. Vai ler o buffer até o `\n`;
2. Erro! O valor `A` não é um inteiro, nenhuma conversão foi um sucesso, retorna `0`;
3. A mensagem avisando o erro ao usuário é exibida;
4. O buffer ainda possui o `A`, a conversão falha e a mensagem é exibida;

Para limpar esse buffer, vamos usar a função `getchar`, declarada no header `stdio`. Essa função navega pelo buffer de entrada e limpa um caractere de cada vez. Seu valor de retorno é justamente esse caractere que acabou de ser limpo.

Portanto, **enquanto** o valor de retorno do `getchar` for diferente de `\n`, o buffer ainda precisa ser limpo:

```c
int numero = 0;
printf("Digite um número: ");

while(scanf("%d", &numero) != 1)
{
 while(getchar() != '\n') {}

 printf("Digite um número inteiro: ");
}
```

Uma implicação da não sanitização do buffer de entrada pela função `scanf` é que, mesmo se a entrada for convertida corretamente, o caractere `\n` ainda permanece no buffer.

Felizmente, formatadores de números como o `%d` e `%f` ignoram esses espaços e quebras de linha automaticamente na próxima leitura. No entanto, se a sua próxima leitura for de um caractere único (`%c`), esse `\n` residual será lido por engano. Nesse caso, use um espaço antes do formatador para instruir o `scanf` a ignorar o lixo do buffer: `scanf(" %c", &letra);`.

## do while

A última versão do código usando o `getchar` junto ao `while` _loop_ para validar a entrada do usuário é funcional, mas apresenta problemas em sua construção. Vamos tentar usar uma estratégia similar para limitar a entrada do usuário entre 0 e 10, para valores de notas, por exemplo.

Para tal, vamos juntar os possíveis erros de entrada em **uma única linha**, usando o operador lógico **OU**. Caso **qualquer uma das condições** seja verdadeira, o `while` _loop_ vai continuar.

> Usamos o `%lf` porque a variável `nota` é do tipo `double`. Pode ser lido como **l**ong **f**loat, do inglês "float longo". Se nota fosse `float` usaríamos `%f`.

```c
double nota;
printf("Digite uma nota: ");

while (scanf("%lf", &nota) != 1 || nota < 0.0 || nota > 10.0)
{
 while (getchar() != '\n')
 {
 }

 printf("Digite novamente: ");
}

printf("Parabéns por tirar %g!\n", nota);
```

> É importante salientar que a **ordem das condições** importa! Em C elas são lidas da esquerda para a direita.

Você concorda que adicionar essa simples checagem já deixou o código mais confuso? Temos que usar vários **OU**s juntos, o que dificulta a leitura. Caso seja preciso adicionar mensagens de erros mais claras, como "Digite um número maior que 0" se `numero` for menor que `0`, teríamos que verificar a condição novamente.

Para resolver esse problema vamos usar outra estrutura de repetição, o **`do while`**. Primeiro vou mostrar a substituição do `while` pelo `do while`, **sem o limite de 0 a 10**:

> Não se esqueça de importar o _header_ `stdbool.h`

```c
printf("Digite uma nota: ");

double nota = 0.0;
bool leitura_valida = false;
do
{
 int resultado = scanf("%lf", &nota);
 if (resultado != 1)
 {
  while (getchar() != '\n')
  {
  }

  printf("Digite um número real: ");
 }
    else
    {
        leitura_valida = true;
    }
} while (!leitura_valida);

printf("Parabéns por tirar %g!\n", nota);
```

Com o `do while(!leitura_valida)`, a validação da entrada do usuário se dá através da _flag_ booleana chamada `leitura_valida`. Essa _flag_ é uma variável do tipo booleana que começa como `false` e só se torna `true` quando o `scanf` lê um número real com sucesso, momento em que o laço para.

Você pode estar pensando que o código ficou maior, e é verdade. A troca é intencional: ganhamos clareza na estrutura em troca de algumas linhas a mais. Conforme o código crescer, com verificações de intervalo e mensagens de erro específicas, essa clareza vai compensar.
Veja como adicionar o limite entre 0 e 10 ficou mais fácil.

```c
const double min = 0.0;
const double max = 10.0;

printf("Digite uma nota: ");

double nota = 0.0;
bool leitura_valida = false;
do
{
 int resultado = scanf("%lf", &nota);

 if (resultado != 1)
 {
  while (getchar() != '\n')
  {
  }

  printf("Digite um número real: ");
 }
    else if (nota < min)
 {
  printf("Digite um número maior que %g: ", min);
 }
    else if (nota > max)
 {
  printf("Digite um número menor que %g: ", max);
 }
    else
    {
        leitura_valida = true;
    }
} while (!leitura_valida);

printf("Parabéns por tirar %g!\n", nota);
```

### Retomando o exemplo da senha

Por fim, vamos analisar o nosso primeiro exemplo do uso do `while` e ver como o `do while` é a estrutura de repetição ideal para **leitura de dados**.
Retomando:

```c
const int senha = 1234;
int tentativa = 0;

while (tentativa != senha)
{
    // ...
}
```

Precisamos criar a variável `tentativa` com o valor `0` apenas para garantir que a condição `0 != 1234` fosse verdadeira e o _loop_ **pudesse começar**.

Mas e se a senha real do sistema fosse exatamente `0`? Como o valor inicial da tentativa seria igual à senha, a condição `0 != 0` seria falsa.
O programa simplesmente pularia o _loop_ inteiro e diria que a senha está correta sem o usuário ter digitado absolutamente nada!
Poderíamos usar outro valor, como `1` e o programa passaria a funcionar, mas vamos por outro caminho.

O `while` segue a seguinte lógica: "**verificar, depois fazer**", ou seja, ele vai verificar se `tentativa != senha` para aí começar o _loop_.
Mas como estamos lendo uma entrada do usuário, não temos **nada para verificar** no começo do _loop_, é apenas **dentro dele** que a entrada é armazenada na variável `tentativa`.

O `do while` surge como uma forma de **inverter a lógica do while**, ou seja "**fazer, depois verificar**".
O código final fica assim:

> Note que a variável `resultado` foi renomeada para `r`, por simplicidade apenas.

```c
const int senha = 1234;

int tentativa;
bool leitura_valida = false;
do
{
 printf("Digite a senha de 4 dígitos: ");
 int r = scanf("%d", &tentativa);

 if (r != 1)
 {
  while (getchar() != '\n')
  {
  }

  printf("Você não digitou um inteiro!\n");
 }
    else if (tentativa != senha)
 {
  printf("Você digitou a senha errada!\n");
 }
    else
    {
        leitura_valida = true;
    }
} while (!leitura_valida);

printf("A senha está correta!\n");
```
