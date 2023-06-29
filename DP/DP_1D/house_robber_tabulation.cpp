#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&arr, vector<int>&dp)
{
        int num=arr.size();
        dp[0]=arr[0];
        for(int i=1;i<num;i++)
        {
        int pick=arr[i];
        if(i>1)
        pick+=dp[i-2];
        int notpick=0+dp[i-1]; 
        dp[i]=max(pick, notpick);
        }
        return dp[num-1];  
 }
int main()
{
    int num;
    cin>>num;
    vector<int>arr(num);
    vector<int>dp(num, -1);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    vector<int>arr1;
    vector<int>arr2;
    if(num==1) return arr[0];
    for(int i=0;i<num;i++)
    {
        if(i!=0)
        arr1.push_back(arr[i]);
        if(i!=num-1)
        arr2.push_back(arr[i]);
    }
    int max1=solve(arr1,dp);
    for(int i=0;i<num;i++)
    dp[i]=-1;
    int max2=solve(arr2,dp);
    cout<<max(max1, max2);
    return 0;
}
/*
IP
4
2 1 4 9
OP
10
*/