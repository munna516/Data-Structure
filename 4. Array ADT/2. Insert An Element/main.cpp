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
void Append(Array *a, int x)
{
    if (a->length < a->size)
        a->A[a->length++] = x;
}
int main()
{
    Array ar = {{1, 2, 3, 4, 5}, 20, 5};
    Append(&ar, 16);
    display(ar);
    return 0;
}