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
void Insert(Array *a, int index, int x)
{
    if (index >= 0 && index <= a->length)
    {
        for (int i = a->length; i >= index; i--)
        {
            a->A[i] = a->A[i - 1];
        }
        a->A[index] = x;
        a->length++;
    }
}
int main()
{
    Array ar = {{1, 2, 3, 4, 5}, 20, 4};
    Insert(&ar, 3, 19);
    display(ar);
    return 0;
}