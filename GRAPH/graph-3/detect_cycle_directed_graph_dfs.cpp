#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int>adjlist[], int vis[], int pathvis[])
{
    vis[node]=1;
    pathvis[node]=1;
    for(auto it : adjlist[node])
    {
        if(!vis[it])
        {
            if(dfs(it, adjlist, vis, pathvis)==true)
            return true;
        }
        else if(pathvis[it])
        return true;
    }
    pathvis[node]=0;
    return false;
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<int>adjlist[n];
    for(int i=0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        adjlist[u].push_back(v);
    }
    int vis[n]={0};
    int pathvis[n]={0};

    int s=1;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i, adjlist, vis, pathvis)==false)
            s=0;
        }
    }
    if(s==0)
    cout<<"false";
    else
    cout<<"true";
    return 0;
}
/*
IP
10 11
0 1
1 2
2 3
3 4
2 6
6 4
4 5
7 1
7 8
8 9
9 7
OP
true
IP
3 2
0 1 
1 2
OP
false
IP
3 3
0 1
1 2 
2 0
OP
true
*/