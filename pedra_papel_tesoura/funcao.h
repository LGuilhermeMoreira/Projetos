#ifndef FUNCAO_H_INCLUDED
#define FUNCAO_H_INCLUDED
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

void inicializa(char *resp){
    cout << "Opa, Esse e meu primeiro projeto criando um 'bot' !" << endl << "Para qualquer resposta use 's' para sim" << endl << endl;
    cout << "Deseja iniciar?" << endl;
    cin >> resp;
    cin.ignore();
}

void le_nome(string *n){
    cout << "Informe seu nome: ";
    getline(std::cin, *n);
}

void jogada_player(string *n,char *p){
    cout << "('S' para tesoura, 'R' para pedra e 'P' para papel)" << endl;
    cout << *n << " informe sua escolha: ";
    cin >> *p;
    cin.ignore();
    cout << endl;
}

void jogada_bot(char *b){
    srand(time(NULL));
    int v = rand() % 3;
    if(v == 0) *b = 'R';
    else if(v == 1) *b = 'P';
    else *b = 'S'; 
}

void comapra_jogada(string *n,char *p,char *b){

    cout << *n << " jogou: " << *p << endl;
    cout << "bot jogou: " << *b << endl << endl;

    if(*p == *b){
        cout << "Empate!" << endl;
    }else if((*p == 'R' && *b == 'S')||(*p == 'P' && *b == 'R')||(*p == 'S' && *b == 'P')){
        cout << *n << " e o ganhador!" << endl;
    }else{
        cout << "Bot e o ganhador!" << endl;
    }
}

void continua(int *n){
    cout << endl << "Deseja continuar?" << endl;
    char resp;
    cin >> resp;
    if(resp == 's') *n = 2;
    else *n = 0;
}

#endif