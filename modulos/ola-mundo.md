<p align="center">
  <a href="./instalacao.md">← Instalando o C</a>
  &nbsp;|&nbsp;
  <a href="./linguagem-c.md">O que é C? →</a>
</p>

---

# Olá, Mundo

O programa "Olá, Mundo!" é a iniciação de todo programador. Ele vai nos mostrar algumas regras básicas da linguagem C.

Antes de escrever o programa em si, vamos ver como usar o Visual Studio Code e o GCC para escrever e compilar os programas que vamos desenvolver.

## Como Organizar seus Códigos

Vamos estabelecer uma regra que seguiremos por todo o guia: **a cada novo módulo, crie uma nova pasta com o nome do módulo**. Isso evita que os arquivos de módulos diferentes se misturem, e já aproveitamos para praticar o uso do terminal.

Abra o VS Code e, dentro dele, abra o terminal integrado com o atalho `` Ctrl + ` `` (ou pelo menu **Terminal > New Terminal**).

> Se você estiver no Windows, configure o terminal integrado do VS Code para usar o **PowerShell** por padrão, já que os comandos que ensinamos neste guia foram pensados para ele, não para o Prompt de Comando (`cmd`). Para isso, aperte `Ctrl + Shift + P`, digite `Terminal: Select Default Profile` e escolha `PowerShell` na lista. Feche o terminal aberto e abra um novo para a mudança ter efeito.

Com o terminal aberto, crie uma pasta chamada `intro` (o nome desse primeiro módulo) e entre nela:

```bash
mkdir intro
cd intro
```

O comando `mkdir` (de _make directory_) cria uma pasta nova, e o `cd` (de _change directory_) entra dentro dela. A partir de agora, todo comando que rodarmos no terminal vai valer **dentro** dessa pasta `intro`. Esse mesmo padrão se repete nos próximos módulos: ao chegar em Variáveis, por exemplo, você criaria uma pasta `variaveis`, e assim por diante.

## Criando e Editando Arquivos

Para criar e abrir o arquivo do nosso primeiro programa, use o comando `code`, seguido do nome do arquivo:

```bash
code main.c
```

Se o arquivo `main.c` ainda não existir, o VS Code o cria automaticamente e já abre ele para edição. Esse comando, `code <arquivo>`, vai valer para o resto do guia: sempre que um capítulo pedir para criar um arquivo, use-o dentro da pasta certa.

Por ora, copie e cole isso dentro de `main.c`:

```c
int main(void)
{
    return 0;
}
```

Esse é um programa que **não faz nada**, só é necessário para o próximo passo.

## Compilando com o GCC

Antes do compilar os programas, não se esqueça de **salvá-los**! Para isso use o atalho `Ctrl + s` ou, ainda melhor, ative a opção de *Salvar Automaticamente* dentro do VS Code da seguinte maneira: abra o menu de **Configurações** apertando `Ctrl + ,`, pesquise por "*Auto Save*" e selecione a opção "*After Delay*".

O computador não entende C diretamente, então precisamos **traduzir** o arquivo `main.c` para um executável, usando o compilador instalado anteriormente, o `gcc`.

Ainda no terminal, **dentro da pasta `intro`**, e com o `main.c` **já salvo**, rode:

```bash
gcc -o main main.c
```

Vamos entender essa linha, pedaço por pedaço:

- `gcc`: é o programa que vai compilar o código.
- `main.c`: é o arquivo de código-fonte que queremos compilar.
- `-o main`: diz ao `gcc` qual nome deve ser dado ao **executável gerado**. Sem essa opção, o `gcc` usaria um nome genérico. Aqui, escolhemos chamar o nosso de `main`, mas poderia ser qualquer outro.

> No Windows, o `gcc` adiciona a extensão `.exe` automaticamente ao nome escolhido, então o executável se chamará `main.exe`, mesmo você tendo digitado só `main` no comando.

Se tudo ocorrer bem, esse comando **não imprime nada** no terminal, apenas cria o arquivo executável na mesma pasta. Se houver algum erro no seu código, o `gcc` vai mostrar mensagens indicando a linha e o motivo do erro.

## Executando o Programa

Por fim, para rodar o programa que acabamos de compilar:

```bash
./main
```

> Repare no `./` antes do nome do executável. Isso indica ao terminal que o programa está na **pasta atual**, e não em algum outro lugar do sistema. Sem esse prefixo, o terminal não vai encontrar o `main`.

Nesse caso, o nosso programa **deve fazer nada** mesmo.

O ciclo de **editar com `code`, compilar com `gcc`, executar com `./main`** — vai se repetir em praticamente todo capítulo do guia, então vale a pena se acostumar com ele desde já.
Você também pode usar as teclas "Seta para Cima" e "Seta para Baixo" para navegar pelo **histórico de comandos** - que são os últimos comandos executados no terminal.

---

Agora sim, vamos escrever o programa "Olá, Mundo!". Ao final, vamos ver erros de compilação comuns e como resolvê-los.

## Código

Dentro do mesmo `main.c`, agora escreva:

```c
#include <stdio.h>

