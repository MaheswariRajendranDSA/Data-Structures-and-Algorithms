#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 2, 4, 5, 3};
    int n = arr.size();
    int element = 4;
    for(int i = 0; i< n; i ++)
    {
        if(arr[i] == element)
        {
            cout<<"The index of the element is "<<i;
            return 0;
        }
    }
    cout<<"The element does not exits";
    return 0;
}

/*
The index of the element is 2
*/