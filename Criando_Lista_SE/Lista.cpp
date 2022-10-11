#include <iostream>
using namespace std;

class No
{
private:
    int num;        // valor dentro do no
    No *proximo_no; // aponta para o proximo no;
public:
    No(int v)
    {
        this->num = v;
        this->proximo_no = nullptr;
    }

    int retorna_num()
    {
        return this->num;
    }

    No *retorna_proximo_no()
    {
        return proximo_no;
    }

    void seta_proximo_no(No *p)
    {
        proximo_no = p;
    }
};

class Lista
{
private:
    No *cabeca; // inicio da lista
    No *cauda;  // fim da lista
public:
    Lista()
    {
        cabeca = nullptr;
        cauda = nullptr;
    }

    Lista(int v)
    {
        cabeca = new No(v);
        cauda = cabeca;
    }

    ~Lista()
    {
        delete cabeca;
    }

    bool vazia()
    { // mostra se esta vazia ou não
        if (cabeca == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void mostra()
    {
        No *aux = cabeca; // aux é no corrente

        if (vazia())
        {
            runtime_error("a lista esta vazia");
        }
        else
        {
            while (aux)
            { // aux != nullptr
                cout << aux->retorna_num() << " ";
                aux = aux->retorna_proximo_no();
            }
            cout << endl;
        }
    }

    void botar_inicio_elementos(int n)
    {
        No *new_no = new No(n);
        new_no->seta_proximo_no(cabeca);
        cabeca = new_no;
    }

    void botar_final_elementos(int v)
    {
        No *new_no = new No(v);

        if (vazia())
        {
            cabeca = new_no;
            cauda = new_no;
        }

        else
        {
            cauda->seta_proximo_no(new_no);
            cauda = new_no;
        }
    }

    int tamanho()
    {
        if (vazia())
            return 0;

        No *aux = cabeca;
        int cont = 0;

        do
        {
            aux = aux->retorna_proximo_no();
            cont++;
        } while (aux);

        return cont;
    }

    bool existe(int v)
    {
        No *aux = cabeca;
        while (aux)
        { // percorre lista assim!!
            if (aux->retorna_num() == v)
                return true;
            aux = aux->retorna_proximo_no();
        }
        return false;
    }

    void remove()
    {
        if (!vazia())
        {
            if (cabeca->retorna_proximo_no() == nullptr)
                cabeca = nullptr;                                                   // 1 elemento
            else if (cabeca->retorna_proximo_no()->retorna_proximo_no() == nullptr) // dois elementos
                cabeca->seta_proximo_no(nullptr);
            else
            {
                No *ant_ant = cabeca;
                No *ant = cabeca->retorna_proximo_no();
                No *corrente = cabeca->retorna_proximo_no()->retorna_proximo_no();

                while (corrente)
                {
                    No *aux = ant;
                    ant = corrente;
                    ant_ant = aux;
                    corrente = corrente->retorna_proximo_no();
                }

                delete ant_ant->retorna_proximo_no();
                ant_ant->seta_proximo_no(nullptr);
                cauda = ant_ant;
            }
        }
    }
};

int main()
{
    Lista l;

    for (int i = 0; i < 5; i++)
    {
        l.botar_inicio_elementos(i + 1);
    }

    l.mostra();
}
