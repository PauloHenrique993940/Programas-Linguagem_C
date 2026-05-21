#include <stdio.h>

static int ehMaiuscula(char caractere)
{
   return caractere >= 'A' && caractere <= 'Z';
}

static int ehMinuscula(char caractere)
{
   return caractere >= 'a' && caractere <= 'z';
}

static char paraMaiuscula(char caractere)
{
   if (caractere >= 'a' && caractere <= 'z')
   {
      return (char)(caractere - ('a' - 'A'));
   }

   return caractere;
}

static int textoEhSair(const char texto[])
{
   return paraMaiuscula(texto[0]) == 'S' &&
          paraMaiuscula(texto[1]) == 'A' &&
          paraMaiuscula(texto[2]) == 'I' &&
          paraMaiuscula(texto[3]) == 'R' &&
          texto[4] == '\0';
}

static int converterPosicao(const char texto[], int *linha, int *coluna)
{
   char colunaTexto;
   char linhaTexto;

   if (texto[0] == '\0' || texto[1] == '\0' || texto[2] != '\0')
   {
      return 0;
   }

   colunaTexto = paraMaiuscula(texto[0]);
   linhaTexto = texto[1];

   if (colunaTexto < 'A' || colunaTexto > 'H')
   {
      return 0;
   }

   if (linhaTexto < '1' || linhaTexto > '8')
   {
      return 0;
   }

   *coluna = colunaTexto - 'A';
   *linha = 8 - (linhaTexto - '0');
   return 1;
}

static int pecaPertenceAoJogador(char peca, int jogadorAtual)
{
   if (jogadorAtual == 0)
   {
      return ehMaiuscula(peca);
   }

   return ehMinuscula(peca);
}

static int valorAbsoluto(int valor)
{
   if (valor < 0)
   {
      return -valor;
   }

   return valor;
}

static int caminhoLivre(char tabuleiro[8][8], int origemLinha, int origemColuna, int destinoLinha, int destinoColuna)
{
   int passoLinha = 0;
   int passoColuna = 0;
   int linhaAtual;
   int colunaAtual;

   if (origemLinha < destinoLinha)
   {
      passoLinha = 1;
   }
   else if (origemLinha > destinoLinha)
   {
      passoLinha = -1;
   }

   if (origemColuna < destinoColuna)
   {
      passoColuna = 1;
   }
   else if (origemColuna > destinoColuna)
   {
      passoColuna = -1;
   }

   linhaAtual = origemLinha + passoLinha;
   colunaAtual = origemColuna + passoColuna;

   while (linhaAtual != destinoLinha || colunaAtual != destinoColuna)
   {
      if (tabuleiro[linhaAtual][colunaAtual] != ' ')
      {
         return 0;
      }

      linhaAtual += passoLinha;
      colunaAtual += passoColuna;
   }

   return 1;
}

static int validarMovimentoPeao(
    char tabuleiro[8][8],
    char peca,
    int origemLinha,
    int origemColuna,
    int destinoLinha,
    int destinoColuna)
{
   int direcao;
   int linhaInicial;
   int diferencaLinha;
   int diferencaColuna;
   char destino;

   if (ehMaiuscula(peca))
   {
      direcao = 1;
      linhaInicial = 1;
   }
   else
   {
      direcao = -1;
      linhaInicial = 6;
   }

   diferencaLinha = destinoLinha - origemLinha;
   diferencaColuna = destinoColuna - origemColuna;
   destino = tabuleiro[destinoLinha][destinoColuna];

   if (diferencaColuna == 0)
   {
      if (diferencaLinha == direcao && destino == ' ')
      {
         return 1;
      }

      if (origemLinha == linhaInicial && diferencaLinha == 2 * direcao && destino == ' ')
      {
         int linhaIntermediaria = origemLinha + direcao;
         return tabuleiro[linhaIntermediaria][origemColuna] == ' ';
      }
   }

   if (diferencaLinha == direcao && valorAbsoluto(diferencaColuna) == 1 && destino != ' ')
   {
      return 1;
   }

   return 0;
}

static int validarMovimento(char tabuleiro[8][8], char peca, int origemLinha, int origemColuna, int destinoLinha, int destinoColuna)
{
   int diferencaLinha = destinoLinha - origemLinha;
   int diferencaColuna = destinoColuna - origemColuna;
   char tipoPeca = paraMaiuscula(peca);

   if (origemLinha == destinoLinha && origemColuna == destinoColuna)
   {
      return 0;
   }

   switch (tipoPeca)
   {
   case 'P':
      return validarMovimentoPeao(tabuleiro, peca, origemLinha, origemColuna, destinoLinha, destinoColuna);
   case 'T':
      if (origemLinha != destinoLinha && origemColuna != destinoColuna)
      {
         return 0;
      }
      return caminhoLivre(tabuleiro, origemLinha, origemColuna, destinoLinha, destinoColuna);
   case 'B':
      if (valorAbsoluto(diferencaLinha) != valorAbsoluto(diferencaColuna))
      {
         return 0;
      }
      return caminhoLivre(tabuleiro, origemLinha, origemColuna, destinoLinha, destinoColuna);
   case 'Q':
      if (origemLinha == destinoLinha || origemColuna == destinoColuna || valorAbsoluto(diferencaLinha) == valorAbsoluto(diferencaColuna))
      {
         return caminhoLivre(tabuleiro, origemLinha, origemColuna, destinoLinha, destinoColuna);
      }
      return 0;
   case 'N':
      return (valorAbsoluto(diferencaLinha) == 2 && valorAbsoluto(diferencaColuna) == 1) ||
             (valorAbsoluto(diferencaLinha) == 1 && valorAbsoluto(diferencaColuna) == 2);
   case 'K':
      return valorAbsoluto(diferencaLinha) <= 1 && valorAbsoluto(diferencaColuna) <= 1;
   default:
      return 0;
   }
}

