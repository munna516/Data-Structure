#include <iostream>
using namespace std;
int main()
{
    // using Loop  **Time Complexity O(n^2)
    int A[]{3, 4, 1, 6, 4, 9, 8, 5, 6, 2, 9, 8, 5, 6, 4, 8, 11};
    int n = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < n - 1; i++)
    {
        int count = 1;
        if (A[i] != -1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (A[j] == A[i])
                {
                    count++;
                    A[j] = -1;
                }
            }
        }
        if (count > 1)
            cout << A[i] << " Appeares in " << count << " times" << endl;
    }
    cout << endl;


    // Using Hash Table **(Time Complexity O(n))
    cout << "Hashing Method : " << endl;
    int B[50]{0};
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