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

void solve()
{
    int n;
    cin >> n;
    vi arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
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