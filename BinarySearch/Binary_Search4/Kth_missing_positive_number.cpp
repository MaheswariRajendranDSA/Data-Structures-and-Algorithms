#include<bits/stdc++.h>
using namespace std;

int findDays ( vector<int> &arr, int capacity){
    int days = 1, load = 0;
    for (int i=0;i<arr.size();i++)
    {
        if(arr[i]+load > capacity)
        {
            days++;
            load = arr[i];
        }
        else
            load += arr[i];
    }
    return days;
}
int findLeastWeightCapacity(vector<int> &arr, int days){
 int low = *max_element(arr.begin(), arr.end());
 int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high){
        int mid = (low+high)/2;

        int numberOfDays = findDays(arr, mid);
        if(numberOfDays<= days)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
int main() {
    /*int n=, target;
    cin>>n;
    cin>>target;*/
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    //for(int i=0;i<n;i++)
      //  cin>>a[i];
    int leastWeight = findLeastWeightCapacity(arr, days);
    cout<<"The Least weight to ship packages in 5 days is: "<<leastWeight;
    return 0;
}
/*
The Least weight to ship packages in 5 days is: 15
*/