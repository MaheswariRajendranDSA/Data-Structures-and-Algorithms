#include<bits/stdc++.h>
using namespace std;

int findCherryPickedbyNinja(int i, int j1, int j2,int col, int row, vector<vector<int>>&matrix)
{
    if(j1<0 || j1>=col || j2<0 || j2>=col)
    return -1e9;
    if(i==row-1)
    {
        if(j1==j2)
        return matrix[i][j1];
        else
        return matrix[i][j1]+matrix[i][j2];
    }
    int maxi=INT_MIN;
    for(int dj1=-1;dj1<=1;dj1++)
    {
        for(int dj2=-1;dj2<=1;dj2++)
        {
            int ans;
            if(j1==j2)
            ans=matrix[i][j1]+findCherryPickedbyNinja(i+1, j1+dj1, j2+dj2, col, row, matrix);
            else
            ans=matrix[i][j1]+matrix[i][j2]+findCherryPickedbyNinja(i+1, j1+dj1, j2+dj2, col, row, matrix);
            maxi=max(maxi,ans);
        }
    }
    return maxi;
}

int main()
{
int row, col;
cin>>row>>col;
vector<vector<int>>matrix(row, vector<int>(col));
for(int i=0;i<row;i++)
{
    for(int j=0;j<col;j++)
    cin>>matrix[i][j];
}
int maxi=findCherryPickedbyNinja(0, 0, col-1, col, row, matrix);
cout<<maxi<<"\n";
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