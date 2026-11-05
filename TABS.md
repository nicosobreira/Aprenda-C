# Correções

- [x] Seta para o próximo capítulo e capítulo anterior
- [x] Aviso sobre o autosave do VSCode
- [x] Colocar os códigos antes de erros de saída em um details.
- [ ] Usar o `int main(void) {}` quando valer apena executar, caso contrário não.

## Linguagem C

- [x] No segundo parágrafo final, muitos conceitos atrapalham quem está començando. Simplificar oque é falado (não citar conceitos específicos)

## Olá Mundo

- [x] Mensagens de erros mais completas e claras. Fazer um passo a passo de como ler uma mensagem de erro (Ver [Error](./correcoes/erro.md))

### Compilando com o GCC

- [x] O autosave do vs code não foi habilitado

### main

- [x] Pulou a parte em que o return fica antes do `printf`
- [x] Explicar o que não escrever `main` faz (erro no linker)
- [x] Explicar o que colocar o código sem `main` faz, mas como `printf`
- [x] Explicar que é o return que retorna 0

## Variáveis

### Declaração

- [x] Mostrar mais tipos primitos (int, char, float) para elucidar melhor.
- [x] Ao falar da mudança semântica da variável, dar um contexto antes que deixe essa ideia explícita.

### Atribuição

- [x] Não expliquei por que é necessário o uso de `int` e quando não é. Mais exemplos em código.

### int

- [x] Mais exemplos (em código) sobre as operações matemáticas (3 a 5 exemplos que mostrem todas as possíveis operações) (var x var, etc).
- [x] Deixar claro que para inserir a variável no printf é necessário o `%` (não deixar implícito) 
- [x] Explicar que dá para fazer `printf("%d\n", 1 + 2);`

### float/double

- [x] Não vou falado como mais bits e precisão estão conectados. Talvez colocar ao final uma tabela de quantos bits cada variável tem. Primeiro falar que os dois representam números reais, apenas isso, mais para frente explicar a diferença.
- [ ] Falar sobre conversão de valores (int para float, float para int) com exemplos em código, com e sem printf (misturar com operações também).
- [x] Explicar melhor o que o `.2` e `.0` faz.
- [x] Explicar a importância do `.0` para diferenciar do `int`.

### char

- [x] Explicar a diferença entre `''` e `""` no começo
- [x] Colocar os testes `char letra = 67` e `char letra = '\n'` (mais exemplos com código).
- [x] Explicar direito o que é a tabela ASCII, por ela existe.
- [ ] Explicar o que é um overflow com exemplo de acento `char letra = 'á'`
- [x] Eu menti no inicio, não existem caracteres acentuados em ASCII.

### bool

- [ ] Não converto o tipo bool para string em condicionais, arrumar isso.

### Regras de Nomenclatura

- [x] Explicar o que é um "identificador" antes de falar sobre as regras.
- [x] Explicar o que é uma palavra reservada

### Variáveis Constantes

- [x] Deixar claro que o `const` deixa constante.

### Inicialização

- [x] Deixar claro que a inicialização vale para mais de um tipo.
- [x] Mostrar como inicializar variável no final.

### Valores Mágicos

- [x] Colocar parênteses entre as expressões com valores mágicos.

## Condicionais

## if e else

- [x] Erro de ortografia: "guarda chuva" -> "guarda-chuva"

## else if

- [x] **Não tinha explicado o que são comentários**. Deixar claro que o `//` também pode ser usado para `/* */` na hora de ocultar o `printf`.
- [x] Não expliquei direito o `if else`. O código está muito jogado e não vou trabalhado.
- [x] Deixar que o `if`, `if else` e `else` ignoram os outros.
- [x] Mudar "- não incluindo - para cima".
- [x] Falar sobre `>=` e `>` antes.
- [ ] Explicar a saída de `if ((12 <= idade) <= 17)` retorna. Tudo é 0 e 1 no final, (12 <= idade) retorna um número que é comparado.
- [x] Explicar o `&&` e `||`
- [x] Condições dentro das outras.
- [x] Condições com parentêses (ordem das verificações padrão).
- [x] Colocar condições em variáveis `bool eh_triangulo = (a + b) > c && ...`.

## Negação

- [x] Mover o capítulo sobre Retorno Antecipado para Funções (em Boas Práticas). Aqui, ele só serve para confundir e não agrega muito. Pensar em um exemplo de negação usando intervalos, ou algo do tipo.
- [ ] Não expliquei direito o que é o padrão IEEE 754. Deixar claro que ele organiza os bits em certa forma.
- [x] Usar uma variável `tem_acesso` para explicar `!tem_acesso`.

## Ideiais de Exercícios para Variáveis

- [x] Analisar expressão aritmética, calcular média ()

## Exercícios Condicional

- [ ] Deixar claro nos exercícios para evitar a usar valores mágicos.
- [ ] Criar uma tabela de valores para testar o programa.
- [ ] Exercício de dinheiro (quantas notas de 100, 50, 20, 10, 5).
