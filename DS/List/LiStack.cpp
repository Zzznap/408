#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} *LiStack;

bool InitStack(LiStack &S)
{
    S = NULL;
    return true;
}
bool Push(LiStack &S, int x)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = S;
    S = s;
    return true;
}

bool Pop(LiStack &S, int &x)
{
    if (S == NULL)
    {
        throw invalid_argument("Stack is empty");
        return false;
    }
    x = S->data;
    LNode *p = S;
    S = S->next;
    free(p);
    return true;
}
bool DestoryStack(LiStack &S)
{
    while (S != NULL)
    {
        // LNode *p = S;
        // S = S->next;
        // free(p);
        Pop(S, S->data);
    }
    return true;
}

bool Empty(LiStack S)
{
    return (S == NULL);
}
bool GetTop(LiStack S, int &x)
{
    if (S == NULL)
        return false;
    x = S->data;
    return true;
}

int main()
{
    LiStack s;
    InitStack(s);
    Push(s, 1);
    Push(s, 2);
    Push(s, 3);
    DestoryStack(s);
    int x;
    try
    {
        /* code */
        Pop(s, x);
        cout << x << endl;
        Pop(s, x);
        cout << x << endl;
        Pop(s, x);
        cout << x << endl;
        Pop(s, x);
        cout << x << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}