#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str, int i, int j)
{
    while(i<j)
    {
        if(str[i]!=str[j])
        return false;
        i++;j--;
    }

    return true;
}
int findMinimumCost(int i, string &str, int n)
{
    if(i==n)
    return 0;

    int mincost=INT_MAX;
    for(int j=i;j<n;j++)
    {
        if(isPalindrome(str, i, j))
        {
            int cost=1+findMinimumCost(j+1, str, n);
            mincost=min(mincost, cost);
        }
    }
    return mincost;
}
int main()
{
    string str;
    cin>>str;
    int n=str.size();
    int ans=findMinimumCost(0, str, n)-1;
    cout<<ans<<"\n";
    return 0;
}

/*
IP
bbabcbadcede
OP
4
*/