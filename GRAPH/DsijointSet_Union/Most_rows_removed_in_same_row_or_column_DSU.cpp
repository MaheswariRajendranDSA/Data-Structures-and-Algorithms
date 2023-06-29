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

int maxRemove(int n, vector<vector<int>> &stones)
{
    int maxRow = 0;
    int maxCol = 0;
    for(auto it : stones)
    {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }

    disjointSet ds(maxRow+maxCol+1);
    unordered_map<int , int> stoneNode;

    for(auto it : stones)
    {
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow + 1;
        ds.unionBysize(nodeRow, nodeCol);
        stoneNode[nodeRow] = 1;
        stoneNode[nodeCol] = 1;
    }

    int cnt = 0;
    for(auto it : stoneNode)
    {
        if(ds.findUpar(it.first) == it.first)
        cnt++;
    }
    return n-cnt;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> stones;
    for(int i=0;i<n;i++)
    {
        vector<int>temp;
        for(int j=0;j<2;j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        stones.push_back(temp);
    }

    int ans = maxRemove(n, stones);
    cout<<ans<<"\n";
    return 0;
}

/*
IP
6
0 0
0 1
1 0
1 2
2 1
2 2
OP
5
*/
