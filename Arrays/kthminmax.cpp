#include <bits/stdc++.h>
using namespace std;

pair<int, int> kthminmax(int arr[], int size, int k)
{
    sort(arr, arr + size);
    return make_pair(arr[k - 1], arr[size - k - 1]);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(a) / sizeof(a[0]);

    pair<int, int> ans = kthminmax(a, size, 3);

    cout << ans.first << " " << ans.second << endl;

    return 0;
}