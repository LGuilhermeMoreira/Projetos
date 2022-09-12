#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
#include "funcao.h"
using namespace std;

int main(){
    char resp;
    inicializa(&resp);

    if(resp == 's'){
        cout << endl << endl;
        string nome;
        int control = 1;
        le_nome(&nome);

        do{
            if(control == 1){
                cout << endl<< "Inicializando..." << endl << endl;
                control++;
            }
            
            char jogada_p,jogada_b;

            jogada_player(&nome,&jogada_p);
            jogada_bot(&jogada_b);
            comapra_jogada(&nome,&jogada_p,&jogada_b);
            continua(&control);

        }while(control != 0);
    }

}