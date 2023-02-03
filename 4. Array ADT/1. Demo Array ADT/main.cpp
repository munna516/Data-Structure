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
int main()
{
    Array ar(100,10);
    ar.set();
    ar.display();

    return 0;
}