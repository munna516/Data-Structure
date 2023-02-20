#include <bits/stdc++.h>
using namespace std;
class LowerTri
{
private:
    int *A;
    int n;

public:
    LowerTri(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    ~LowerTri()
    {
        delete[] A;
    }
    void Set(int row, int col, int value);
    int Get(int row, int col);
    void display();
};
void LowerTri::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << A[i * (i - 1) / 2 + j - 1] << " ";
            else
                cout << "0"
                     << " ";
        }
        cout << endl;
    }
}
void LowerTri::Set(int row, int col, int value)
{
    if (row >= col)
        A[row * (row - 1) / 2 + col - 1] = value;
}
int LowerTri::Get(int row, int col)
{
    if (row >= col)
        return A[row * (row - 1) / 2 + col - 1];
    else
        return 0;
}
int main()
{
    int d, x;
    cout << "Enter The Dimension : ";
    cin >> d;
    LowerTri m(d);
    cout << "Enter All The Elements : " << endl;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            m.Set(i, j, x);
        }
    }
    cout << "\n\n\n"
         << endl;

    m.display();
}