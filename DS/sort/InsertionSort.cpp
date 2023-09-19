#include <bits/stdc++.h>
#include "SortTest.h"
using namespace std;

// 插入排序
void InsertionSort(vector<int> &arr)
{
    if (arr.size() <= 0)
        return;
    int i, j;
    for (i = 1; i < arr.size(); ++i)
    {
        if (arr[i] >= arr[i - 1])
            continue;
        int temp = arr[i];

        for (j = i - 1; j >= 0 && temp < arr[j]; --j)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

void InsertSort_OPT(vector<int> &arr)
{
    if (arr.size() <= 0)
        return;
    int i, j;
    for (i = 1; i < arr.size(); ++i)
    {
        if (arr[i] >= arr[i - 1])
            continue;
        int temp = arr[i];
        int low = 0, high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            // 为了保证稳定性，当mid相同时，应继续在右边区间进行查找
            if (arr[mid] <= temp)
                low = mid + 1;
            else
                high = mid - 1;
        }
        for (j = i - 1; j >= low; --j)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;
    }
}
// 链表插入排序
class LinkList
{
public:
    class LinkNode
    {
    public:
        LinkNode *pre, *next;
        int key;
        LinkNode() : key(0), pre(nullptr), next(nullptr) {}
        LinkNode(int k) : key(k), pre(nullptr), next(nullptr) {}
    };

    LinkNode *root;
    int size;
    LinkList()
    {
        root = new LinkNode;
        size = 0;
    }
    void Insert(int key)
    {
        Insert(root, key);
    }
    void InsertSort()
    {
        if (size == 0 || size == 1)
            return;
        LinkNode *pi = root->next->next;
        while (pi != nullptr && pi->next != nullptr)
        {
            LinkNode *p = pi->pre;
            LinkNode *temp = p->next;
            if (p->key > pi->key)
            {
                while (pi->key < p->key && p->pre != root)
                    p = p->pre;
                pi->pre->next = pi->next;
                if (pi->next != nullptr)
                    pi->next->pre = pi->pre;
                pi->next = p;
                pi->pre = p->pre;
                p->pre = pi;
                pi->pre->next = pi;
                pi = temp;
            }
            else
                pi = pi->next;
        }
    }
    void PrintList()
    {
        LinkNode *p = root->next;
        while (p->next != nullptr)
        {
            cout << p->key << " ";
            p = p->next;
        }
    }

private:
    void InitLinkList(LinkNode *root)
    {
        root = new LinkNode;
        size = 0;
    }
    void Insert(LinkNode *root, int key)
    {
        LinkNode *p = root;
        while (p->next != nullptr)
            p = p->next;
        p->next = new LinkNode(key);
        p->next->pre = p;
        ++size;
    }
};
int main()
{
    LinkList list1;
    for (int i = 0; i < 1e2; ++i)
    {
        list1.Insert(rand() % 1000);
    }
    list1.PrintList();
    cout << endl;
    list1.InsertSort();
    list1.PrintList();

    // SortTest::testSort(InsertSort_OPT, 1e2, true);
    return 0;
}