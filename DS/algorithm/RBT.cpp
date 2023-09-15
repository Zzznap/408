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

class BSTree
{
public:
    RBTNode *root;
    RBTNode *NIL;
    BSTree()
    {
        NIL = new RBTNode;
        NIL->color = 0;
        root = NIL;
    }
    void insert(int key);
    void print();

private:
    void insert(int key, RBTNode *node);
    void insertFixup(RBTNode *node);
    void leftRotate(RBTNode *node);
    void rightRotate(RBTNode *node);
    void print(RBTNode *node);
};

int main()
{
}