int main(void)
{
    printf("Olá, Mundo!\n");

    return 0;
}
```

Vamos entender esse código começando pela função `main` — o coração de todo programa em C.

> Não se esqueça de compilar o programa e executá-lo antes de continuar!

## main

É uma função especial dentro do C; ela é o **ponto inicial** de nosso programa, por isso do nome "main", do inglês, principal.

As funções em C são semelhantes as da matemática. Dentro dos parênteses são colocados os parâmetros da função, quando escrevemos `f(x)`, dizemos que `x` é um parâmetro da função `f`. Nesse caso, o parênteses está com a palavra `void`, indicando que essa função não recebe nenhum argumento. É importante salientar que nem sempre esse é o caso, a função `main` pode sim receber parâmetros, mas veremos isso mais para frente.

O `int` é usado para indicar que essa função **retornará** um valor do tipo _inteiro_ em algum momento da execução da função `main`. Esse valor é retornado com o `return`; ele vai para o **sistema operacional** e mostra se o programa executou corretamente, retornando `0`, ou falhou em algum momento, retornando um valor diferente de `0`, como `1` ou `128`. Diferentes números indicam diferentes erros.

O comando `return` encerra a função na mesma hora. Se você colocar o `return 0;` antes do `printf`, como no código a seguir, o programa fechará imediatamente e o texto nunca será exibido. Faça esse teste antes de continuar.

``` c
#include <stdio.h>

int main(void)
{
    return 0;

    printf("Olá, Mundo!\n");
}
```

Após os parênteses, temos as chaves. Elas indicam a definição da função, que é todo o código que será executado quando função ser chamada, ou seja, o programa a ser executado. Diferente das outras funções, a função `main` é chamada automaticamente ao rodarmos o nosso programa.

### Formatação do código

Você pode escrever a função da seguinte maneira:

```c
int main() {
    ...
}
```

E está tudo certo. A linguagem C é bem flexível quanto ao modo como escolhemos formatar o nosso código. Quebrar uma linha para a abertura das chave é um costume meu, e é o que vou usar ao longo desse guia.

## include

Você deve estar se perguntando: de onde vem a função `printf`? Nós não escrevemos o código dela em lugar nenhum!

A resposta é a **Biblioteca Padrão do C**: um conjunto de funções prontas que já vêm junto com a linguagem, para tarefas comuns, como exibir texto na tela ou ler dados do usuário. Pense nela como uma caixa de ferramentas: ao invés de cada programador precisar inventar sua própria forma de escrever no terminal, a Biblioteca Padrão já oferece essa ferramenta pronta, chamada `printf`, para todo mundo usar.

Essas ferramentas ficam organizadas em arquivos chamados de **_headers_** (do inglês, "cabeçalhos"), reconhecidos pela extensão `.h`. Cada header guarda um grupo de funções parecidas entre si. O header `stdio.h`, por exemplo, guarda as funções de entrada e saída (**i**nput/**o**utput), como o `printf` e o `scanf`.

O `#include <stdio.h>` é o que **libera o uso** dessas funções no nosso código. Sem essa linha, o compilador não saberia o que é `printf`, e o programa não compilaria.

> Falaremos sobre o porquê de usarmos os símbolos `<>` mais para frente.

## printf

A função `printf` **imprime** (_print_) textos **formatados** (_f_) no terminal. Nós veremos os diferentes tipos de formatação em [Variáveis](./variaveis.md), mas o que você precisa saber agora é que o `printf` escreve o texto "Olá, Mundo!" no terminal.

Nós precisamos colocar esse `\n`, lido como "barra **n**ova linha", no final para quebrar a linha. Tire ele e veja como a saída sai meio grudada.

O ponto e vírgula vai ao final dos comandos. Sem ele o compilador irá tentar executar desde o `printf` até o próximo ponto e vírgula, ou seja, até `return 0;`, o que vai gerar um erro (que veremos logo em seguida).

## Mensagens de Compilação

A primeira vista, as mensagens de compilação são assustadores e difíceis de decifrar, quando não sabemos como lê-las. Vamos analisar diversas mensagens comuns, e ao final, espero que você veja como as mensagens de compilação nos ajudam a identificar e corrigir erros.

