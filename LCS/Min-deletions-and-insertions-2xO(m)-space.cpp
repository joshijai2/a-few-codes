// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// str1 and str2 be the given strings.
// m and n be their lengths respectively.
// len be the length of the longest common subsequence of str1 and str2
// minimum number of deletions minDel = m � len
// minimum number of Insertions minInsert = n � len
class Solution{
    public:
        // function to find longest common subsequence
        int lcs(int x, int y, string s1, string s2)
        {
            int dp[2][y+1];
            
            for(int i=0; i<=x; i++){
                for(int j=0; j<=y; j++){
                    if(i==0||j==0)
                        dp[i%2][j]=0;
                    else if(s1[i-1]==s2[j-1])
                        dp[i%2][j]=dp[(i-1)%2][j-1]%mod+1;
                    else
                        dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
                }
            }
            return dp[x%2][y];
        }
        
        int minDel(int x, int y, string s1, string s2)
        {
            int lcs = lcs(x, y, s1, s2);
            return x-lcs;
        }
        int minDel(int x, int y, string s1, string s2)
        {
            int lcs = lcs(x, y, s1, s2);
            return y-lcs;
        }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.minDel(x, y, s1, s2) << endl;
        cout << ob.minIns(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends