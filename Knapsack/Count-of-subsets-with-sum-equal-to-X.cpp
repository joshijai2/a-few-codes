#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum;
    //vector <int> val,wt; //uncomment to use vectors instead of array
    cin >> n;
    int arr[n];
    cin >> sum;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // arr.push_back(x); //uncomment to use vectors instead of array
    vector<vector<int>> t(n + 1, vector<int>(sum + 1, -1));
    for (int j = 0; j <= sum; j++)
        t[0][j] = 0;
    for (int i = 0; i <= n; i++)
        t[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                t[i][j] = (t[i - 1][j - arr[i - 1]] + t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    cout << t[n][sum];
}