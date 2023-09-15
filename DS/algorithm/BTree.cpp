#include <bits/stdc++.h>
using namespace std;
const int t = 3; // B树的最小度数

// B树的节点
class BTreeNode
{
public:
    bool is_leaf;
    std::vector<int> keys;
    std::vector<BTreeNode *> children;

    BTreeNode(bool leaf = true) : is_leaf(leaf) {}
};

// B树
class BTree
{
public:
    BTreeNode *root;

    BTree()
    {
        root = new BTreeNode();
    }

    // 在B树中查找键值
    bool search(int key)
    {
        return search(root, key);
    }

    // 插入键值到B树
    void insert(int key)
    {
        BTreeNode *r = root;
        if (r->keys.size() == 2 * t - 1)
        {
            BTreeNode *new_node = new BTreeNode(false);
            new_node->children.push_back(root);
            split_child(new_node, 0);
            root = new_node;
            insert_non_full(new_node, key);
        }
        else
        {
            insert_non_full(root, key);
        }
    }

private:
    bool search(BTreeNode *x, int key)
    {
        int i = 0;
        while (i < x->keys.size() && key > x->keys[i])
            i++;

        if (i < x->keys.size() && key == x->keys[i])
            return true;

        if (x->is_leaf)
            return false;

        return search(x->children[i], key);
    }

    void insert_non_full(BTreeNode *x, int key)
    {
        int i = x->keys.size() - 1;

        if (x->is_leaf)
        {
            x->keys.push_back(0); // 扩展数组
            while (i >= 0 && key < x->keys[i])
            {
                x->keys[i + 1] = x->keys[i];
                i--;
            }
            x->keys[i + 1] = key;
        }
        else
        {
            while (i >= 0 && key < x->keys[i])
                i--;

            i++;
            if (x->children[i]->keys.size() == 2 * t - 1)
            {
                split_child(x, i);
                if (key > x->keys[i])
                    i++;
            }
            insert_non_full(x->children[i], key);
        }
    }

    void split_child(BTreeNode *x, int i)
    {
        BTreeNode *y = x->children[i];
        BTreeNode *z = new BTreeNode(y->is_leaf);

        x->keys.insert(x->keys.begin() + i, y->keys[t - 1]);
        x->children.insert(x->children.begin() + i + 1, z);

        for (int j = 0; j < t - 1; j++)
            z->keys.push_back(y->keys[j + t]);

        y->keys.erase(y->keys.begin() + t - 1, y->keys.end());

        if (!y->is_leaf)
        {
            for (int j = 0; j < t; j++)
                z->children.push_back(y->children[j + t]);
            y->children.erase(y->children.begin() + t, y->children.end());
        }
    }
};

int main()
{
    BTree btree;

    btree.insert(3);
    btree.insert(7);
    btree.insert(1);
    btree.insert(5);
    btree.insert(12);
    btree.insert(15);
    btree.insert(8);
    btree.insert(17);
    btree.insert(9);
    btree.insert(2);

    std::cout << "查找结果:" << std::endl;
    std::cout << "键值 3: " << (btree.search(3) ? "找到" : "未找到") << std::endl;
    std::cout << "键值 8: " << (btree.search(8) ? "找到" : "未找到") << std::endl;
    std::cout << "键值 9: " << (btree.search(9) ? "找到" : "未找到") << std::endl;
    std::cout << "键值 10: " << (btree.search(10) ? "找到" : "未找到") << std::endl;

    return 0;
}