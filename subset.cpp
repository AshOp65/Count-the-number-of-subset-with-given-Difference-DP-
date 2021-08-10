#include <bits/stdc++.h>
using namespace std;
int t[1003][1003];
int difference(int arr[], int n, int d)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int s = (d + sum) / 2;

    int t[n + 1][s + 1];
    for (int i = 0; i <= n; i++)
        t[i][0] = 1;
    for (int i = 1; i <= s; i++)
        t[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][s];
}
int main()
{
    int n, d;
    cin >> n >> d;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << difference(arr, n, d);
    return 0;
}