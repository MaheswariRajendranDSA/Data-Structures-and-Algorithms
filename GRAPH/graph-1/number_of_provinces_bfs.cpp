#include<bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>>&adjlst, int n, vector<int>&visited)
{
    queue<int>q;
    q.push(start);
    visited[start]=1;
    while(!q.empty())
    {
    int node=q.front();
    q.pop();

    for(auto it: adjlst[start])
    {
        if(!visited[it])
        {
            visited[it]=1;
            q.push(it);
        }
    }
    }
}
int provinces_bfs(int n, int m, vector<vector<int>>&adjmat)
{
    vector<vector<int>>adjlst(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(adjmat[i][j]==1 && i!=j)
            {
                adjlst[i].push_back(j);
            }
        }
    }
    vector<int>visited(n, 0);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cnt++;
        bfs(i, adjlst, n, visited);
    }
    cout<<cnt<<"\n";
    return 0;
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>>adjmat(n, vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>adjmat[i][j];
        }
    }
    
    provinces_bfs(n, m, adjmat);
}

/*
IP
3 3
1 0 1
0 1 0
1 0 1
OP
3
*/