### Esquecer o ponto e vírgula

Execute o comando `gcc -o main main.c` e veja oque acontece quando esquecemos de colocar o `;` ao final do `printf`.

**Código**:

``` c
#include <stdio.h>

int main(void)
{
    printf("Olá, Mundo!\n")

    return 0;
}
```

Ao longo do guia, ao mostrar as saídas de comandos, como o de compilação, usarei o `$` na primeira linha para indicar qual foi o comando executado e abaixo sua saída, como a seguir:

```
$ gcc -o main main.c
main.c: In function ‘main’:
main.c:5:28: error: expected ‘;’ before ‘return’
    5 |     printf("Olá, Mundo!\n")
      |                            ^
      |                            ;
    6 |
    7 |         return 0;
      |         ~~~~~~

```

Parece muita coisa, mas a saída sempre segue o mesmo padrão. Vamos ler a saída com calma, de cima para baixo.

#### 1. Onde: `main.c: In function ‘main’:`

A primeira linha indica a **localização** do erro, ou seja, em qual **arquivo** e em qual **função** o erro foi encontrado. Nesse caso é a função `main` dentro do arquivo `main.c`.

#### 2. Localização: `main.c:5:28`

Sabemos que o erro está no arquivo `main.c`, função `main`, mas a onde em específico? Nessa linha, o compilador nos informa novamente em qual arquivo o erro ocorreu e ainda informa a **linha** e **coluna** do erro, seguindo o seguinte padrão: `arquivo:linha:coluna`. Nesse caso, o erro está na **linha 5**, **coluna 28** de `main.c`. Note que a linha 5 é onde o `printf` começa, e a coluna 28 é onde não colocamos o `;`.

#### 3. Gravidade: `error`, `warning` e `note`

Os trechos passados da mensagem indicam **a onde** o erro ocorreu, já `error: expected ‘;’ before ‘return’` é a mensagem do **que aconteceu de errado**. Cada mensagem começa com um desses três **rótulos**:

- **`error`**: o programa não compila. É necessário corrigi-lo.
- **`warning`**: o programa compila, mas algo provavelmente está errado. Nunca ignore os avisos.
- **`note`**: uma informação extra para te ajudar a resolver um problema. Não é o problema em si.

#### 4. O que aconteceu: `expected ‘;’ before ‘return’`

Essa é a explicação do erro, uma tradução da mensagem seria: `O ‘;’ é esperado antes do ‘return’`.

#### 5. O trecho do código

```
    5 |     printf("Olá, Mundo!\n")
      |                            ^
      |                            ;
    6 |
    7 |         return 0;
      |         ~~~~~~
```

Ao final, temos o trecho do código que gerou o erro. Antes do trecho começar, são colocados alguns espaços (nesse caso quatro) para indicar a qual mensagem o erro se refere. As marcações `5 |`, `6 |` e `7 |` indicam **as linhas no código** em que o erro aconteceu, seguido por seus conteúdos.

Já as linhas que possuem apenas `|`, sem numeração, são anotações sobre o erro que o compilador está passando para nós. O compilador "grifou" o `return` com uma série de acentos (`~~~~~~`) e sinalizou que devemos adicionar um ponto e vírgula ao final do `printf` da seguinte maneira:

```
^
;
```

### Esquecer do `include`

Veja a mensagem gerada pelo compilador quando esquecemos de colocar o `#include <stdio.h>` antes de usar a função `printf`:

**Código**:

``` c
int main(void)
{
    printf("Olá, Mundo!\n");

    return 0;
}
```

**Saída**:

```
$ gcc -o main main.c
main.c: In function ‘main’:
main.c:3:5: error: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
    3 |     printf("Olá, Mundo!\n");
      |     ^~~~~~
main.c:1:1: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
  +++ |+#include <stdio.h>
    1 | int main(void)
main.c:3:5: warning: incompatible implicit declaration of built-in function ‘printf’ [-Wbuiltin-declaration-mismatch]
    3 |     printf("Olá, Mundo!\n");
      |     ^~~~~~
main.c:3:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’

```

Em saídas com muitas mensagens, é comum que apenas as **primeiras mensagens** apontem para o **erro principal** e as outras mostrarem outros erros **gerados** pelo erro principal. Vamos analisar essa mensagem de cima para baixo e identificar o **erro principal** (ausência do `#include`).

#### 1. Onde

A primeira linha junto com `main.c:3:5` indicam que a mensagem se refere à função `main` no arquivo `main.c`, linha 3 e coluna 5.

#### 2. O que aconteceu

