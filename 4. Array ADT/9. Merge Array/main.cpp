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
Array *Merge(Array *arr1, Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3;
    arr3 = new Array[sizeof(Array)];
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 20;
    return arr3;
}
int main()
{
    Array ar1 = {{1, 5, 8, 10, 16}, 20, 5};
    Array ar2 = {{2, 3, 4, 6, 9}, 20, 5};
    Array *ar3;
    ar3 = Merge(&ar1, &ar2);
    display(*ar3);

    return 0;
}