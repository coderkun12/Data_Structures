/* 1. To print all unique elements
2.print no. of duplicate elements
3. Sum of all elements */
#include <iostream>
using namespace std;
int main()
{
    int i, j, a[100], n, sum, count1, opt;
    cout << "Enter number of elements in an array:" << endl;
    cin >> n;
    cout << "\nEnter " << n << " elements:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the task number associated with task you perform:\n1. Print unique elements\n2. Number of duplicate elements\n3. Sum of elements" << endl;
    cin >> opt;
    switch (opt)
    {
    case 1:
        cout << "\nThe list of unique elements is:" << endl;
        for (i = 0; i < n; i++)
        {
            count1 = 0;
            for (j = 0; j < n; j++)
            {
                if (a[i] == a[j] && i != j)
                {
                    count1++;
                }
            }
            if (count1 == 0)
            {
                cout << a[i] << endl;
            }
        }
        break;
    case 2:
        count1 = 0;
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (a[i] == a[j])
                {
                    count1++;
                    break;
                }
            }
        }
        cout << "The number of repeating elements are:" << count1 << endl;
        break;
    case 3:
        sum = 0;
        for (i = 0; i < n; i++)
        {
            sum = sum + a[i];
        }
        cout << "\nThe sum of elements is: " << sum;
        break;

    default:
        break;
    }
}