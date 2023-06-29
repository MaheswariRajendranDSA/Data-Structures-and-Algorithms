#include<bits/stdc++.h>
using namespace std;

int findFibonacci(int ind)
{
    if(ind<=1)
    return ind;
    return findFibonacci(ind-1)+findFibonacci(ind-2);
}
int main()
{
    int num;
    cin>>num;
    cout<<findFibonacci(num);
    return 0;
}
/*
IP
4
OP
3
*/