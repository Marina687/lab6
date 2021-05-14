#pragma once

#include "QueueBase.h"
#include "ListD.h"

template<typename T>
class Queue2 : public QueueBase<T>
{
private:

    ListD<T>* list2;
    int size;

public:
    Queue2();

    Queue2(const Queue2& other);

    Queue2(Queue2&& other);

    ~Queue2();

    int GetSize() const;

    void Push(const T& element);

    T Pop();

    T Peek() const;

    Queue2& operator=(const Queue2& other);
    Queue2& operator=(Queue2&& other);

    template<typename T>
    friend std::ostream& operator<< (std::ostream& os, const Queue2<T>& obj);
};

template<typename T>
Queue2<T>::Queue2()
{
    list2 = new ListD<T>();
    size = 0;
}

template<typename T>
Queue2<T>::Queue2(const Queue2& other)
{
    list2 = new ListD<T>();
    size = other.size;

    for (int i = 0; i < other.size; i++)
    {
        this->list2->Push(other.list2->sel_el(i));
    }
}

template<typename T>
Queue2<T>::Queue2(Queue2&& other)
{
    size = other.size;
    list2 = other.list2;
    other.size = NULL;
    other.list2 = nullptr;
}

template<typename T>
Queue2<T>::~Queue2() {
    delete list2;
    size = 0;
}

template<typename T>
int Queue2<T>::GetSize() const { return size; }

template<typename T>
void Queue2<T>::Push(const T& element)
{
    list2->Push(element);
    ++size;
}

template<typename T>
T Queue2<T>::Pop()
{
    --size;
    return list2->Pop();
}

template<typename T>
T Queue2<T>::Peek() const { return list2->sel_el(0); }

template<typename T>
Queue2<T>& Queue2<T>::operator=(const Queue2<T>& other)
{
    if (this == &other)
    {
        return *this;
    }

    list2->clear();

    size = other.size;

    for (int i = 0; i < other.size; i++)
    {
        this->list2->push(other.list2->sel_el(i));
    }
}

template<typename T>
Queue2<T>& Queue2<T>::operator=(Queue2<T>&& other)
{
    if (this == &other)
    {
        return *this;
    }

    list2.clear();

    size = other.size;
    list2 = other.list2;
    other.size = NULL;
    other.list2 = nullptr;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Queue2<T>& obj)
{
    for (size_t i = 0; i < obj.size; i++)
    {
        os << obj.list2->sel_el(i) << " ";
    }

    os << std::endl;

    return os;
}

