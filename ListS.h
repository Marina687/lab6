#pragma once
#include <iostream>

template<typename T>
class List // Linked list
{
private:

    class Node // ?????????
    {
    public:
        Node(T data = T(), Node* pNext = nullptr); // ???????????

        Node* pNext; // ?????????? ??????
        T data; // ??????
    };

    int size; // ???-?? ??
    Node* head; //?????? ??????
    Node* tail; // ????? ??????

public:

    List(); // ???????????

    ~List(); // ??????????

       void insert(T data, int index); // ?????????? ???????? ? ????????? ?????

    void push(T data); //?????????? ? ?????

    T pop(); // ???????? ???????

    T removeAT(int index); // ???????? ? ????????? ?????

    void clear(); // ???????? ????

    int getsize() const; // ???-?? ?????????

    T sel_el(const int index) const; // ?????????? ??????? ?? ???????

};

template<typename T>
List<T>::Node::Node(T data, Node* pNext)
{
    this->data = data;
    this->pNext = pNext;
}

template<typename T>
List<T>::List()
{
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
List<T>::~List() { clear(); }

template<typename T>
void List<T>::insert(T data, int index)
{
    if (index > this->size - 1) // 
    {
        std::cout << "????????? ?????? ????????? ??? ??????!" << std::endl;
        return T();
    }
    else
    {
        Node* previous = this->head;

        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node* newNode = new Node(data, previous->pNext);
        previous->pNext = newNode;
        size++;
    }
}

template<typename T>
void List<T>::push(T data)
{
    if (head == nullptr)
    {
        head = tail = new Node(data);
    }
    else
    {
        Node* current = this->tail;
        current->pNext = new Node(data);
        tail = current->pNext;
    }
    size++;
}

template<typename T>
T List<T>::pop()
{
    Node* temp = head;

    T data = temp->data;

    head = head->pNext;

    delete temp;
    size--;

    return data;
}

template<typename T>
T List<T>::removeAT(int index)
{
    if (index > this->size - 1)
    {
        std::cout << "????????? ?????? ????????? ??? ??????!" << std::endl;
        return T();
    }
    else if (index == 0)
    {
        return pop();
    }
    else
    {
        Node* previous = this->head;

        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;

        }
        Node* toDelete = previous->pNext;

        if (toDelete->pNext == nullptr)
            tail = previous;

        previous->pNext = toDelete->pNext;
        T data = toDelete->data;
        delete toDelete;
        size--;

        return data;
    }
}

template<typename T>
void List<T>::clear()
{
    while (size)
    {
        pop();
    }
}

template<typename T>
int List<T>::getsize() const { return size; }

template<typename T>
T List<T>::sel_el(const int index) const
{
    if (index > this->size - 1)
    {
        std::cout << "????????? ?????? ????????? ??? ??????!" << std::endl;
        return T();
    }

    if (index == 0)
        return head->data;
    else if (index == this->size - 1)
        return tail->data;
    else
    {
        Node* current = head;

        for (int i = 0; i < index; i++)
        {
            current = current->pNext;
        }

        return current->data;
    }
}