Seguido do `error:` vem a mensagem `implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]`. Uma tradução dessa mensagem seria: `declaração implícita da função ‘printf’`, já o conteúdo entre colchetes, `[-Wimplict-function-declaration]`, indica o nome da opção do GCC que gerou essa mensagem (ele é útil para pesquisar mais sobre o erro em especifico na internet). Essa mensagem está dizendo que a função `printf` foi **implicitamente declarada**, isso quer dizer que quando o compilador encontrou o uso do `printf` na linha 3 ele não sabia que essa função existia, e por isso não sabe como continuar.

> Veremos o que exatamente é uma função "implicitamente declarada" em [Funções](./funcoes.md).

#### 3. Trecho do código

```
    3 |     printf("Olá, Mundo!\n");
      |     ^~~~~~
```

O compilador mostra a linha com problema e usa `^~~~~~` para **apontar exatamente** onde está o erro: a palavra `printf`, que não é conhecida pelo compilador.

#### 4. A solução: `main.c:1:1: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’`

Nessa linha temos duas informações, qual é a solução do problema e a onde devemos colocá-la. A solução é incluir o `stdio.h` ou dar uma declaração para a função `printf`. Se nos "declaramos a função `printf`" teremos outro problema, esse veremos em [Funções](./funcoes.md), então vamos incluir o `stdio.h`. Logo abaixo temos o seguinte trecho do código:

```
  +++ |+#include <stdio.h>
    1 | int main(void)
```

O compilador utilizou o `+++ |` para indicar exatamente **o que fazer** e **a onde fazer** a alteração, que no caso é incluir a linha `#include <stdio.h>` acima de `int main(void)`.

#### 5. Outras mensagens

O compilador ainda nos informa mais duas mensagens:

```
main.c:3:5: warning: incompatible implicit declaration of built-in function ‘printf’ [-Wbuiltin-declaration-mismatch]
    3 |     printf("Olá, Mundo!\n");
      |     ^~~~~~
main.c:3:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
```

Note que elas apontam para o mesmo lugar do erro principal: linha 3, coluna 5, o `printf`. Isso é um sinal de que ambas são consequências do mesmo problema, a ausência do `#include <stdio.h>`.

Aqui temos um aviso, não um erro. Uma tradução seria: `declaração implícita incompatível da função embutida ‘printf’`.

O compilador GCC já conhece algumas funções da Biblioteca Padrão, como o `printf`, por serem muito usadas. Elas são chamadas de funções embutidas (*built-in functions*), e o GCC sabe qual é a forma correta de usá-las: quais parâmetros recebem e o que retornam. O nome entre colchetes, `[-Wbuiltin-declaration-mismatch]`, identifica a opção que gerou o aviso, e vale pesquisá-lo na Internet para saber mais. Em resumo, o compilador está dizendo: "você usou uma função que eu conheço, mas do jeito errado, porque não me disse de onde ela vem".

Lembre-se do que vimos em gravidade: um `warning` sozinho não impede a compilação, mas indica que algo provavelmente está errado. Aqui, ele só aparece junto do error, mas em outros programas você poderá ter um executável gerado com avisos. Não os ignore!

A última mensagem é igual à que vimos no passo 4: `include ‘<stdio.h>’ or provide a declaration of ‘printf’`. O `note` sempre complementa a mensagem logo acima dele. Como o GCC emitiu dois problemas (o `error` e o `warning`), ele repetiu a mesma dica para cada um, afinal, a solução é a mesma.

Por isso, a saída tem duas notas idênticas: a primeira ajuda com o `error`, a segunda com o `warning`.

Adicione o `#include <stdio.h>` no começo do arquivo e compile novamente. Todas as quatro mensagens desaparecem juntas! Esse é o hábito mais importante ao ler uma saída do compilador:

1. Identifique o erro principal, em geral o primeiro `error`.
2. Corrija apenas ele.
3. Compile de novo e veja o que sobrou.

Muitas vezes, uma única correção elimina diversas mensagens de uma vez.

### Outros erros

Ainda existem muitos erros de compilação, mas para entendê-los são necessários conteúdos que veremos mais para frente. A baixo vou mostrar códigos que apresentam alguns erros para você evitar, veremos as suas causas mais para frente:

- **Não definir a função `main`**:

``` c
#include <stdio.h>

printf("Olá, Mundo!\n");
```

- **Não escrever nada**:

``` c
#include <stdio.h>
```

---

<p align="center">
  <a href="./instalacao.md">← Instalando o C</a>
  &nbsp;|&nbsp;
  <a href="./linguagem-c.md">O que é C? →</a>
</p>

