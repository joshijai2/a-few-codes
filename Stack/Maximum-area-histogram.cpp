// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// Function to return Maximum Rectangular area in a histogram
// arr[]: input array
// n: size of array

class Solution
{
public:
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> NSR(n), NSL(n);
        stack<long long> rs, ls;        
        
        for (int i = n - 1; i >= 0; i--)
        {
            while (!rs.empty() && arr[rs.top()] >= arr[i])
                rs.pop();
                
            if (!rs.empty())
                NSR[i] = rs.top();
                
            else
                NSR[i] = n;
                
            rs.push(i);
        }
        
        for (int i = 0; i < n; i++)
        {
            while (!ls.empty() && arr[ls.top()] >= arr[i])
                ls.pop();
                
            if (!ls.empty())
                NSL[i] = ls.top();
                
            else
                NSL[i] = -1;
                
            ls.push(i);
        }
        
        long long maxArea = 0;
        
        for (int i = 0; i < n; i++)
        {   
            // cout<<arr[i]<<NSR[i]<<NSL[i]<<endl;
            maxArea = max(maxArea,(arr[i] * (NSR[i] - NSL[i] - 1)));
        }
        
        return maxArea;
    }
};

// { Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends