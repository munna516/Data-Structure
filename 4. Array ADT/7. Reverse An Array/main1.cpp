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
void Reverse(Array *ar)
{
    int *B;
    B = new int[ar->length];
    for (int i = ar->length - 1, j = 0; i >= 0; i--, j++)
        B[j] = ar->A[i];
    for (int i = 0; i < ar->length; i++)
        ar->A[i] = B[i];
}
int main()
{
    Array ar = {{1, 2, 3, 4, 5, 6, 7, 8}, 20, 8};
    Reverse(&ar);
    display(ar);
    return 0;
}