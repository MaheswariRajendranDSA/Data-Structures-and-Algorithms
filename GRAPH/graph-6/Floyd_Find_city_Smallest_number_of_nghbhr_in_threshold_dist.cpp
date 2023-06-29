#include<bits/stdc++.h>
using namespace std;

int findCity(int n, int m, vector<vector<int>> &edges, int threshold)
{
    vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
    //adjacency matrix
    for(auto it: edges)
    {
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }

    for(int i=0;i<n;i++) dist[i][i]=0;
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
            if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)
            continue;
            dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    int countcity = n;
    int cityNode = -1;
    for(int city =0;city<n;city++)
    {
        int count=0;
        for(int adjcity=0;adjcity<n;adjcity++)
        {
        if(dist[city][adjcity]<=threshold)
        count++;
        }
        if(count <= countcity)
        {
            countcity = count;
            cityNode = city;
        }
    }
    return cityNode;
}
int main()
{
    int n, m, threshold;
    cin>>n>>m>>threshold;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
        vector<int> temp;
        for(int j=0;j<3;j++)
        {
            int x;
            cin>>x;
        temp.push_back(x);
        }
        edges.push_back(temp);
    }
    int citynumber = findCity(n, m, edges, threshold);
    cout<<citynumber<<"\n";
    return 0;
}

/*
IP
4 4 4 
0 1 3
1 2 1
1 3 4
2 3 1
OP
3
*/