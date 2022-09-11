#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

typedef struct
{ // criando struct
    string posicao;
    string nome;
    int numero;
} Time;

Time le_jogador()
{ // recebendo o nome,numero e posição do jogador!
    Time a;
    cin.ignore();

    cout << "Digite o nome: ";
    getline(cin, a.nome);

    cout << "Digite a posicao: ";
    getline(cin, a.posicao);

    cout << "Digite o numero da camisa: ";
    cin >> a.numero;

    cout << endl;

    return a;
}

Time *adiciona_jogador(Time *v, int *n, Time novo)
{ // cadastrando jogador!
    *n += 1;
    Time *novo_ = new Time[*n];

    if (v != 0)
    {
        for (int i = 0; i < *n - 1; i++)
        {
            novo_[i] = v[i];
        }
    }

    delete[] v;
    v = nullptr;

    novo_[*n - 1] = novo;
    return novo_;
}

Time *remove_jogador(Time *v, int *n, int num)
{ // retirando jogador cadastrado
    for (int i = 0; i < *n; i++)
    {
        if (v[i].numero == num)
        {
            v[i] = v[*n - 1];
            *n -= 1;
            return v;
        }
    }

    system("cls");
    cout << "Nao ha nenhum jogador com esse numero na camisa" << endl;
    return v;
}

void mostra_elenco(Time *v, int *n)
{
    cout << "----------------------------------------------------------------" << endl;
    for (int i = 0; i < *n; i++)
    {
        cout << "Nome: " << v[i].nome << endl;
        cout << "Posicao: " << v[i].posicao << endl;
        cout << "Numero: " << v[i].numero << endl;
        cout << "----------------------------------------------------------------" << endl;
    }
    if (n == 0)
    {
        cout << "Nao tem ninguem convocado!" << endl;
        cout << "----------------------------------------------------------------" << endl;
    }
}

int main()
{
    int tamanho = 0, resp = 0;
    Time *selecao = 0;

    cout << "Opa! Esse e meu projeto de alocacao dinamica!" << endl
         << endl;

    do
    {

        cout << "Informe o que deseja" << endl
             << endl
             << "1 - Adicionar um jogador ao time" << endl
             << "2 - Expulsar um jogador do time" << endl
             << "3 - Mostrar os jogadores convocados" << endl
             << "4 - Encerrar" << endl
             << endl;
        cin >> resp;

        if (resp == 1)
        {
            system("cls");
            Time a = le_jogador();
            selecao = adiciona_jogador(selecao, &tamanho, a);
        }
        else if (resp == 2)
        {
            system("cls");
            int numero__;
            mostra_elenco(selecao, &tamanho);
            cout << "Informe o numero que deseja expulsar: ";
            cin >> numero__;
            selecao = remove_jogador(selecao, &tamanho, numero__);
            cout << endl;
        }
        else
        {
            mostra_elenco(selecao, &tamanho);
        }

    } while (resp != 4);

    cout << "Valeu!" << endl; // fim!
}