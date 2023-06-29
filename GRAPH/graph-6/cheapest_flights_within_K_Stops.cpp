#include<bits/stdc++.h>
using namespace std;

int cheapestFlights(int n, int src, int dest, int k, vector<vector<int>> &flights)
{
    vector<pair<int, int>> adj[n];
    for(auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }

    queue<pair<int, pair<int,int>>> q;
    q.push({0, {src, 0}});
    vector<int>dist(n, 1e9);
    dist[src]=0;

    while(!q.empty())
    {
        auto it = q.front();
        int stops = it.first;
        int  node = it.second.first;
        int dis = it.second.second;
        q.pop();

        if(stops>k) continue;

        for(auto it : adj[node])
        {
            int adjnode = it.first;
            int edgw = it.second;

            if(dis+edgw < dist[adjnode] && stops<=k)
            {
                dist[adjnode] = dis+edgw;
                q.push({stops+1, {adjnode, dist[adjnode]}});
            }
        }
    }
        if(dist[dest]==1e9)
        return -1;
        return dist[dest];
}
int main()
{
    int n, src, dest, k;
    cin>>n>>src>>dest>>k;
    vector<vector<int>> flights;
    for(int i=0;i<n;i++)
    {
        vector<int>temp;
        for(int i=0;i<3;i++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        flights.push_back(temp);
    }

    
    /*int n = 4, src = 0, dest = 3, k = 1;

    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600},
    {2, 3, 200}};*/
    int ans = cheapestFlights(n, src, dest, k, flights);
    cout<<ans<<"\n";
    return 0;
}
/*
IP
5 0 3 1
0 1 100
1 2 100
2 0 100
1 3 600
4 3 200
OP
700
*/