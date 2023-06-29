#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num, fees;
    cin>>num>>fees;
    vector<int>arr(num+1);
    for(int i=0;i<num;i++)
    cin>>arr[i];

    vector<vector<int>>dp(num+1, vector<int>(2, 0));
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
                    profit=max(arr[i]-fees+dp[i+1][1], 0+dp[i+1][0]);
                }
            dp[i][buy]=profit;
        }
    }
    cout<<dp[0][1];
}

/*
IP
6 2
1 3 2 8 4 9
OP
8
*/