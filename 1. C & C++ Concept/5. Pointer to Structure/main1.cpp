#include <bits/stdc++.h>
using namespace std;
struct area
{
    int height;
    int base;
    char name[30];
};
struct area r;
int main()
{
    r = {10, 2};
    strcpy(r.name, "Rectangular");
    cout << r.base << " " << r.height << " " << r.name << endl;
    struct area *p;
    p = &r;
    cout << p->height << " " << p->base << " " << p->name << endl;
    p->base = 30;
    p->height = 56;
    strcpy(p->name, "Triangle");
    cout << p->height << " " << p->base << " " << p->name << endl;

    return 0;
}