#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<vector<int>>points(num, vector<int>(4));
    vector<vector<int>>dp(num, vector<int>(4, -1));

    for(int i=0;i<num;i++)
    {
        for(int j=0;j<3;j++)
        {
             cin>>points[i][j];
        }
    }
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max({points[0][0],points[0][1],points[0][2]});

    for(int days=1;days<num;days++)
    {
        for(int last=0;last<4;last++)
        {
            dp[days][last]=0;
            for(int task=0;task<3;task++)
            {
                if(task!=last)
                {
                    int point=points[days][task]+dp[days-1][task];
                    dp[days][last]=max(dp[days][last], point);
                }
            }
        }
    }
    cout<<dp[num-1][3];
    return 0;
}
/*
IP
2
10 50 1
5 100 11
OP
110
*/