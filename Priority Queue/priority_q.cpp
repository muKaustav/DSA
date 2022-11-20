#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef vector<pii> vpii;
typedef vector<pci> vpci;
typedef vector<psi> vpsi;
typedef map<int, int> mii;
typedef unordered_map<char, int> mci;
typedef unordered_map<string, int> msi;
#define MOD 1e9 + 7
#define imax INT_MAX
#define imin INT_MIN

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

void init()
{
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void maxHeapify(vi &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(vi &arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}
void increaseKey(vi &arr, int key, int i)
{
    if (key < arr[i])
        return;

    arr[i] = key;

    while (arr[i / 2] < arr[i] && i > 0)
    {
        swap(&arr[i / 2], &arr[i]);
        i /= 2;
    }
}

void decreaseKey(vi &arr, int key, int i, int n)
{
    if (key > arr[i])
        return;

    arr[i] = key;

    while ((2 * i) + 1 <= n)
    {
        if (arr[(2 * i) + 1] > arr[(2 * i) + 2] && arr[2 * i + 1] > arr[i])
        {
            swap(&arr[(2 * i) + 1], &arr[i]);
            i = (2 * i) + 1;
        }

        if (arr[(2 * i) + 2] > arr[(2 * i) + 1] && arr[2 * i + 2] > arr[i])
        {
            swap(&arr[(2 * i) + 2], &arr[i]);
            i = (2 * i) + 2;
        }
    }
}

void insert(vi &arr, int key, int n)
{
    arr.push_back(key);

    while (arr[n / 2] < arr[n] && n > 0)
    {
        swap(&arr[n / 2], &arr[n]);
        n /= 2;
    }
}

int extractMax(vi &arr, int n)
{
    int max = arr[0];

    swap(&arr[n - 1], &arr[0]);
    maxHeapify(arr, n - 1, 0);
    arr.pop_back();

    return max;
}

int extractMin(vi &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    int max = arr[0];

    swap(&arr[n - 1], &arr[0]);
    minHeapify(arr, n - 1, 0);
    arr.pop_back();

    return max;
}

int maximum(vi &arr)
{
    return arr[0];
}

void solve()
{
    int n;
    cin >> n;
    vi arr1(n), arr2(n);

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr1[i] = arr2[i] = temp;
    }

    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr1, n, i);

    for (int i = 0; i < arr1.size(); i++)
        cout << arr1[i] << " ";

    cout << endl;

    increaseKey(arr1, 8, 4);

    for (int i = 0; i < arr1.size(); i++)
        cout << arr1[i] << " ";

    cout << endl;

    decreaseKey(arr1, 3, 2, n);

    for (int i = 0; i < arr1.size(); i++)
        cout << arr1[i] << " ";

    cout << endl;

    insert(arr1, 35, n);

    for (int i = 0; i < arr1.size(); i++)
        cout << arr1[i] << " ";

    cout << endl
         << extractMax(arr1, arr1.size());
    cout << endl
         << extractMin(arr1, arr1.size()) << endl;

    for (int i = 0; i < arr1.size(); i++)
        cout << arr1[i] << " ";
}

int main()
{
    init();

    int tc;
    cin >> tc;

    while (tc--)
        solve();

    return 0;
}