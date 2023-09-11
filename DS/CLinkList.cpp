#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
    /* data */
} LNode, *LinkList;

// 初始化循环单链表
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        return false;
    }
    // 头结点next指向头结点
    L->next = L;
    return true;
}
bool Empty(LinkList L)
{
    return (L->next == L);
}
bool isTail(LinkList L, LNode *p)
{
    return (p->next == L);
}