#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num, target;
    cin>>num>>target;
    vector<int>price(num);
    for(int i=0;i<num;i++)
    cin>>price[i];

    vector<int>front (2*target+1, 0), cur(2*target+1, 0);

    for(int ind=num-1;ind>=0;ind--)
    {
        for(int transid=2*target-1;transid>=0;transid--)
        {
            if(transid%2==0)
             cur[transid]=max(-price[ind]+front[transid+1], 0+front[transid]);
            else
            cur[transid]=max(price[ind]+front[transid+1], 0+front[transid]);
        }
        front = cur;
    }
    cout<<front[0];
}