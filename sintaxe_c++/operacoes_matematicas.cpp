#include <iostream>

int number1;
int number2;

int main()
{
    std::cout << "Digite o primeiro número: ";
    std::cin >> number1;
    std::cout << "Digite o segundo número: ";
    std::cin >> number2;

    int sum = number1 + number2;
    int sub = number1 - number2;
    int mul = number1 * number2;
    int div = number1 / number2;
    float fdiv = (float)number1 / (float)number2;
    float res = number1 % number2;

    std::cout << "Soma: " << sum << std::endl;
    std::cout << "Subtração: " << sub << std::endl;
    std::cout << "Multiplicação: " << mul << std::endl;
    std::cout << "Divisão: " << div << std::endl;
    std::cout << "Divisão com ponto flutuante: " << fdiv << std::endl;
    std::cout << "Resto da divisão: " << res << std::endl;

    return 0;
}