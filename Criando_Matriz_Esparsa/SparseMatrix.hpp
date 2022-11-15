#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include "Node.hpp"

class SparseMatrix {

    private:
        //Atributos de uma matriz
        Node *head{nullptr};
        int lines{0};
        int columns{0};

    public:
        //Prototipacao das funcoes membro (metodos) da classe Sparse Matrix
        SparseMatrix(int,int);
        ~SparseMatrix();
        void insert(double,int,int);
        void print();
        double get(int,int);
        int getcolumns();
        int getlines();
        bool isEmpty();
};


#endif