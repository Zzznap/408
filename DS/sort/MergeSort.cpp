#include <bits/stdc++.h>
#include "SortTest.h"

using namespace std;
void PrintVector(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}
void Merge(vector<int> &arr, vector<int> &arr_temp, int low, int mid, int high)
{
    int i, j, k;
    for (k = low; k <= high; ++k)
        arr_temp[k] = arr[k];
    for (i = low, j = mid + 1, k = low; i <= mid && j <= high; k++)
    {
        if (arr_temp[i] <= arr_temp[j])
            arr[k] = arr_temp[i++];
        else
            arr[k] = arr_temp[j++];
    }
    // 只剩下一边
    while (i <= mid)
        arr[k++] = arr_temp[i++];
    while (j <= high)
        arr[k++] = arr_temp[j++];
}
void MergeSort(vector<int> &arr, vector<int> &arr_temp, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(arr, arr_temp, low, mid);
        MergeSort(arr, arr_temp, mid + 1, high);
        Merge(arr, arr_temp, low, mid, high);
    }
}

void MergeSort(vector<int> &arr)
{
    vector<int> arr_temp = arr;
    MergeSort(arr, arr_temp, 0, arr.size() - 1);
}

int main()
{
    // vector<int> arr;
    // for (int i = 0; i < 1e1; ++i)
    // {
    //     arr.push_back(rand() % 100);
    // }
    // MergeSort(arr);
    // PrintVector(arr);
    SortTest::testSort(MergeSort, 1e7, false);
    return 0;
}