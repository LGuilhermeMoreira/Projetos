#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include "SparseMatrix.hpp"
using namespace std;

SparseMatrix *readSparseMatrix(string inputFile) {
    fstream file;

    file.open(inputFile, ios::in);
    int nLines, nColumns;
    file >> nLines >> nColumns;
    SparseMatrix *inputMatrix = new SparseMatrix(nLines, nColumns);
    if (file.is_open()) {
        while (!file.eof()) {
            int line, column;
            double value;
            file >> value >> line >> column;
            inputMatrix->insert(value, line, column);
        }
    }
    else {
        throw std::runtime_error("Arquivo nao aberto ou nao encontrado");
    }

    return inputMatrix;
}
// soma duas matrizes de tamanhos iguais
/*
    ANALIDE DE COMPLEXIDADE DE PIOR CASO

    O(n) * O(n)
   
    Complexidade: O(n^(2)) 
*/
SparseMatrix *adicao(SparseMatrix *a, SparseMatrix *b){
    //caso elas tenham tamanhos diferentes, é lançado uma exeção
    if(a->getlines() != b->getlines() || a->getcolumns() != b->getcolumns()){
        throw std::out_of_range("Matrizes de tamanhos diferentes");
    }
    //cria uma nova matriz resultante
    SparseMatrix *c = new SparseMatrix(a->getlines(),a->getcolumns());

    cout << "Matriz A: " << a->isEmpty() << endl << "Matriz B: " << b->isEmpty() << endl;

    // caso esteja vazia, retorna uma matriz vazia
    if(a->isEmpty() == true && b->isEmpty() == true){
        return c; // O(1)
    }

    // caso uma esteja vazia e a outra não, retorna a matriz não vazia
    else if(a->isEmpty() == false && b->isEmpty() == true){
        return a; // O(1
    }
    else if(a->isEmpty() == true && b->isEmpty() == true){
        return b; // O(1
    }

    // soma as duas matrizes passadas como parametro e insere os resultados na matriz resultante
    for(int i = 1; i <= a->getlines(); i++){ // O(n)
        for(int j = 1; j <= a->getcolumns(); j++){  // O(n)
            double aux = a->get(i,j) + b->get(i,j);
            if(aux != 0){
                c->insert(aux,i,j);
            }
        }
    }
    return c;
}

// multiplica duas matrizes de tamanhos iguais
SparseMatrix *multiplicacao(SparseMatrix *a, SparseMatrix *b){
    //caso elas tenham tamanhos diferentes, é lançado uma exeção
    if(a->getlines() != b->getlines() || a->getcolumns() != b->getcolumns()){
        throw std::out_of_range("Matrizes de tamanhos diferentes");
    }

    // criação da matriz resultante 
    SparseMatrix *c = new SparseMatrix(a->getlines(),a->getcolumns());

    // caso as duas matrizes estejam vazias, retorna uma matriz vazia
    if(a->isEmpty() == true && b->isEmpty() == true){
        return c;
    }

    // multiplica as duas matrizes passadas como parametro e insere os resultados na matriz resultante
    for(int i = 1; i <= a->getlines(); i++){
        for(int j = 1; j <= b->getcolumns(); j++){
            double soma = 0;
            for(int k = 0; k < a->getcolumns(); k++){
                soma += a->get(i,k) * b->get(k,j);
            }
            if(soma != 0){
                c->insert(soma,i,j);
            }
        }
    }
    return c;
}

/*
        COMANDOS DA MAIN

        - create {
            adiciona uma matriz ao vector
        }

        - exit {
            sai do programa
        }

        - show {
            mostra as matrizes adicionadas ao vector
        }

        - sum {
            soma duas matrizes
        }

        - multiplies {
            multiplica duas matrizes
        }

        - sum_aqv {
            soma uma matriz com a matriz lida do arquivo
        }

        - multiplies_aqv {
            multiplica uma matriz com a matriz lida do arquivo
        }


        - add {
            adiciona um elemento a uma matriz escolhida
        }

        - add_aqv {
            adiciona um elemento a uma matriz lida do arquivo
        }

        - get {
            mostra o elemento de uma matriz escolhida
        }    

        - get_aqv {
            mostra o elemento de uma matriz lida do arquivo
        }

        - remove {
            remove um elemento de uma matriz escolhida
        }

        - remove_aqv {
            remove um elemento de uma matriz lida do arquivo
        }

*/

