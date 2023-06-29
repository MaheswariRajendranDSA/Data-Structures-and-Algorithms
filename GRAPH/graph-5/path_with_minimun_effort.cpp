#include<bits/stdc++.h>
using namespace std;

int minimumHeight(int n, int m, vector<vector<int>> &heights)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
    greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0]=0;
    pq.push({0, {0, 0}});

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;
        if(row ==n-1 && col == m-1)
        return diff;

        for(int i=0;i<4;i++)
        {
            int nrow = row+dr[i];
            int ncol = col+dc[i];
            if(nrow >=0 && ncol>=0 &&nrow<n &&ncol<m)
            {
                int neweffort = max(abs(heights[nrow][ncol]-heights[row][col]), diff);
                if(neweffort < dist[nrow][ncol])
                {
                    dist[nrow][ncol] = neweffort;
                    pq.push({neweffort, {nrow, ncol}});
                }
            }
        }
    }
    return 0;//if unreachable
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>grid[i][j];
    }
    int res = minimumHeight(n, m, grid);
    cout<<res<<"\n";
    return 0;
}

/*
IP
3 3
1 2 2
3 8 2
5 3 5
OP
2
*/