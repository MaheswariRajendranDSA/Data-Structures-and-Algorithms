#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 1, 0, 1, 1, 1, 0, 1, 1};
    int n = arr.size();
    int maxi = 0, cnt = 0;
    for(int i = 0; i < n; i ++){
        if(arr[i] == 1){
            cnt++;
            maxi =max(maxi, cnt);
        }
        else    
            cnt = 0;
    }
     cout<<"The maximum consecutive ones are :"<<maxi;
}
/*
The maximum consecutive ones are :3
*/