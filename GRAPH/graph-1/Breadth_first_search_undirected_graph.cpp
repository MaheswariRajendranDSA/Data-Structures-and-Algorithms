//undirected graph
#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int nodes, vector<vector<int>>&adjlist)
{
    int visited[nodes]={0};
    visited[0]=1;
    queue<int>q;
    q.push(0);
    vector<int>bfs;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it : adjlist[node])
        {
            if(!visited[it])
            {
                visited[it]=1;
                q.push(it);
            }
        }

    }
    return bfs;
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
    vector<int>bfsres=bfs(n, adjlist);
    for(int i=0;i<bfsres.size();i++)
    cout<<bfsres[i]<<" ";
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
0 1 2 3 4 5 6 
*/