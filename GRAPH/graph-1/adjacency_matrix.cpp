#include<bits/stdc++.h>
using namespace std;

int main()

{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adjmat(n, vector<int>(m));
    for(int i=0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        adjmat[u][v]=1;
        adjmat[v][u]=1;    
    }
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<m;j++)
     {
        cout<<adjmat[i][j]<<" ";
     }
     cout<<"\n";
     }
     return 0;
}

/*
IP
7 6
0 1
0 2
1 3
1 4
2 5
2 4
0 1 1 0 0 0
1 0 0 1 1 0
1 0 0 0 1 1
0 1 0 0 0 0
0 1 1 0 0 0
0 0 1 0 0 0
0 0 0 0 0 0
*/