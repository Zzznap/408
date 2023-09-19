#include <bits/stdc++.h>
using namespace std;

// AVL 树节点
class AVLNode
{
public:
    int key;
    int height;
    AVLNode *left;
    AVLNode *right;

    AVLNode(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

// 计算树的高度
int getHeight(AVLNode *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

// 更新节点高度
void updateHeight(AVLNode *node)
{
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// 计算平衡因子
int getBalanceFactor(AVLNode *node)
{
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// 右旋转
AVLNode *rotateRight(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *xr = x->right;

    x->right = y;
    y->left = xr;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// 左旋转
AVLNode *rotateLeft(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *yl = y->left;

    y->left = x;
    x->right = yl;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// 插入节点
AVLNode *insert(AVLNode *root, int key)
{
    if (root == nullptr)
        return new AVLNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    updateHeight(root);

    int balance = getBalanceFactor(root);

    // 左子树高于右子树，需要右旋转
    if (balance > 1 && key < root->left->key)
        return rotateRight(root);

    // 右子树高于左子树，需要左旋转
    if (balance < -1 && key > root->right->key)
        return rotateLeft(root);

    // 左子树的右子树高于左子树，需要左旋转后右旋转
    if (balance > 1 && key > root->left->key)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // 右子树的左子树高于右子树，需要右旋转后左旋转
    if (balance < -1 && key < root->right->key)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// 删除节点
AVLNode *remove(AVLNode *root, int key)
{
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = remove(root->left, key);
    else if (key > root->key)
        root->right = remove(root->right, key);
    else
    {
        if (root->left == nullptr || root->right == nullptr)
        {
            // 左子树为空，临时记录右子树,否则记录左子树
            AVLNode *temp = root->left ? root->left : root->right;

            // 无子树
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            // 否则，复制临时记录的子树
            else
                *root = *temp;

            delete temp;
        }
        else
        {
            // 找到右子树的最小值
            AVLNode *temp = root->right;
            while (temp->left != nullptr)
                temp = temp->left;

            root->key = temp->key;
            root->right = remove(root->right, temp->key);
        }
    }

    if (root == nullptr)
        return root;

    updateHeight(root);

    int balance = getBalanceFactor(root);

    // 左子树高于右子树，需要右旋转
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rotateRight(root);

    // 右子树高于左子树，需要左旋转
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return rotateLeft(root);

    // 左子树的右子树高于左子树，需要左旋转后右旋转
    if (balance > 1 && getBalanceFactor(root->left) < 0)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // 右子树的左子树高于右子树，需要右旋转后左旋转
    if (balance < -1 && getBalanceFactor(root->right) > 0)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}
// 后序遍历
void inorderTraversal(AVLNode *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        cout << root->key << " ";

        inorderTraversal(root->right);
    }
}
// 后序遍历
void postorderTraversal(AVLNode *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        inorderTraversal(root->right);
        cout << root->key << " ";
    }
}
// 二叉树输出
void printTree(AVLNode *root, int level)
{
    if (root == nullptr)
        return;
    printTree(root->right, level + 1);
    for (int i = 0; i < level; i++)
        cout << "    ";
    cout << root->key << endl;
    printTree(root->left, level + 1);
}
void printTree(AVLNode *root)
{
    cout << "AVL Tree:" << endl;
    printTree(root, 0);
}
int main()
{
    AVLNode *root = nullptr;
    // 计算时间
    // 创建一个线性同余引擎
    std::linear_congruential_engine<uint32_t, 48271, 0, 2147483647> engine;

    // 使用当前时间作为种子来初始化引擎
    unsigned int seed = static_cast<unsigned int>(std::time(nullptr));
    engine.seed(seed);

    // 创建一个正态分布对象
    double mean = 0.0;   // 均值
    double stddev = 1.0; // 标准差
    std::normal_distribution<double> normalDist(mean, stddev);
    clock_t start, end;
    start = clock();
    vector<int> arr = {33, 10, 44, 5, 20, 35, 78, 4, 8, 15, 25, 36, 50, 88, 1, 6, 12, 23, 28, 48, 62, 21};
    vector<int> arr2 = {15, 5, 20, 2, 6, 1};
    vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7};

    for (int i = 0; i < arr3.size(); i++)
    {
        root = insert(root, arr3[i]);
    }
    cout << endl;
    end = clock();
    printTree(root);

    // cout << "排序时间" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
