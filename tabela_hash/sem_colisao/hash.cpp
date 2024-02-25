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
    int local = HashFunc(aluno);
    structure[local] = aluno;
    items_quantity++;
}

void Hash::remove(Aluno aluno)
{
    int local = HashFunc(aluno);
    if (structure[local].getRa() == -1)
    {
        structure[local] = Aluno(-1, " ");
        items_quantity--;
    }
}

void Hash::search(Aluno &aluno, bool &busca)
{
    int local = HashFunc(aluno);
    Aluno aux = structure[local]; // o que ta la
    if (aluno.getRa() != aux.getRa())
    {
        busca = false;
    }
    else
    {
        busca = true;
        aluno = aux;
    }
}

void Hash::print()
{
    cout << "Tabela Hash:\n";
    for (int i = 0; i < max_positions; i++)
    {
        if (structure[i].getRa() != -1)
        {
            cout << i << ":" << structure[i].getRa();
            cout << " - " << structure[i].getNome() << endl;
        }
    }
}