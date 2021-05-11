// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// function to find longest palindromic subsequence

class Solution{
    public:
        int lps(string s) {
        int n = s.length();
        int lcs[2][n+1];
        memset(lcs, 0, sizeof lcs);
        
        string t = s;
        reverse(t.begin(), t.end());
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==t[j-1])
                    lcs[i%2][j]=lcs[(i-1)%2][j-1]+1;
                else
                    lcs[i%2][j]=max(lcs[(i-1)%2][j],lcs[i%2][j-1]);
            }
        }
        
        return lcs[n%2][n];
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(s) << endl;
    }
    return 0;
}
  // } Driver Code Ends