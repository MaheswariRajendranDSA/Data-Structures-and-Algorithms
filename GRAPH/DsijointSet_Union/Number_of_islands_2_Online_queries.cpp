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

bool isValid(int adjr, int adjc, int n, int m)
{
return adjr>=0 && adjr<n && adjc>=0 &&adjc<m;
}

vector<int> numofIslands(int n, int m, vector<vector<int>> &operators)
{
    disjointSet ds(n*m);
    int vis[n][m];
    memset(vis, 0, sizeof vis);
    int cnt =0;
    vector<int> ans;
    for(auto it : operators)
    {
        int row = it[0];
        int col = it[1];
        if(vis[row][col] ==1)
        {
            ans.push_back(cnt);
            continue;
        }
        vis[row][col]=1;
        cnt++;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for(int ind =0;ind<4;ind++)
        {
            int adjr = row+dr[ind];
            int adjc = col+dc[ind];
            if(isValid(adjr, adjc, n, m))
            {
                if(vis[adjr][adjc]==1)
                {
                int nodeNo= row*m+col;
                int adjnodeNo = adjr*m+adjc;
                if(ds.findUpar(nodeNo)!=ds.findUpar(adjnodeNo))
                {
                    cnt--;
                    ds.unionBysize(nodeNo, adjnodeNo);
                }
                }
            }
        }
    ans.push_back(cnt);
    }
    return ans;
}
int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> operators;
    for(int i=0;i<k;i++)
    {
        vector<int> temp;
        for(int j=0;j<2;j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        operators.push_back(temp);
    }


    vector<int> ans = numofIslands(n, m, operators);
    for(auto it: ans)
    cout<<it<<" ";
    cout<<"\n";
    return 0;
}


/*
IP
4 5 4  
1 1
0 1
3 3
3 4
OP
1 1 2 2
*/