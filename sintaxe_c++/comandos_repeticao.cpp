#include <iostream>

// Usando a declaração para evitar repetição do prefixo std::
using namespace std;

int main()
{
    int number1;
    int counter = 0;
    int amout = 0;
    // while
    while (counter < 10)
    {
        cout << "Digite um número (" << counter << ")" << endl;
        cin >> number1;

        if (number1 < 5)
        {
            amout++;
        }
        counter++;
    }

    // for
    int total;
    for (int i = 2; i <= 20; i++)
    {
        total += i;
    }

    cout << "A soma da série é" << total << endl;

    // do while
    int count2;
    int number3;
    int sum;
    do
    {
        cout << "Insira um novo número: " << endl;
        cin >> number3;

        sum += number3;
        count2++;
    } while (number3 != 0);

    float avg = (float)sum / (float)(count2 - 1);
    cout << "A média da série é: " << avg << endl;

    return 0;
}