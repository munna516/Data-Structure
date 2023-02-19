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
    void Reverse();
    void Swap(int *x, int *y);
    void Issort();
    void InsertSort(int x);
};

// Swapping Two Elements
void Array::Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Printing Array Elements
void Array::display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Insert New Value In a Array
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

// Deleting A Value From An Array
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

// Searching Element
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

// Searching Element
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

// Searching Element Using Recursion
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

// Get The value Specific Index
void Array::Get(int index)
{
    cout << "In index " << index << " the value is : " << A[index] << endl;
}

// Set a  new Value at a index
void Array::Set(int index, int value)
{
    int x = A[index];
    A[index] = value;
    cout << "Set the value at index " << index << " is : " << A[index] << endl;
}

// Finding Max Value From An Array
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

// Finding Minimun Value From An Array
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

// Finding The sum of an Array
void Array::Sum()
{
    int sum = 0;
    for (int i = 0; i < length; i++)
        sum += A[i];
    cout << "Sum Of the Array is : " << sum << endl;
    cout << "Average of the Array is : " << (float)sum / length << endl;
}

// Reversing The Array
void Array::Reverse()
{
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        Swap(&A[i], &A[j]);
    }
}

// Check Array is Sort Or Not
void Array::Issort()
{
    int count = 0;
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            count++;
            break;
        }
    }
    if (count == 0)
        cout << "The Array is Sorted" << endl;
    else
        cout << "The Array is not Sorted" << endl;
}

// Insert a Element In a sorted Array
void Array::InsertSort(int x)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (A[i] > A[j])
                Swap(&A[i], &A[j]);
        }
    }
    int i = length - 1;
    while (i >= 0 && A[i] > x)
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}
int main()
{
    Array ar(20);
    ar.Insert(0, 10);
    ar.Insert(1, 30);
    ar.Insert(2, 60);
    ar.Insert(3, 40);
    ar.Insert(4, 49);
    ar.Insert(5, 20);
    ar.Insert(6, 70);
    ar.display();
    ar.Delete(6);
    ar.display();
    ar.LinearSearch(40);
    ar.BinarySearch(600);
    ar.Get(2);
    ar.Set(4, 50);
    ar.Max();
    ar.Min();
    ar.Sum();
    ar.Reverse();
    ar.display();
    ar.Reverse();
    ar.display();
    ar.Issort();
    ar.InsertSort(35);
    ar.display();

    return 0;
}