#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    int prevf=arr[0];
    int prevs=0;
    for(int i=1;i<num;i++)
    {
        int pick=arr[i];
        if(i>1)
        pick+=prevs;
        int notpick=0+prevf; 
        int curi=max(pick, notpick); 
        prevs=prevf;
        prevf=curi; 
     }
    cout<<prevf;
    return 0;
}
/*
3
2 3 4
6
*/