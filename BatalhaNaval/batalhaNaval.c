#include <stdio.h>

#define TAMANHO_TABULEIRO 5
#define TOTAL_NAVIOS 7
#define MAX_TENTATIVAS 15

static char paraMaiuscula(char caractere)
{
   if (caractere >= 'a' && caractere <= 'z')
   {
      return (char)(caractere - ('a' - 'A'));
   }

   return caractere;
}

static void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], char valor)
{
   int linha;
   int coluna;

   for (linha = 0; linha < TAMANHO_TABULEIRO; linha++)
   {
      for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++)
      {
         tabuleiro[linha][coluna] = valor;
      }
   }
}

static void posicionarNavios(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
   tabuleiro[0][0] = 'N';
   tabuleiro[0][1] = 'N';
   tabuleiro[0][2] = 'N';

   tabuleiro[2][3] = 'N';
   tabuleiro[3][3] = 'N';

   tabuleiro[4][0] = 'N';
   tabuleiro[4][1] = 'N';
}

static void exibirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
   int linha;
   int coluna;

   printf("\n  A B C D E\n");
   for (linha = 0; linha < TAMANHO_TABULEIRO; linha++)
   {
      printf("%d ", linha + 1);
      for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++)
      {
         printf("%c ", tabuleiro[linha][coluna]);
      }
      printf("%d\n", linha + 1);
   }
   printf("  A B C D E\n");
}

static int converterCoordenada(const char texto[], int *linha, int *coluna)
{
   char letra;
   char numero;

   if (texto[0] == '\0' || texto[1] == '\0' || texto[2] != '\0')
   {
      return 0;
   }

   letra = paraMaiuscula(texto[0]);
   numero = texto[1];

   if (letra < 'A' || letra > 'E')
   {
      return 0;
   }

   if (numero < '1' || numero > '5')
   {
      return 0;
   }

   *coluna = letra - 'A';
   *linha = numero - '1';
   return 1;
}

static int textoEhSair(const char texto[])
{
   return paraMaiuscula(texto[0]) == 'S' &&
          paraMaiuscula(texto[1]) == 'A' &&
          paraMaiuscula(texto[2]) == 'I' &&
          paraMaiuscula(texto[3]) == 'R' &&
          texto[4] == '\0';
}

int main(void)
{
   char nomeJogador[50];
   char tiroTexto[10];
   char tabuleiroOculto[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
   char tabuleiroVisivel[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
   int tentativas = MAX_TENTATIVAS;
   int acertos = 0;

   inicializarTabuleiro(tabuleiroOculto, '~');
   inicializarTabuleiro(tabuleiroVisivel, '~');
   posicionarNavios(tabuleiroOculto);

   printf("=== Batalha Naval ===\n");
   printf("Tabuleiro %dx%d com %d partes de navios escondidas.\n", TAMANHO_TABULEIRO, TAMANHO_TABULEIRO, TOTAL_NAVIOS);
   printf("Voce vence se destruir todos os navios antes de acabar as tentativas.\n");

   printf("\nDigite o nome do jogador: ");
   scanf("%49s", nomeJogador);

   while (tentativas > 0 && acertos < TOTAL_NAVIOS)
   {
      int linha;
      int coluna;

      printf("\nJogador: %s\n", nomeJogador);
      printf("Tentativas restantes: %d\n", tentativas);
      printf("Acertos: %d de %d\n", acertos, TOTAL_NAVIOS);
      exibirTabuleiro(tabuleiroVisivel);

      printf("Digite a coordenada do tiro (ex: B3) ou SAIR: ");
      scanf("%9s", tiroTexto);

      if (textoEhSair(tiroTexto))
      {
         printf("Partida encerrada pelo jogador.\n");
         return 0;
      }

      if (!converterCoordenada(tiroTexto, &linha, &coluna))
      {
         printf("Coordenada invalida. Use valores de A1 ate E5.\n");
         continue;
      }

      if (tabuleiroVisivel[linha][coluna] == 'X' || tabuleiroVisivel[linha][coluna] == 'O')
      {
         printf("Voce ja atirou nessa posicao. Escolha outra casa.\n");
         continue;
      }

      tentativas--;

      if (tabuleiroOculto[linha][coluna] == 'N')
      {
         tabuleiroVisivel[linha][coluna] = 'X';
         acertos++;
         printf("Acertou um navio!\n");
      }
      else
      {
         tabuleiroVisivel[linha][coluna] = 'O';
         printf("Agua!\n");
      }
   }

   printf("\n=== Resultado Final ===\n");
   exibirTabuleiro(tabuleiroVisivel);

   if (acertos == TOTAL_NAVIOS)
   {
      printf("Parabens, %s! Voce venceu a Batalha Naval!\n", nomeJogador);
   }
   else
   {
      printf("Fim de jogo, %s. Suas tentativas acabaram.\n", nomeJogador);
      printf("Tabuleiro com os navios:\n");
      exibirTabuleiro(tabuleiroOculto);
   }

   return 0;
}
