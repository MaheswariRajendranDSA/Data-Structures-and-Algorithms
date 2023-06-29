#include<bits/stdc++.h>
using namespace std;

bool IsValid(int row, int col, vector<string>board, int num)
{
    int duprow=row;
    int dupcol=col;
    while(row>=0&&col>=0)
    {
        if(board[row][col]=='Q')
        return false;
        row--;
        col--;
    }
    col=dupcol;
    row=duprow;
    while(col>=0)
    {
        if(board[row][col]=='Q')
        return false;
        col--;
    }
    col=dupcol;
    row=duprow;
    while(row<num&&col>=0)
    {
        if(board[row][col]=='Q')
        return false;
        row++;
        col--;
    }
    return true;
}
void Solve(int col, int num, vector<string>&board, vector<vector<string>>&ans)
{
    if(col==num)
    {
        ans.push_back(board);
        return;
    }
    for(int row=0;row<num;row++)
    {
        if(IsValid(row, col, board, num))
        {
            board[row][col]='Q';
            Solve(col+1, num, board, ans);
            board[row][col]='.';
        }
    }
}
vector<vector<string>>SolveNQueen(int num)
{
    vector<vector<string>>ans;
    vector<string>board(num);
    string str(num,'.');
    for(int i=0;i<num;i++)
    board[i]=str;
    Solve(0, num, board, ans);
    return ans;
}
int main()
{
    int num;
    cin>>num;
    vector<vector<string>>ans;
    ans=SolveNQueen(num);
    for(int i=0;i<ans.size();i++)
    {
        cout<<"Arrangement"<<i+1<<"\n";
        for(int j=0;j<ans[i].size();j++)
        cout<<ans[i][j]<<"\n";
    }
    return 0;
}
/*
IP
4
OP
Arrangement1
..Q.
Q...
...Q
.Q..
Arrangement2
.Q..
...Q
Q...
..Q.
*/