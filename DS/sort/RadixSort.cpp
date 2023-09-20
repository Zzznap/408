#include <bits/stdc++.h>
#include <unistd.h>
#include "SortTest.h"
#include "RunningTime.h"
using namespace std;

// 定义一个计算函数执行时间的函数模板
template <typename Func, typename... Args>
long long calculate_execution_time(Func &&func, Args &&...args)
{
    auto start_time = std::chrono::high_resolution_clock::now();
    std::forward<Func>(func)(std::forward<Args>(args)...);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    return duration.count(); // 返回执行时间（微妙）
}
int GetMax(const vector<int>& arr)
{
    int max = INT_MIN;
    for (auto i : arr)
        max = i > max ? i : max;
    return max;
}
int GetMaxLen(int a)
{
    int i = 0;
    while (a > 0)
    {
        a /= 10;
        ++i;
    }
    return i;
}
// 队列实现
void RadixSort(vector<int> &arr)
{
    queue<int> qa[10];
    int maxLen = GetMaxLen(GetMax(arr));
    int mod = 1;
    for (int i = 0; i < maxLen; ++i)
    {
        for (int j : arr)
        {
            int index_temp = (j / mod) % 10;
            qa[index_temp].push(j);
        }
        int index = 0;
        for (auto & j : qa)
        {
            while (!j.empty())
            {
                arr[index++] = j.front();
                j.pop();
            }
        }
        mod *= 10;
    }
}
// 非队列实现
void RadixSort_NOQUE(vector<int> &arr)
{
    // 辅助数组
    vector<int> arr2;
    arr2.resize(arr.size(), 0);
    int maxLen = GetMaxLen(GetMax(arr));
    int mod = 1;
    for (int i = 0; i < maxLen; ++i)
    {
        int count[10] = {0};

        for (int j : arr)
        {
            ++count[(j / mod) % 10];
        }
        // 对应位数在数组中的位置
        for (int j = 1; j < 10; ++j)
            count[j] += count[j - 1];
        for (int j = arr.size()-1; j >=0;--j)
        {
            int index = (arr[j] / mod) % 10;
            arr2[count[index]-1] = arr[j];
            --count[index];
        }
        arr = arr2;
        mod *= 10;
    }
}
void PrintVector(const vector<int>& arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr;
    for (int i = 0; i < 1e7; ++i)
    {
        arr.push_back(rand() % 100);
    }
    // RadixSort(arr);
    // PrintVector(arr);
    int size = 1e7;
//    SortTest::testSort(RadixSort, size, false);
//    SortTest::testSort(RadixSort_NOQUE, size, false);
//     cout << "time:" << calculate_execution_time(RadixSort, arr) << " ms" << endl;
    return 0;
}