
//undirected graph
#include<bits/stdc++.h>
using namespace std;

vector<int> dfs(int start, vector<vector<int>>&adjlist, int nodes, vector<int>&visited, vector<int>&ans)
{
    visited[start]=1;
    ans.push_back(start);
    for(auto it:adjlist[start])
    {
        if(!visited[it])
        {
            dfs(it, adjlist, nodes, visited, ans);
        }
    }
    return ans;
}
int main()

{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adjlist(n, vector<int>(m));
    for(int i=0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);    
    }
    vector<int>visited(n, 0);
    vector<int>ans;
    vector<int>dfsres=dfs(0, adjlist, n, visited, ans);
    for(int i=0;i<dfsres.size();i++)
    cout<<dfsres[i]<<" ";
    cout<<"\n";
}

/*
IP
7 6
0 1                    
0 2
1 3 
1 4 
2 5
2 6
OP
0 1 3 4 2 5 6  
*/