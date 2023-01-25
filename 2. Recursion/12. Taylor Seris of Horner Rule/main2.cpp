#include <iostream>
using namespace std;
double e(int x, int n)
{
    double s = 1;
    int i;
    double nume = 1;
    double deno = 1;
    for (i = 1; i <= n; i++)
    {
        nume *= x;
        deno *= i;
        s += nume / deno;
    }
    return s;
}
int main()
{
    cout << e(1, 10) << endl;

    return 0;
}