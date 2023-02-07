#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Missing element is in 1 to n natural Numbers
    int sum = 0;
    int A[] = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    int x = (10 * 11) / 2;
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        sum += A[i];
    }
    cout << "Missing Element is : " << x - sum << endl;

    // If the element start at any point
    int B[] = {5, 6, 7, 8, 10, 11, 12, 13, 14, 15};
    int diff = B[0] - 0;
    for (int i = 0; i < sizeof(B) / sizeof(B[0]); i++)
    {
        if (B[i] - i != diff)
        {
            cout << "Missing Element is : " << i + diff << endl;
            break;
        }
    }
    return 0;
}