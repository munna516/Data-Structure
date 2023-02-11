#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Finding Multiple Missing elements
    int sum = 0;
    int A[] = {4, 5, 6, 8, 9, 10, 11, 12, 15, 16};
    int diff = A[0];
    cout << "Missing Elements are : ";
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        if (A[i] - i != diff)
        {
            while (diff < A[i] - i)
            {
                cout << diff + i << " ";
                diff++;
            }
        }
    }
    cout << endl;
    // Reduce time complixiety method
    int l = 1, h = 12, n = 10;
    int B[]{3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    int *C = new int[n];
    for (int i = 0; i < n; i++)
    {
        C[B[i]]++;
    }
    cout << "Missing Elements are : ";
    for (int i = l; i <= h; i++)
    {
        if (C[i] == 0)
            cout << i << " ";
    }

    return 0;
}