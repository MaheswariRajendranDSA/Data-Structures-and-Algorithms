#include<bits/stdc++.h>
using namespace std;


int main()
{
    int row;
    cin>>row;
    vector<vector<int>>triangle(row, vector<int>(row));
    vector<int>front(row, 0), cur(row, 0);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<=i;j++)
         cin>>triangle[i][j];
    }
    for(int j=0;j<row;j++)
    {
        front[j]=triangle[row-1][j];
    }
    for(int i=row-2;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
        {
            int down=front[j]+triangle[i][j];
            int diagonal=front[j+1]+triangle[i][j];
            cur[j]=min(down, diagonal);      
        }
        front = cur;
    }
    cout<<front[0]; 
    return 0;
}
/*
IP
4
1
2 3
3 6 7
8 9 6 10
OP
14
*/