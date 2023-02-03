#include <bits/stdc++.h>
using namespace std;
class Array
{
private:
    int *A;
    int size;
    int length;

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
            return i;
    }
    return -1;
}
int main()
{
    Array ar(100, 6);
    ar.Set();
    ar.Insert(4, 500);
    ar.display();
    int x = ar.LinearSearch(30);
    if (x > 0)
        cout << "Value find in Index : " << x << endl;
    else
        cout << "Value Not Found In the Array" << endl;
    return 0;
}