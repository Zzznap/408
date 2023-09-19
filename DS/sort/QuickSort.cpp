#include <bits/stdc++.h>
#include "SortTest.h"

using namespace std;

void QuickSort(vector<int> &arr, int low, int high)
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

            if (arr[high] < temp)
            {
                arr[low] = arr[high];
                ++low;
                lowEmpty = false;
            }
            else
                --high;
        }
        if (!lowEmpty)
        {

            if (arr[high] > temp)
            {
                arr[high] = arr[low];
                --high;
            }
            else
                ++low;
        }
    }
    arr[low] = temp;
    QuickSort(arr, low_temp, low - 1);
    QuickSort(arr, low + 1, high_temp);
}
void QuickSort(vector<int> &arr)
{
    QuickSort(arr, 0, arr.size() - 1);
}
int main()

{
    SortTest::testSort(QuickSort, 1e2, true);

    return 0;
}