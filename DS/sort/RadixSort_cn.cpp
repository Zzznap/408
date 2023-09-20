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
int maxbit(int data[], int n) // 辅助函数，求数据的最大位数
{
    int maxData = data[0]; ///< 最大数
    /// 先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
    for (int i = 1; i < n; ++i)
    {
        if (maxData < data[i])
            maxData = data[i];
    }
    int d = 1;
    int p = 10;
    while (maxData >= p)
    {
        // p *= 10; // Maybe overflow
        maxData /= 10;
        ++d;
    }
    return d;
    /*    int d = 1; //保存最大的位数
        int p = 10;
        for(int i = 0; i < n; ++i)
        {
            while(data[i] >= p)
            {
                p *= 10;
                ++d;
            }
        }
        return d;*/
}
void radixsort(int data[], int n) // 基数排序
{
    int d = maxbit(data, n);
    int *tmp = new int[n];
    int *count = new int[10]; // 计数器
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= d; i++) // 进行d次排序
    {
        for (j = 0; j < 10; j++)
            count[j] = 0; // 每次分配前清空计数器
        for (j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; // 统计每个桶中的记录数
            count[k]++;
        }
        for (j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; // 将tmp中的位置依次分配给每个桶
        for (j = n - 1; j >= 0; j--)            // 将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for (j = 0; j < n; j++) // 将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
    delete[] tmp;
    delete[] count;
}

int main()
{
    int size = 1e7;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand() % size;
    cout << "time:" << calculate_execution_time(radixsort, arr, size) << " ms" << endl;
    delete[] arr;
}