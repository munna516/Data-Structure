#include <iostream>
using namespace std;
int add(int a, int b) // Formal Perameter
{
    int c;
    c = a + b;
    return c;
}
int main()
{
    int x = 10, y = 20, sum;
    sum = add(x, y); // Actual Perameter
    cout << sum << endl;

    return 0;
}