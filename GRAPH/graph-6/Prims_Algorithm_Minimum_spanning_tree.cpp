#include<bits/stdc++.h>
using namespace std;

int spanningTree(int n, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(n, 0);
    pq.push({0, 0});
    int sum =0;
     while(!pq.empty())
     {
        auto it = pq.top();
        pq.pop();
        int node  = it.second;
        int wt = it.first;

        if(vis[node]==1) continue;
        vis[node]=1;
        sum+=wt;

        for(auto it : adj[node])
        {
            int adjnode = it[0];
            int edgw = it[1];
            if(!vis[adjnode])
            {
                pq.push({edgw, adjnode});
            }
        }
     }
     return sum;
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
        vector<int> temp;
        for(int k=0;k<3;k++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        edges.push_back(temp);
    }
    vector<vector<int>> adj[n];

    for(auto it : edges)
    {
        vector<int> temp(2);
        temp[0] = it[1];
        temp[1] = it[2];
        adj[it[0]].push_back(temp);
        temp[0] = it[0];
        temp[1] = it[2];
        adj[it[1]].push_back(temp);

    }
    int sum = spanningTree(n, adj);
    cout<<sum<<"\n";
    return 0;
}

/*
IP
3 3
0 1 5
1 2 3
0 2 1
OP
4
*/