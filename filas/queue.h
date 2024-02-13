#include "item_type.h"

int const MAX_ITEMS = 10;

class Queue
{
public:
    Queue();
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    void print() const;

    void enqueue(ItemType);
    ItemType dequeue();

private:
    int front;
    int back;
    ItemType *structure;
};