#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    vector<int>dp(num+1, 1), count(num+1, 1);
    int maxi=1;
    for(int ind=0;ind<num;ind++)
    {
        for(int prev=0;prev<ind;prev++)
        {
            if(arr[ind]>arr[prev]&&1+dp[prev]>dp[ind])
            {
                dp[ind]=1+dp[prev];
                count[ind]=count[prev];
            }
            else if(arr[ind]>arr[prev]&&1+dp[prev]==dp[ind])
            {
                count[ind]+=count[prev];
            }
        }
        //if(dp[ind]>maxi)
        maxi=max(maxi, dp[ind]);
   }
   int noofsub=0;
   for(int ind=0;ind<num;ind++)
   {
    if(dp[ind]==maxi)
    {
        noofsub+=count[ind];
    }
   }
   cout<<noofsub<<"\n";
   return 0;
}
/*
5
1 3 5 4 7
2
*/