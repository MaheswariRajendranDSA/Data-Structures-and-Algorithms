#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num, target;
    cin>>num>>target;
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    vector<vector<int>>dp(num, vector<int>(target+1, 0));
    
    for(int tar=0;tar<=target;tar++)
    {
        if(tar%arr[0]==0)
        dp[0][tar]=tar/arr[0];
        else
        dp[0][tar]=1e9;
    }
    for(int i=1;i<num;i++)
    {
        for(int tar=0;tar<=target;tar++)
        {
            int nottake=dp[i-1][tar];
            int take=1e9;
            if(arr[i]<=tar)
            take=1+dp[i][tar-arr[i]];
            dp[i][tar]=min(take, nottake);
        }
    }
    cout<<dp[num-1][target];
    return 0;
}

/*
IP
4 11
9 6 5 1
OP
2
*/