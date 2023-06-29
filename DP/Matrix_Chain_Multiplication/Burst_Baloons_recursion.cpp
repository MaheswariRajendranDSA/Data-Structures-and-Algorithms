#include<bits/stdc++.h>
using namespace std;

int findMaxCoinsToBurst(int i, int j, vector<int>&arr, int n)
{
    if(i>j)
    return 0;
    int maxi=INT_MIN;
    for(int ind=i;ind<=j;ind++)
    {
        int cost=arr[i-1]*arr[ind]*arr[j+1]+findMaxCoinsToBurst(i, ind-1, arr, n)+findMaxCoinsToBurst(ind+1, j, arr, n);
        maxi=max(maxi, cost);
    }
    return maxi;
}

int maxcoins(vector<int>&arr, int n)
{
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    return findMaxCoinsToBurst(1, n, arr, n);
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int ans=maxcoins(arr, n);
    int len=arr.size();
    cout<<ans<<"\n";
}
/*
IP
4
3 1 5 8
OP
167
*/