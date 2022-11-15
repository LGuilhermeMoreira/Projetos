#ifndef NODE_H
#define NODE_H

struct Node {   
    
    //Atributos de um no
    int column;
    int line;
    Node *right;
    Node *down;
    double value;

    //Construtor sendo incializado
    Node(double value, int line,int column,Node* right,Node* down){
        this->value = value;
        this->line = line;
        this->column = column;
        this->right = right;
        this->down = down;
    }
};


#endif 