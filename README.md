# Projetos em C

Este repositório reúne programas simples em C para praticar entrada e saída de dados, tipos de variáveis e jogos de console.

## Como compilar

No PowerShell, a partir da raiz do projeto, use um comando no formato abaixo:

```powershell
gcc .\pasta\arquivo.c -o .\pasta\programa.exe
```

Exemplo:

```powershell
gcc .\BatalhaNaval\batalhaNaval.c -o .\BatalhaNaval\batalhaNaval.exe
```

## Como executar

```powershell
Set-Location .\BatalhaNaval
.\batalhaNaval.exe
```

O mesmo padrão vale para os demais programas, ajustando a pasta e o nome do executável.

## Programas

### OlaMundo

- [OlaMundo/hello.c](OlaMundo/hello.c): imprime Hello, World.
- [OlaMundo/olaMundo.c](OlaMundo/olaMundo.c): imprime uma saudação em português usando locale.

### Entrada e Saida

- [entradaSaida/entradaSaida.c](entradaSaida/entradaSaida.c): demonstra formatos de impressão com printf e apresenta funções comuns de entrada e saída.
- [entradaSaida/entradaDados.c](entradaSaida/entradaDados.c): lê nome e senha pelo teclado e exibe os valores informados.
- [entradaSaida/calculoMedia.c](entradaSaida/calculoMedia.c): lê nome e três notas de um aluno e calcula a média.

### Variaveis e Tipos

- [variblesTipos/variables_Tipos.c](variblesTipos/variables_Tipos.c): apresenta variáveis inteiras, float, char e strings, com exibição formatada no console.

### Super Trunfo

- [superTrunfo/gameSuperTrunfo.c](superTrunfo/gameSuperTrunfo.c): cadastra duas cartas com cidade, população, área, PIB e pontos turísticos. Em seguida, dois jogadores escolhem um atributo para comparar e o programa informa o vencedor.

Como jogar:

1. Preencha os dados da carta 1.
2. Preencha os dados da carta 2.
3. Informe o nome dos dois jogadores.
4. Escolha o atributo da comparação.

### Xadrez

- [gameXadres/gameXadrez.c](gameXadres/gameXadrez.c): exibe um tabuleiro de xadrez e alterna turnos entre dois jogadores.

Funcionalidades atuais:

1. Cada jogador escolhe a origem e o destino da peça por coordenadas, como A2 e A4.
2. O jogo valida posse da peça, coordenada de entrada, captura da própria peça e movimento das peças principais.
3. Estão implementados os movimentos de peão, torre, bispo, cavalo, rainha e rei.
4. O jogo pode ser encerrado digitando SAIR na origem.

Limitações atuais:

1. Ainda não há xeque, xeque-mate, roque, promoção ou en passant.
2. O jogo não bloqueia jogadas que deixem o rei em xeque.

### Batalha Naval

- [BatalhaNaval/batalhaNaval.c](BatalhaNaval/batalhaNaval.c): jogo de console em um tabuleiro 5x5 com navios ocultos.

Como jogar:

1. Informe o nome do jogador.
2. Digite coordenadas de tiro de A1 até E5.
3. O tabuleiro mostra X para acerto e O para água.
4. O jogo termina quando todos os navios forem destruídos ou quando as tentativas acabarem.
5. Você pode encerrar digitando SAIR.

Regras do Batalha Naval:

1. O jogador tem 15 tentativas.
2. Existem 7 posições de navios escondidas no tabuleiro.
3. Não é permitido repetir tiro na mesma posição.

## Sugestões de evolução

1. Adicionar aleatoriedade no posicionamento dos navios da batalha naval.
2. Criar modos para dois jogadores.
3. Melhorar o xadrez com xeque, xeque-mate e regras especiais.
4. Permitir leitura de nomes com espaços nos programas de entrada.