#include <iostream>
using namespace std;
int main()
{
    int n, size, index;
    cout << "Enter the Array Size : ";
    cin >> size;
    int A[size];
    cout << "Enter How many Number you want to Store : ";
    cin >> n;
    if (n <= size)
    {
        cout << "Enter the Numbers : ";
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        cout << "Enter Which Index You Want to delete : ";
        cin >> index;
        int x = 0;
        x = A[index];
        if (index >= 0 && index < n)
        {
            for (int i = index; i < n - 1; i++)
            {
                A[i] = A[i + 1];
            }
            cout << "You Delete the number : " << x << "  index : " << index << endl;
            n--;
            cout << "After Deleting An Element From Array : " << endl;
            for (int i = 0; i < n; i++)
            {
                cout << A[i] << " ";
            }
        }
        else
        {
            cout << "You Give An Invalid index." << endl;
        }
    }
    else
    {
        cout << "Your Element number Limit Exceed over Array Size." << endl;
    }

    return 0;
}