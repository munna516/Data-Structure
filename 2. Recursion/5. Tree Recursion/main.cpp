#include<bits/stdc++.h>
using namespace std;
void fun(int x)
{
    if (x > 0)
    {
        cout << x << " ";
        fun(x - 1);
        fun(x - 1);
    }
}
int main()
{
    int r = 3;
    fun(r);
    return 0;
}
/* Indirect Recursion has more than one function & it called each other circular fashion*/