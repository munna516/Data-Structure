#include <iostream>
using namespace std;
struct Array
{
    int A[100];
    int size;
    int length;
};
void display(struct Array ar) // Printing Elements
{
    for (int i = 0; i < ar.length; i++)
    {
        cout << ar.A[i] << " ";
    }
    cout << endl;
}
void Append(struct Array *ar, int value) // Add new element at the last index
{
    if (ar->length < ar->size)
    {

        ar->A[ar->length] = value;
        ar->length++;
    }
}
void Inset(struct Array *ar, int index, int value) // inserting a new element
{
    if (index >= 0 && index < ar->length)
    {
        for (int i = ar->length; i >= index; i--)
        {
            ar->A[i] = ar->A[i - 1];
        }
        ar->A[index] = value;
        ar->length++;
    }
}
void Delete(struct Array *ar, int index) // Deleting an element from any index
{
    int x = 0;
    x = ar->A[index];
    for (int i = index; i < ar->length; i++)
    {
        ar->A[i] = ar->A[i + 1];
    }
    ar->length--;
}
int Linear_Search(struct Array ar, int value) // Searching Elements
{
    for (int i = 0; i < ar.length; i++)
    {
        if (ar.A[i] == value)
        {
            return i;
        }
    }
    return -1;
}
int Binary_Search(struct Array ar, int value) // Searching Elements
{
    int l = 0, h = ar.length - 1, mid;
    while (l <= h)
    {
        mid = (h + l) / 2;
        if (value == ar.A[mid])
            return mid;
        else if (value > ar.A[mid])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}
int Get(struct Array ar, int index) // Get value from Index
{
    if (index >= 0 && index < ar.length)
    {
        return ar.A[index];
    }
    return -1;
}
void Set(struct Array *ar, int index, int value) // Set a new value at a index
{
    int y = 0;

    if (index >= 0 && index < ar->length)
    {
        ar->A[index] = value;
    }
}
int Max(struct Array ar) // Maximum value of the array
{
    int max = ar.A[0];
    for (int i = 1; i < ar.length; i++)
    {
        if (ar.A[i] > max)
            max = ar.A[i];
    }
    return max;
}
int Min(struct Array ar) // Minimum Value of the array
{
    int min = ar.A[0];
    for (int i = 1; i < ar.length; i++)
    {
        if (ar.A[i] < min)
            min = ar.A[i];
    }
    return min;
}
int Sum(struct Array ar) // Sum of the array
{
    int sum = 0;
    for (int i = 0; i < ar.length; i++)
        sum += ar.A[i];
    return sum;
}
float Avg(struct Array ar) // Average of the array
{
    return (float)Sum(ar) / ar.length;
}
int main()
{
    struct Array ar = {{1, 2, 3, 4, 5, 6}, 20, 6};
    cout << "Printing Array Element : ";
    display(ar);
    cout << "Appending an Element : ";
    Append(&ar, 10);
    display(ar);
    cout << "Inserting a value in an index : ";
    Inset(&ar, 2, 100);
    display(ar);
    cout << "Deleting a value from an index : ";
    Delete(&ar, 2);
    display(ar);
    cout << "Value found in index(Linear Search : ) : " << Linear_Search(ar, 4) << endl;
    cout << "Value found in index(Binary Search : ) : " << Binary_Search(ar, 2) << endl;
    cout << "In given index value is : " << Get(ar, 3) << endl;
    cout << "Set a new value in an index : ";
    Set(&ar, 3, 9);
    display(ar);
    cout << "Maximum Value of the Array : " << Max(ar) << endl;
    cout << "Minimum Value of the Array : " << Min(ar) << endl;
    cout << "Sum of the Array is : " << Sum(ar) << endl;
    cout << "Average of the Array is : " << Avg(ar) << endl;
    return 0;
}