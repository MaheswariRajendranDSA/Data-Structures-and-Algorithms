#include<bits/stdc++.h>
using namespace std;

int findZeroOneKnapsack(int num, int wtofbg, vector<int>&weight, vector<int>&value)
{
    if(num==0)
    {
        if(weight[0]<=wtofbg)
        return (int)((wtofbg/weight[0])*value[0]);
        else
        return 0;
    }
    int nottake=0+findZeroOneKnapsack(num-1, wtofbg, weight, value);

    int take=INT_MIN;
    if(weight[num]<=wtofbg)
    take=value[num]+findZeroOneKnapsack(num, wtofbg-weight[num], weight, value);

    return max(take, nottake);
}
int main()
{
    int num, wtofbg;
    cin>>num>>wtofbg;
    vector<int>weight(num), value(num);

    for(int i=0;i<num;i++)
    {
        cin>>weight[i];
    }
    for(int i=0;i<num;i++)
    {
        cin>>value[i];
    }
    int res=findZeroOneKnapsack(num-1, wtofbg, weight, value);
    cout<<res<<"\n";
    return 0;
}

/*
IP
3 10
2 4 6
5 11 13
OP
27
*/