#include <iostream>
#include <cstddef>
#include "tree.h"

using namespace std;

Tree::Tree()
{
    this->raiz = NULL;
}
Tree::~Tree()
{
    deleteTree(raiz);
}
void Tree::deleteTree(Node *path)
{
    if (path != NULL)
    {
        deleteTree(path->filhoE);
        deleteTree(path->filhoD);

        delete path;
    }
}
Node *Tree::getRoot() // obter a raiz
{
    return raiz;
}
bool Tree::isFull()
{
    try
    {
        Node *temp = new Node;
        delete temp;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}
bool Tree::isEmpty()
{
    return (raiz == NULL);
}
void Tree::insert(Aluno aluno)
{
    if (isFull())
    {
        cout << "A árvore está cheia!\n";
        cout << "Não foi possivel inserir este elemento!\n";
    }
    else
    {
        Node *NewNode = new Node;
        NewNode->aluno = aluno;
        NewNode->filhoD = NULL;
        NewNode->filhoE = NULL;
        if (isEmpty())
        {
            raiz = NewNode;
        }
        else
        {
            Node *temp = raiz;
            while (temp != NULL)
            {
                if (aluno.getRa() < temp->aluno.getRa())
                {
                    if (temp->filhoE == NULL)
                    {
                        temp->filhoE = NewNode;
                        break;
                    }
                    else
                    {
                        temp = temp->filhoE;
                    }
                }
                else
                {
                    if (temp->filhoD == NULL)
                    {
                        temp->filhoD = NewNode;
                        break;
                    }
                    else
                    {
                        temp = temp->filhoD;
                    }
                }
            }
        }
    }
}
void Tree::remove(Aluno aluno)
{
    removeSearch(aluno, raiz);
}
void Tree::removeSearch(Aluno aluno, Node *&noAtual)
{
    if (aluno.getRa() < noAtual->aluno.getRa())
    {
        removeSearch(aluno, noAtual->filhoE);
    }
    else if (aluno.getRa() > noAtual->aluno.getRa())
    {
        removeSearch(aluno, noAtual->filhoD);
    }
    else
    {
        deleteNode(noAtual);
    }
}
void Tree::deleteNode(Node *&noAtual)
{
    Node* temp = noAtual;
    if (noAtual->filhoE == NULL)
    {
        noAtual = noAtual->filhoD;
        delete temp;
    }
    else if (noAtual->filhoD == NULL)
    {
        noAtual = noAtual->filhoE;
        delete temp;
    }
    else
    {
        Aluno alunoSucessor;
        getSucessor(alunoSucessor, noAtual);
        noAtual->aluno = alunoSucessor;
        removeSearch(alunoSucessor, noAtual->filhoD);
    }
}
void Tree::getSucessor(Aluno &alunoSucessor, Node *temp)
{
    temp = temp->filhoD;
    while (temp->filhoE != NULL)
    {
        temp = temp->filhoE;
    }
    alunoSucessor = temp->aluno;
}
void Tree::search(Aluno &aluno, bool &search)
{
    search = false;
    Node *temp = getRoot();
    while (temp != NULL)
    {
        if (aluno.getRa() < temp->aluno.getRa())
        {
            temp = temp->filhoE;
        }
        else if (aluno.getRa() > temp->aluno.getRa())
        {
            temp = temp->filhoD;
        }
        else
        {
            search = true;
            aluno = temp->aluno;
            break;
        }
    }
}
void Tree::printPreOrder(Node *path)
{
    if (path != NULL)
    {
        cout << path->aluno.getNome() << ": ";
        cout << path->aluno.getRa() << endl;

        printPreOrder(path->filhoE);
        printPreOrder(path->filhoD);
    }
}
void Tree::printOrder(Node *path)
{
    if (path != NULL)
    {
        printOrder(path->filhoE);
        cout << path->aluno.getNome() << ": ";
        cout << path->aluno.getRa() << endl;
        printOrder(path->filhoD);
    }
}
void Tree::printPostOrder(Node *path)
{
    if (path != NULL)
    {
        printPostOrder(path->filhoE);
        printPostOrder(path->filhoD);
        cout << path->aluno.getNome() << ": ";
        cout << path->aluno.getRa() << endl;
    }
}