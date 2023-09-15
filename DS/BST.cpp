#include <iostream>
using namespace std;
typedef struct BSTNode
{
    int key;
    struct BSTNode *lchild, *rchild, *parent;
} BSTNode, *BSTree;
// 打印节点的函数
void printNode(BSTNode *node, int level)
{
    if (node == NULL)
        return;

    // 打印右子树
    printNode(node->rchild, level + 1);

    // 打印当前节点
    for (int i = 0; i < level; i++)
        printf("    "); // 缩进，可以根据需要调整
    printf("%d\n", node->key);

    // 打印左子树
    printNode(node->lchild, level + 1);
}

// 打印整个BST的函数
void printBST(BSTree tree)
{
    if (tree == NULL)
        return;

    printf("Binary Search Tree:\n");
    printNode(tree, 0);
}
// 非递归
BSTNode *BST_Search(BSTree T, int key)
{
    while (T != NULL && key != T->key)
    {
        if (key < T->key)
            T = T->lchild;
        else
            T = T->rchild;
    }
    return T;
}
// 递归
BSTNode *BSTSearch(BSTree T, int key)
{
    if (T == NULL || key == T->key)
        return T;
    if (key < T->key)
        return BSTSearch(T->lchild, key);
    else
        return BSTSearch(T->rchild, key);
}
int BST_Insert(BSTree &T, int k, BSTNode *parent)
{
    if (T == NULL)
    {
        T = new BSTNode;
        T->key = k;
        T->lchild = T->rchild = NULL;
        T->parent = parent;
        return 1;
    }
    else if (k == T->key)
        return 0;
    else if (k < T->key)
        return BST_Insert(T->lchild, k, T);
    else
        return BST_Insert(T->rchild, k, T);
}
int BST_Insert(BSTree &T, int k)
{
    return BST_Insert(T, k, NULL);
}

void Create_BST(BSTree &T, int str[], int n)
{
    T = NULL;
    int i = 0;
    while (i < n)
    {
        BST_Insert(T, str[i]);
        i++;
    }
}
BSTNode *Child_MAX(BSTree T)
{
    while (T->rchild != NULL)
        T = T->rchild;
    return T;
}
BSTNode *Child_MIN(BSTree T)
{
    while (T->lchild != NULL)
        T = T->lchild;
    return T;
}

int BST_Delete(BSTree &T, int k)
{
    if (T == NULL)
        return 0;
    else
    {
        BSTNode *p = BST_Search(T, k);
        if (p->lchild == NULL && p->rchild == NULL)
        {
            if (p->parent->lchild == p)
                p->parent->lchild = NULL;
            else
                p->parent->rchild = NULL;
            delete p;
        }
        // 只有右子树
        else if (p->lchild == NULL)
        {
            if (p->parent->lchild == p)
                p->parent->lchild = p->rchild;
            else
                p->parent->rchild = p->rchild;
            delete p;
        }
        // 只有左子树
        else if (p->rchild == NULL)
        {
            if (p->parent->lchild == p)
                p->parent->lchild = p->lchild;
            else
                p->parent->rchild = p->lchild;
            delete p;
        }
        // 左右子树都有，选择一个最大的或者最小的
        else
        {

            // 找到左子树的最大值，左子树最右下角的结点，并且这个结点一定是右孩子结点
            BSTNode *q = Child_MAX(p->lchild);
            // 把这个值赋给p
            p->key = q->key;
            // 删除这个最大值，该结点至多有一个左子树
            q->parent->rchild = q->lchild;
            delete q;
        }
    }
}

void InOrder_Traverse(BSTree T)
{
    if (T != NULL)
    {
        InOrder_Traverse(T->lchild);
        cout << T->key << " ";
        InOrder_Traverse(T->rchild);
    }
}
int main()
{
    int str[] = {50, 66, 60, 26, 21, 30, 70, 68};
    BSTree T;
    Create_BST(T, str, 8);
    printBST(T);
    BST_Delete(T, 50);
    printBST(T);
    BSTNode *p = BST_Search(T, 26);
    cout << p->parent->key << endl;
    // if (p == NULL)
    //     cout << "Not Found" << endl;
    // else
    //     cout << p->key << endl;
    return 0;
}