#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int *l, int *r, int nl, int nr)
{
    int i = 0, j = 0, k = 0;

    while (i < nl && j < nr)
    {
        if (l[i] < r[j])
            arr[k++] = l[i++];

        else
            arr[k++] = r[j++];
    }

    while (i < nl)
        arr[k++] = l[i++];

    while (j < nr)
        arr[k++] = r[j++];
}

void mergesort(int *arr, int n)
{
    if (n < 2)
        return;

    int mid = n / 2, *l = new int[mid], *r = new int[n - mid];

    for (int i = 0; i < mid; i++)
        l[i] = arr[i];

    for (int i = mid; i < n; i++)
        r[i - mid] = arr[i];

    mergesort(l, mid);
    mergesort(r, n - mid);
    merge(arr, l, r, mid, n - mid);

    delete[] l;
    delete[] r;
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, size);

    cout << "Sorted array is: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}