#include<stdio.h>

float calculadora (float n1, float n2, char op){
   float resp;

   if(op == '+'){
      resp = n1 + n2;
   }
   else if(op == '-'){
      resp = n1 - n2;
   }
   else if(op == '*'){
      resp = n1 * n2;
   }
   else if(op == '/'){
      resp = n1 / n2;
   }
   return resp;
}

int main()
{
   for(int i = 1; i > 0;i++){

     if(i == 1){ 
         printf("Inicializando calculadora...\n");
         printf("('s' para sim e 'n' para nao)\n");
     }

     printf("\n");
      
      float numero1,numero2;
      printf("Digite o primeiro numero: ");
      scanf("%f",&numero1);

      printf("\n");

      printf("Digite o operador: ");
      char operator;
      scanf(" %c",&operator);
     
      printf("\n");

      printf("Digite o segundo numero: ");
      scanf("%f",&numero2);

      printf("\n");

      float resposta=  calculadora(numero1,numero2,operator);

      printf("Sua Resposta e: %f\n",resposta);

      printf("\n");

      printf("Deseja fazer uma conta metematica com a resposta ?\n");
      char respo;
      scanf(" %c",&respo);

      if(respo == 's'){
         char respostaa;
         printf("Digite o operador: ");
         scanf(" %c",&respostaa);
         float seguno_numero;
         printf("\n");
         printf("Digite o numero: ");
         scanf("%f",&seguno_numero);
         printf("Sua nova resposta e: %.2f\n",calculadora(resposta,seguno_numero,respostaa));
         printf("\n");
      }

      printf("Deseja continuar na calculadora ?\n");
      char resp;

      scanf(" %c",&resp);

      if(resp == 's'){
         printf("Continue...\n");
      }
      else{
         break;
      }

   }

   printf("Foi bom enquanto durou :(\n");

   return 0;
}