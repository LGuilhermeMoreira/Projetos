#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

struct time{ // criando struct
    string posicao;
    string nome;
    int numero;
};


time le_jogador(){ // recebendo o nome,numero e posição do jogador!
    time a;
    cin.ignore();
    
    cout << "digite o nome: ";
    getline(cin,a.nome);
   
    cout << "digite a posicao: ";
    getline(cin,a.posicao);
   
    cout << "digite o numero da camisa: ";
    cin >> a.numero;

    return a;
}

time *adiciona_jogador(time *v,int *n,time novo){ // cadastrando jogador!
    *n+=1;
    time *novo_ = new time[*n];
    
    if(v != 0){
        for(int i=0;i<*n-1;i++){
            novo_[i] = v[i];
        }
    }

    delete []v;
    v = nullptr;

    novo_[*n-1] = novo;
    return novo_;
}

time *remove_jogador(time *v,int *n,int num){ // retirando jogador cadastrado
    for(int i=0;i<*n;i++){
        if(v[i].numero == num){
            v[i] = v[*n-1];
            *n-=1;
            break;
        }
    }

    return v;
}

void mostra_elenco(time *v,int *n){
    cout << "----------------------------------------------------------------" << endl;
    for(int i=0;i<*n;i++){
        cout << "Nome: " << v[i].nome << endl;
        cout << "Posicao: " << v[i].posicao << endl;
        cout << "Numero: " << v[i].numero << endl;
        cout << "----------------------------------------------------------------" << endl;
    }
    if(n == 0){
        cout << "Nao tem ninguem convocado!" << endl;
        cout << "----------------------------------------------------------------" << endl;
    }
}

int main(){
    int tamanho = 0,resp = 0;
    time *selecao = 0;

    cout << "opa! Esse é meu projeto de alocaçao dinamica!" << endl << endl;

    do{

        cout << "informe o que deseja" << endl << endl
            << "1 - adicionar um jogador ao time" << endl
            << "2 - expulsar um jogador do time" << endl
            << "3 - mostrar os jogadores convocados" << endl
            << "4 - encerrar" << endl << endl;
        cin >> resp;

        if(resp == 1){
            system("cls");
            time a = le_jogador();
            selecao = adiciona_jogador(selecao,&tamanho,a);
        }else if(resp == 2){
            system("cls");
            int numero__;
            cout << "informe o numero que deseja expulsar: ";
            cin >> numero__;
            selecao = remove_jogador(selecao,&tamanho,numero__);
        }else{
            mostra_elenco(selecao,&tamanho);
        }

    }while(resp != 4);

    cout << "Valeu!" << endl;
}