#include<bits/stdc++.h>
using namespace std;

 bool checkForCycle(int s, int V, vector<int> adj[], vector<int> &visited)
    {
        // Create a queue for BFS
        queue<pair<int, int>> q;
        visited[s] = true;
        q.push({s, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
 
            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle(i, V, adj, vis))
                    return true;
            }
        }
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
        adjlist[v].push_back(u);
    }
    int ans=0;
    ans = isCycle(n, adjlist);
    if(ans==0)
    cout<<"false";
    else
    cout<<"true";
   return 0;
}

/*
3 3
0 1
1 2
2 0
OP
true
IP
4 3
0 1
1 2
2 3
OP
false
*/