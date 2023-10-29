#include<bits/stdC++.h>
using namespace std;

string getPermutation(int n, int k)
{
    int fact=1;
    vector<int>numbers;
    for(int i=1;i<n;i++)
    {
    fact*=i;
    numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans="";
    k=k-1;
    while(true)
    {
        ans+=to_string(numbers[k/fact]);
        numbers.erase(numbers.begin()+k/fact);
        if(numbers.size()==0)
        break;
        k%=fact;
        fact/=numbers.size();
    }
    return ans;
}
int main()
{
    int n, k;
    cin>>n>>k;
    string ans;
    ans=getPermutation(n, k);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i];
    cout<<"\n";
    return 0;
}

/*
IP
3 3
OP
213
*/