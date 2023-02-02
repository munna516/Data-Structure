#include <bits/stdc++.h>
using namespace std;
class Array
{
public:
    int A[100];
    int size;
    int length;
};
void display(Array ar) // Displaying The elements
{
    for (int i = 0; i < ar.length; i++)
    {
        cout << ar.A[i] << " ";
    }
    cout << endl;
}
int Get(Array ar, int index)
{
    if (index >= 0 && index < ar.length)
    {
        return ar.A[index];
    }
}
void Set(Array *ar, int index, int x)
{
    if (index >= 0 && index < ar->length)
    {
        ar->A[index] = x;
    }
}
int Max(Array ar)
{
    int max = ar.A[0];
    for (int i = 1; i < ar.length; i++)
    {
        if (ar.A[i] > max)
            max = ar.A[i];
    }
    return max;
}
int min(Array ar)
{
    int min = ar.A[0];
    for (int i = 1; i < ar.length; i++)
    {
        if (ar.A[i] < min)
            min = ar.A[i];
    }
    return min;
}
int Sum(Array ar)
{
    int total = 0;
    for (int i = 0; i < ar.length; i++)
    {
        total += ar.A[i];
    }
    return total;
}
int main()
{
    Array ar = {{1, 9, 2, 5, 8, 15, 14, 12, 3, 5, 7}, 100, 11};
    cout << "The Value at index " << 7 << " : " << Get(ar, 7) << endl;
    cout << "Setting New Value :  " << endl;
    Set(&ar, 5, 100);
    display(ar);
    cout << "Maximum value of this Array : " << Max(ar) << endl;
    cout << "Minimun value of this Array : " << min(ar) << endl;
    int total = Sum(ar);
    cout << "Summation of the array : " << total << endl;
    cout << "Average of the Array : " << (double)total / (ar.length) << endl;

    return 0;
}