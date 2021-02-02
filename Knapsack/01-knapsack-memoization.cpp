#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int w, int n, vector<vector<int>> &t)
{
    if (n == 0 || w == 0)
        return 0; 

    if (t[n][w] != -1)
        return t[n][w];

    if (wt[n - 1] <= w)
        t[n][w] = std::max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1, t), knapsack(wt, val, w, n - 1, t));

    else
        t[n][w] = knapsack(wt, val, w, n - 1, t);

    return t[n][w];
}

int main()
{
    //variable initialization and input
    int n, c;
    //vector <int> val,wt; //uncomment to use vectors instead of array
    cin >> n >> c;
    int val[n], wt[n];

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
        // val.push_back(x); //uncomment to use vectors instead of array
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
        // wt.push_back(x); //uncomment to use vectors instead of array
    }
    //dp table initialization and processing
    vector <vector <int>> t(n+1, vector <int> (c+1,-1));

    //output
    cout << knapsack(wt, val, c, n, t);
}