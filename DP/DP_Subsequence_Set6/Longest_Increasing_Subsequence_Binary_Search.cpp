#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int>arr(num);
    for(int i=0;i<num;i++)
    cin>>arr[i];
    vector<int>temp;
    //sort(arr.begin(), arr.end());
    temp.push_back(arr[0]);
    int len=1;
    for(int i=1;i<num;i++)
    {
        if(arr[i]>temp.back())
        {
            temp.push_back(arr[i]);
            len++;
        }
        else
        {
            int ind=lower_bound(temp.begin(), temp.end(),arr[i])-temp.begin();
            temp[ind]=arr[i];
        }
    }
    cout<<len<<"\n";
}

/*
IP
8
10 9 2 5 3 7 101 18
OP
4
*/