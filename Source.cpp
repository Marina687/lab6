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

    cout << "������ ������� � ������ : " << d1.Peek() << ";  ����� ��������� : " << d1.GetSize() << endl;

    Queue2<int> d2;
    d2.Push(2);
    d2.Push(1);

    cout << d2;

    cout << "������ ������� � ������ : " << d2.Peek() << "; ����� ��������� : " << d2.GetSize() << endl;

    cout << "����� ������� � ���������� ���������" << endl;
    cout << "�������� �� ������ �������" << endl;
    MyFuncWithPointer(&d1);
    cout << "�������� �� ������ �������" << endl;
    MyFuncWithPointer(&d2);
    cout << "����� ������� � ���������� ������" << endl;
    cout << "�������� �� ������ �������" << endl;
    MyFuncWithReference(d1);
    cout << "�������� �� ������ �������" << endl;
    MyFuncWithReference(d2);
    return 0;
}

