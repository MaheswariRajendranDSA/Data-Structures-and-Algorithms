#include<bits/stdc++.h>
using namespace std;

void SolveO(int col, int num, vector<string>&board, 
vector<vector<string>>&ans, vector<int>&leftrow, vector<int>&upperDiagonal, vector<int>&lowerDiagonal)
{
    if(col==num)
    {
        ans.push_back(board);
        return;
    }
    for(int row=0;row<num;row++)
    {
        if(leftrow[row]==0&&lowerDiagonal[row+col]==0&&upperDiagonal[num-1-row+col]==0)
        {
            board[row][col]='Q';
            leftrow[row]=1;
            upperDiagonal[num-1-row+col]=1;
            lowerDiagonal[row+col]=1;
            SolveO(col+1, num, board, ans, leftrow, upperDiagonal, lowerDiagonal);
            board[row][col]='.';
            leftrow[row]=0;
            upperDiagonal[num-1-row+col]=0;
            lowerDiagonal[row+col]=0;
;        }      
    }
}
vector<vector<string>> SolveNQueensO(int num)
{
    vector<vector<string>>ans;
    vector<string>board(num);
    string str(num, '.');
    for(int i=0;i<num;i++)
    board[i]=str;
    vector<int>leftrow(num, 0), upperDiagonal(2*num-1,0), lowerDiagonal(2*num-1, 0);
    SolveO(0, num, board, ans, leftrow, upperDiagonal, lowerDiagonal);
    return ans;
}
int main()
{
    int num;
    cin>>num;
    vector<vector<string>>ans;
    ans=SolveNQueensO(num);
    for(int i=0;i<ans.size();i++)
    {
        cout<<"Arrangement: "<<i+1<<"\n";
        for(int j=0;j<ans[i].size();j++)
        cout<<ans[i][j]<<"\n";
    }
    return 0;
}
/*
IP
4
OP
Arrangement: 1
..Q.
Q...
...Q
.Q..
Arrangement: 2
.Q..
...Q
Q...
..Q.
*/