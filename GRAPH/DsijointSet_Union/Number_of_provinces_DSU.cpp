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


int findNumberofProvinces(int n, int m, vector<vector<int>> &adj)
{
    disjointSet ds(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(adj[i][j]==1)
            ds.unionBysize(i, j);
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(ds.parent[i] == i)
        cnt++;
    }
    return cnt;
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n, vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>adj[i][j];
        }
    }
    int res = findNumberofProvinces(n, m, adj);
    cout<<res<<"\n";
    return 0;
}

/*
3 3
1 0 1
0 1 0
1 0 1
2
*/