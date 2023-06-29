#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int check[], vector<int>adjlist[], int vis[], int pathvis[])
{
    vis[node]=1;
    pathvis[node]=1;
    check[node]=0;
    for(auto it : adjlist[node])
    {
        if(!vis[it])
        {
            if(dfs(it, check, adjlist, vis, pathvis)==true)
            {
            check[node]=0;
            return true;
            }
        }
        else if(pathvis[it])
        return true;
    }
    check[node]=1;
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
    int check[n]={0};
    vector<int>safe_nodes;
    int s=1;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i, check, adjlist, vis, pathvis);
        }
    }

    for(int i=0;i<n;i++)
    {
        if(check[i]==1)
        {
            safe_nodes.push_back(i);
        }
    }
    for(int i=0;i<safe_nodes.size();i++)
    cout<<safe_nodes[i]<<" ";
    return 0;
}
/*
IP
12 13
0 1 
1 2
2 3
3 4
4 6
3 5
5 6
6 7
8 1
8 9
9 10
10 8
11 9
OP
0 1 2 3 4 5 6 7
*/