#include<bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int findNoofWays(int i, int j, int isTrue, string &str)
{
    if(i>j)
    return 0;
    if(i==j)
    {
        if(isTrue==1)
        return str[i]=='T';
        else
        return str[i]=='F';
    }
    int ways=0;
    for(int ind=i+1;ind<=j-1;ind+=2)
    {
        int leftTrue = findNoofWays(i, ind-1, 1, str);
        int leftFalse = findNoofWays(i, ind-1, 0, str);
        int rightTrue = findNoofWays(ind+1, j, 1, str);
        int rightFalse = findNoofWays(ind+1, j, 0, str);

        if(str[ind]=='&')
        {
            if(isTrue)
            {
            ways=(ways+(leftTrue*rightTrue)%mod)%mod;
            }
            else
            ways=(ways+(leftTrue*rightFalse)%mod+(leftFalse*rightTrue)%mod+(leftFalse*rightFalse)%mod)%mod;
        }
         else if(str[ind]=='|')
        {
            if(isTrue)
            {
            ways=(ways+(leftTrue*rightTrue)+(leftTrue*rightFalse)+(leftFalse*rightTrue)%mod)%mod;
            }
            else
            ways=(ways+(leftFalse*rightFalse)%mod)%mod;
        }
        else
        {
            if(isTrue)
            {
             ways=(ways+(leftTrue*rightFalse)%mod+(leftFalse*rightTrue)%mod)%mod;
            }
            else
            ways=(ways+(leftTrue*rightTrue)%mod+(leftFalse*rightFalse)%mod)%mod;
        }
    }
 return ways;
}
int main()
{
    string str;
    cin>>str;
    int len=str.size();
    int res=findNoofWays(0, len-1, 1, str);
    cout<<res<<"\n";
    return 0;
}

/*
IP
F|T^F
OP
2
*/