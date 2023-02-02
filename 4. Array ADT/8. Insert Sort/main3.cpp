// Re-arranging The Array
#include <iostream>
using namespace std;
class Array
{
public:
    int A[20];
    int size;
    int length;
};
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void display(Array ar)
{
    cout << "Printing Elements : " << endl;
    for (int i = 0; i < ar.length; i++)
        cout << ar.A[i] << " ";
    cout << endl;
}
void Rearrange(Array *ar)
{
    int i = 0;
    int j = ar->length - 1;
    while (i < j)
    {
        while (ar->A[i] < 0)
        {
            i++;
        }
        while (ar->A[j] >= 0)
        {
            j--;
        }
        if (i < j)
            swap(&ar->A[i], &ar->A[j]);
    }
}

int main()
{
    Array ar = {{1, -3, 5, 7, -9, 11, -13, 15}, 20, 8};
    Rearrange(&ar);
    display(ar);
    return 0;
}