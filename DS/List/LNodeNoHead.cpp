#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
    /* data */
} LNode, *LinkList;

// 不带头结点
// 初始化一个空的单链表（不带头结点）
bool InitList(LinkList &L)
{
    L = NULL;
    return true;
}

bool Empty(LinkList L)
{
    // 头结点的指针域为空
    return (L == NULL);
}

// 按位查找
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
    {
        return NULL;
    }
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}

// 后插操作
bool InsertNextNode(LNode *p, int e)
{
    if (p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    // 内存分配失败
    if (s == NULL)
    {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
// 前插操作（逻辑上前插）
bool InsertPriorNode(LNode *p, int e)
{
    if (p = NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->next = p->next;
    s->data = p->data;
    p->next = s;
    p->data = e;
    return true;
}
// 删除指定节点p.p不是最后一个节点
bool DeleteNode(LNode *p)
{
    if (p == NULL)
        return false;

    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}
// 插入
bool ListInsert(LinkList &L, int i, int e)
{
    // 头结点不存储数据
    if (i < 0)
    {
        return false;
    }
    LNode *p = GetElem(L, i);
    return InsertNextNode(p, e);
}

bool ListDelete(LinkList &L, int i, int &e)
{
    if (i < 0)
    {
        return false;
    }
    LNode *p;
    int j = 0;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
    {
        return false;
    }
    if (p->next == NULL)
    {
        return false;
    }
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}
// 求表长度
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

// 带头结点尾插法
bool Tail_ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    return InsertNextNode(p, e);
}

// 带头结点头插法
bool Head_ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    return InsertNextNode(p, e);
}
// 尾插法输入
LinkList List_TailInsett(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    // 初始化为空链表
    L->next = NULL;
    LNode *s, *r = L;

    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}
// 头插法输入
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    // 初始化为空链表
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}
// 从头输出
void print(LinkList L)
{
    LNode *p = L->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}
int main()
{
    LinkList L;
    InitList(L);
    L = List_TailInsett(L);
    print(L);
    return 0;
}