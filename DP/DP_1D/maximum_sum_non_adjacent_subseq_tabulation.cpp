#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>arr(num);
    vector<int>dp(num, -1);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    dp[0]=arr[0];
    for(int i=1;i<num;i++)
    {
        int pick=arr[i];
        if(i>1)
        pick+=dp[i-2];
        int notpick=0+dp[i-1]; 
        dp[i]=max(pick, notpick);  
     }
    cout<<dp[num-1];
    return 0;
}
/*
3
2 3 4
6
*/