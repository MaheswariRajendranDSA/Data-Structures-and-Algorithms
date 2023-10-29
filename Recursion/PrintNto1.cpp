#include<bits/stdc++.h>
using namespace std;

void printNto1(int i,int num)
{
    if(i<1)
    return;
    cout<<i<<endl;
    printNto1(i-1,num);
}
int main()
{
  int num;
  cin>>num;
  printNto1(num,num);
  return 0;
}

/*
IP 
4 
OP 
4 3 2 1
*/