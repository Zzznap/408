#include <bits/stdc++.h>
#include "SortTest.h"

using namespace std;

void HeapAdjust(vector<int> &arr, int k, int len)
{
    arr[0] = arr[k];
    for (int i = k * 2; i <= len; i *= 2)
    {
        // 找到更大的后代
        if (i < len - 1 && arr[i] < arr[i + 1])
            ++i;
        if (arr[0] >= arr[i])
            break;
        // i < len,但2*i可能=len
        else if (i < len)
        {
            arr[k] = arr[i];
            k = i;
        }
    }
    arr[k] = arr[0]; // 被筛选节点的值放入最终位置
    arr[0] = -1;
}
void printVector(vector<int> arr)
{
    for (auto it = arr.begin(); it < arr.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void BuildMaxHeap(vector<int> &arr, int len)
{
    for (int i = len / 2; i > 0; --i)
        HeapAdjust(arr, i, len);
}
void HeapSort(vector<int> &arr)
{
    int len = arr.size();
    BuildMaxHeap(arr, len);
    for (int i = len; i > 1; --i)
    {
        swap(arr[1], arr[i - 1]);
        HeapAdjust(arr, 1, i - 1);
        printVector(arr);
    }
}
int main()
{

    SortTest::testSort(HeapSort, 5, true);
    return 0;
}