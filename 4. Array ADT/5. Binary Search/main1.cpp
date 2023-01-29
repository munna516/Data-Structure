#include <iostream>
using namespace std;
class Array
{
public:
    int A[20];
    int size;
    int length;
};
void display(Array ar)
{
    cout << "Printing Elements : " << endl;
    for (int i = 0; i < ar.length; i++)
        cout << ar.A[i] << " ";
    cout << endl;
}
int Binary_Search_Recursion(Array ar, int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == ar.A[mid])
            return mid;
        else if (key < ar.A[mid])
            return Binary_Search_Recursion(ar, l, mid - 1, key);
        else
            return Binary_Search_Recursion(ar, mid + 1, h, key);
    }
    return -1;
}
int main()
{
    Array ar = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, 20, 15};
    cout << Binary_Search_Recursion(ar, 0, ar.length, 13) << endl;
    display(ar);
    return 0;
}