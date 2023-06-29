#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>arr(num+1);
    for(int i=0;i<num;i++)
    cin>>arr[i];

    vector<int>front (2, 0), cur(2, 0);
    front[0]=front[1]=0;
                
    for(int i=num-1;i>=0;i--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            long profit=0;
                if(buy)
                {
                    profit=max(-arr[i]+front[0], 0+front[1]);
                }
                else
                {
                    profit=max(arr[i]+front[1], 0+front[0]);
                }
            cur[buy]=profit;
        }
        front=cur;
    }
    cout<<front[1];
}