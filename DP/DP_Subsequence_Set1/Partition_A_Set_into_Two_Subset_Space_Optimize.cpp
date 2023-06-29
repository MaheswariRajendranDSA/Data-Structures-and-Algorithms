#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>arr(num);
    int total_sum=0;
    for(int i=0;i<num;i++)
    {
    cin>>arr[i];
    total_sum+=arr[i];
    }
    vector<bool>prev(total_sum+1, 0), cur(total_sum+1, 0);

    prev[0]=cur[0]=true;

    if(arr[0]<=total_sum)
    prev[total_sum]=true;

    for(int ind=1;ind<num;ind++)
    {
        for(int target=1;target<=total_sum;target++)
        {
            bool nottake=prev[target];

            bool take=false;
            if(arr[ind]<=target)
            take=cur[target-arr[ind]];

            cur[target]=take||nottake;
       }
       prev=cur;
    }
    int mini=1e9;
    for(int target=0;target<=total_sum;target++)
    {
        if(prev[target])
        {
        int diff=abs(target-(total_sum-target));
        mini=min(mini, diff);
        }
    }
    cout<<mini<<"\n";
    return 0;
}
/*
IP
4
1 2 3 4
OP
0
*/