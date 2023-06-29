#include<bits/stdc++.h>
using namespace std;

int findMaxMeritPoints(int days, int last, vector<vector<int>>&points, vector<vector<int>>&dp)
{

    if(days==0)
    {
        int maxi=0;
        for(int task=0;task<=2;task++)
        {
            if(task!=last)
            maxi=max(maxi, points[0][task]);
        }
        return maxi;
    }
    if(dp[days][last]!=-1)
    return dp[days][last];
        int maxi=0;
    for(int task=0;task<=2;task++)
    {
        if(task!=last)
        {
            int ans=points[days][task]+findMaxMeritPoints(days-1, task, points, dp);
            dp[days][last]=max(dp[days][last], ans);
        }
    }
    return dp[days][last];
}
int main()
{
    int num;
    cin>>num;
    vector<vector<int>>points(num, vector<int>(4));
    vector<vector<int>>dp(num, vector<int>(4, -1));
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<3;j++)
        cin>>points[i][j];
    }
    cout<<findMaxMeritPoints(num-1, 3, points, dp);
    return 0;
}
/*
IP
2
10 50 1
5 100 11
OP
110
*/