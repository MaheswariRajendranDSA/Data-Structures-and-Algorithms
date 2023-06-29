#include<bits/stdc++.h>
using namespace std;

int main()
{
    int mod=(int)1e9+7;
    int num, diff;
    cin>>num>>diff;
    vector<int>arr(num);
    int total_sum=0;
    for(int i=0;i<num;i++)
    {
    cin>>arr[i];
    total_sum+=arr[i];
    }
    int s2=(total_sum-diff)/2;
    vector<int>prev(s2+1, 0), cur(s2+1, 0);

    if(total_sum-diff<0||(total_sum-diff)%2)
    return 0;

    if(arr[0]==0)
    prev[0]=2;
    else
    prev[0]=1;

    if(arr[0]!=0&&arr[0]<=s2) 
    prev[arr[0]]=1;

    for(int ind=1;ind<num;ind++)
    {
        for(int tar=0;tar<=s2;tar++)
        {
            int nottake=prev[tar];

            int take=0;
            if(arr[ind]<=tar)
            take=prev[tar-arr[ind]];

            cur[tar]=(take+nottake)%mod;
        }
        prev=cur;
    }
    cout<<prev[s2]<<"\n";
    return 0;
}

/*
IP
4 3 
5 2 6 4
OP
1
*/