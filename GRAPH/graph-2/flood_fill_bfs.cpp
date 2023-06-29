#include<bits/stdc++.h>
using namespace std;

int bfs (int sr, int sc, vector<vector<int>>&ans, vector<vector<int>>image, int new_color, 
int delrow[], int delcol[],
int initial_color)
{
    queue<pair<int, int>>q;
    q.push({sr, sc});
    ans[sr][sc]=new_color;
    int n=image.size();
    int m=image[0].size();
    while(!q.empty())
    {
    int row=q.front().first;
    int col=q.front().second;
    q.pop();

    for(int i=0;i<4;i++)
    {
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initial_color &&
         ans[nrow][ncol]!=new_color )
         {
            ans[nrow][ncol]=new_color;
            q.push({nrow, ncol});
         }
    }
    }
}
void flood_fill(int n, int m, int sr, int sc, int new_color, vector<vector<int>>&image)
{
    vector<vector<int>>ans=image;
    int initial_color=image[sr][sc];
    int delrow[]={-1, 0, +1, 0};
    int delcol[]={0, 1, 0, -1};
    bfs(sr, sc, ans, image, new_color, delrow, delcol, initial_color);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    int n, m, sr, sc, new_color;
    cin>>n>>m>>sr>>sc>>new_color;
    vector<vector<int>>image(n, vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>image[i][j];
        }
    }
    flood_fill(n, m, sr, sc, new_color, image);
}

/*
IP
n m sr sc newcolor
3 3 2 0 3
1 1 1
2 2 0
2 2 2
OP
1 1 1 
3 3 0 
3 3 3 
*/