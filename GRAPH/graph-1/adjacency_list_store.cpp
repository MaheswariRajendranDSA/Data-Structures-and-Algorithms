#include<bits/stdc++.h>
using namespace std;

int main()

{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adjlist(n);
    for(int i=0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);    
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";
     for(auto it: adjlist[i])
     {
        cout<<it<<" ";
     }
     cout<<"\n";
     }
     return 0;
}