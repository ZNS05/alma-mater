#include <iostream>
#include "Queue.h"
#define N 10
Queue::Queue()
{
    int *array = new int[N];
    for (int i = 0; i < N; ++i)
    {
        array[i] = 0;
    }
    std::cout << this << "constructor" << std::endl;
}

Queue::~Queue()
{
    delete[] array;
    std::cout << this << "destructor" << std::endl;
}

void Queue::Print()
{
    for (int i = front; i <= rear; i = (i + 1) % N)
    {
        if (i == front) {std::cout << "Front->"};
        if (i == rear)  {std::cout << "Rear->"};
        std::cout << array[i] << "";
    }
    std::cout << std::endl;
}

void Queue::Creat()
{

}

Queue& Queue::operator++()
{
    for (int i = front; i <= rear; i = (i + 1) % N)
    {
        array[i] += 1;
    }
    return *this;
}

Queue Queue::operator++(int)
{

    return ++(*this);
}

Queue& Queue::operator--()
{
    if()
}
