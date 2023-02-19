#include <iostream>
using namespace std;
class Array
{
private:
    int *A;
    int size;
    int length;

public:
    Array(int sz)
    {
        length = 0;
        size = sz;
        A = new int[sz];
    }
    ~Array()
    {
        delete[] A;
    }
    void display();
    void Insert(int index, int value);
    void Delete(int index);
    void LinearSearch(int key);
    void BinarySearch(int key);
    int BinarySearchRecursion(int low, int high, int key);
    void Get(int index);
    void Set(int index, int value);
    void Max();
    void Min();
    void Sum();
};
void Array::display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
void Array::Insert(int index, int value)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length; i >= index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = value;
        length++;
    }
}
void Array::Delete(int index)
{
    if (index >= 0 && index < length)
    {
        int x = A[index];
        for (int i = index; i < length; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
    }
}
void Array::LinearSearch(int key)
{
    int x = -1;
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            x = i;
            break;
        }
    }
    if (x >= 0)
        cout << "Linear_Search Value Found in : " << x + 1 << " index" << endl;
    else
        cout << "Value Not Found" << endl;
}
void Array::BinarySearch(int key)
{
    int l = 0, h = length - 1, mid, y = -1;
    while (l <= h)
    {
        mid = (h + l) / 2;
        if (key == A[mid])
        {
            y = mid;
            break;
        }
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    if (y >= 0)
        cout << "Binary_Search Value Found in : " << y + 1 << " index" << endl;
    else
        cout << "Value Not Found" << endl;
}
int Array::BinarySearchRecursion(int low, int high, int key)
{
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (A[mid] == key)
            return mid;
        else if (key < A[mid])
            return (low, mid - 1, key);
        else
            return (mid + 1, high, key);
    }
}
void Array::Get(int index)
{
    cout << "In index " << index << " the value is : " << A[index] << endl;
}
void Array::Set(int index, int value)
{
    int x = A[index];
    A[index] = value;
    cout << "Set the value at index " << index << " is : " << A[index] << endl;
}
void Array::Max()
{
    int max = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    cout << "Maximun Value of The arry is : " << max << endl;
}
void Array::Min()
{
    int min = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] < min)
            min = A[i];
    }
    cout << "Maximun Value of The arry is : " << min << endl;
}
void Array::Sum()
{
    int sum = 0;
    for (int i = 0; i < length; i++)
        sum += A[i];
    cout << "Sum Of the Array is : " << sum << endl;
    cout << "Average of the Array is : " << (float)sum / length << endl;
}

int main()
{
    Array ar(20);
    ar.Insert(0, 10);
    ar.Insert(1, 20);
    ar.Insert(2, 30);
    ar.Insert(3, 40);
    ar.Insert(4, 49);
    ar.Insert(5, 60);
    ar.Insert(6, 70);
    ar.display();
    ar.Delete(2);
    ar.display();
    ar.Insert(2, 30);
    ar.LinearSearch(40);
    ar.BinarySearch(600);
    ar.Get(2);
    ar.Set(4, 50);
    ar.Max();
    ar.Min();
    ar.Sum();

    return 0;
}