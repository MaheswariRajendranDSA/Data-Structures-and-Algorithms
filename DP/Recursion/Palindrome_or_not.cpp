#include<bits/stdc++.h>
using namespace std;

bool find_reverse(string name, int start, int end)
{
    if(start>=name.size()/2)
    return true;
    if(name[start]!=name[end])
    return false;
    return find_reverse(name, start+1, end-1);
}
int main()
{
    string name;
    cin>>name;
    if(find_reverse(name,0,name.size()-1))
    cout<<"IS PALINDROME"<<"\n";
    else
    cout<<"NOT A PALINDROME"<<"\n";
    return 0;
}
/*
IP  
MADAM
OP   
IS PALINDROME 
IP  
state
OP  
NOT A PALINDROME
*/