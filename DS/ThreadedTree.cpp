#include <iostream>

using namespace std;

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
    int ltag, rtag;
} BiTNode, *BiTree;
BiTNode *pre = NULL;
void InitBiTree(BiTree &T)
{
    T = NULL;
}

void CreateBiTree(BiTree &T)
{
    char ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else
    {
        T = new BiTNode;
        T->data = ch;
        T->ltag = 0;
        T->rtag = 0;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

// 遍历
void InOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild);
    cout << T->data << " ";
    InOrderTraverse(T->rchild);
}

// 线索化

void ThreadVisit(BiTNode *q)
{
    if (q->lchild == NULL)
    {
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL)
    {
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}
void InThread(BiTree &T)
{
    if (T != NULL)
    {
        InThread(T->lchild);
        ThreadVisit(T);
        InThread(T->rchild);
    }
}
void CreateInThread(BiTree T)
{
    pre = NULL;
    if (T != NULL)
    {
        InThread(T);
        if (pre->rchild == NULL)
            pre->rtag = 1;
    }
}
// 先序线索化

// 先序线索化会出现问题，因为先序线索化的时候，
// pre指针会先指向右子树，然后再指向左子树，这样会导致后面的线索化出现问题
void PreThread(BiTree &T)
{
    if (T != NULL)
    {
        ThreadVisit(T);
        if (T->ltag == 0)
            PreThread(T->lchild);
        // if (T->rtag == 0)
        PreThread(T->rchild);
    }
}
// 后续线索化
void PostThread(BiTree &T)
{
    if (T != NULL)
    {
        PostThread(T->lchild);
        PostThread(T->rchild);
        ThreadVisit(T);
    }
}
// 中序线索树的遍历
//********************************************************************************
//  找到以P为根的子树中，第一个被中序遍历的结点
BiTNode *FirstNodeInOrder(BiTNode *p)
{
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}
// 找到以P为根的子树中，最后一个被中序遍历的结点
BiTNode *LastNodeInOrder(BiTNode *p)
{
    // 最右下角的结点
    while (p->rtag == 0)
        p = p->rchild;
    return p;
}
// 在中序线索数中找到节点P的前驱结点
BiTNode *PreNodeInOrder(BiTNode *p)
{
    if (p->ltag == 0)
        return FirstNodeInOrder(p->lchild);
    else
        return p->lchild;
}
// 在中序线索二叉树中找到结点P的后继结点
BiTNode *NextNodeInOrder(BiTNode *p)
{
    // 右子树中最左下的结点（即中序遍历中p的后继）
    if (p->rtag == 0)
        return FirstNodeInOrder(p->rchild);
    else
        return p->rchild;
}
// 中序线索二叉树的中序遍历
void InOrderTraverse_Thr(BiTree T)
{
    BiTNode *p;
    p = FirstNodeInOrder(T);
    while (p != NULL)
    {
        cout << p->data << " ";
        p = NextNodeInOrder(p);
    }
}
// 先序线索树的遍历
//********************************************************************************
// 在先序线索二叉树中找到结点P的后继结点
BiTNode *NextNodePreOrder(BiTNode *p)
{
    // 如果ltag为0，则不是线索，那么p的左孩子就是p的后继
    if (p->ltag == 0)
        return p->lchild;
    // 否则，lchild指向前驱
    // 如果rtag为0，则不是线索，那么p的右孩子就是p的后继
    else if (p->rtag == 0)
        return p->rchild;
}
// 先序线索二叉树节点P的前驱结点
BiTNode *PreNodePreOrder(BiTNode *p)
{
    // 如果rtag为0，找不到前驱，除非为三叉链表
    if (p->ltag == 1)
        return p->lchild;
    else
        return NULL;
}
int main()
{
    BiTree T;
    InitBiTree(T);
    // 输入示例：AB#D##C##
    CreateBiTree(T);
    // 中序线索化
    InOrderTraverse(T);
    cout << endl;
    CreateInThread(T);
    InOrderTraverse_Thr(T);
    return 0;
}