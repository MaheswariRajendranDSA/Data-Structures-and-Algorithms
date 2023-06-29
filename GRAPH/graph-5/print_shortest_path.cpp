#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath (int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[n+1];
    for(auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, 1e9), parent(n+1);
    for(int i=1;i<=n;i++)
    parent[i]=i;
    dist[1]=0;
    pq.push({0, 1});
    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int dis = it.first;
        int node  = it.second;
        for(auto it : adj[node])
        {
            int curnode = it.first;
            int edgeweight = it.second;
            if(dis+edgeweight < dist[curnode])
            {
                dist[curnode] = dis + edgeweight;
                pq.push({dist[curnode], curnode});
                parent[curnode] = node;
            }
        }
    }
    if(dist[n]==1e9)
    return {-1};
    else
    {
        vector<int>path; int node = n;
        while(parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
        vector<int>temp;
        for(int i=0;i<3;i++)
        {
        int x;
        cin>>x;
        temp.push_back(x);
        }
        edges.push_back(temp);
    }
    vector<int> res = shortestPath(n, m, edges);
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
    cout<<"\n";
    return 0;
}

/*
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
1 4 3 5
*/