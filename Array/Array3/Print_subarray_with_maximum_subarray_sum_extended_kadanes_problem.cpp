#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = arr.size();
    long long sum = 0, maxi = INT_MIN;
    long long ansStart = -1, ansEnd= -1, start = 0;
    for(int i = 0; i < n; i++){
        if(sum == 0){
            start = i;
        }
        sum += arr[i];
        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum < 0)
            sum = 0;
    }
    cout<<"The maximum subarray array is : ";
    for(int i = ansStart; i < ansEnd ; i ++)
        cout<<arr[i]<<" ";
    return 0;
}
/*
The maximum subarray array is : 4 -1 2
*/