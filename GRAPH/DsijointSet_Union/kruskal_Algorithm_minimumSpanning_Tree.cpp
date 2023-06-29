#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    public:
    vector<int> size, parent;
    disjointSet(int n){
    size.resize(n+1, 1);
    parent.resize(n+1);
    for(int i=0;i<=n;i++)
    parent[i] = i;
    }
    int findUpar(int node)
    {
        if(node == parent[node])
        return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionBysize(int u, int v)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v)
        return;
        if(size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
         else {
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

int spanningTree(int n, vector<vector<int>> adj[])
{
    vector<pair<int, pair<int, int>>> edges;
    for(int i=0;i<n;i++)
    {
        for(auto it : adj[i])
        {
            int wt = it[1];
            int adjNode = it[0];
            int node = i;
            edges.push_back({wt, {node, adjNode}});
        }
    }

    disjointSet ds(n);
    sort(edges.begin(), edges.end());

    int mstWt = 0;
    for(auto it: edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(ds.findUpar(u)!=ds.findUpar(v))
        {
            mstWt+=wt;
            ds.unionBysize(u, v);
        }
    }
    return mstWt;
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
        vector<int> temp;
        for(int j=0;j<3;j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        edges.push_back(temp);
    }

    vector<vector<int>> adj[n];
    for(auto it: edges)
    {
        vector<int>temp(2);
        temp[0]=it[1];
        temp[1]=it[2];
        adj[it[0]].push_back(temp);

        temp[0]=it[0];
        temp[1]=it[2];
        adj[it[1]].push_back(temp);
    }
    int res = spanningTree(n, adj);
    cout<<res<<"\n";
    return 0;
}

/*
IP
5 6
0 1 2
0 2 1
1 2 1
2 3 2
3 4 1
4 2 2
OP
5
*/