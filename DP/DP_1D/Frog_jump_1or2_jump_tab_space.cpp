#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    int prevf=0;
    int prevs=0;
    vector<int>height(num+1);
    for(int i=0;i<num;i++)
    cin>>height[i];
    for(int i=1;i<num;i++)
    {
        int left=prevf+ abs(height[i]-height[i-1]);
        int right=INT_MAX;
        if(i>1)
        right=prevs+ abs(height[i]-height[i-2]);
        int curi=min(left,right);
        prevs=prevf;
        prevf=curi;
    }
    cout<<prevf;
    return 0;
}
/*
IP
6
30 10 60 10 60 50
OP
40
*/