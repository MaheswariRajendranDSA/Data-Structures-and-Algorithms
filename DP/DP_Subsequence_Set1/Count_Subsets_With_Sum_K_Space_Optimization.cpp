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
    
    for(int i=0;i<num;i++)
    prev[0]=cur[0]=1;

    if(arr[0]<=target)
    prev[arr[0]]=1;

    for(int ind=1;ind<num;ind++)
    {
        for(int tar=0;tar<=target;tar++)
        {
            int nottake=prev[tar];
            int take=0;
            if(arr[ind]<=tar)
            take=prev[tar-arr[ind]];

            cur[tar]=take+nottake;
        }
        prev=cur;
    }
    cout<<prev[target]<<"\n";
    return 0;
}

/*
IP
4 3
1 2 2 3
OP
3
*/