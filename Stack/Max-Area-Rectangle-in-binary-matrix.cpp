// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends


/*You are required to complete this method*/
class Solution{
    public:
        int getMaxArea(vector<int> arr, int n){
            vector<int> nsl, nsr, area;
            stack<int> ls, rs;
            
            for(int i=0; i<n; i++){
                while(ls.size()>0 && arr[ls.top()]>=arr[i])
                    ls.pop();
                nsl.push_back(ls.empty()? -1: ls.top());
                ls.push(i);
            }
            
            for(int i=n-1; i>=0; i--){
                while(rs.size()>0 && arr[rs.top()]>=arr[i])
                    rs.pop();
                nsr.push_back(rs.empty()? n: rs.top());
                rs.push(i);
            }
            reverse(nsr.begin(), nsr.end());
            
            for(int i=0; i<n; i++){
                // cout<<arr[i]<<" "<<nsr[i]<<" "<<nsl[i]<<endl;
                area.push_back(arr[i]*(nsr[i]-nsl[i]-1));
            }
            
            return *max_element(area.begin(), area.end());        
            }
        
        int maxArea(int M[MAX][MAX], int n, int m) {
            vector<int> h(m,0);
            int max=0;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(M[i][j]==0)
                        h[j] = 0;
                    else 
                        h[j]++;
                }
                int mah = getMaxArea(h,m);
                if (mah>max)
                    max = mah;
            }
            return max;
        }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends