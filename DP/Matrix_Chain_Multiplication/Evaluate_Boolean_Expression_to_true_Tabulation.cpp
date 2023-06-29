#include<bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int main()
{
    string str;
    cin>>str;
    int len=str.size();
    vector<vector<vector<int>>>dp(len+1, vector<vector<int>>(len+1, vector<int>(2, 0)));
    
    for(int i=len-1;i>=0;i--)
    {
        for(int j=0;j<=len-1;j++)
        {
            if(i>j) continue;
            for(int isTrue=0;isTrue<=1;isTrue++)
            {
                if(i==j)
                {
                    if(isTrue==1)
                    dp[i][j][isTrue]=str[i]=='T';
                    else
                    dp[i][j][isTrue]=str[i]=='F';
                    continue;
                }
                int ways=0;
                for(int ind=i+1;ind<=j-1;ind+=2)
                {
                    int leftTrue = dp[i][ind-1][1];
                    int leftFalse = dp[i][ind-1][0];
                    int rightTrue = dp[ind+1][j][1];
                    int rightFalse = dp[ind+1][j][0];

                    if(str[ind]=='&')
                    {
                        if(isTrue)
                        {
                            ways=(ways+(leftTrue*rightTrue)%mod)%mod;
                        }
                        else
                            ways=(ways+(leftTrue*rightFalse)%mod+(leftFalse*rightTrue)%mod+(leftFalse*rightFalse)%mod)%mod;
                    }
                    else if(str[ind]=='|')
                    {
                        if(isTrue)
                        {
                        ways=(ways+(leftTrue*rightTrue)+(leftTrue*rightFalse)+(leftFalse*rightTrue)%mod)%mod;
                        }
                        else
                        ways=(ways+(leftFalse*rightFalse)%mod)%mod;
                     }
                    else
                    {
                        if(isTrue)
                        {
                        ways=(ways+(leftTrue*rightFalse)%mod+(leftFalse*rightTrue)%mod)%mod;
                        }
                        else
                        ways=(ways+(leftTrue*rightTrue)%mod+(leftFalse*rightFalse)%mod)%mod;
                    }
                }
            dp[i][j][isTrue]=ways; 
            }
        }
    }
    cout<<dp[0][len-1][1]<<"\n";
    return 0;
}

/*
IP
F|T^F
OP
2
*/