#include<bits/stdc++.h>
using namespace std;

bool check_bipartite_bfs(int start, int node, int color[], vector<int>adjlist[])
{
    color[start]=0;
    queue<int>q;
    q.push(start);

    while(!q.empty())
    {
        int n = q.front();
        q.pop();

        for(auto it : adjlist[n])
        {
            if(color[it]==-1)
            {
                color[it] = !color[n];
                q.push(it);
            }
            else if(color[it] == color[n])
            return false;
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<int>adjlist[n];
    //vector<vector<int>>adjlist(n, vector<int>(m));
    for(int j=0;j<m;j++)
    {
        int u, v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    int color[n];
    for(int i=0;i<n;i++)
    color[i]=-1;

    int ans= 0;
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            if(check_bipartite_bfs(i, n, color, adjlist)==false)
            ans=1;
        }
    }
    if(ans==0)
    cout<<"true"<<"\n";
    else
    cout<<"false"<<"\n";
    return 0;
}

/*
IP
6 6
0 1
1 2
1 4
2 3
4 3
3 5
OP
true
IP
8 8
0 1 
1 2 
1 5
5 4
2 3
4 3
3 6
6 7
OP
false
*/