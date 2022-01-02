#include <bits/stdc++.h>
using namespace std;

int main()
{
    // read nth character from end of file
    ifstream in("heapsort.cpp");
    string s;

    in.seekg(-2, ios::end);
    getline(in, s);

    cout << s[s.size() - 1] << endl;

    return 0;
}