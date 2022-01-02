#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void reverseArr(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
        swap(arr[i], arr[size - i - 1]);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int size = sizeof(arr) / sizeof(arr[0]);

    reverseArr(arr, size);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}
