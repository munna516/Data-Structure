#include <iostream>
using namespace std;
struct rectangle
{
    int length;
    int breadth;
};
void initialize(struct rectangle *r, int l, int b)
{
    r->length = l;
    r->breadth = b;
}
int area(struct rectangle x)
{
    return x.length * x.breadth;
}
void change_value(struct rectangle *p, int l)
{
    p->length = l;
}
int main()
{
    struct rectangle r;
    initialize(&r, 10, 5);
    int y = area(r);
    change_value(&r, 20);
    cout << "Length  : " << r.length << " "
         << " Breadth : " << r.breadth << endl;
    return 0;
}