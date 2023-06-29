#include<bits/stdc++.h>
using namespace std;

int findUniquePathingrid(int row, int col)
{
    if(row==0&&col==0)
    return 1;
    if(row<0||col<0)
    return 0;
    int up=findUniquePathingrid(row-1,col);
    int left=findUniquePathingrid(row, col-1);
    return up+left;
}
int main()
{
    int row, col;
    cin>>row>>col;
    cout<<findUniquePathingrid(row-1, col-1);
    return 0;
}
/*
IP
1 1
2 2 
3 2
1 6
OP
1
2 
3 
1
*/