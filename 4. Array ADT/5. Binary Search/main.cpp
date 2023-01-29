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
int Binary_Search(Array ar, int key)
{
    int l = 0, h = ar.length - 1;
    int mid;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == ar.A[mid])
            return mid;
        else if (key < ar.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int main()
{
    Array ar = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, 20, 15};
    cout << Binary_Search(ar, 11) << endl;
    display(ar);
    return 0;
}