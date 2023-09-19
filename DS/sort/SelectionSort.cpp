#include <bits/stdc++.h>
#include "SortTest.h"
using namespace std;

void SelectionSort(vector<int> &arr)
{

    for (int i = 0; i < arr.size(); ++i)
    {
        int min = i;
        for (int j = i; j < arr.size(); ++j)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[i], arr[min]);
    }
}
int main()
{
    SortTest::testSort(SelectionSort, 1e2, true);
    return 0;
}