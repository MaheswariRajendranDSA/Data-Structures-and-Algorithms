#include<bits/stdc++.h>
using namespace std;

int findRodCuting(int ind, int num, vector<int>&price)
{
    if(ind==0)
    return (num*price[0]);

    int nottake=findRodCuting(ind-1, num, price);

    int take=INT_MIN;
    int rodlength=ind+1;
    if(rodlength<=num)
      take=findRodCuting(ind, num-rodlength, price)+price[ind];

    return max(take, nottake);

}
int main()
{
    int num;
    cin>>num;
    vector<int>price(num);
    for(int i=0;i<num;i++)
    cin>>price[i];
    int ans=findRodCuting(num-1, num, price);
    cout<<ans<<"\n";
    return 0;
}


/*
IP
5
2 5 7 8 10
OP
12
*/