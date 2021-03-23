// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
	int DivisibleByM(vector<int> nums, int m)
	{
		int n = nums.size();
		if (n > m)
			return 1;

		int s = nums[0];

		int r[m];
		memset(r, 0, sizeof(r));
		r[s % m]++;

		for (int i = 0; i < n; i++)
		{
			s += nums[i];
			if (r[s % m])
				return 1;
			else
				r[s % m]++;
		}
		return 0;
	}
};

// { Driver Code Starts.
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> nums(n);
		for (int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.DivisibleByM(nums, m);
		cout << ans << "\n";
	}
	return 0;
} // } Driver Code Ends