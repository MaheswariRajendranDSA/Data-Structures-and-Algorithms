#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cin>>row>>col;
    vector<vector<int>>grid(row, vector<int>(col));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>grid[i][j];
        }
    }
    vector<vector<int>>front(col, vector<int>(col, 0)), cur(col, vector<int>(col, 0));
    for(int j1=0;j1<col;j1++)
    {
        for(int j2=0;j2<col;j2++)
        {
            if(j1==j2)
            front[j1][j2]=grid[row-1][j1];
            else
            front[j1][j2]=grid[row-1][j1]+grid[row-1][j2];
        }
    }
    for(int i=row-2;i>=0;i--)
    {
        for(int j1=0;j1<col;j1++)
        {
           for(int j2=0;j2<col;j2++) 
           {
                int maxi=INT_MIN;
            for(int dj1=-1;dj1<=1;dj1++)
            {
               for(int dj2=-1;dj2<=1;dj2++) 
               {
                int ans=0;
                if(j1==j2)
                ans=grid[i][j1];
                else
                ans=grid[i][j1]+grid[i][j2];
                if(j1+dj1<0 || j1+dj1>=col || j2+dj2<0 || j2+dj2>=col)
                ans+=-1e8;
                else
                ans+=front[j1+dj1][j2+dj2];
                maxi=max(maxi, ans);
               }
            }
           cur[j1][j2]=maxi;
           }
        }
        front=cur;
    }
    cout<<front[0][col-1]<<"\n";
    return 0;
}

/*
IP
3 4
2 3 1 2
3 4 2 2
5 6 3 5
OP
21
*/