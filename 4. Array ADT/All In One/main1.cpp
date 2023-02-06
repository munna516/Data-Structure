#include <iostream>
using namespace std;
struct Array
{
    int A[100];
    int size;
    int length;
};
void Swap(int *x, int *y) // Swapping Two elements
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
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
void Reverse1(struct Array *ar) // Reversing The Array (method 1)
{
    int *B;
    B = new int[ar->length];
    for (int i = ar->length - 1, j = 0; i >= 0; i--, j++)
        B[j] = ar->A[i];
    for (int i = 0; i < ar->length; i++)
    {
        ar->A[i] = B[i];
    }
}
void Reverse2(struct Array *ar) // Reverse an Array (method 2)
{
    for (int i = 0, j = ar->length - 1; i < j; i++, j--)
    {
        Swap(&ar->A[i], &ar->A[j]);
    }
}
void InsertSort(struct Array *ar, int value) // Inserting An element of sorted Array
{
    int i = ar->length - 1;
    if (ar->length == ar->size)
        return;
    while (i >= 0 && ar->A[i] > value)
    {
        ar->A[i + 1] = ar->A[i];
        --i;
    }
    ar->A[i + 1] = value;
    ar->length++;
}
bool isSort(struct Array ar) // Checking Element is sort or not
{
    for (int i = 0; i < ar.length - 1; i++)
    {
        if (ar.A[i] > ar.A[i + 1])
            return false;
    }
    return true;
}
void Rearrange(Array *ar) // Rearranging Array
{
    int i = 0;
    int j = ar->length - 1;
    while (i < j)
    {
        while (ar->A[i] < 0)
        {
            i++;
        }
        while (ar->A[j] >= 0)
        {
            j--;
        }
        if (i < j)
            Swap(&ar->A[i], &ar->A[j]);
    }
}
struct Array *Merge(Array *arr1, Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3;
    arr3 = new Array[sizeof(Array)];
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 20;
    return arr3;
}
int main()
{
    struct Array ar = {{1, 6, 7, 9, 10}, 20, 5};
    struct Array ar2 = {{2, 3, 4, 5, 8}, 20, 5};
    struct Array *ar3 = Merge(&ar, &ar2);
    display(*ar3);

    cout << "Printing Array Element : ";
    display(ar);

    cout << "Appending an Element : ";
    Append(&ar, 11);
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
    Set(&ar, 2, 3);
    display(ar);

    cout << "Maximum Value of the Array : " << Max(ar) << endl;
    cout << "Minimum Value of the Array : " << Min(ar) << endl;
    cout << "Sum of the Array is : " << Sum(ar) << endl;
    cout << "Average of the Array is : " << Avg(ar) << endl;

    cout << "Inserting a new Element of Sorted Array : ";
    InsertSort(&ar, 8);
    display(ar);

    cout << "Check the Array is Sorted or not : " << boolalpha << isSort(ar) << endl;
    cout << "Reversing the Array : ";
    Reverse1(&ar);
    display(ar);
    
    return 0;
}