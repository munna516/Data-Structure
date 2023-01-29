#include <iostream>
using namespace std;
class Array
{
public:
    int A[20];
    int size;
    int length;
};
void display(Array *a)
{
    for (int i = 0; i < a->length; i++)
    {
        cout << a->A[i] << " ";
    }
    cout << endl;
}
int Delete(Array *a, int index)
{
    int x = 0;
    x = a->A[index];
    if (index >= 0 && index < a->length)
    {
        for (int i = index; i < a->length - 1; i++)
        {
            a->A[i] = a->A[i + 1];
        }
        a->length--;
        return x;
    }
}
int main()
{
    Array ar = {{1, 2, 3, 4, 5, 6, 7}, 20, 7};
    cout << "Before Deleting Element : ";
    display(&ar);
    cout << "Deleted Elements is : " << Delete(&ar, 4) << endl;
    cout << "After Deleting Element : ";
    display(&ar);

    return 0;
}