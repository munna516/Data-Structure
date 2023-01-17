#include <bits/stdc++.h>
using namespace std;
void swap(int a, int b) // call by vlaue
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void swapp(int *a, int *b) // call by address
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void ref(int &a, int &b) // call by reference
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    int x = 10, y = 15;
    swap(x, y); // call by value
    cout << "Swapping Call by Value is : " << x << " " << y << endl;
    swapp(&x, &y); // Call by address
    cout << "Swapping Call by Address is : " << x << " " << y << endl;
    ref(x, y); // call by reference
    cout << "Swapping call by reference is : " << x << " " << y << endl;

    return 0;
}