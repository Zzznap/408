#include <bits/stdc++.h>

using namespace std;

template <typename Iterator>
// 插入排序
void InsertionSort(Iterator begin, Iterator end)
{
    if (begin == end)
        return;
    for (auto i = begin + 1; i != end; i++)
    {
        if (*i >= *(i - 1))
            continue;
        auto temp = *i;
        auto j = i - 1;
        while (j >= begin && *j > temp)
        {
            *(j + 1) = *j;
            j--;
        }
        *(j + 1) = temp;
    }
}
// 直接插入排序（带哨兵）
// 不用判断是否大于0
template <typename Iterator>
void InsertSort(Iterator begin, Iterator end)
{
    if (begin == end)
        return;
    auto i = begin, j = begin;
    for (i = begin + 2; i != end; ++i)
    {
        if (*i < *(i - 1))
        {
            *begin = *i;
            for (j = i - 1; *j > *begin; --j)
                *(j + 1) = *j; // 向后移动
            *(j + 1) = *begin;
        }
    }
}
template <typename Iterator>
void InsertSort_OPT(Iterator begin, Iterator end)
{
    if (begin == end)
        return;
    for (auto i = begin + 1; i != end; i++)
    {
        if (*i >= *(i - 1))
            continue;
        auto temp = *i;
        auto j = i - 1;
        auto high = j, low = begin;
        while (high >= low)
        {
            auto mid = low + (high - low) / 2;
            if (*mid >= temp)
                low = mid + 1;
            else
                high = mid - 1;
        }
        for (auto n = i; i > low; --n)
        {
            *n = *(n - 1);
        }
        *(j + 1) = temp;
    }
}
//**********************************************************************
template <typename T>
void printArr(vector<T> arr, bool flag = true)
{
    if (flag)
    {
        for (auto i : arr)
            cout << i << " ";
        cout << endl;
    }
}
template <typename Iterator>
void testSort(void (*sort)(Iterator begin, Iterator end), int size = 1e5, bool isPrint = false)
{
    vector<int> arr;
    // 定义随机数范围
    int min_val = 1;
    int max_val = size;
    // 创建一个随机数生成器对象
    std::random_device rd;
    std::mt19937 gen(rd()); // 使用Mersenne Twister算法的随机数生成器

    clock_t rand_start, rand_end;
    rand_start = clock();
    // 创建一个分布对象，指定随机数范围
    std::uniform_int_distribution<int> dist(min_val, max_val);
    for (int i = 0; i < size; i++)
        arr.push_back(dist(gen));
    rand_end = clock();
    cout << "rand: " << (double)(rand_end - rand_start) / CLOCKS_PER_SEC << "s" << endl;
    printArr(arr, isPrint);
    // 记录时间
    clock_t start, end;
    start = clock();
    sort(arr.begin(), arr.end());
    end = clock();
    cout << "InsertionSort: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
    printArr(arr, isPrint);
    cout << endl;
}
int main()
{
    testSort(InsertionSort<vector<int>::iterator>, 1e2, true);
    return 0;
}