#include <iostream>
#include "time.h"    
using namespace std;

int main()
{
    /*
        Neste primeiro objeto, passamos todos os parâmetros. Em outras palavras, nenhum valor padrão foi usado.
    */
    Time t1(23, 59, 59);
    t1.print();
    t1.setHour(12);
    t1.setMinute(30);
    t1.setSecond(45);

    for (int i = 0; i < 25; i++)
    {
        t1.nextSecond();
        t1.print();
    }

    Time t2(12);
    t2.print();
    t2.setSecond(45);
    t2.nextSecond();
}