#include <iostream>
using namespace std;
void funB(int x);
void funA(int x)
{
    if (x > 0)
    {
        cout << x << " ";
        funB(x - 1);
    }
}
void funB(int x)
{
    if (x > 1)
    {
        cout << x << " ";
        funA(x / 2);
    }
}
int main()
{
    funA(20);

    return 0;
}