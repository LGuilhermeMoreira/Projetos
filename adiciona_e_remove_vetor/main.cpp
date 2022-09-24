#include <iostream>
using namespace std;

int *adiciona(int *v, int *tam, int newNUm)
{
    *tam += 1;
    int *add = new int[*tam]; // criando o novo vetor

    if (*tam != 1)
    {
        for (int i = 0; i < *tam - 1; i++)
        {
            add[i] = v[i]; // passando os antigos numeros do vetor para o novo
        }
    }

    delete[] v;  // deletando o vetor
    v = nullptr; // zerando ele

    add[*tam - 1] = newNUm;

    return add; // retornando o novo vetor
}

int *remove_ultimo(int *v, int *tam)
{
    int *newv = new int[*tam - 1]; // criando o novo vetor

    for (int i = 0; i < *tam - 1; i++)
    {
        newv[i] = v[i]; // passando os antigos numeros do vetor para o novo
    }

    delete[] v;  // deletando o vetor
    v = nullptr; // zerando ele

    *tam -= 1;

    return newv; // retornando novo vetor
}

void mostra(int *v, int tam)
{ // informando os vetores presentes no array!
    if (tam == 0)
    {
        cout << "Nao existe nenhum numero presente no vetor" << endl
             << endl;
        return;
    }

    cout << "numeros presentes no vetor: ";

    for (int i = 0; i < tam; i++)
    {
        cout << v[i] << " ";
    }

    cout << endl
         << endl;
}

int main()
{
    int *array = 0;  // criar um vetor com aloc dinamica
    int tamanho = 0; // tamanho do vetor
    int resp = 0;

    cout << "Opa, esse e meu projeto de aprendizagem de alocacao dinamica" << endl
         << endl;

    while (resp != 4)
    {
        cout << "Digite o que deseja" << endl
             << endl
             << "1 - Adiciona" << endl
             << "2 - Remove" << endl
             << "3 - Mostra" << endl
             << "4 - Encerra" << endl;

        cout << endl
             << "resposta: ";

        cin >> resp;

        cout << endl;

        if (resp == 1)
        {
            int a; // variavel criada para adicionar ao novo vetor
            cout << "Digite o numero que deseja adicionar: ";
            cin >> a;
            array = adiciona(array, &tamanho, a);
            cout << endl
                 << endl;
        }

        else if (resp == 2)
        {
            array = remove_ultimo(array, &tamanho);
        }

        else if (resp == 3)
        {
            mostra(array, tamanho);
        }
    }

    cout << "Fim!!";
}