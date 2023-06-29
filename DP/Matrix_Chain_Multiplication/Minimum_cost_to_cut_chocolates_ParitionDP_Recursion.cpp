#include<bits/stdc++.h>
using namespace std;

int findMatrixMultiplicationMini(int i, int j, vector<int>&cuts)
{
    if(i>j)
    return 0;
    int mini=1e9;
    for(int k=i;k<=j;k++)
    {
        int steps=cuts[j+1]-cuts[i-1]+findMatrixMultiplicationMini(i, k-1, cuts)+
        findMatrixMultiplicationMini(k+1, j, cuts);
        mini=min(mini, steps);
    }
    return mini;
}
int main()
{
    int num, sizeofc;
    cin>>num>>sizeofc;
    vector<int>cuts(sizeofc);
    for(int i=0;i<sizeofc;i++)
    cin>>cuts[i];
    cuts.push_back(num);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    int mini=findMatrixMultiplicationMini(1, sizeofc, cuts);
    cout<<mini<<"\n";
    return 0;
}