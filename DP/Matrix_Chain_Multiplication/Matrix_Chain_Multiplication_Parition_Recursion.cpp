#include<bits/stdc++.h>
using namespace std;

int findMatrixMultiplicationMini(int i, int j, vector<int>&cost)
{
    if(i==j)
    return 0;
    int mini=1e9;
    for(int k=i;k<=j-1;k++)
    {
        int steps=cost[i-1]*cost[k]*cost[j]+findMatrixMultiplicationMini(i, k, cost)+findMatrixMultiplicationMini(k+1, j, cost);
        mini=min(mini, steps);
    }
    return mini;
}
int main()
{
    int num;
    cin>>num;
    vector<int>cost(num);
    for(int i=0;i<num;i++)
    cin>>cost[i];
    int mini=findMatrixMultiplicationMini(1, num-1, cost);
    cout<<mini<<"\n";
    return 0;
}