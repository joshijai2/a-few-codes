// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        int dp[n+1][k+1];
        // table initialization
        for(int i=1; i<=n; i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        
        for(int j=0; j<=k; j++)
            dp[1][j] = j;
        
        for(int i=2; i<=n; i++){
            for(int j=2; j<=k; j++){
                dp[i][j] = 1 + max(dp[i][j-1], dp[i-1][0]);
                
                for(int j_curr=j-2, j_prev=1; j_curr>=0; j_curr--, j_prev++){
                    
                    int v1 = dp[i][j_curr]; // egg not broken
                    int v2 = dp[i-1][j_prev]; // egg broken
                    
                    dp[i][j] = min(dp[i][j], 1 + max(v1, v2));
                }
            }
        }
        
        return dp[n][k];    
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends