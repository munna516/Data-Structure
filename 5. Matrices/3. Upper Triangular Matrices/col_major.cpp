#include <bits/stdc++.h>
using namespace std;
class UpperTriangle
{
private:
    int *A;
    int n;

public:
    UpperTriangle(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    ~UpperTriangle()
    {
        delete[] A;
    }
    void Set(int row, int col, int value);
    int Get(int row, int col);
    void Display();
};
void UpperTriangle::Display()
{
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            if (col >= row)
                cout << A[col * (col - 1) / 2 + (row - 1)] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
void UpperTriangle::Set(int row, int col, int value)
{
    if (col >= row)
    {
        A[col * (col - 1) / 2 + (row - 1)] = value;
    }
}
int UpperTriangle::Get(int row, int col)
{
    if (col >= row)
        return A[col * (col - 1) / 2 + (row - 1)];
    else
        return 0;
}
int main()
{
    int a, x;
    cout << "Enter The Dimension : ";
    cin >> a;
    UpperTriangle m(a);
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= a; j++)
        {
            cin >> x;
            m.Set(i, j, x);
        }
    }
    cout << endl;
    m.Display();
    return 0;
}