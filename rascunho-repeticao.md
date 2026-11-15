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
