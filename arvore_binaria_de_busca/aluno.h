#include <iostream>
using namespace std;

class Aluno
{
private:
    int ra;
    std::string nome;

public:
    Aluno();
    Aluno(int ra, std::string nome);
    string getNome();
    int getRa();
};