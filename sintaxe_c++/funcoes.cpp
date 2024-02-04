#include <iostream>

// Usando a declaração para evitar repetição do prefixo std::
using namespace std;

int main()
{

    int number1;
    int number2;

    cout << "Digite um número: ";
    cin >> number1;
    cout << "Digite outro número: ";
    cin >> number2;

    cout << "A soma dos números é: " << sum(number1, number2);

    return 0;
}

int sum(int n1, int n2) {
    return n1 + n2;
}