#include <iostream>
using namespace std;
class Array
{
public:
    int A[100];
    int size;
    int length;
};
void display(Array ar)
{
    for (int i = 0; i < ar.length; i++)
    {
        cout << ar.A[i] << " ";
    }
    cout << endl;
}
int LinearSearch(Array ar, int Key)
{
    for (int i = 0; i < ar.length; i++)
    {
        if (ar.A[i] == Key)
            return i;
    }
    return -1;
}
int main()
{
    Array ar = {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 20, 10};
    cout << "Element Found in Index : " << LinearSearch(ar, 7) << endl;
    display(ar);

    return 0;
}