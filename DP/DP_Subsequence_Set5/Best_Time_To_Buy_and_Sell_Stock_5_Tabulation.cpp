#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>arr(num+1);
    for(int i=0;i<num;i++)
    cin>>arr[i];

    vector<vector<int>>dp(num+2, vector<int>(2, 0));

    // no need of base condition 
    dp[num][0]=dp[num][1]=0;
                
    for(int i=num-1;i>=0;i--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            long profit=0;
                if(buy)
                {
                    profit=max(-arr[i]+dp[i+1][0], 0+dp[i+1][1]);
                }
                else
                {
                    profit=max(arr[i]+dp[i+2][1], 0+dp[i+1][0]);
                }
            dp[i][buy]=profit;
        }
    }
    cout<<dp[0][1];
}

/*
IP
5
4 9 0 4 10
OP
11
*/