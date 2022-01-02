#include <bits/stdc++.h>
using namespace std;

pair<int, int> minmax(int a[], int size)
{
    int min = a[0];
    int max = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] < min)
            min = a[i];

        if (a[i] > max)
            max = a[i];
    }
    
    return make_pair(min, max);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(a) / sizeof(a[0]);

    pair<int, int> p = minmax(a, size);

    cout << p.first << " " << p.second;

    return 0;
}