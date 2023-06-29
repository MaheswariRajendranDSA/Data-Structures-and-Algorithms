#include<bits/stdc++.h>
using namespace std;

int findRodCuting(int ind, int num, vector<int>&price, vector<vector<int>>&dp)
{
    if(ind==0)
    return (num*price[0]);

    if(dp[ind][num]!=-1)
    return dp[ind][num];

    int nottake=findRodCuting(ind-1, num, price, dp);

    int take=INT_MIN;
    int rodlength=ind+1;
    if(rodlength<=num)
    take=findRodCuting(ind, num-rodlength, price, dp)+price[ind];

    return dp[ind][num]=max(take, nottake);

}
int main()
{
    int num;
    cin>>num;
    vector<int>price(num);
    for(int i=0;i<num;i++)
    cin>>price[i];
    vector<vector<int>>dp(num, vector<int>(num+1, -1));
    findRodCuting(num-1, num, price, dp);
    cout<<dp[num-1][num]<<"\n";
    return 0;
}


/*
IP
5
2 5 7 8 10
OP
12
*/