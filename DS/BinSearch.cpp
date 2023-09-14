#include <iostream>
#include <time.h>
using namespace std;

// 产生一个随机顺序数组
void generateArray(int *arr, int length)
{
    srand((unsigned)time(NULL));
    int count = 0;
    for (int i = 0; i < INT_MAX; i++)
    {
        if (rand() * 1.0 / RAND_MAX < 0.5)
        {
            arr[count] = i;
            count++;
        }

        if (count == length)
            break;
    }
}

// 二分查找
int binSearch(int *arr, int length, int target)
{
    int left = 0, right = length - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int main()
{
    int length = 1e8;
    int *arr = new int[length];
    cout << "generateArray start" << endl;
    generateArray(arr, length);
    cout << "generateArray end" << endl;
    int target = arr[rand() % length];

    // 计时
    clock_t start, end;
    start = clock();
    int index = binSearch(arr, length, target);
    end = clock();
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
    cout << "index: " << index << endl;
    cout << "numb: " << arr[index < length - 1 ? 0 : index] << endl;
    delete[] arr;
}
