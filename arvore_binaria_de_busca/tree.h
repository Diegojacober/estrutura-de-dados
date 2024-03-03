#include <iostream>
#include "aluno.h"

struct Node
{
    Aluno aluno;
    Node *filhoE;
    Node *filhoD;
};

class Tree
{ // BST = Binary Search Tree
private:
    Node* raiz; // root
public:
    Tree();
    ~Tree();
    void deleteTree(Node* path);
    Node* getRoot(); // obter a raiz
    bool isFull();
    bool isEmpty();
    void removeSearch(Aluno aluno, Node*& noAtual); // busca quem vai ser removido
    void deleteNode(Node*& noAtual);
    void getSucessor(Aluno& alunoSucessor, Node* temp);
    void insert(Aluno aluno);
    void remove(Aluno aluno);
    void search(Aluno& aluno, bool& search);
    void printPreOrder(Node* path);
    void printOrder(Node* path);
    void printPostOrder(Node* path);
};