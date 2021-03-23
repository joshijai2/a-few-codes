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
    /**
    We can optimize space. We create a boolean 2D array subset[2][sum+1].
    Using bottom up manner we can fill up this table. The idea behind using 2 in
    “subset[2][sum+1]” is that for filling a row only the values from previous row is required.
    So alternate rows are used either making the first one as current and second as
    previous or the first as previous and second as current.
    **/
    vector<vector<bool>> t(2, vector<bool>(sum + 1, -1));
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= sum; j++)
        {
            // A subset with sum 0 is always possible
            if (j == 0)
                t[i % 2][j] = true;
            // If there exists no element no sum is possible
            else if (i == 0)
                t[i % 2][j] = false;

            else if (arr[i - 1] <= j)
                t[i % 2][j] = t[(i + 1) % 2]
                               [j - arr[i - 1]] ||
                              t[(i + 1) % 2][j];

            else
                t[i % 2][j] = t[(i + 1) % 2][j];
        }
    cout << t[n][sum] ? "YES" : "NO";
}