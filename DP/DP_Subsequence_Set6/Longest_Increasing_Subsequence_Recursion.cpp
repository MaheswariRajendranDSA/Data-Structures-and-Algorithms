#include<bits/stdc++.h>
using namespace std;

int findLongestIncreasingSubsequence(int ind, int prevInd, int num, vector<int>&arr)
{
    if(ind==num)
    return 0;

    int len = 0+findLongestIncreasingSubsequence(ind+1, prevInd, num, arr);
    if(prevInd==-1||arr[ind]>arr[prevInd])
    {
        len = max(len, 1+findLongestIncreasingSubsequence(ind+1, ind, num, arr));
    }
    return len;
 }
int main()
{
    int num;
    cin>>num;
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    int res=findLongestIncreasingSubsequence(0, -1, num, arr);
    cout<<res<<"\n";
    return 0;
}

/*
IP
8
10 9 2 5 3 7 101 8
OP
4
*/