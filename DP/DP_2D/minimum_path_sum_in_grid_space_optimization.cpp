#include<bits/stdc++.h>
using namespace std;


int main()
{
    int row, col;
    cin>>row>>col;
    vector<vector<int>>grid(row, vector<int>(col));
    vector<int>prev(col, 0);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        cin>>grid[i][j];
    }
      for(int i=0;i<row;i++)
      {
        vector<int>temp(col, 0);
        for(int j=0;j<col;j++)
        {
            if(i==0&&j==0)
            {
            temp[j]=grid[i][j];
            continue;
            }
            int up=0;
            int left=0;
            up=grid[i][j];
            if(i>0)
            up+=prev[j];
            else
            up+=1e9;
            left=grid[i][j];
            if(j>0)
            left+=temp[j-1];
            else
            left+=1e9;
            temp[j]=min(up, left);
        }
        prev=temp;
    }

    cout<<prev[col-1];
    return 0;
}
/*
IP
2 3           
5 9 6
11 5 2
OP
21
*/