#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num, target;
    cin>>num>>target;
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    vector<bool>prev(target+1, 0), cur(target+1, 0);
    prev[0]=cur[0]=true;
    if(arr[0]<=target)
    prev[arr[0]]=true;
    for(int i=1;i<num;i++)
    {
        for(int k=1;k<=target;k++)
        {
            bool nottake=prev[k];
            bool take=false;
            if(k-arr[i]>=0)
            take=prev[k-arr[i]];
            cur[k]=take||nottake;
        }
        prev=cur;
    }
  if(prev[target])
  cout<<"true";
  else
  cout<<"false";
    return 0;
}

/*
IP
4 100
1 2 3 4
OP
false
*/