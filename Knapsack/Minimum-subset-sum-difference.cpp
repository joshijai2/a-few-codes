// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int minDiffernce(int arr[], int n)
    {
        long sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        int s = sum / 2;

        vector<vector<bool>> t(n + 1, vector<bool>(s + 1, -1));
        for (int j = 0; j <= s; j++)
            t[0][j] = 0;
        for (int i = 0; i <= n; i++)
            t[i][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= s; j++)
            {
                if (arr[i - 1] <= j)
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j];
            }
        while (t[n][s] != 1)
            s--;
        return sum - 2 * s;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDiffernce(a, n) << "\n";
    }
    return 0;
} // } Driver Code Ends