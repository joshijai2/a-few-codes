// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> NGR(n);
        stack<long long> st;
    
        for (int i = 0; i < n; i--)
        {
            while (!st.empty() && st.top() <= arr[i])
                st.pop();
                
            if (!st.empty())
                NGR[i] = st.top();
                
            else
                NGR[i] = -1;
                
            st.push(arr[i]);
        }
        
        return NGR;
    }
};

// { Driver Code Startst.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends