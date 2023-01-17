#include <bits/stdc++.h>
using namespace std;
struct student
{
    int roll;
    char name[25];
    char add[30];
};
// Structure variable can also declareable as a global variable
int main()
{
    struct student s = {25, "Munna", "Ghatail"}; // declare + initialization
    struct student s1;
    cout << s.roll << " " << s.name << " " << s.add << endl;
    s.roll = 26;
    strcpy(s.name, "Anik");
    strcpy(s.add, "Tangail");
    s1 = s;
    cout << s1.roll << " " << s1.name << " " << s1.add << endl;

    return 0;
}