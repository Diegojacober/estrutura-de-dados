#include "aluno.h"

class Hash
{
private:
    int HashFunc(Aluno aluno);
    int max_items;
    int max_positions;
    int items_quantity;
    Aluno* structure;

public:
    Hash(int vetor_size, int max);
    ~Hash();
    bool isFull();
    int size();
    void insert(Aluno aluno);
    void remove(Aluno aluno);
    void search(Aluno& aluno, bool& busca);
    void print();
};