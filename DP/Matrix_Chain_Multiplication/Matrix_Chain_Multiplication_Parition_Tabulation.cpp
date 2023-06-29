#include<bits/stdC++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>cost(num);
    for(int i=0;i<num;i++)
    cin>>cost[i];
    vector<vector<int>>dp(num+1, vector<int>(num+1, 0));
    for(int i=num-1;i>=1;i--)
    {
        for(int j=i+1;j<=num-1;j++)
        {
            int mini=1e9;
            for(int k=i;k<=j-1;k++)
            {
                int steps=cost[i-1]*cost[k]*cost[j]+dp[i][k]+dp[k+1][j];
                mini=min(mini, steps);
            }
            dp[i][j]=mini;
        }
    }
    cout<<dp[1][num-1]<<"\n";
    return 0;
}