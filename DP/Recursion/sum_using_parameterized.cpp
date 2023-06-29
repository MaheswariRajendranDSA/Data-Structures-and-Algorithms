#include<bits/stdc++.h>
using namespace std;

void find_sum(int sum, int num)
{
    if(num<=0)
    {
        cout<<sum<<"\n";
        return;
    }
    find_sum(sum+num,num-1);
}
int main()
{
    int num;
    cin>>num;
    find_sum(0, num);
    return 0;
}
/*
IP 
6 
OP 
21
*/