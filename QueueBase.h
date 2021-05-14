#pragma once

template <typename T>
class QueueBase
{
public:
    virtual int GetSize() const = 0;
    virtual T Pop() = 0;
    virtual void Push(const T& element) = 0;
    virtual T Peek() const = 0;
};

