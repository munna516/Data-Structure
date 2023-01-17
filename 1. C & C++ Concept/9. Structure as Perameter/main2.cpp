#include <iostream>
using namespace std;
struct Rectangle
{
    int length[5];
    int breadth;
};
void funn(struct Rectangle x)
{
    cout << "Call By Value : " << endl;
    cout << "Length : " << x.length[0] << " " << x.length[1] << " " << x.length[2] << " " << x.length[3] << " " << x.length[4] << " "
         << "     Breadth : " << x.breadth << endl;
    cout << endl;
}
void fun(struct Rectangle *x)
{
    cout << "Call By Address : " << endl;
    cout << "Length : " << x->length[0] << " " << x->length[1] << " " << x->length[2] << " " << x->length[3] << " " << x->length[4] << " "
         << "     Breadth : " << x->breadth << endl;
    cout << endl;
}
int main()
{
    struct Rectangle r1 = {{1, 2, 3, 4, 5}, 8};
    funn(r1); // Call by value
    struct Rectangle r = {{10, 20, 30, 40, 50}, 7};
    fun(&r); // call by address

    return 0;
}