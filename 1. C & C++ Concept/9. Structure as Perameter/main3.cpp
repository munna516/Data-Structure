#include <iostream>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};
struct Rectangle *fun()
{
    struct Rectangle *p;
    p = new Rectangle();  // Dynamically Allocating Memory
    p->length = 15;
    p->breadth = 9;
    return p;
}
int main()
{
    struct Rectangle *ptr = fun();
    cout << "Length : " << ptr->length << " "
         << " Breadth : " << ptr->breadth << endl;
    return 0;
}
