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
        vector<long long> nsl, nsr, area;
        stack<long long> ls, rs;

        for (int i = 0; i < n; i++)
        {
            while (ls.size() > 0 && arr[ls.top()] >= arr[i])
                ls.pop();
            nsl.push_back(ls.empty() ? -1 : ls.top());
            ls.push(i);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (rs.size() > 0 && arr[rs.top()] >= arr[i])
                rs.pop();
            nsr.push_back(rs.empty() ? n : rs.top());
            rs.push(i);
        }
        reverse(nsr.begin(), nsr.end());

        for (int i = 0; i < n; i++)
        {
            // cout<<arr[i]<<" "<<nsr[i]<<" "<<nsl[i]<<endl;
            area.push_back(arr[i] * (nsr[i] - nsl[i] - 1));
        }

        return *max_element(area.begin(), area.end());
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