#include <iostream>
using namespace std;

#define MaxSize 50
typedef struct
{
    int data[MaxSize];
    int front, rear;
} SqQueue;
void InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
}
bool isEmpty(SqQueue Q)
{
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}
bool isFull(SqQueue Q)
{
    if ((Q.rear + 1) % MaxSize == Q.front)
        return true;
    else
        return false;
}
bool EnQueue(SqQueue &Q, int x)
{

    if (true)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

int main()
{
    SqQueue Q;
    InitQueue(Q);
    return 0;
}