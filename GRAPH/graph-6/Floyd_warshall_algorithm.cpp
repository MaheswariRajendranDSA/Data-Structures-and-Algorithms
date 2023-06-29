#include<bits/stdc++.h>
using namespace std;

void shortestDistance(vector<vector<int>> &mat)
{
    int n = mat.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
        if(mat[i][j]==-1)
        mat[i][j]=1e9;
        if(i==j)
        mat[i][j]=0;
        }
    }

    for(int throughpath =0;throughpath<n;throughpath++)
    {
       for(int i=0;i<n;i++)
       {
            for(int j=0;j<n;j++)
            {
                mat[i][j]=min(mat[i][j], mat[i][throughpath]+mat[throughpath][j]);
            }
       }
    }
      for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        if(mat[i][j]==1e9)
        mat[i][j]=-1;
    }
}
int main()
{
    int n=4;
    vector<vector<int>> mat(n, vector<int> (n, -1));
    mat[0][1]=2;
    mat[1][0]=1;
    mat[1][2]=3;
    mat[3][0]=3;
    mat[3][1]=5;
    mat[3][2]=4;
    shortestDistance(mat);
    for(auto it : mat)
    {
        for(auto cell : it)
        cout<<cell<<" ";
        cout<<"\n";
    }
    return 0;
}
/*
OP
0 2 5 -1 
1 0 3 -1
-1 -1 0 -1
3 5 4 0
*/