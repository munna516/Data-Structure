#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int &r = a; // This is the reference
    cout << a << " " << r << endl;
    int b = 34;
    r = b;
    cout << a << " " << r << endl;

    return 0;
}