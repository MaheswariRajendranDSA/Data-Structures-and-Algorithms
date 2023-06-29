#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    vector<int> size, parent;
    public:
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

int main()
{
    disjointSet ds(7);
    ds.unionBysize(1,2);
    ds.unionBysize(2,3);
    ds.unionBysize(4,5);
    ds.unionBysize(6,7);
    ds.unionBysize(5,6);
    if(ds.findUpar(3) == ds.findUpar(7))
    {
        cout<<"same\n";
    }
    else cout<<"Not Same\n";
    ds.unionBysize(3,7);
    if(ds.findUpar(3) == ds.findUpar(7))
    {
        cout<<"same\n";
    }
    else cout<<"Not Same\n";
    return 0;
}

/*
OP
Not Same
same
*/
