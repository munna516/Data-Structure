#include <iostream>
using namespace std;
void fun(int *A, int n)
{
    for (int i = 0; i < n; i++) // Printing value of A
        cout << *A + i << " ";
}
int *fun_1(int size) // Creating an array dynamically in Heap
{
    int *p;
    p = new int(size);
    for (int i = 0; i < size; i++)
        p[i] = i + 1;
    return p;
}
int main()
{
    int A[]{1, 2, 3, 4, 5, 6};
    int n = 6;
    fun(A, n);
    cout << endl;

    int *x, size;
    size = 7;
    x = fun_1(size);
    for (int i = 0; i < size; i++)
        cout << x[i] << endl;
    return 0;
}