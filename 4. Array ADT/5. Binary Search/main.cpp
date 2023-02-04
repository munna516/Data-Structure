#include <iostream>
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
    void set();
    int Binary_Search(int key);
};
void Array::display()
{
    cout << "Printing Elements : " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
}
void Array::set()
{
    for (int i = 0; i < 10; i++)
    {
        A[i] = i + 1;
    }
}
int Array::Binary_Search(int key)
{
    int l = 0, h = length - 1;
    int mid;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int main()
{
    Array ar(10, 8);
    ar.set();
    cout << ar.Binary_Search(4) << endl;

    ar.display();
    return 0;
}