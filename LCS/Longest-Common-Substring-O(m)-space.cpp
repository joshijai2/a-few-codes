// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        int dp[m + 1];
        memset(dp, 0, sizeof dp);

        int c = 0;

        for (int i = n - 1; i >= 0; i--)
            for (int j = 0; j < m; j++)
            {
                if (S1[i] == S2[j])
                    dp[j] = 1 + dp[j + 1];
                else
                    dp[j] = 0;

                c = max(c, dp[j]);
            }
        return c;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends