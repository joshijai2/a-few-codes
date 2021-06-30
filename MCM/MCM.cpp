// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        int m[n][n];
        
        // Cost for multiplications of 1 length
        for(int i=1; i<n; i++)
            m[i][i] = 0;
        
        // Calc costs for multiplications of different lengths
        for(int L=2; L<n; L++){
            for(int i=1; i<n-L+1; i++){
                int j = i + L - 1;
                
                //initialize cost at i, j
                m[i][j] = m[i][i] + m[i+1][j] +
                    (arr[i-1] * arr[i] * arr[j]);
                    
                // Find minimum cost for multiplications at i, j
                for(int k=i+1; k<j; k++)
                    m[i][j] = min(m[i][j],
                        m[i][k] + m[k+1][j] +
                        (arr[i-1] * arr[k] * arr[j]));
            }
        }
        
        return m[1][n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends