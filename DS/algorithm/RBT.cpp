#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class RBTNode
{
public:
    int key;
    int color;
    RBTNode *lchild, *rchild;
    RBTNode *parent;
    RBTNode(int k) : key(k), color(1), lchild(nullptr), rchild(nullptr), parent(nullptr) {}
    RBTNode() : key(0), color(0), lchild(nullptr), rchild(nullptr), parent(nullptr) {}
};

class BRTree
{
public:
    enum
    {
        RED,
        BLACK
    };
    enum Traversal
    {
        InOrder,
        PreOrder,
        PostOrder
    };
    RBTNode *root;
    RBTNode *NIL;
    BRTree()
    {
        NIL = new RBTNode;
        NIL->color = BLACK;
        root = NIL;
    }
    void insert(int key)
    {
        insert(key, root);
    }
    void print()
    {
        print(InOrder);
    }
    void printTree()
    {
        cout << "Red-Black Tree:" << endl;
        printTree(root, 0);
    }
    void print(Traversal traversal)
    {
        switch (traversal)
        {
        case InOrder:
            printInOrder(root);
            break;
        case PreOrder:
            printPreOrder(root);
            break;
        case PostOrder:
            printPostOrder(root);
            break;
        default:
            break;
        }
    }

private:
    void insert(int key, RBTNode *node)
    {
        if (node == NIL)
        {
            node = new RBTNode(key);
            node->parent = NIL;
            node->lchild = NIL;
            node->rchild = NIL;
            node->color = BLACK;
            root = node;
            return;
        }
        if (key < node->key)
        {
            if (node->lchild == NIL)
            {
                node->lchild = new RBTNode(key);
                node->lchild->parent = node;
                node->lchild->lchild = NIL;
                node->lchild->rchild = NIL;
                node->lchild->color = RED;
                insertFixup(node->lchild);
            }
            else
                insert(key, node->lchild);
        }
        else
        {
            if (node->rchild == NIL)
            {
                node->rchild = new RBTNode(key);
                node->rchild->parent = node;
                node->rchild->lchild = NIL;
                node->rchild->rchild = NIL;
                node->rchild->color = RED;
                insertFixup(node->rchild);
            }
            else
                insert(key, node->rchild);
        }
    }
    // 插入修复
    void insertFixup(RBTNode *node)
    {
        if (node == root)
        {
            node->color = BLACK;
            return;
        }
        if (node->parent->color == BLACK)
            return;
        else
        {
            RBTNode *uncle = getUncle(node);
            // 叔叔为红
            if (uncle->color == RED)
            {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                insertFixup(node->parent->parent);
            }
            // 叔叔为黑色，父亲为红色
            else
            {
                // *R型
                if (node == node->parent->rchild)
                {
                    // RR型
                    if (node->parent == node->parent->parent->rchild)
                    {
                        node->parent->color = BLACK;
                        node->parent->parent->color = RED;
                        leftRotate(node->parent->parent);
                    }
                    // LR型
                    else
                    {
                        node->color = BLACK;
                        node->parent->parent->color = RED;
                        leftRotate(node->parent);
                        rightRotate(node->parent);
                    }
                }
                // *L型
                else if (node == node->parent->lchild)
                {
                    // LL型
                    if (node->parent == node->parent->parent->lchild)
                    {
                        node->parent->color = BLACK;
                        node->parent->parent->color = RED;
                        rightRotate(node->parent->parent);
                    }
                    // RL型
                    else
                    {
                        node->color = BLACK;
                        node->parent->parent->color = RED;
                        rightRotate(node->parent);
                        leftRotate(node->parent);
                    }
                }
            }
        }
    }
    // 获取叔叔节点
    RBTNode *getUncle(RBTNode *node)
    {
        if (node->parent == node->parent->parent->lchild)
            return node->parent->parent->rchild;
        else
            return node->parent->parent->lchild;
    }
    // 左旋
    void leftRotate(RBTNode *node)
    {
        RBTNode *x = node->rchild;
        node->rchild = x->lchild;
        x->lchild = node;
        x->parent = node->parent;
        node->parent = x;
        if (node->rchild != NIL)
            node->rchild->parent = node;
        if (x->parent == NIL)
            root = x;
        else if (node == x->parent->lchild)
            x->parent->lchild = x;
        else
            x->parent->rchild = x;
    }
    // 右旋
    void rightRotate(RBTNode *node)
    {
        RBTNode *x = node->lchild;
        node->lchild = x->rchild;
        x->rchild = node;
        x->parent = node->parent;
        node->parent = x;
        if (node->lchild != NIL)
            node->lchild->parent = node;
        if (x->parent == NIL)
            root = x;
        else if (node == x->parent->lchild)
            x->parent->lchild = x;
        else
            x->parent->rchild = x;
    }
    // 二叉树形态输出
    void printTree(RBTNode *node, int level)
    {
        if (node == NIL)
            return;
        printTree(node->rchild, level + 1);
        for (int i = 0; i < level; i++)
            cout << "    ";
        string color = (node->color == RED) ? "r" : "b";
        cout << node->key << color << endl;
        printTree(node->lchild, level + 1);
    }
    void printInOrder(RBTNode *node);
    void printPreOrder(RBTNode *node);
    void printPostOrder(RBTNode *node);
};

int main()
{
    vector<int> arr = {20, 10, 5, 30, 40, 57, 3, 2, 4, 35, 25, 18, 22, 23, 24, 19, 18};
    BRTree tree;
    for (auto i : arr)
        tree.insert(i);
    tree.printTree();
    return 0;
}