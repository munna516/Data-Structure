#include <iostream>
using namespace std;
int main()
{
    // Time Complexiety O(n^2)
    int A[]{6, 3, 2, 5, 4, 7, 10, 15, 8, 9, 14};
    int k = 10;
    int n = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] + A[j] == k)
            {
                cout << A[i] << " + " << A[j] << " : " << A[i] + A[j] << endl;
            }
        }
    }
    cout << endl;

    // Time Complexiety O(n)
    int B[]{1, 7, 8, 2, 5, 4, 9, 12, 3, 6};
    int H[20]{0};
    int max = -1, k1 = 11;
    int y = sizeof(B) / sizeof(B[0]);
    for (int i = 0; i < y; i++)
    {
        H[B[i]]++;
        if (B[i] > max)
            max = B[i];
    }
    for (int i = 0; i < max; i++)
    {
        if (H[k1 - B[i]] != 0)
        {
            cout << B[i] << " + " << k1 - B[i] << " : " << k1 << endl;
        }
        H[A[i]]++;
    }
    return 0;
}