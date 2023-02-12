#include <iostream>
using namespace std;
int main()
{
    int A[]{4, 5, 5, 7, 8, 9, 9, 10, 11, 12, 14, 15, 15, 15, 15, 16, 17, 18, 18, 19};
    int n = sizeof(A) / sizeof(A[0]);
    int lastduplicate = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] == A[i + 1] && A[i] != lastduplicate)
        {
            cout << A[i] << " ";
            lastduplicate = A[i];
        }
    }
    cout << endl;

    // Counting Duplicate Element
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] == A[i + 1])
        {
            j = i + 1;
            while (A[j] == A[i])
                j++;
            cout << A[i] << " Appeares in " << j - i << " times" << endl;
            i = j - 1;
        }
    }

    // Using Hashtable method
    cout<<"Hashing Method :  "<<endl;
    int B[100]{0};
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        B[A[i]]++;
        if (A[i] > max)
            max = A[i];
    }
    for (int i = 0; i < max; i++)
    {
        if (B[i] > 1)
            cout << i << " Appeare in " << B[i] << " times" << endl;
    }
    return 0;
}