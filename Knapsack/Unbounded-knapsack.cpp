// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        int dp[W + 1];
        memset(dp, 0, sizeof dp);

        for (int j = 0; j <= W; j++)
            for (int i = 0; i < n; i++)
                if (j >= wt[i])
                    dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);

        return dp[W];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
} // } Driver Code Ends
