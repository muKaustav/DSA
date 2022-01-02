#include <bits/stdc++.h>
using namespace std;

int minMovesToSeat(vector<int> &seats, vector<int> &students)
{
    sort(students.begin(), students.end());
    sort(seats.begin(), seats.end());

    int ans = 0;

    for (int i = 0; i < students.size(); i++)
        ans += abs(students[i] - seats[i]);

    return ans;
}

int main()
{

    return 0;
}