#include <iostream>
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