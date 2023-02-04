/* Improving Linear Search */
#include <bits/stdc++.h>
using namespace std;
class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);

public:
    Array(int sz, int len)
    {
        size = sz;
        length = len;
        A = new int[sz];
    }
    ~Array()
    {
        delete[] A;
    }
    void display();
    void Set();
    void Insert(int index, int value);
    int LinearSearch(int value);
};
void Array::display()
{
    cout << "Printing Elements : " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
void Array::swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void Array::Set()
{
    for (int i = 0; i < length; i++)
    {
        A[i] = i + 1;
    }
}
void Array::Insert(int index, int value)
{
    if (index >= 0 && index < length)
    {
        for (int i = length - 1; i >= index; i--)
        {
            A[i + 1] = A[i];
        }
        A[index] = value;
        length++;
    }
}
int Array::LinearSearch(int value)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == value)
        {
            swap(&A[i], &A[0]);
            return i;
        }
    }
    return -1;
}
int main()
{
    Array ar(100, 6);
    ar.Set();
    ar.Insert(4, 500);
    int x = ar.LinearSearch(4);
    cout << "Value find in Index : " << x << endl;
    ar.display();

    return 0;
}