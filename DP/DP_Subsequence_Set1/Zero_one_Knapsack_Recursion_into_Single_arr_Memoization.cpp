#include<bits/stdc++.h>
using namespace std;

int findZeroOneKnapsack(int num, int wtofbg, vector<int>&weight, vector<int>&value, vector<vector<int>>&dp)
{
    if(num==0)
    {
        if(weight[0]<=wtofbg)
        return value[0];
        else
        return 0;
    }

    if(dp[num][wtofbg]!=-1)
    return dp[num][wtofbg];

    int nottake=0+findZeroOneKnapsack(num-1, wtofbg, weight, value, dp);

    int take=INT_MIN;
    if(weight[num]<=wtofbg)
    take=value[num]+findZeroOneKnapsack(num-1, wtofbg-weight[num], weight, value, dp);

    return dp[num][wtofbg]=max(take, nottake);
}
int main()
{
    int num, wtofbg;
    cin>>num>>wtofbg;
    vector<int>weight(num), value(num);

    for(int i=0;i<num;i++)
    {
        cin>>weight[i];
    }
    for(int i=0;i<num;i++)
    {
        cin>>value[i];
    }

    vector<vector<int>>dp(num, vector<int>(wtofbg+1, -1));
    findZeroOneKnapsack(num-1, wtofbg, weight, value, dp);
    cout<<dp[num-1][wtofbg]<<"\n";
    return 0;
}

/*
IP
3 8
3 4 5
30 50 60 
OP
90
*/