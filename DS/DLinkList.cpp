#include <iostream>

using namespace std;

typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

// 带头结点
// 初始化
bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}
// 判断空
bool Empty(DLinkList L)
{
    return (L->next == NULL);
}

/// @brief 按节点插入
/// @param p 插入到p之后
/// @param s 要插入的节点
/// @return 插入成功返回true，否则返回false
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
        return false;
    s->next = p->next;
    if (p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}
// 删除p的后继结点
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL || p->next == NULL)
        return false;
    DNode *q = p->next;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}
void Destory(DLinkList &L)
{
    while (L->next != NULL)
        DeleteNextDNode(L);
    free(L);
    L = NULL;
}
// 双链表遍历 从前向后
void Traverse(DLinkList L)
{
    DNode *p = L->next;
    while (p != NULL)
    {
        /* code */
        p = p->next;
    }
}
// 双链表遍历 从后向前
void ReverseTraverse(DLinkList L)
{
    DNode *p = L->next;
    while (p != NULL)
    {
        /* code */
        p = p->prior;
    }
}
int main()
{
    DLinkList L;
    InitDLinkList(L);
    return 0;
}