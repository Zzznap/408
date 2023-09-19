#include <bits/stdc++.h>
#include "SortTest.h"

using namespace std;

// 定义一个计算函数执行时间的函数模板
template <typename Func, typename... Args>
double calculate_execution_time(Func &&func, Args &&...args)
{
    auto start_time = std::chrono::high_resolution_clock::now();
    std::forward<Func>(func)(std::forward<Args>(args)...);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    return duration.count(); // 返回执行时间（微妙）
}
void _QuickSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int low_temp = low, high_temp = high;
    int temp = arr[low];
    bool lowEmpty = true;
    while (low < high)
    {
        if (lowEmpty)
        {
            // YY写法
            if (arr[high] < temp)
            {
                arr[low] = arr[high];
                ++low;
                lowEmpty = false;
            }
            else
                --high;
        }
        else
        {

            if (arr[low] > temp)
            {
                arr[high] = arr[low];
                --high;
                lowEmpty = true;
            }
            else
                ++low;
        }
    }
    arr[low] = temp;
    _QuickSort(arr, low_temp, low - 1);
    _QuickSort(arr, low + 1, high_temp);
}
void QuickSort(vector<int> &arr)
{
    _QuickSort(arr, 0, arr.size() - 1);
}
void _QuickSort_COM(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int i = low, j = high;
    int pivot = arr[low];
    while (i < j)
    {
        // 找到第一个比基准小的
        while (i < j && arr[j] >= pivot)
            --j;
        arr[i] = arr[j]; // 移到左边
        // 找到第一个比基准大的
        while (i < j && arr[i] <= pivot)
            ++i;
        arr[j] = arr[i]; // 移到右边
    }
    arr[i] = pivot;
    _QuickSort_COM(arr, low, i - 1);
    _QuickSort_COM(arr, i + 1, high);
}

void QuickSort_COM(vector<int> &arr)
{
    _QuickSort_COM(arr, 0, arr.size() - 1);
}
// 随机优化
void _QuickSort_OPT(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int i = low, j = high;
    int pivot = low + rand() % (high - low);
    int temp = pivot;
    pivot = arr[pivot];
    arr[temp] = arr[0];
    arr[0] = pivot;
    while (i < j)
    {
        // 找到第一个比基准小的
        while (i < j && arr[j] >= pivot)
            --j;
        arr[i] = arr[j]; // 移到左边
        // 找到第一个比基准大的
        while (i < j && arr[i] <= pivot)
            ++i;
        arr[j] = arr[i]; // 移到右边
    }
    arr[i] = pivot;
    _QuickSort_OPT(arr, low, i - 1);
    _QuickSort_OPT(arr, i + 1, high);
}

void QuickSort_OPT(vector<int> &arr)
{
    _QuickSort_OPT(arr, 0, arr.size() - 1);
}
int main()

{
    // SortTest::testSort(QuickSort, 1e5, false);

    // SortTest::testSort(QuickSort_COM, 1e6, false);

    // SortTest::testSort(QuickSort_OPT, 1e2, true);
    vector<int> arr;
    for (int i = 0; i < 1e5; i++)
        arr.push_back(i);
    cout << "time:" << calculate_execution_time(QuickSort_COM, arr) << " ms" << endl;
    return 0;
}