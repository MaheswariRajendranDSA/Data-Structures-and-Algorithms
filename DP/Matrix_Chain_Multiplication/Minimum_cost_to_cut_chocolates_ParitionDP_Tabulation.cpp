#include<bits/stdC++.h>
using namespace std;

int main()
{
    int num, sizeofc;
    cin>>num>>sizeofc;
    vector<int>cuts(sizeofc);
    for(int i=0;i<sizeofc;i++)
    cin>>cuts[i];
    cuts.push_back(num);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>>dp(sizeofc+2, vector<int>(sizeofc+2, 0));
    for(int i=sizeofc;i>=1;i--)
    {
        for(int j=1;j<=sizeofc;j++)
        {
            if(i>j) continue;
            int mini=1e9;
            for(int k=i;k<=j;k++)
            {
                int steps=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                mini=min(mini, steps);
            }
            dp[i][j]=mini;
        }
    }
    cout<<dp[1][sizeofc]<<"\n";
    return 0;
}