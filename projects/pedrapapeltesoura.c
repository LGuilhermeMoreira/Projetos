#include<time.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
   // lendo o nome dos jogadores
   printf("Digite o nome do primeiro jogador: ");
   char nome1[100];
   scanf("%[^\n]",nome1);
   printf("Digite o nome do segundo jogador: ");
   char nome2[100];
   scanf(" %[^\n]",nome2);
   
   for(int i = 1; i =! 0;i++){
      if(i == 1){
         // inicializando o jogo
         printf("Inicializando Jogo...\n");
         printf("\n");
      }
      printf("('R' para pedra, 'S' para tesoura e 'P' para papel)\n");
      printf("\n");

      // lendo os mãos dos jogadores
      char jogador1,jogador2;
      printf("Digite a escolha do primeiro jogador: ");
      scanf(" %c",&jogador1);
      printf("\n");
      printf("Digite a escolha do segundo jogador: ");
      scanf(" %c",&jogador2);
      printf("\n");

      // criando as condições
      if((jogador1 == 'R' && jogador2 == 'S')||(jogador1 == 'P' && jogador2 == 'R')||(jogador1 == 'S' && jogador2 == 'P')){
         printf("%s eh o Ganhador\n",nome1);
         printf("\n");
      }
      else if(jogador1 == jogador2){
         printf("Empate :|\n");
         printf("\n");
      }
      else{
         printf("%s eh o Ganhador\n",nome2);
         printf("\n");
      }

      char resposta;
      printf("Deseja continuar jogando? ('s' para sim e 'n' para nao)\n");
      scanf(" %c",&resposta);
      if(resposta == 'n'){
         break;
      }
      else{
         printf("Continue o jogo!\n");
      }
      system("cls");
   }

   printf("\n");

   printf("Foi bom enquanto durou :(\n");

   return 0;
}