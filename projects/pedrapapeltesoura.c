#include<time.h>
#include<stdio.h>
#include<stdlib.h>

char jogada_bot(){
   srand(time(NULL));
   int resp = rand()%3;
   
   if(resp == 0) return 'R'; // pedra
   else if(resp == 1) return 'P'; // papel   
   else return 'S'; // tesoura
}

int main()
{
   // lendo o nome do jogadore
   printf("Digite o nome do primeiro jogador: ");
   char nome1[100];
   scanf("%[^\n]",nome1);
   printf("\n");
  
   for(int i = 1; i =! 0;i++){
      if(i == 1){
         // inicializando o jogo
         printf("Inicializando Jogo...\n");
         printf("\n");
      }
      printf("('R' para pedra, 'S' para tesoura e 'P' para papel)\n");
      printf("\n");

      // lendo os mãos dos jogadores
      char jogador;
      printf("Digite a escolha do primeiro jogador: ");
      scanf(" %c",&jogador);
      printf("\n");

      // criando as condições
      if((jogador == 'R' && jogada_bot() == 'S') || (jogador == 'S' && jogada_bot() == 'P') || (jogador == 'P' && jogada_bot() == 'R')){
         printf("%s = %c e bot = %c\n",nome1,jogador,jogada_bot());
         printf("\n");
         printf("%s eh o vencedor\n");
         printf("\n");
      }
      else if(jogador == jogada_bot()){
         printf("%s = %c e bot = %c\n",nome1,jogador,jogada_bot());
         printf("\n");
         printf("Empate\n");
         printf("\n");
      }
      else{
         printf("%s = %c e bot = %c\n",nome1,jogador,jogada_bot());
         printf("\n");
         printf("bot eh o vencedor\n");
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