#include<bits/stdc++.h>
using namespace std;

int findUniquePathingrid(int row, int col, vector<vector<int>>&dp)
{
    if(row==0&&col==0)
    return 1;
    if(row<0||col<0)
    return 0;
    int up=findUniquePathingrid(row-1,col, dp);
    int left=findUniquePathingrid(row, col-1, dp);
    return up+left;
}
int main()
{
    int row, col;
    cin>>row>>col;
    vector<vector<int>>dp(row, vector<int>(col, -1));
    cout<<findUniquePathingrid(row-1, col-1, dp);
    return 0;
}