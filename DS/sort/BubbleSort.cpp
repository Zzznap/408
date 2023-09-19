#include <bits/stdc++.h>
#include "SortTest.h"

using namespace std;

void BubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        bool flag = false;
        for (int j = 1; j < arr.size() - i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                flag = true;
            }
        }
        if (!flag)
            return;
    }
}

int main()
{
    SortTest::testSort(BubbleSort, 50000, false);
    return 0;
}