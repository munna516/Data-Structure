#include <iostream>
using namespace std;
class Array
{
private:
    int *A;
    int size;
    int length;

public:
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[sz];
    }
    ~Array()
    {
        delete[] A;
    }
    void display();
    // void set();
    void Insert(int index, int x);
    void Delete(int index);
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
void Array::Delete(int index)
{
    int x = 0;
    x = A[index];
    if (index >= 0 && index < length)
    {
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
    }
}
void Array::Insert(int index, int x)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length; i >= index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = x;
        length++;
    }
}
int main()
{
    Array ar(100);
    ar.Insert(0, 15);
    ar.Insert(1, 25);
    ar.Insert(2, 35);
    ar.Insert(3, 65);
    ar.display();
    ar.Delete(1);
    ar.display();

    return 0;
}