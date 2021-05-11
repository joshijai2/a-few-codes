// { Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// } Driver Code Ends
// function to find shortest common supersequence

class Solution
{
public:
    int scs(int x, int y, string s1, string s2)
    {
        int dp[2][y + 1];

        for (int i = 0; i <= x; i++)
        {
            for (int j = 0; j <= y; j++)
            {
                if (i == 0 || j == 0)
                    dp[i % 2][j] = 0;
                else if (s1[i - 1] == s2[j - 1])
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1] % mod + 1;
                else
                    dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
            }
        }
        int lcs = dp[x % 2][y];
        return x + y - lcs;
    }
};

// { Driver Code Starts.
int main()
{
    int t, n, k, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y; // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2; // Take both the string as input
        Solution ob;
        cout << ob.scs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends