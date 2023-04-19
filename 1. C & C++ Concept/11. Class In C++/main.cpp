#include<bits/stdc++.h>
using namespace std;
class rectangle
{
private:
    int length;
    int breadth;

public:
    rectangle()
    {
        length = 0;
        breadth = 0;
    }

    rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
    int area()
    {
        return length * breadth;
    }
    int change_value(int l)
    {
        return length = l;
    }
};
int main()
{
    rectangle r(10, 5);
    cout << r.area() << endl;
    cout << r.change_value(60) << endl;
    return 0;
}