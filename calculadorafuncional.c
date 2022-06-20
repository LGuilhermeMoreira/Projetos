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

     if(i == 1) printf("Inicializando calculadora...\n");

     printf("\n");
      
      float numero1,numero2;
      printf("digite o primeiro numero: ");
      scanf("%f",&numero1);

      printf("\n");

      printf("digite o operador: ");
      char operator;
      scanf(" %c",&operator);
     
      printf("\n");

      printf("Digite o segundo numero: ");
      scanf("%f",&numero2);

      printf("Sua Resposta e: %.2f\n",calculadora(numero1,numero2,operator));

      printf("Deseja continuar ?\n");
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