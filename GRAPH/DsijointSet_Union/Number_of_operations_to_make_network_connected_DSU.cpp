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

int findConnectedComp(int n, vector<vector<int>> &edges)
{
    disjointSet ds(n);

    int cntExtras=0;

    for(auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        if(ds.findUpar(u) == ds.findUpar(v))
        {
            cntExtras++;
        }
        else
            ds.unionBysize(u, v);
    }
    int cntC =0;
    for(int i=0;i<n;i++)
    {
        if(ds.parent[i]==i)
        cntC++;
    }
    int Noedges = cntC-1;
    if(cntExtras>=Noedges)
    return Noedges;
    return -1;
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
        vector<int>temp;
        for(int j=0;j<2;j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        edges.push_back(temp);
    }

 //vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};
    int res = findConnectedComp(n, edges);
    cout<<res<<"\n";
    return 0;
}

/*
IP
4 3 
0 1 
0 2
1 2
OP
1
*/
