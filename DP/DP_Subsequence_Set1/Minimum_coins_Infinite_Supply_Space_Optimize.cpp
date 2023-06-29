#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num, target;
    cin>>num>>target;
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    vector<int>prev(target+1, 0), cur(target+1, 0);
    
    for(int tar=0;tar<=target;tar++)
    {
        if(tar%arr[0]==0)
        prev[tar]=tar/arr[0];
        else
        prev[tar]=1e9;
    }
    for(int i=1;i<num;i++)
    {
        for(int tar=0;tar<=target;tar++)
        {
            int nottake=prev[tar];
            int take=1e9;
            if(arr[i]<=tar)
            take=1+cur[tar-arr[i]];
            cur[tar]=min(take, nottake);
        }
        prev=cur;
    }
    cout<<prev[target];
    return 0;
}

/*
IP
4 11
9 6 5 1
OP
2
*/