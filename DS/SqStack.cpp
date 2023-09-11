#include <iostream>
using namespace std;
int MAX_SIZE = 1000;
typedef struct
{
    int data[1000];
    int top;
} SqStack;

void InitStack(SqStack &s)
{
    // 注意s.top的值，初始值为-1和0不一样
    s.top = -1;
}
bool StackEmpty(SqStack s)
{
    if (s.top == -1)
        return true;
    else
        return false;
}

bool Push(SqStack &S, int x)
{
    if (S.top == MAX_SIZE - 1)
        return false;
    // S.top = S.top + 1;
    // S.data[S.top] = x;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, int &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}
bool GetTop(SqStack &S, int &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}
int main()
{
    SqStack s;
}