#include <iostream>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};
int main()
{
    struct Rectangle r;
    r.length = 15;
    r.breadth = 45;
    Rectangle *p = &r;

    cout << "Allocating Memory in Stack : " << endl;
    cout << p->length << endl;
    cout << p->breadth << endl;

    cout << "Allocating Memory in Heap : " << endl;
    p = new struct Rectangle();
    ///p = (Rectangle *)malloc(sizeof(int));  // in c language 
    p->length = 34;
    p->breadth = 12;
    cout << p->length << endl;
    cout << p->breadth << endl;
    free(p);

    return 0;
}