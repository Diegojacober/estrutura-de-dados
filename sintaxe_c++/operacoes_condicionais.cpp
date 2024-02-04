#include <iostream>

// Usando a declaração para evitar repetição do prefixo std::
using namespace std;

int number1;
int number2;

int main()
{
    cout << "Digite o primeiro número: ";
    cin >> number1;
    cout << "Digite o segundo número: ";
    cin >> number2;

    if (number1 == number2)
    {
        cout << number1 << " == " << number2 << endl;
    }
    if (number1 != number2)
        cout << number1 << " != " << number2 << endl;
    if (number1 < number2)
        cout << number1 << " < " << number2 << endl;
    if (number1 > number2)
        cout << number1 << " > " << number2 << endl;

    return 0;
}