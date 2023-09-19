#include <iostream>
using namespace std;

int Index_KMP(string S, string T, int next[])
{
    int i = 1, j = 1;
    while (i <= S.length() && j < T.length())
    {
        if (j == 0 || S[i] == T[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if (j > T.length())
        return i - T.length();
    else
        return 0;
}
int *NextArray(int *next, string str2)
{
    next[0] = -1;             // 默认-1
    next[1] = 0;              // 默认0
    int cn = 0;               // 前缀的长度(前缀下一个字符的下标)以及记录next数组的值
    int i = 2;                // str2 位标从2开始
    while (i < str2.length()) // next数组正常与str2长度相同，但根据不同题目有的要多求一位
    {
        if (str2[i - 1] == str2[cn])
        {
            next[i++] = ++cn; // 相同的话next值较前一位+1
        }
        else if (cn > 0)
        {
            cn = next[cn]; // 不等的话，递归查询已经部分生成的next数组，确定较小前缀长度
        }
        else
        {
            next[i++] = 0; // cn变为0、-1的时候，该位置的next值就为0
        }
    }
    return next;
}
int main()
{
    string S, T;
    cin >> S >> T;
    int *next = new int[T.length()];
    NextArray(next, T);
    for (int i = 0; i < T.length(); i++)
    {
        cout << T[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < T.length(); i++)
    {
        cout << next[i] << " ";
    }
    delete[] next;
    return 0;
}
