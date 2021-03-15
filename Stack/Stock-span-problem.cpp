#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> calculateSpan(int price[], int n)
	{
		vector<int> v;
		stack<int> s;
		for (int i = 0; i < n; i++)
		{
			while (s.size() > 0 && price[s.top()] <= price[i])
				s.pop();
			v.push_back((s.size() == 0) ? (i + 1) : (i - s.top()));
			s.push(i);
		}
		return v;
	}
};

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int i, a[n];
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		Solution obj;
		vector<int> s = obj.calculateSpan(a, n);

		for (i = 0; i < n; i++)
		{
			cout << s[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
