// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
	int subarraysDivByK(vector<int> &A, int k)
	{
		int n = A.size();
		int s = 0;

		int r[k];
		memset(r, 0, sizeof(r));
		r[0] = 1;

		for (int i = 0; i < n; i++)
		{
			s += A[i];
			r[(s % k + k) % k]++;
		}

		int totalsubs = 0;
		for (int i = 0; i < k; i++)
			totalsubs += (r[i] * (r[i] - 1)) / 2;
		return totalsubs;
	}
};

// { Driver Code Starts.
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> nums(n);
		for (int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.DivisibleByM(nums, k);
		cout << ans << "\n";
	}
	return 0;
} // } Driver Code Ends