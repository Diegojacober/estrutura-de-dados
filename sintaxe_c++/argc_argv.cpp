#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

// argc => quantidade de parametros guardados
// argv => ponteiro para uma matriz de pointeiro de caracteres
int main(int argc, char *argv[])
{

    // cout << argv[0] << "\n\n";
    // cout << argv[1] << "\n\n";
    // cout << argc << "\n\n";

    if (argc > 1)
    {
        // maior que 0, quando a primeira for maior que a segunda
        // menor que 0, quando a primeira for menor que a segunda
        // 0 quando forem iguais
        if (!strcmp(argv[1], "sol"))
        {
            cout << "Parametro sol informardo \n \n";
        }
        else if (!strcmp(argv[1], "nublado"))
        {
            cout << "cinema. \n\n";
        }
        else
        {
            cout << "ficar em casa. \n\n";
        }
    }

    //system("pause"); // para windows
    return 0;
}