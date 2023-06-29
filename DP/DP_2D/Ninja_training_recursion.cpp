#include<bits/stdc++.h>
using namespace std;

int findMaxMeritPoints(int days, int last, vector<vector<int>>&points)
{

    if(days==0)
    {
        int maxi=0;
        for(int task=0;task<=2;task++)
        {
            if(task!=last)
            maxi=max(maxi, points[0][task]);
        }
        return maxi;
    }
        int maxi=0;
    for(int task=0;task<=2;task++)
    {
        if(task!=last)
        {
            int ans=points[days][task]+findMaxMeritPoints(days-1, task, points);
            maxi=max(maxi, ans);
        }
    }
    return maxi;
}
int main()
{
    int num;
    cin>>num;
    vector<vector<int>>points(num, vector<int>(4));
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<3;j++)
        cin>>points[i][j];
    }
    cout<<findMaxMeritPoints(num-1, 3, points);
    return 0;
}
/*
IP
2
10 50 1
5 100 11
OP
110
*/