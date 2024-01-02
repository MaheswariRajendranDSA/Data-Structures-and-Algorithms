#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    int n = arr.size();
    int mini = arr[0], profit= 0, cost = 0;
    for(int i = 1; i < n;i ++){
        cost = arr[i] - mini;
        mini = min(mini, arr[i]);
        profit = max(profit, cost);
    }
    cout<<"The profit is : "<<profit;
    return 0;
}

/*
The profit is : 5
*/