#include <iostream>
using namespace std;
int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return fact(n - 1) * n;
}
int nCr(int n, int r) // Using simple
{
    int neu, den;
    neu = fact(n);
    den = fact(r) * fact(n - r);
    return neu / den;
}
int NCR(int n, int r)  // Using Recursion
{
    if (n == r || r == 0)
        return 1;
    else
        return NCR(n - 1, r - 1) + NCR(n - 1, r);
}
int main()
{
    cout << nCr(5, 2) << endl;
    cout << NCR(5, 2) << endl;

    return 0;
}