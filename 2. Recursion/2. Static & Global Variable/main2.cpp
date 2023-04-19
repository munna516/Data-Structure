#include<bits/stdc++.h>
using namespace std;
int fun(int a)
{
    static int x = 0;
    if (a > 0)
    {
        ++x;
        return fun(a - 1) + x;
    }
    return 0;
}
int main()
{
    int r = 5;
    cout << fun(r) << endl;

    return 0;
}