#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cin>>row>>col;
    vector<vector<int>>matrix(row, vector<int>(col));
    vector<int>prev(col, 0), cur(col,0);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>matrix[i][j];
        }
    }
    for(int j=0;j<col;j++)
    prev[j]=matrix[0][j];

    for(int i=1;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int down=matrix[i][j]+prev[j];
            int leftdiagonal=matrix[i][j];
            if(j-1>=0)
            leftdiagonal+=prev[j-1];
            int rightdiagonal=matrix[i][j];
            if(j+1<=col-1)
            rightdiagonal+=prev[j+1];
            cur[j]=max({down, leftdiagonal, rightdiagonal});
        }
        prev=cur;
    }
    int maxi=prev[0];
    for(int i=1;i<col;i++)
    maxi=max(maxi, prev[i]);
    cout<<maxi<<"\n";
    return 0;
}

/*
IP
4 4
1 2 10 4
100 3 2 1
2 1 20 2
1 2 2 1
OP
106
*/