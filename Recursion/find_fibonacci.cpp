#include<bits/stdc++.h>
using namespace std;

int find_fibonacci(int num)
{
    if(num<=1)
    return num;
    return find_fibonacci(num-1)+find_fibonacci(num-2);
}
int main()
{
    int num;
    cin>>num;
    int res=find_fibonacci(num);
    cout<<res<<"\n";
    return 0;
}

/*
IP 
4
OP 
3
*/