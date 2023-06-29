#include<bits/stdc++.h>
using namespace std;

int findMaximumSum(int i, vector<int>&arr, int n, int k)
{
    if(i==n)
    return 0;

    int len=0, maxielement=INT_MIN, resmax=INT_MIN;
    for(int j=i;j<min(i+k,n);j++)
    {
        len++;
        maxielement=max(maxielement, arr[j]);
        int sum=len*maxielement+findMaximumSum(j+1, arr, n, k);
        resmax=max(resmax, sum);
    }
    return resmax;
}
int main()
{
    int n, k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int ans=findMaximumSum(0, arr, n, k);
    cout<<ans<<"\n";
    return 0;
}

/*
IP
7 3
1 15 7 9 2 5 10
OP
84
*/
