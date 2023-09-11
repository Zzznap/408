#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string s = "1+2+3+(3-2+3*(2/3))";
    vector<char> op;
    vector<int> numb;
    int i = 0;
    stack<int> num;
    num.push(413251);
    cout << num.top();
}