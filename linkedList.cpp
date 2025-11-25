#include "linkedList.hpp"
#include <iostream>
#include <string>

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

void removeIndexFromList(int &index)
{
    if (index < 0 || !head)
        return;

    Node *curr = head;
    int i = 0;

    while (curr && i < index)
    {
        curr = curr->next;
        index++;
    }

    if (!curr)
        return;

    if (curr == head)
    {
        head = curr->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
    }
    else if (curr == tail)
    {
        tail = curr->prev;
        tail->next = nullptr;
    }
    else
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    delete curr;
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