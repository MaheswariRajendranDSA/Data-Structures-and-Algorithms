#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cin>>row>>col;
    vector<vector<int>>grid(row, vector<int>(col));
    vector<int>prev(col,0);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<row;i++)
    {
        vector<int>cur(col,0);
        for(int j=0;j<col;j++)
        {
            if(i>=0&&j>=0&&grid[i][j]==-1)
            {
                 cur[j]=0;
                continue;
            }
            if(i==0&&j==0)
            {
                 cur[j]=1;
                continue;
            }
            int up=0;
            int left=0;
            if(i>0)
            up=prev[j];
            if(j>0)
            left=cur[j-1];
            cur[j]=up+left;
        }
        prev=cur;
    }
    cout<<prev[col-1];
    return 0;
}
/*
IP
3 3
0 0 0
0 -1 0
0 0 0
OP
2
*/