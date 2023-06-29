#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<int>dp(n+2, 0);

    for(int i=n-1;i>=0;i--)
    {
        int len=0, maxelement=INT_MIN, resmax=INT_MIN;
        for(int j=i;j<min(i+k, n);j++)
        {
            len++;
            maxelement=max(maxelement, arr[j]);
            int sum=len*maxelement+dp[j+1];
            resmax=max(resmax, sum);
        }
        dp[i]=resmax;
    }
    cout<<dp[0]<<"\n";
    return 0;
}

/*
IP
7 3
1 15 7 9 2 5 10
OP
84
*/
