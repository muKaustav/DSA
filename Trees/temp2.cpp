#include <iostream>
#include <stdlib.h>
using namespace std;

class Student
{
public:
    int roll;
    char name[20];
    float marks[2], avg = 0, total = 0;

    void getdata()
    {
        cout << "Enter roll no: ";
        cin >> roll;

        cout << "Enter name: ";
        cin >> name;

        for (int i = 0; i < 2; i++)
        {
            cout << "Enter marks of subject " << i + 1 << ": ";
            cin >> marks[i];
        }

        cout << endl;

        total = marks[0] + marks[1];
        avg = total / 2;
    }

    float avg_calc()
    {
        return avg;
    }

    void display()
    {
        cout << "Roll no: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks[0] << " " << marks[1] << endl;
        cout << "Average: " << avg << endl;
    }
};

int main()
{

    int num;
    float total = 0;

    cout << "Enter number of students: ";
    cin >> num;

    Student s[num];

    for (int i = 0; i < num; i++)
    {
        s[i].getdata();
        total += s[i].avg_calc();
    }

    cout << "Class Average: " << total / num << endl;

    cout << "\nIndividual marks of students:\n";

    for (auto i : s)
    {
        i.display();
        cout << endl;
    }

    cout << "Above Average Students: " << endl;

    for (auto i : s)
    {
        if (i.avg_calc() >= total / num)
        {
            i.display();
            cout << endl;
        }
    }

    cout << "Below Average Students: " << endl;

    for (auto i : s)
    {
        if (i.avg_calc() <= total / num)
        {
            i.display();
            cout << endl;
        }
    }

    Student temp;

    for (int m = 0; m < num - 1; m++)
    {
        for (int n = m + 1; n < num; n++)
        {
            if (s[m].avg_calc() >= s[n].avg_calc())
            {
                temp = s[m];
                s[m] = s[n];
                s[n] = temp;
            }
        }
    }

    cout << "Student with highest marks: ";
    s[num - 1].display();

    return 0;
}