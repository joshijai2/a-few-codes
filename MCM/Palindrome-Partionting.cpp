// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string s)
    {
        int n = s.length();
        
        //store min no. of cuts.
        int c[n];
        //store if s[j:i] is palindrome.
        bool p[n][n];
        
        memset(p, false, sizeof p);
        
        for(int i=0; i<n; i++){
            // initialize no. of cuts with max value possible.
            int minc = i;
            // loop from 0 to ith index to
            // find min no. of cuts for string of 'i+1' length.
            for(int j=0; j<=i; j++){
                // if char at first(j) and last(i) index are equal.
                if(s[j]==s[i])
                    // if length of string is less than 2
                    // or if s[j+1:i-1] is a palindrome.
                    if (i-j < 2 || p[j+1][i-1]){
                        // s[j:i] is a palindrome.
                        p[j][i] = true;
                        // min no of cuts
                        minc = min(minc, j==0 ? 0 : (c[j-1]+1));
                    }
            }
            // add the min value to c table.
            c[i] = minc;
        }
        
        return c[n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends