// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next smaller element for each element of the array.
    vector<long long> nextSmallerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> NSL(n);
        stack<long long> st;
    
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top() >= arr[i])
                st.pop();
                
            if (!st.empty())
                NSL[i] = st.top();
                
            else
                NSL[i] = -1;
                
            st.push(arr[i]);
        }
        
        return NSL;
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
        vector <long long> res = obj.nextSmallerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends