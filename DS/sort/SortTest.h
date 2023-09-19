#ifndef TestSort
#define TestSort
#pragma once

#include <vector>
#include <random>
#include <iostream>
#include <time.h>
class SortTest
{
public:
    static void testSort(void (*sort)(std::vector<int> &arr), int size = 1e5, bool isPrint = false)
    {
        std::vector<int> arr;
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
        std::cout << "rand: " << (double)(rand_end - rand_start) / CLOCKS_PER_SEC << "s" << std::endl;
        printArr(arr, isPrint);
        // 记录时间
        clock_t start, end;
        start = clock();
        sort(arr);
        end = clock();
        std::cout << "Sort: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;
        printArr(arr, isPrint);
        std::cout << std::endl;
    }
    static void printArr(std::vector<int> arr, bool flag = true)
    {
        if (flag)
        {
            for (auto i : arr)
                std::cout << i << " ";
            std::cout << std::endl;
        }
    }
};

#endif