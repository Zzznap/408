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
// 希尔排序
void ShellSort(vector<int> &arr)
{
    if (arr.size() <= 0)
        return;
    int i, j;
    int d = arr.size() / 2;
    while (d > 1)
    {
        for (i = d; i < arr.size(); ++i)
        {
            if (arr[i] < arr[i - d])
            {
                int temp = arr[i];

                for (j = i - d; j >= 0 && temp < arr[j]; j -= d)
                {
                    arr[j + d] = arr[j];
                }
                arr[j + d] = temp;
            }
        }
        d = d >> 1;
    }
}
int main()
{
    int size = 50000;
    SortTest::testSort(ShellSort, 1e7);
    // SortTest::testSort(InsertionSort, size);
    return 0;
}