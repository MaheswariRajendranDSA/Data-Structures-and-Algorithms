#include<bits/stdc++.h>
using namespace std;

bool IsSafe(int node, int color[], bool graph[101][101], int N, int col)
{
    for(int k=0;k<N;k++)
    {
        if(k!=node&&graph[k][node]==true&&color[k]==col)
        return false;
    }
    return true;
}
bool Solve(int node, int color[], int m, int N, bool graph[101][101])
{
    if(node==N)
    {
        return true;
    }
    for(int i=1;i<=m;i++)
    {
        if(IsSafe(node, color, graph, N, i))
        {
        color[node]=i;
        if(Solve(node+1, color, m, N, graph))
        return true;
        else
        color[node]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    int color[n]={0};
    if(Solve(0, color, m, n, graph))
    return true;
    return false;
}

int main()
{
    int n,m,e;
    cin>>n>>m>>e;
    bool graph[101][101];
    for(int i=0;i<n;i++)
        memset(graph[i],0,sizeof(graph[i]));
    
    for(int j=0;j<e;j++)
    {
        int a, b;
        cin>>a>>b;
        graph[a-1][b-1]=1;
        graph[b-1][a-1]=1;
    }
   bool res=false;
   res=graphColoring(graph, m, n);
   cout<<res;
   return 0;
}
/*
IP
4 3 5
1 2
2 3
3 4
4 1
1 3
OP
1
IP
3 2 3
1 2
2 3
1 3
OP
0
*/