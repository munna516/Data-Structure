#include<bits/stdc++.h>
using namespace std;
int fun(int a)
{
    if (a > 0)
    {
        return fun(a - 1) + a;
    }
    return 0;
}
int main()
{
    int r = 5;
    cout << fun(r) << endl;

    return 0;
}