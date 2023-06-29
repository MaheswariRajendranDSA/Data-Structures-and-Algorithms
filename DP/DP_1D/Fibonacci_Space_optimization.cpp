#include<bits/stdc++.h>
using namespace std;


int main()
{
    int num;
    cin>>num;
    int prevs=0;
    int prevf=1;
    for(int i=2;i<=num;i++)
    {
        int curi=prevf+prevs;
        prevs=prevf;
        prevf=curi;
    }
    cout<<prevf;
    return 0;
}
/*
IP
4
OP
3
*/