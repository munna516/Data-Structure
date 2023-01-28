#include <iostream>
using namespace std;
int main()
{
    int A[100], n, index, value;
    cout << "Enter How many Element you store in Array : ";
    cin >> n;
    cout << "Enter the Array Elements : ";
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << endl;
    cout << "Enter Which indices you want to chose : ";
    cin >> index;
    cout << "Enter the value that you put in " << index << " index : ";
    cin >> value;
    if (index >= 0 && index <= n)
    {

        for (int i = n; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = value;
        ++n;
        cout << "Here the final Array :" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }
    }
    else
        cout << "You Enter the out of Range index" << endl;

    return 0;
}