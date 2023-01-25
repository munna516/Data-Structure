#include <iostream>
using namespace std;
double e(int x, int n)
{
    static double res;

    if (n == 0)
        return res;
    res = 1 + res * x / n;
    return e(x, n - 1);
}
int main()
{
    cout << e(1, 10) << endl;

    return 0;
}