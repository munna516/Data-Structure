// Check the Array is Sorted
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
int IsSort(Array ar)
{
    for (int i = 0; i < ar.length - 1; i++)
    {
        if (ar.A[i] > ar.A[i + 1])
            return 0;
    }
    return 1;
}
int main()
{
    Array ar = {{1, 3, 5, 7, 9, 11, 13, 15}, 20, 8};
    cout << IsSort(ar) << endl;
    display(ar);
    return 0;
}