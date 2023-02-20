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
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            if (row >= col)
                cout << A[n * (col - 1) + (col - 2) * (col - 1) / 2 + row - col] << " ";
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
        A[n * (col - 1) + (col - 2) * (col - 1) / 2 + row - col] = value;
}
int LowerTri::Get(int row, int col)
{
    if (row >= col)
        return A[n * (col - 1) + (col - 2) * (col - 1) / 2 + row - col];
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