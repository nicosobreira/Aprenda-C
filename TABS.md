# Correções

- [ ] Seta para o próximo capítulo e capítulo anterior
- [ ] Aviso sobre o autosave do VSCode
- [ ] Colocar os códigos antes de erros de saída em um details.
- [ ] Usar o `int main(void) {}` quando valer apena executar, caso contrário não.

## Linguagem C

- [ ] No segundo parágrafo final, muitos conceitos atrapalham quem está començando. Simplificar oque é falado (não citar conceitos específicos)

## Olá Mundo

- [ ] Mensagens de erros mais completas e claras. Fazer um passo a passo de como ler uma mensagem de erro (Ver [Error](./correcoes/erro.md))

### Compilando com o GCC

- [ ] O autosave do vs code não foi habilitado

### main

- [ ] Pulou a parte em que o return fica antes do `printf`
- [ ] Explicar o que não escrever `main` faz (erro no linker)
- [ ] Explicar o que colocar o código sem `main` faz, mas como `printf`
- [ ] Explicar que é o return que retorna 0

## Variáveis

### Declaração

- [ ] Mostrar mais tipos primitos (int, char, float) para elucidar melhor.
- [ ] Ao falar da mudança semântica da variável, dar um contexto antes que deixe essa ideia explícita.

### Atribuição

- [ ] Não expliquei por que é necessário o uso de `int` e quando não é. Mais exemplos em código.

### int

- [ ] Mais exemplos (em código) sobre as operações matemáticas (3 a 5 exemplos que mostrem todas as possíveis operações) (var x var, etc).
- [ ] Deixar claro que para inserir a variável no printf é necessário o `%` (não deixar implícito) 
- [ ] Explicar que dá para fazer `printf("%d\n", 1 + 2);`

### float/double

- [ ] Não vou falado como mais bits e precisão estão conectados. Talvez colocar ao final uma tabela de quantos bits cada variável tem. Primeiro falar que os dois representam números reais, apenas isso, mais para frente explicar a diferença.
- [ ] Falar sobre conversão de valores (int para float, float para int) com exemplos em código, com e sem printf (misturar com operações também).
- [ ] Explicar melhor o que o `.2` e `.0` faz.
- [ ] Explicar a importância do `.0` para diferenciar do `int`.

### char

- [ ] Explicar a diferença entre `''` e `""` no começo
- [ ] Colocar os testes `char letra = 67` e `char letra = '\n'` (mais exemplos com código).
- [ ] Explicar direito o que é a tabela ASCII, por ela existe.
- [ ] Explicar o que é um overflow com exemplo de acento `char letra = 'á'`
- [ ] Eu menti no inicio, não existem caracteres acentuados em ASCII.

### bool

- [ ] Não converto o tipo bool para string em condicionais, arrumar isso.

### Regras de Nomenclatura

- [ ] Explicar o que é um "identificador" antes de falar sobre as regras.
- [ ] Explicar o que é uma palavra reservada

### Variáveis Constantes

- [ ] Deixar claro que o `const` deixa constante.

### Inicialização

- [ ] Deixar claro que a inicialização vale para mais de um tipo.
- [ ] Mostrar como inicializar variável no final.

### Valores Mágicos

- [ ] Colocar parênteses entre as expressões com valores mágicos.

## Condicionais

## if e else

- [ ] Erro de ortografia: "guarda chuva" -> "guarda-chuvanvim"

## else if

- [ ] **Não tinha explicado o que são comentários**. Deixar claro que o `//` também pode ser usado para `/* */` na hora de ocultar o `printf`.
- [ ] Não expliquei direito o `if else`. O código está muito jogado e não vou trabalhado.
- [ ] Deixar que o `if`, `if else` e `else` ignoram os outros.
- [ ] Mudar "- não incluindo - para cima".
- [ ] Falar sobre `>=` e `>` antes.
- [ ] Explicar a saída de `if ((12 <= idade) <= 17)` retorna. Tudo é 0 e 1 no final, (12 <= idade) retorna um número que é comparado.
- [ ] Explicar o `&&` e `||`
- [ ] Condições dentro das outras.
- [ ] Condições com parentêses (ordem das verificações padrão).
- [ ] Colocar condições em variáveis `bool eh_triangulo = (a + b) > c && ...`.

## Negação

- [ ] Mover o capítulo sobre Retorno Antecipado para Funções (em Boas Práticas). Aqui, ele só serve para confundir e não agrega muito. Pensar em um exemplo de negação usando intervalos, ou algo do tipo.
- [ ] Não expliquei direito o que é o padrão IEEE 754. Deixar claro que ele organiza os bits em certa forma.
- [ ] Usar uma variável `tem_acesso` para explicar `!tem_acesso`.

## Ideiais de Exercícios para Variáveis

- [ ] Analisar expressão aritmética, calcular média ()

## Exercícios Condicional

- [ ] Deixar claro nos exercícios para evitar a usar valores mágicos.
- [ ] Criar uma tabela de valores para testar o programa.
- [ ] Exercício de dinheiro (quantas notas de 100, 50, 20, 10, 5).
