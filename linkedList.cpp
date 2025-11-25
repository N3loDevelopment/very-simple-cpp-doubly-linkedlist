#include <iostream>
#include <string>

struct Node
{
    std::string data;
    Node *prev;
    Node *next;
};

Node *head;
Node *tail;

void initList()
{
    head = nullptr;
    tail = nullptr;
}

void addToList(const std::string &val)
{
    Node *n = new Node{val, nullptr, nullptr};
    if (!head)
    {
        head = n;
        tail = n;
        return;
    }
    tail->next = n;
    n->prev = tail;
    n->next = nullptr;
    tail = n;
}

void removeFromList(const std::string &val)
{
    Node *curr = head;
    while (curr)
    {
        if (curr->data == val)
        {
            if (curr->prev)
                curr->prev->next = curr->next;
            else
                head = curr->next;

            if (curr->next)
                curr->next->prev = curr->prev;
            else
                tail = curr->prev;

            delete curr;
            return;
        }
        curr = curr->next;
    }
}

void getList()
{
    Node *curr = head;
    while (curr)
    {
        std::cout << curr->data << std::endl;
        curr = curr->next;
    }
}