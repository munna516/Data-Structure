// Only the diagonal element is non-zero

#include <bits/stdc++.h>
using namespace std;
class Matrices
{
private:
    int *A;
    int n;

public:
    Matrices(int n)
    {
        this->n = n;
        A = new int[n];
    }
    ~Matrices()
    {
        delete[] A;
    }
    void Set(int row, int col, int value);
    int Get(int row, int col);
    void display();
};
void Matrices::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << A[i] << " ";
            else
                cout << "0"
                     << " ";
        }
        cout << endl;
    }
}
void Matrices::Set(int row, int col, int value)
{
    if (row == col)
        A[row - 1] = value;
}
int Matrices::Get(int row, int col)
{
    if (row == col)
        return A[row - 1]; // A[col-1];
    else
        return 0;
}
int main()
{
    Matrices m(5);
    m.Set(1, 1, 15);
    m.Set(2, 2, 10);
    m.Set(3, 3, 16);
    m.Set(4, 4, 25);
    m.Set(5, 5, 29);
    cout << m.Get(3, 3) << endl;
    m.display();
}