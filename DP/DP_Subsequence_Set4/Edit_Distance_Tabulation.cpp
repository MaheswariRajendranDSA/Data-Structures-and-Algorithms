#include<bits/stdc++.h>
using namespace std;


int main()
{
    string str, tar;
    cin>>str>>tar;
    int strlen=str.size();
    int tarlen=tar.size();
    vector<vector<int>>dp(strlen+1, vector<int>(tarlen+1, 0));
    
    for(int i=0;i<=strlen;i++)
    dp[i][0]=i;
    for(int j=0;j<=tarlen;j++)
    dp[0][j]=j;

    for(int i=1;i<=strlen;i++)
    {
        for(int j=1;j<=tarlen;j++)
        {
            if(str[i-1]==tar[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            dp[i][j]=1+min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
        }
    }
    cout<<dp[strlen][tarlen]<<"\n";
    return 0;
}

/*
IP
horse
ros
OP
3
*/