#include <iostream>
using namespace std;
class Array
{
public:
    int *A;
    int size;
    int length;
 /*
    void display()    // Printing Inside The Class 
    {
        for (int i = 0; i < length; i++)
            cout << A[i] << endl;
    }  
 */
};
void display(Array a)
{
    cout << "Printing Elements : " << endl;
    for (int i = 0; i < a.length; i++)
    {
        cout << a.A[i] << " ";
    }
}
int main()
{
    Array ar;
    int n;
    cout << "Enter the size of an array : ";
    cin >> ar.size;
    ar.A = new int[ar.size];
    ar.length = 0;
    cout << "Enter how many elements : ";
    cin >> n;
    ar.length = n;
    cout << "Scanning elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> ar.A[i];
    }
     display(ar);  // Calling Outside class 

    //ar.display();   // Calling Inside The class

    return 0;
}