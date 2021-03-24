#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, S;
    //vector <int> val,wt; //uncomment to use vectors instead of array
    cin >> n;
    int nums[n];
    cin >> S;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // arr.push_back(x); //uncomment to use vectors instead of array
    int sum = 0, c = 0;

    for (auto itr : nums)
    {
        sum += itr;
        if (itr == 0)
            c++;
    }

    if (sum < S || (sum - S) % 2 != 0)
        return 0;
    int s = (sum - S) / 2;

    int dp[n + 1][s + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= s; j++)
        {
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }

    cout << dp[n][s];
}