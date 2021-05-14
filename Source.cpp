#include <iostream>
#include "QueueBase.h"
#include "Queue1.h"
#include "Queue2.h"

using namespace std;

template<typename T>
void MyFuncWithPointer(QueueBase<T>* s)
{
    cout << s->Peek() << endl;
}

template<typename T>
void MyFuncWithReference(QueueBase<T>& s)
{
    cout << s.Peek() << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    Queue1<int> d1;
    d1.Push(2);
    d1.Push(1);
    d1.Push(10);

    cout << d1;

    cout << "Первый элемент с начала : " << d1.Peek() << ";  Всего элементов : " << d1.GetSize() << endl;

    Queue2<int> d2;
    d2.Push(2);
    d2.Push(1);

    cout << d2;

    cout << "Первый элемент с начала : " << d2.Peek() << "; Всего элементов : " << d2.GetSize() << endl;

    cout << "Вызов функции с аргументом указателя" << endl;
    cout << "Элементы из первой очереди" << endl;
    MyFuncWithPointer(&d1);
    cout << "Элементы из второй очереди" << endl;
    MyFuncWithPointer(&d2);
    cout << "Вызов функции с аргументом ссылки" << endl;
    cout << "Элементы из первой очереди" << endl;
    MyFuncWithReference(d1);
    cout << "Элементы из второй очереди" << endl;
    MyFuncWithReference(d2);
    return 0;
}

