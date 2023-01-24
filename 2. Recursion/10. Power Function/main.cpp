#include <iostream>
using namespace std;
int power1(int m, int n)
{
    if (n == 0)
        return 1;
    else
        return power1(m, n - 1) * m;
}
int power2(int m, int n)  // reduce multiplication method
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return power2(m * m, n / 2);
    else
        return m * power2(m * m, (n - 1) / 2);
}
int main()
{
    int x = power1(2, 3);
    cout << x << endl;
    cout << power2(2, 9) << endl;

    return 0;
}