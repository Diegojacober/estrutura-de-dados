#include <iostream>
#include "hash.h"
using namespace std;

int main()
{
    int vetor_size, max_items;
    cout << "Programa gerador de hash" << endl;
    cout << "Digite o tamanho da hash\n";
    cin >> vetor_size;
    cout << "Digite o numero maximo de elementos\n";
    cin >> max_items;
    cout << "O fator de carga é: " << (float)max_items / (float)vetor_size << endl;
    Hash alunoHash(vetor_size, max_items);
    int opcao;
    int ra;
    string nome;
    bool busca;

    do
    {
        cout << "Digite 0 para parar o algoritmo\n";
        cout << "Digite 1 para parar inserir um elemento\n";
        cout << "Digite 2 para parar remover um elemento\n";
        cout << "Digite 3 para parar buscar um elemento\n";
        cout << "Digite 4 para parar printar a hash\n";
        cin >> opcao;

        if (opcao == 1)
        {
            cout << "Qual o RA do aluno? \n";
            cin >> ra;
            cout << "Qual o nome do aluno?\n";
            cin >> nome;
            Aluno aluno(ra, nome);
            alunoHash.insert(aluno);
        }
        else if (opcao == 2)
        {
            cout << "Qual o RA do aluno a ser removido?\n";
            cin >> ra;
            Aluno aluno(ra, " ");
            alunoHash.remove(aluno);
        }
        else if (opcao == 3)
        {
            cout << "Qual o RA do aluno a ser buscado?\n";
            cin >> ra;
            Aluno aluno(ra, " ");
            alunoHash.search(aluno, busca);
            if (busca)
            {
                cout << "Aluno encontrado: \n";
                cout << "RA: " << aluno.getRa() << endl;
                cout << "Nome: " << aluno.getNome() << endl;
            }
            else
            {
                cout << "Aluno nao encontrado\n";
            }
        }
        else if (opcao == 4)
        {
            alunoHash.print();
        }
    } while (opcao != 0);

    return 0;
}