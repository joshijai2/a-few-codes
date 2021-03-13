#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
        vector<int> v, span(n,1);
        stack<int> s;
        for(int i=0; i<n; i++){
            while(s.size()>0 && price[s.top()]<=price[i])
                s.pop();
            if(s.size()==0)
                v.push_back(-1);
            else
                v.push_back(s.top());
            s.push(i);
        }
        for(int i=0;i<n;i++){
            span[i]=i-v[i];
        }
        return span;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}