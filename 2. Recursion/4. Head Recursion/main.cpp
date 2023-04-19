#include<bits/stdc++.h>
using namespace std;
void fun(int x)
{
    if (x > 0)
    {
        fun(x - 1);
        cout << x << " ";
    }
}
int main()
{
    int x = 3;
    fun(x);

    return 0;
}

/*if a recursive function call itself at first & it has some more instrction
after the recursive call then it is Head Recursion
It has only recursive phase
 */