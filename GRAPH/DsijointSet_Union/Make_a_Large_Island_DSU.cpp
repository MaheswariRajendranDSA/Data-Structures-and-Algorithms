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

bool isValid(int newr, int newc, int n)
{
    return newr>=0 && newc>=0 &&newr<n &&newc<n;
}
int maximumConnection(int n, vector<vector<int>> &grid)
{
    disjointSet ds(n*n);

    //step 1:

    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
            if(grid[row][col]==0)
            continue;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};

            for(int ind=0;ind<4;ind++)
            {
                int newr = row+dr[ind];
                int newc = col+dc[ind];

                if(isValid(newr, newc, n )&& grid[newr][newc]==1)
                {
                    int nodeNo = row*n +col;
                    int adjnodeNo = newr*n +newc;
                    ds.unionBysize(nodeNo, adjnodeNo);
                }
            }
        }
    }
    int mx=0;
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
            if(grid[row][col]==1)
            continue;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            set<int> components;
            for(int ind=0;ind<4;ind++)
            {
                int newr = row+dr[ind];
                int newc = col+dc[ind];

                if(isValid(newr, newc, n )&& grid[newr][newc]==1)
                {
                    components.insert(ds.findUpar(newr*n+newc));
                }
            }
        int sizeTot =0;
        for(auto it : components)
        {
        sizeTot+=ds.size[it];
        }
        mx = max(mx, sizeTot+1);
    }
    }
    for(int cellno =0;cellno <n*n;cellno++)
    {
        mx =max(mx, ds.size[ds.findUpar(cellno)]);
    }
    return mx;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>grid[i][j];
    }

    int ans= maximumConnection(n, grid);
    cout<<ans<<"\n";
    return 0;
}

/*
3 
1 0 1
1 0 1
1 0 1
7
*/