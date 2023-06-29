#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>arr(num);
    int total_sum=0;
    for(int i=0;i<num;i++)
    {
    cin>>arr[i];
    total_sum+=arr[i];
    }
    vector<vector<bool>>dp(num, vector<bool>(total_sum+1, 0));
    for(int i=0;i<num;i++)
    dp[i][0]=true;

    if(arr[0]<=total_sum)
    dp[0][total_sum]=true;

    for(int ind=1;ind<num;ind++)
    {
        for(int target=1;target<=total_sum;target++)
        {
            bool nottake=dp[ind-1][target];

            bool take=false;
            if(arr[ind]<=target)
            take=dp[ind-1][target-arr[ind]];

            dp[ind][target]=take||nottake;
       }
    }
    int mini=1e9;
    for(int target=0;target<=total_sum;target++)
    {
        if(dp[num-1][target])
        {
        int diff=abs(target-(total_sum-target));
        mini=min(mini, diff);
        }
    }
    cout<<mini<<"\n";
    return 0;
}
/*
IP
4
1 2 3 4
OP
0
*/