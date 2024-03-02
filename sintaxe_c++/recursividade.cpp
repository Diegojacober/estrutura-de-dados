#include <iostream>

using namespace std;

void contador(int num, int cont = 0);
int fibonacci(int n);
int fatorial(int n);

int main()
{
    // contador(30);

    int val, res;

    val = 8;
    res = fatorial(val);
    cout << "Fatorial de " << val << ": " << res;

    cout << "\n\nFibonacci com " << val << " valores: ";
    for (int i = 0; i < val; i++)
    {
        cout << fibonacci(i + 1) << " ";
    }

    cout << "\n\n";
    return 0;
}

void contador(int num, int cont)
{
    cout << cont << "\n";
    if (num > cont)
    {
        contador(num, ++cont);
    }
}

int fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// 10! = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1
int fatorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fatorial(n - 1);
}