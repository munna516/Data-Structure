#include <iostream>
using namespace std;
void fun(int x)
{
    if (x > 0)
    {
        cout << x << " ";
        fun(x - 1);
    }
}
int main()
{
    int x = 3;
    fun(x);

    return 0;
}

/*If a recursive call in a function is the last statement then it is tail recursion
It has only calling Phase do not have any returning phase.
It is more efficient to write a loop through tail recursion
 */