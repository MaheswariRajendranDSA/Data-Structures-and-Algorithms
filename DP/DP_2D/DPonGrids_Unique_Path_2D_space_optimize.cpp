#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cin>>row>>col;
    vector<int>prev(col, 0);
    for(int i=0;i<row;i++)
    {
        vector<int>temp(col, 0);
        for(int j=0;j<col;j++)
        {
            if(i==0&&j==0)
            {
            temp[j]=1;
            continue;
            }
            int up=0;
            int left=0;
            if(i>0)
            up=prev[j];
            if(j>0)
            left=temp[j-1];
            temp[j]=up+left;
        }
        prev=temp;
    }
    cout<<prev[col-1];
    return 0;
}
/*
IP
3 2
OP
3
*/