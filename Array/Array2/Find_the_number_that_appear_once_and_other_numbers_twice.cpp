#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4};
    int n = arr.size();
    int xor1 = 0;
    for(int i = 0; i < n; i ++){
        xor1 = xor1 ^ arr[i];
    }
     cout<<"The number which appear once is : "<<xor1;
}
/*
The number which appear once is : 2
*/