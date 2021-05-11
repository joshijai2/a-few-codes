// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        bool dp[n][n];

        memset(dp, false, sizeof dp);

        int start = 0, max_len = 1;

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
            if (i < n - 1 && s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;

                if (max_len < 2)
                {
                    max_len = 2;
                    start = i;
                }
            }
        }

        for (int k = 3; k <= n; k++)
        {
            for (int i = 0; i < n - k + 1; i++)
            {
                int j = i + k - 1;
                if ((s[i] == s[j]) && dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = true;
                    int len = j - i + 1;
                    if (max_len < len)
                    {
                        max_len = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, max_len);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.longestPalindrome(S) << endl;
    }
    return 0;
}
// } Driver Code Ends