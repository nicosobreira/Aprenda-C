# Dúvidas e Revelações de um Novato em C

Fonte: [Pointer Tricks that Leveled Up my Programming](https://youtu.be/-q6slaYwZzw)

- Tudo são bytes por debaixo do pano
- O que é padding? Para que serve?
- O novato não entende como a memória é **organizada**
- "As abstrações são montadas em cima de conceitos que você pode entender"

# Módulos para um Novato em C

Baseado no artigo: [On the Criteria To Be Used in Decomposing Systems into Modules](https://wstomv.win.tue.nl/edu/2ip30/references/criteria_for_modularization.pdf)

- Decompor o código é transformar ele em módulos.
- Não olhar a decomposição do código como um *flowchart*, mas sim como um conjunto de módulos ligados.
- A **primeira coisa** que um novato pode pensar é que: módularizar significa **dividir os processos**. O artigo argumenta contra esse ponto de vista, nos oferencendo uma nova perspectiva - de que devemos pensar em **isolar a parte complicada primeiro**, aquela que pode mudar, e trabalhar apartir dai.
- A decomposição, segundo Parnas, deve se basear em **isolar as partes do design**. Deve-se ocultar o que pode mudar com frequencia e o que é complicado

## Critérios para a Decomposição

### 1. Todas as funcionalidades de uma **estrutura de dados** deve ficar em **um único módulo**

### 2. A **sequência** de passos (funções) para executar uma **processo** e o próprio processo devem ficar no mesmo módulo

``` c
// Antes
if (sensor_is_ready() && sensor_check_power()) {
    sensor_trigger_hardware();
    int raw = sensor_read_register();
    int dado = sensor_apply_filter(raw);
}

// Depois
int dado = sensor_obter_leitura_filtrada();
```

### 3. Não acessar diretamente os membros de um `struct`

Falar em [Structs](./variaveis/struct.md)

### 4. Existem módulos que só servem para trazer **flexibilidade**

### 5. Como o processamento é feito deve ficar escondido

Exemplo: criar funções auxiliares para o acesso de uma estrutura de dados.
