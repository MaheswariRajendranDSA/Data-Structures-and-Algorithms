#include<bits/stdc++.h>
using namespace std;

void find_subsequences(vector<int>&arr, int num, int index, vector<int>&res)
{
    if(index==num)
    {
        for(auto a : res)
        cout<<a<<" ";
        cout<<"\n";
        return;
    }
    res.push_back(arr[index]);
    find_subsequences(arr, num, index+1,res);
    res.pop_back();
    find_subsequences(arr, num, index+1,res);
}
int main()
{
    int num;
    cin>>num;
    vector<int> arr(num+1);
    vector<int>res;
    for(int i=0;i<num;i++)
    cin>>arr[i];
    find_subsequences(arr, num, 0, res);
    return 0;
}
/*IP 
 3
 1 2  3
OP 
1 2 3
1 2
1 3
1
2 3
2
3
*/