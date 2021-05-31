// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
// } Driver Code Ends

class Solution
{

    // Function to find the trapped water between the blocks.
public:
    int trappingWater(int arr[], int n)
    {
        if(n<3)
            return 0;
        
        int n2 = n/2;
        
        int h[n];
        
        h[0] = arr[0]; //0
        h[n - 1] = arr[n - 1]; //n-1
        
        for (int i = 1; i < n2; ++i){
            h[i] = max(h[i-1], arr[i]);

            h[n-i-1] = max(h[n-i], arr[n-i-1]);
        }
        
        int l, r, water = 0;
        
        if(n%2==1){
            l = max(h[n2-1], arr[n2]);
            r = max(h[n2+1], arr[n2]);
            water += min(l,r) - arr[n2]; // n/2
        }
        else{
            --n2;
            l = h[n2];
            r = h[n2+1];
        }
        
        for (int i = n2+1; i < n-1; ++i){
            if(arr[i]>l)
                l = arr[i];
            if(arr[n-i-1]>r)
                r = arr[n-i-1];
            water += min(h[i], l) - arr[i]
                + min(h[n-i-1], r) - arr[n-i-1];
        }
        // we don't need to calculate water for n-1 and 0
        // as it will always be 0.
        return water;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;
        //size of array
        cin >> n;
        int a[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends