#include<bits/stdc++.h>
using namespace std;


int main()
{
    int num, wtofbg;
    cin>>num>>wtofbg;
    vector<int>weight(num), value(num);

    for(int i=0;i<num;i++)
    {
        cin>>weight[i];
    }
    for(int i=0;i<num;i++)
    {
        cin>>value[i];
    }

    vector<vector<int>>dp(num, vector<int>(wtofbg+1, 0));

    for(int i=weight[0];i<=wtofbg;i++)
    dp[0][i]=(int)((i/weight[0])*value[0]);

    for(int ind=1;ind<num;ind++)
    {
        for(int wt=0;wt<=wtofbg;wt++)
        {
            int nottake=dp[ind-1][wt];

            int take=INT_MIN;
            if(weight[ind]<=wt)
            take=dp[ind][wt-weight[ind]]+value[ind];

            dp[ind][wt]=max(take, nottake);
        }
    }
    cout<<dp[num-1][wtofbg]<<"\n";
    return 0;
}

/*
IP
3 10
2 4 6
5 11 13
OP
27
*/