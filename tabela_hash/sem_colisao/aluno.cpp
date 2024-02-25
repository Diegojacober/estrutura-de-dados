#include "aluno.h"

Aluno::Aluno()
{
    ra = -1;
    nome = " ";
}

Aluno::Aluno(int r, string n)
{
    ra = r;
    nome = n;
}

int Aluno::getRa()
{
    return ra;
}

string Aluno::getNome()
{
    return nome;
}