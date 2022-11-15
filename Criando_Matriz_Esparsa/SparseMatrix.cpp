#include "SparseMatrix.hpp"
#include <iostream>

//Construtor
SparseMatrix::SparseMatrix(int lines, int columns) {

    //Inicializando os atributos
    this->lines = lines;
    this->columns = columns;
    head = new Node(0,0,0,nullptr,nullptr);

    //Criando as linhas
    Node *aux = head;
    for(int i = 0; i < lines; i++) { // O(n)
        Node *novo = new Node(0,i+1,0,nullptr,nullptr);
        novo->right = novo; 
        aux->down = novo;
        aux = aux->down;
    }
    aux->down = head; //Fazendo encadeamento circular dos nós sentinelas das linhas

    //Criando as colunas
    aux = head;
    for(int i = 0; i < columns; i++) { // O(m)
        Node *novo = new Node(0,0,i+1,nullptr,nullptr);
        novo->down = novo;
        aux->right = novo;
        aux = aux->right;
    }
    aux->right = head; //Fazendo encadeamento circular dos nós sentinelas das linhas
    
    /*Lembrando que os ponteiros right dos nos das linhas apontam poara o proprio no, pois
    esta eh simplesmente a implementação do "esqueleto" da matriz. O mesmo para os ponteiros
    down dos nos das colunas*/
}

//Destrutor
SparseMatrix::~SparseMatrix() {

    for(int i = 0; i < lines; i++) { //Laco para percorrer as linhas  //O(n)
        Node *aux = head; // aponta para o no m_head
        
        for(int j = 0; j < columns; j++) { //Laco para percorrer as colunas  //O(m)
            if(aux->right == aux) break;
            Node *ant = aux->right;
            aux->right = ant->right;
            delete ant;
            //Liberando memoria e ajustando os ponteiros
        }

        head = head->down;
        delete aux;
        //Liberando memoria e indo para a proxima linha
    }

    std::cout << "Matrix destruida com sucesso!" << std::endl;
}

//Inserir elemento
/*
    ANALIDE DE COMPLEXIDADE DE PIOR CASO

    - caso line == column

    2*O(n) + 2*O(n)
    4*O(n)
    
    Complexidade: O(n)
*/
void SparseMatrix::insert(double value, int line, int column) {
/*Insere um valor na linha e coluna especificados nos parametros. Se esse valor for 0 e já existir
um no nessa posicao, este sera excluido*/

    //Verifica se valores sao válidos
    if(line < 0 || line > lines || column < 0 || column > columns) { // O(1)
        throw std::out_of_range("Posição inválida");
    }

    Node *ptr_line = head;
    int cont = 0;
    while(cont < line){ //Percorrendo ate a linha especificada  //O(n)
        ptr_line = ptr_line->down;
        cont++;
    }

    Node *ptr_column = head;
    cont = 0;
    while(cont < column){ //Percorrendo ate a coluna especificada  //O(m)
        ptr_column = ptr_column->right;
        cont++;
    }

    if(value != 0) {
        //Caso haja algum no na posicao, apenas o valor eh alterado
        if(get(line,column) != 0){
            Node *corrent_l = ptr_line; //No para percorrer as linhas
            //Percorrendo para a direita
            while(corrent_l->right != ptr_line && corrent_l->right->column < column){  //O(n)
                corrent_l = corrent_l->right;
            }

            corrent_l->right->value = value;
        }
        //Adicionando um novo no
        else {

            Node *novo = new Node(value,line,column,nullptr,nullptr);

            Node *corrent_l = ptr_line; //No para percorrer as linhas
            //Percorrendo para a direita
            while(corrent_l->right != ptr_line && corrent_l->right->column < column) { //O(n)
                corrent_l = corrent_l->right;
            }
            
            //Ajustando os ponteiros
            Node *ant = corrent_l->right;
            corrent_l->right = novo;
            novo->right = ant;

            Node *corrent_c = ptr_column; //No para percorrer as colunas
            //Percorrendo para baixo
            while(corrent_c->down != ptr_column && corrent_c->down->line < line) { // O(n)
                corrent_c = corrent_c->down;
            }

            //Ajustando os ponteiros
            ant = corrent_c->down;
            corrent_c->down = novo;
            novo->down = ant;

            //std::cout << "no (" << line << "," << column << ") adicionado" << std::endl;
        }

    }

    //Deletando no
    else {
        if(get(line,column) != 0){
            //Percorre a lista encadeada para remover o elemento
            Node *corrent_l = ptr_line;
            while(corrent_l->right != ptr_line && corrent_l->right->column < column){  //O(n)
                corrent_l = corrent_l->right;
            }
            
            //Ajustando os ponteiros e liberando memoria
            Node *ant = corrent_l->right->right;
            Node *ptr = corrent_l->right;
            delete ptr;
            corrent_l->right = ant;

            //Percorre a lista encadeada para remover o elemento
            Node *corrent_c = ptr_column;
            while(corrent_c->down != ptr_column && corrent_c->down->line < line){  //O(n)
                corrent_c = corrent_c->down;
            }

            //Ajustando os ponteiros e liberando memoria
            Node *ant2 = corrent_c->down->down;
            Node *ptr2 = corrent_c->down;
            delete ptr2;
            corrent_c->down = ant2;
            
            //std::cout << "no (" << line << "," << column << ") retirado" << std::endl;
        }
    }
}

//Retorna o valor do no na posicao especificada nos parametros do metodo
/*
    ANALIDE DE COMPLEXIDADE DE PIOR CASO

    - caso line == column

    O(n-1) + O(n)
   
    Complexidade: O(n) + O(n-1)
*/
double SparseMatrix::get(int line, int column) {

    //Verifica se os valores sao validos
    if(line < 0 || line > lines || column < 0 || column > columns) { // O(1)
        throw std::out_of_range("Posição inválida");
    }

    else {
        Node *ptr_line = head->down;
       
        int cont = 1;
        while(cont < line) { //Percorrendo ate a linha especificada  //O(n-1)
            ptr_line = ptr_line->down;
            cont++;
        }
        
        //Percorre ate a coluna especificada para encontrar o valor
        Node *ptr = ptr_line->right;
        while(ptr != ptr_line) {  //O(n)
            if(ptr->column == column && ptr->line == line) {
                return ptr->value;
            }
            ptr = ptr->right;
        }
    }
    return 0;
}

//Imprime a matriz inteira
void SparseMatrix::print(){
    //Para cada linha, as colunas desta sao percorridas printando os valores
    for(int i = 0; i < lines; i++) {
        for(int j = 0; j < columns; j++) {
            std::cout << get(i+1,j+1) << " ";
        }
        std::cout<<std::endl;
    }
}

//Retorna a quantidade de linhas da matriz
int SparseMatrix::getlines() { return this->lines; }

//Retrona a quantidade de colunas da matriz
int SparseMatrix::getcolumns() { return this->columns; }

bool SparseMatrix::isEmpty(){
    Node *aux = head->right;
    int cont_line = 0,cont_column = 0;
    while(aux != head){
        if(aux->down != aux){
            return false;
        }
        aux = aux->right;
    }

    aux = head->down;
    while(aux != head){
        if(aux->right == aux){
            return false;
        }
        aux = aux->down;
    }

    return true;
}