static void exibirTabuleiro(char tabuleiro[8][8])
{
   int linha;
   int coluna;

   printf("\n  A B C D E F G H\n");
   for (linha = 0; linha < 8; linha++)
   {
      printf("%d ", 8 - linha);
      for (coluna = 0; coluna < 8; coluna++)
      {
         printf("%c ", tabuleiro[linha][coluna]);
      }
      printf("%d\n", 8 - linha);
   }
   printf("  A B C D E F G H\n");
}

static void moverPeca(char tabuleiro[8][8], int origemLinha, int origemColuna, int destinoLinha, int destinoColuna)
{
   char peca = tabuleiro[origemLinha][origemColuna];

   tabuleiro[destinoLinha][destinoColuna] = peca;
   tabuleiro[origemLinha][origemColuna] = ' ';
}

int main()
{
   char jogador1[50];
   char jogador2[50];
   char origemTexto[10];
   char destinoTexto[10];
   int turno = 0;

   // Criando o tabuleiro
   // R = Torre, N = Cavalo, B = Bispo, Q = Rainha, K = Rei, P = Peao
   char tabuleiro[8][8] = {
       {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
       {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
       {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
       {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
       {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};

   printf("=== Jogo de Xadrez ===\n");
   printf("Tabuleiro inicial:\n");
   exibirTabuleiro(tabuleiro);

   printf("\nDigite o nome do Jogador 1: ");
   scanf("%49s", jogador1);

   printf("Digite o nome do Jogador 2: ");
   scanf("%49s", jogador2);

   printf("\nO jogo de xadrez entre %s e %s foi iniciado!\n", jogador1, jogador2);
   printf("%s controla as pecas maiusculas.\n", jogador1);
   printf("%s controla as pecas minusculas.\n", jogador2);

   printf("\nDigite SAIR no campo de origem para encerrar a partida.\n");

   while (1)
   {
      char *nomeJogador;
      int origemLinha;
      int origemColuna;
      int destinoLinha;
      int destinoColuna;
      char pecaOrigem;
      char pecaDestino;

      nomeJogador = turno % 2 == 0 ? jogador1 : jogador2;

      printf("\nTurno de %s\n", nomeJogador);
      exibirTabuleiro(tabuleiro);

      printf("Escolha a peca pela origem (ex: A2): ");
      scanf("%9s", origemTexto);

      if (textoEhSair(origemTexto))
      {
         break;
      }

      if (!converterPosicao(origemTexto, &origemLinha, &origemColuna))
      {
         printf("Posicao de origem invalida. Use coordenadas como A2 ou H7.\n");
         continue;
      }

      pecaOrigem = tabuleiro[origemLinha][origemColuna];
      if (pecaOrigem == ' ')
      {
         printf("Nao ha nenhuma peca nessa casa.\n");
         continue;
      }

      if (!pecaPertenceAoJogador(pecaOrigem, turno % 2))
      {
         printf("Essa peca pertence ao outro jogador.\n");
         continue;
      }

      printf("Digite o destino da jogada (ex: A4): ");
      scanf("%9s", destinoTexto);

      if (!converterPosicao(destinoTexto, &destinoLinha, &destinoColuna))
      {
         printf("Posicao de destino invalida. Use coordenadas como A4 ou H5.\n");
         continue;
      }

      pecaDestino = tabuleiro[destinoLinha][destinoColuna];
      if (pecaDestino != ' ' && pecaPertenceAoJogador(pecaDestino, turno % 2))
      {
         printf("Voce nao pode capturar sua propria peca.\n");
         continue;
      }

      if (!validarMovimento(tabuleiro, pecaOrigem, origemLinha, origemColuna, destinoLinha, destinoColuna))
      {
         printf("Movimento invalido para essa peca.\n");
         continue;
      }

      moverPeca(tabuleiro, origemLinha, origemColuna, destinoLinha, destinoColuna);
      printf("%s moveu %c de %s para %s.\n", nomeJogador, pecaOrigem, origemTexto, destinoTexto);
      turno++;
   }

   printf("\nPartida encerrada. Tabuleiro final:\n");
   exibirTabuleiro(tabuleiro);

   return 0;
}