int main(){
	vector<SparseMatrix*> matriz;
    SparseMatrix *arqv = readSparseMatrix("input_file.txt");
    //arqv->print();

	while(true) {
		string comando, token;
        cout << "Digite o comando: ";	
		getline(cin, comando);
		stringstream buffer{ comando };
        buffer >> token;

        cout << "$" << buffer.str() << endl;

		// exit
		if(token == "exit") {
			for(unsigned i = 0; i < matriz.size(); i++)
				delete matriz[i];
			matriz.clear();
            delete arqv;
            system("cls || clear");
			break;
		}
		// create
		else if(token == "create") {
             int tl,tc;
            cout << "Digite a quantidade de linhas da matriz: ";
            cin >> tl;
            cout << "Digite a quantidade de colunas da matriz: ";
            cin >> tc;
			SparseMatrix *lst = new SparseMatrix(tl,tc);
			matriz.push_back(lst);
            cin.ignore();
            system("cls || clear");
		}
		// multiplies
		else if(token == "multiplies") {
            cout << "- ";
            for(int i = 0; i < matriz.size(); i++){
                cout << "lista " << i << " - ";
            }
            cout << endl;
            int lista_1, lista_2;
            cout << "Digite a lista 1: ";
            cin >> lista_1;
            cout << "Digite a lista 2: ";
            cin >> lista_2;
            SparseMatrix *lst = multiplicacao(matriz[lista_1],matriz[lista_2]);
            matriz.push_back(lst);
            cin.ignore();
            system("cls || clear");
		}
        // sum
		else if(token == "sum") {
            cout << "- ";
            for(int i = 0; i < matriz.size(); i++){
                cout << "lista " << i << " - ";
            }
            cout << endl;
            int lista_1, lista_2;
            cout << "Digite a lista 1: ";
            cin >> lista_1;
            cout << "Digite a lista 2: ";
            cin >> lista_2;
            SparseMatrix *lst = adicao(matriz[lista_1],matriz[lista_2]);
            matriz.push_back(lst);
            cin.ignore();
            system("cls || clear");
		}
        // sum_aqv
		else if(token == "sum_aqv") {
            cout << "- ";
            for(int i = 0; i < matriz.size(); i++){
                cout << "lista " << i << " - ";
            }
            cout << endl;
			int list;
            cout << "Digite a lista: ";
            cin >> list;
            SparseMatrix *lst = adicao(matriz[list],arqv);
            matriz.push_back(lst);
            cin.ignore();
            system("cls || clear");
		}
        // multiplies_aqv
		else if(token == "multiplies_aqv") {
            cout << "- ";
            for(int i = 0; i < matriz.size(); i++){
                cout << "lista " << i << " - ";
            }
            cout << endl;
			int list;
            cout << "Digite a lista: ";
            cin >> list;
            SparseMatrix *lst = multiplicacao(matriz[list],arqv);
            matriz.push_back(lst);
            cin.ignore();
            system("cls || clear");
		}
        // show
		else if(token == "show") {
            for(unsigned i = 0; i < matriz.size(); ++i) {
                cout << "lista " << i << ": " << endl;
                matriz[i]->print();
                cout << endl;
            }
            cout << "lista do arquivo: " << endl;
            arqv->print();
            cout << endl;	
		}
        // add
        else if(token == "add"){
            cout << "- ";
            for(int i = 0; i < matriz.size(); i++){
                cout << "lista " << i << " - ";
            }
            cout << endl;
            int l,li,ci,v;
            cout << "Digite a lista que deseja adicionar o elemento: ";
            cin >> l;
            cout << "Digite a linha: ";
            cin >> li;
            cout << "Digite a coluna: ";
            cin >> ci;
            cout << "Digite o valor: ";
            cin >> v;
            matriz[l]->insert(v,li,ci);
            cin.ignore();
            system("cls || clear");
        }
        // get
        else if(token == "get"){
            cout << "- ";
            for(int i = 0; i < matriz.size(); i++){
                cout << "lista " << i << " - ";
            }
            cout << endl;
            int l,li,ci;
            cout << "Digite a lista que deseja mostar o elemento: ";
            cin >> l;
            cout << "Digite a linha do elemento: ";
            cin >> li;
            cout << "Digite a coluna do elemento: ";
            cin >> ci;
            cin.ignore();
            cout << "Valor do elemento: " << matriz[l]->get(li,ci) << endl << endl;
        }
        // remove
        else if(token == "remove"){
            cout << "- ";
            for(int i = 0; i < matriz.size(); i++){
                cout << "lista " << i << " - ";
            }
            cout << endl;
            int l,li,ci;
            cout << "Digite a lista que deseja remover o elemento: ";
            cin >> l;
            cout << "Digite a linha: ";
            cin >> li;
            cout << "Digite a coluna: ";
            cin >> ci;
            matriz[l]->insert(0,li,ci);
            cin.ignore();
            system("cls || clear");
        }
        // add_aqv
        else if(token == "add_aqv"){
            int l,c,v;
            cout << "Digite a linha: ";
            cin >> l;
            cout << "Digite a coluna: ";
            cin >> c;
            cout << "Digite o valor: ";
            cin >> v;
            arqv->insert(v,l,c);
            cin.ignore();
            system("cls || clear");
        }
        // get_aqv
        else if(token == "get_aqv"){
            int l,c;
            cout << "Digite a linha: ";
            cin >> l;
            cout << "Digite a coluna: ";
            cin >> c;
            cin.ignore();
            cout << "Valor do elemento: " << arqv->get(l,c) << endl << endl;
        }
        // remove_aqv
        else if(token == "remove_aqv"){
            int l,c;
            cout << "Digite a linha: ";
            cin >> l;
            cout << "Digite a coluna: ";
            cin >> c;
            arqv->insert(0,l,c);
            cin.ignore();
            system("cls || clear");
        }
		else {
			cout << "comando inexistente" << endl;
		}
	}
}

