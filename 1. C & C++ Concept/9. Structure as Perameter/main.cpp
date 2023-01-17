#include <iostream>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};
void fun(struct Rectangle x)  // Structure as perameter
{
    x.length = 20;
    x.breadth = 15;
    cout << "Fun -- Length : " << x.length << " "
         << "Breadth : " << x.breadth << endl;
}
int main()
{
    struct Rectangle r = {10, 5};
    fun(r); // call by value
    cout << "Main -- Length : " << r.length << " "
         << "Breadth : " << r.breadth << endl;

    return 0;
}
// Main function & func function value will be different .