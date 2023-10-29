#include<bits/stdc++.h>
using namespace std;

void print1toN(int i,int num)
{
    if(i>num)
    return;
    cout<<i<<endl;
    print1toN(i+1,num);
}
int main()
{
  int num;
  cin>>num;
  print1toN(1,num);
  return 0;
}
/*
IP 
4
OP
1 2 3 4
*/