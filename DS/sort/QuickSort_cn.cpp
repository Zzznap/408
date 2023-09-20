#include <iostream>
#include <bits/stdc++.h>
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
// 参考：http://www.dutor.net/index.php/2011/04/recursive-iterative-quick-sort/
struct Range
{
    int start, end;
    Range(int s = 0, int e = 0)
    {
        start = s, end = e;
    }
};
template <typename T> // 整數或浮點數皆可使用,若要使用物件(class)時必須設定"小於"(<)、"大於"(>)、"不小於"(>=)的運算子功能
void quick_sort(T arr[], const int len)
{
    if (len <= 0)
        return; // 避免len等於負值時宣告堆疊陣列當機
    // r[]模擬堆疊,p為數量,r[p++]為push,r[--p]為pop且取得元素
    Range r[len];
    int p = 0;
    r[p++] = Range(0, len - 1);
    while (p)
    {
        Range range = r[--p];
        if (range.start >= range.end)
            continue;
        T mid = arr[range.end];
        int left = range.start, right = range.end - 1;
        while (left < right)
        {
            while (arr[left] < mid && left < right)
                left++;
            while (arr[right] >= mid && left < right)
                right--;
            std::swap(arr[left], arr[right]);
        }
        if (arr[left] >= arr[range.end])
            std::swap(arr[left], arr[range.end]);
        else
            left++;
        r[p++] = Range(range.start, left - 1);
        r[p++] = Range(left + 1, range.end);
    }
}

int main()
{
    int size = 1e6;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand() % size;
    cout << "time:" << calculate_execution_time(quick_sort<int>, arr, size) << " ms" << endl;
    delete[] arr;
}