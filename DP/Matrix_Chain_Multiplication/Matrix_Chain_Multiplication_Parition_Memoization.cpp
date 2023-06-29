#include<bits/stdc++.h>
using namespace std;

int findMatrixMultiplicationMini(int i, int j, vector<int>&cost, vector<vector<int>>&dp)
{
    if(i==j)
    return 0;
    int mini=1e9;

    if(dp[i][j]!=-1)
    return dp[i][j];

    for(int k=i;k<=j-1;k++)
    {
        int steps=cost[i-1]*cost[k]*cost[j]+findMatrixMultiplicationMini(i, k, cost, dp)+
        findMatrixMultiplicationMini(k+1, j, cost, dp);
        mini=min(mini, steps);
    }
    return dp[i][j]=mini;
}
int main()
{
    int num;
    cin>>num;
    vector<int>cost(num);
    for(int i=0;i<num;i++)
    cin>>cost[i];
    vector<vector<int>>dp(num+1, vector<int>(num+1, -1));
    int mini=findMatrixMultiplicationMini(1, num-1, cost, dp);
    cout<<mini<<"\n";
    return 0;
}