#include<bits/stdc++.h>
using namespace std;

int main()
{
    int mod=(int)1e9+7;
    int num, diff;
    cin>>num>>diff;
    vector<int>arr(num);
    int total_sum=0;
    for(int i=0;i<num;i++)
    {
    cin>>arr[i];
    total_sum+=arr[i];
    }
    int s2=(total_sum-diff)/2;
    vector<vector<int>>dp(num, vector<int>(s2+1, 0));

    if(total_sum-diff<0||(total_sum-diff)%2)
    return 0;

    if(arr[0]==0)
    dp[0][0]=2;
    else
    dp[0][0]=1;

    if(arr[0]!=0 && arr[0]<=s2) 
    dp[0][arr[0]]=1;

    for(int ind=1;ind<num;ind++)
    {
        for(int tar=0;tar<=s2;tar++)
        {
            int nottake=dp[ind-1][tar];

            int take=0;
            if(arr[ind]<=tar)
            take=dp[ind-1][tar-arr[ind]];

            dp[ind][tar]=take+nottake;
        }
    }
    cout<<dp[num-1][s2]<<"\n";
    return 0;
}

/*
IP
4 3 
5 2 6 4
OP
1
*/