#include<bits/stdc++.h>
using namespace std;

int countPath(int n, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[n];
    for(auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n, 1e9), ways(n, 0);
    dist[0]=0;
    ways[0]=1;
    pq.push({0, 0});
    int mod = (int)(1e9+7);

    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int dis = it.first;
        int node = it.second;

        for(auto it: adj[node])
        {
            int adjnode = it.first;
            int edgw = it.second;
            if(dis+edgw < dist[adjnode])
            {
                dist[adjnode]= dis+edgw;
                pq.push({dis+edgw, adjnode});
                ways[adjnode] = ways[node];
            }
            else if(dis+edgw == dist[adjnode])
            {
                ways[adjnode] = (ways[node]+ways[adjnode])%mod;
            }
        }
    }
    return ways[n-1]%mod;
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
        vector<int> temp;
        for(int i=0;i<3;i++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        edges.push_back(temp);
    }
    int ans = countPath(n, edges);
    cout<<ans<<"\n";
    return 0;
}

/*
IP
6 8
0 5 8
0 2 2
0 1 1
1 3 3
1 2 3
2 5 6
3 4 2 
4 5 2
OP
3
*/