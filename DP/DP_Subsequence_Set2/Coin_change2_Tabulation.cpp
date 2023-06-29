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
    dp[0][tar]=(tar%arr[0]==0);

    for(int ind=1;ind<num;ind++)
    {
        for(int tar=0;tar<=target;tar++)
        {
            int nottake=dp[ind-1][tar];
            int take=0;
            if(arr[ind]<=tar)
            take=dp[ind][tar-arr[ind]];

            dp[ind][tar]=take+nottake;
        }
    }
    cout<<dp[num-1][target]<<"\n";
    return 0;
}

/*
IP
3 4
1 2 3
OP
4
*/