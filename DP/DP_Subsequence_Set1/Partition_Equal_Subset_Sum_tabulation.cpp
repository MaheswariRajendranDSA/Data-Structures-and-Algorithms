#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    int sum=0;
    for(int i=0;i<num;i++)
    sum+=arr[i];
    int target=sum/2;
    vector<vector<bool>>dp(num, vector<bool>(sum+1,false));
    for(int i=0;i<num;i++)
    dp[i][0]=true;
    if(arr[0]<=target)
    dp[0][arr[0]]=true;
    for(int i=1;i<num;i++)
    {
        for(int k=1;k<=target;k++)
        {
            bool nottake=dp[i-1][k];
            bool take=false;
            if(k-arr[i]>=0)
            take=dp[i-1][k-arr[i]];
            dp[i][k]=take||nottake;
        }
    }
    if(dp[num-1][target])
    cout<<"true";
    else
    cout<<"false";
    return 0;
}

/*
IP
4 
1 2 3 4
OP
true
*/