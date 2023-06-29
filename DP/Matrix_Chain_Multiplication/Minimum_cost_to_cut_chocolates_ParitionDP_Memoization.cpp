#include<bits/stdc++.h>
using namespace std;

int findMatrixMultiplicationMini(int i, int j, vector<int>&cuts, vector<vector<int>>&dp)
{
    if(i>j)
    return 0;
    int mini=1e9;
    if(dp[i][j]!=-1)
    return dp[i][j];

    for(int k=i;k<=j;k++)
    {
        int steps=cuts[j+1]-cuts[i-1]+findMatrixMultiplicationMini(i, k-1, cuts, dp)+
        findMatrixMultiplicationMini(k+1, j, cuts, dp);
        mini=min(mini, steps);
    }
    return dp[i][j]=mini;
}
int main()
{
    int num, sizeofc;
    cin>>num>>sizeofc;
    vector<int>cuts(sizeofc);
    for(int i=0;i<sizeofc;i++)
    cin>>cuts[i];
    cuts.push_back(num);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>>dp(sizeofc+1, vector<int>(sizeofc+1, -1));
    int mini=findMatrixMultiplicationMini(1, sizeofc, cuts, dp);
    cout<<mini<<"\n";
    return 0;
}