#include <bits/stdc++.h>
using namespace std;

int main()
{   
    //variable initialization and input
    int n,c;
    //vector <int> val,wt; //uncomment to use vectors instead of array
    cin>>n>>c;
    int val[n], wt[c];

    for(int i=0; i<n; i++){
        cin >> val[i];
        // val.push_back(x); //uncomment to use vectors instead of array
    }
    for (int i=0; i<n; i++){
        cin >> wt[i];
        // wt.push_back(x); //uncomment to use vectors instead of array
    }
    //dp table initialization and processing
    // vector <vector <int>> t(n+1, vector <int> (c+1,-1)); //uncomment to use vectors instead of array
    int t[n+1][c+1];

    for(int i = 0; i <= n; i++)
        t[i][0]=0;
    for(int j = 0; j <= c; j++)
        t[0][j] = 0;
 
    for(int i = 1; i <= n; i++)
    for(int j = c; j >= 1; j--)
    {
        if(wt[i-1]<=j)
            t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
        else
            t[i][j]=t[i-1][j];
    }    
    //output
    cout<<t[n][c];
}