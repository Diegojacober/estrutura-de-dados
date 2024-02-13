#include "stack.h"
#include <iostream>

using namespace std;

// Uma string é dita bem formada se:
// • Contém zero ou mais caracteres, o que inclui os caracteres: {, }, (, ), [ e ].
// • Os caracteres {, ( e [ devem ser pareados com os caracteres }, ) e ], respectivamente.
// Exemplos:
// • a{b}a Bem formada
// • a{b[c]b}a Bem formada
// • a{b}[c]{b}a Bem formada
// • a{b]a Mal formada
// • a{b[c}b]a Mal formada
// • a{b[}c]{b}a Mal formada

int main()
{
    ItemType character;
    Stack stack;
    ItemType stackItem;

    cout << "Insira uma string." << endl;
    cin.get(character);

    bool isMatched = true;
    while (isMatched && character != '\n')
    {
        if (character == '{' || character == '(' || character == '[')
        {
            stack.push(character);
        }
        if (character == '}' || character == ')' || character == ']')
        {
            if (stack.isEmpty())
            {
                isMatched = false;
            }
            else
            {
                stackItem = stack.pop();
                isMatched = ((character == '}' && stackItem == '{') || (character == ')' && stackItem == '(') || (character == ']' && stackItem == '['));
            }
        }
        cin.get(character);
    }

    if (isMatched && stack.isEmpty())
    {
        cout << "Bem formada \n";
    }
    else
    {
        cout << "Mal formada \n";
    }
}
