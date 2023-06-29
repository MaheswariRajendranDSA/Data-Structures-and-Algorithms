#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>>adjmat(n, vector<int>(m));
    vector<vector<int>>adjlst(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>adjmat[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
        if(adjmat[i][j]==1 && i!=j)
        {
            adjlst[i].push_back(j);
        }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";
        for(auto it:adjlst[i])
        {
            cout<<it<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

/*
IP
n m
3 3
matrix
0 0 1
0 0 1
1 1 0
adjacency list
0->2
1->2
2->0 1
*/