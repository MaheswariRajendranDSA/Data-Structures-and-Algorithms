#include<bits/stdc++.h>
using namespace std;

int find_sum_func(int num)
{
    if(num<0)
    return 0;
    return num+find_sum_func(num-1);
}
int main()
{
    int num;
    cin>>num;
    int res=find_sum_func(num);
    cout<<res<<"\n";
}

/*
IP 
6 
OP 
21
*/