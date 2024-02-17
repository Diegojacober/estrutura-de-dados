#include <iostream>
#include <cstdlib> // Para a função rand()
#include <ctime>   // Para a função time()
#include <vector>
#include <algorithm>
#include <locale>

using namespace std;

vector<string> letras_tentadas;
int chances = 6;

string sortearPalavra()
{
    string palavras[] = {"CARRO", "MARCO", "TESTE"};
    srand(time(0));
    int tamanho = sizeof(palavras) / sizeof(palavras[0]); // Calcula o tamanho do vetor
    // Gere um índice aleatório
    int indice_aleatorio = rand() % tamanho;

    return palavras[indice_aleatorio];
}

bool existeString(const vector<string> &vetor, const string &procurada)
{
    for (const string &elemento : vetor)
    {
        if (elemento == procurada)
        {
            return true; // Se encontrar a string, retorna true
        }
    }
    return false; // Se não encontrar a string, retorna false
}

bool verificarPalpite(string tentativa, string palavra)
{
    // verificar se a letra existe na palavra
    for (int i = 0; i < palavra.length(); ++i)
    {
        if (tentativa[0] == palavra[i])
        {
            return true;
        }
    }
    return false;
}

void printPalavra(string palavra, vector<string> letras)
{
    for (int i = 0; i < palavra.length(); ++i)
    {
        bool letra_encontrada = false;
        for (int j = 0; j < letras.size(); ++j)
        {
            if (palavra[i] == letras[j][0])
            {
                cout << palavra[i];
                letra_encontrada = true;
                break;
            }
        }
        if (!letra_encontrada)
        {
            cout << "-";
        }
    }
    cout << endl;
}

string palpite()
{
    string entrada;
    while (true)
    {
        cout << "Digite um caractere: ";
        getline(cin, entrada);

        if (entrada.length() == 1)
        {
            string caractere = string(1, entrada[0]);
            for (size_t i = 0; i < caractere.length(); ++i)
            {
                // Transforma o caractere em maiúscula
                caractere[i] = toupper(caractere[i]);
            }
            return caractere;
        }
        else
        {
            cout << "Entrada inválida. Você deve digitar apenas um caractere." << endl;
        }
    }
}

bool verificarAcerto(string palavraSorteada)
{
    string palavra;
    for (int i = 0; i < palavraSorteada.size(); i++)
    {
        for (int j = 0; j < letras_tentadas.size(); ++j)
        {
            if (palavraSorteada[i] == letras_tentadas[j][0])
            {
                palavra += palavraSorteada[i];
                break;
            }
        }
    }
    return (palavra == palavraSorteada);
}

int main()
{
    bool correto = false;
    string palavraSorteada = sortearPalavra();

    while (!correto && chances > 0)
    {
        printPalavra(palavraSorteada, letras_tentadas);
        string tentativa = palpite();

        if (!existeString(letras_tentadas, tentativa))
        {
            letras_tentadas.push_back(tentativa);
            if (verificarPalpite(tentativa, palavraSorteada))
            {

                if (verificarAcerto(palavraSorteada))
                {
                    correto = true;
                    printPalavra(palavraSorteada, letras_tentadas);
                    cout << "Parabéns você acertou a palavra!!" << endl;
                }
            }
            else
            {
                chances--;
                system("clear");
                cout << "Errou! você ainda tem " << chances << " chances, para acertar a palavra" << endl;
            }
        }
        else
        {
            cout << "Você já digitou essa letra!" << endl;
        }
    }
    return 0;
}