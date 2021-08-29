// int main(){
// {
//     int a[10];
//     cout <<”enter the elements of the array\n”;
//     for (int i = 0; i < 10; i++)
//         cin >> a[i];

//     return 0;
// }
// Complete the code such that the even and odd numbers from the array
// ‘a’ are stored into two different arrays.
// The size of these arrays should be same as that of the number of elements
// and their memory should be de - allocated after displaying the odd and even numbers.

#include <iostream>
using namespace std;

int main()
{
    int a[10], count_odd = 0, count_even = 0;
    cout << "\nEnter elements:\n";
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
        {
            count_even++;
        }
        else
        {
            count_odd++;
        }
    }

    int *arr_even = new int(count_even);
    int *arr_odd = new int(count_odd);

    int j = 0, k = 0;

    for (int i = 0; i < 10; i++)
    {
        if (a[i] % 2 == 0)
        {
            arr_even[j] = a[i];
            j++;
        }

        else
        {
            arr_odd[k] = a[i];
            k++;
        }
    }

    cout << "Even elements:" << endl;
    for (int i = 0; i < count_even; i++)
    {
        cout << arr_even[i] << endl;
    }

    cout << "Odd elements:" << endl;
    for (int m = 0; m < count_odd; m++)
    {
        cout << arr_odd[m] << endl;
    }

    delete arr_even;
    delete arr_odd;
    return 0;
}