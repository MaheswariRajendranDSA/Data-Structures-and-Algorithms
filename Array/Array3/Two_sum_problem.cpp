#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int n = arr.size();
    int k = 16;
    int left = 0, right = n-1;
    sort(arr.begin(), arr.end());
    int flag = 0;
     while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == k){
            cout<<"The element is present";
            flag =1;
            break;
        }
        else if(sum > k){
            right --;
        }
        else 
            left ++;
        }
        if(flag == 0)
            cout<<"The element is not present";
        return 0;
}
/*
The element is not present
*/