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
}
void InsertSort(Array *ar, int x)
{
    int i = ar->length - 1;
    while (i >= 0 && ar->A[i] > x)
    {
        ar->A[i + 1] = ar->A[i];
        i--;
    }
    ar->A[i+1] = x;
    ar->length++;
}
int main()
{
    Array ar = {{1, 3, 5, 7, 9, 11, 13, 15}, 20, 8};
    InsertSort(&ar, 6);
    display(ar);
    return 0;
}