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
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void Reverse2(Array *ar)
{
    for (int i = 0, j = ar->length - 1; i <= j; i++, j--)
    {
        swap(&ar->A[i], &ar->A[j]);
    }
}
int main()
{
    Array ar = {{1, 2, 3, 4, 5, 6, 7, 8}, 20, 8};
    Reverse2(&ar);
    display(ar);
    return 0;
}