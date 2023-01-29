/*Improving Linear Search using Transposition &  Move to Front */

#include <iostream>
using namespace std;
class Array
{
public:
    int A[100];
    int size;
    int length;
};
void display(Array *ar)
{
    for (int i = 0; i < ar->length; i++)
    {
        cout << ar->A[i] << " ";
    }
    cout << endl;
}
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int LinearSearch(Array *ar, int Key)
{
    for (int i = 0; i < ar->length; i++)
    {
        if (ar->A[i] == Key)
        {
            swap(ar->A[i], ar->A[i - 1]);
            /* For move in front/Head swap(ar->A[i],ar->A[i-1]) */
            return i;
        }
    }
    return -1;
}
int main()
{
    Array ar = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 20, 10};
    cout << "Element Found in Index : " << LinearSearch(&ar, 4) << endl;
    display(&ar);

    return 0;
}