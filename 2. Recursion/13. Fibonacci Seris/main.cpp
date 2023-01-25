#include <iostream>
using namespace std;
int f[100];
int fib1(int n) // using loop
{
    int t0 = 0, t1 = 1, res = 0;
    if (n <= 1)
        return n;
    for (int i = 2; i <= n; i++)
    {
        res = t0 + t1;
        t0 = t1;
        t1 = res;
    }
    return res;
}
int fib2(int n) // using recursion
{

    if (n <= 1)
        return n;
    else
        return fib2(n - 2) + fib2(n - 1);
}
int fib3(int n) // redused time complixity
{

    if (n <= 1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if (f[n - 2] == -1)
            f[n - 2] = fib3(n - 2);
        if (f[n - 1] == -1)
            f[n - 1] = fib3(n - 1);
        return f[n - 2] + f[n - 1];
    }
}

int main()
{
    cout << fib1(6) << endl;
    cout << fib2(7) << endl;

    for (int i = 0; i < 50; i++)
    {
        f[i] = -1;
    }
    cout << fib3(8) << endl;

    return 0;
}