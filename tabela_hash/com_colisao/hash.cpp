#include <iostream>
#include "hash.h"
using namespace std;

int Hash::HashFunc(Aluno aluno)
{
    return (aluno.getRa() % max_positions);
}

Hash::Hash(int vetor_size, int max)
{
    items_quantity = 0;
    max_items = max;
    max_positions = vetor_size;
    structure = new Aluno[vetor_size];
}

Hash::~Hash()
{
    delete[] structure;
}

bool Hash::isFull()
{
    return (items_quantity == max_items);
}

int Hash::size()
{
    return items_quantity;
}

void Hash::insert(Aluno aluno)
{
    if (isFull())
    {
        cout << "Tabela hash cheia\n\n";
    }
    else
    {
        int local = HashFunc(aluno);
        while (structure[local].getRa() > 0)
        {
            local = (local + 1) % max_positions;
        }

        structure[local] = aluno;
        items_quantity++;
    }
}

void Hash::remove(Aluno aluno)
{
    int local = HashFunc(aluno);
    bool test = false;
    while (structure[local].getRa() != -1)
    {
        if (structure[local].getRa() == aluno.getRa())
        {
            cout << "Elemento removido";
            structure[local] = Aluno(-2, " ");
            items_quantity--;
            test = true;
            break;
        }
        local = (local + 1) % max_positions;
    }
    if (!test)
    {
        cout << "Elemento nao encontrado!\n";
        cout << "Nenhum elemento removido\n";
    }
}

void Hash::search(Aluno &aluno, bool &busca)
{
    int local = HashFunc(aluno);
    busca = false;

    while (structure[local].getRa() != -1)
    {
        if (structure[local].getRa() == aluno.getRa())
        {
            aluno = structure[local];
            busca = true;
            break;
        }
        local = (local + 1) % max_positions;
    }
}

void Hash::print()
{
    cout << "Tabela Hash:\n";
    for (int i = 0; i < max_positions; i++)
    {
        if (structure[i].getRa() > 0)
        {
            cout << i << ":" << structure[i].getRa();
            cout << " - " << structure[i].getNome() << endl;
        }
    }
}