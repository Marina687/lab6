#pragma once

#include "QueueBase.h"
#include "ListS.h"

template<typename T>
class Queue1 : public QueueBase<T>
{
private:

    List<T>* list;
    int size;

public:
    Queue1();

    Queue1(const Queue1& other);

    Queue1(Queue1&& other);

    ~Queue1();

    int GetSize() const;

    void Push(const T& element);

    T Pop();

    T Peek() const;

    Queue1& operator=(const Queue1& other);
    Queue1& operator=(Queue1&& other);

    template<typename T>
    friend std::ostream& operator<< (std::ostream& os, const Queue1<T>& obj);
};

template<typename T>
Queue1<T>::Queue1()
{
    list = new List<T>();
    size = 0;
}

template<typename T>
Queue1<T>::Queue1(const Queue1& other)
{
    list = new List<T>();
    size = other.size;

    for (int i = 0; i < other.size; i++)
    {
        this->list->push(other.list->sel_el(i));
    }
}

template<typename T>
Queque1<T>::Queue1(Queue1&& other)
{
    size = other.size;
    list = other.list;
    other.size = NULL;
    other.list = nullptr;
}

template<typename T>
Queue1<T>::~Queue1() {
    delete list;
    size = 0;
}

template<typename T>
int Queue1<T>::GetSize() const { return size; }

template<typename T>
void Queue1<T>::Push(const T& element)
{
    list->push(element);
    ++size;
}

template<typename T>
T Queue1<T>::Pop()
{
    --size;
    return list->pop();
}


template<typename T>
T Queue1<T>::Peek() const { return list->sel_el(0); }

template<typename T>
Queue1<T>& Queue1<T>::operator=(const Queue1<T>& other)
{
    if (this == &other)
    {
        return *this;
    }

    list->clear();

    size = other.size;

    for (int i = 0; i < other.size; i++)
    {
        this->list->push(other.list->sel_el(i));
    }
}

template<typename T>
Queue1<T>& Queue1<T>::operator=(Queue1<T>&& other)
{
    if (this == &other)
    {
        return *this;
    }

    list.clear();

    size = other.size;
    list = other.list;
    other.size = NULL;
    other.list = nullptr;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Queue1<T>& obj)
{
    for (size_t i = 0; i < obj.size; i++)
    {
        os << obj.list->sel_el(i) << " ";
    }

    os << std::endl;

    return os;
}

