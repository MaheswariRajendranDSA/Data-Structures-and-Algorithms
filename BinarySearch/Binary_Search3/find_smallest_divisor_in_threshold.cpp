#include<bits/stdc++.h>
using namespace std;

int sumOfDivisor ( vector<int> &arr, int divisor, int threshold){
    int sum = 0;
   for(int i=0; i<arr.size();i++){
        sum += ceil((double)arr[i]/(double)divisor);
   }
   return sum;
}
int findSmallDivisor(vector<int> &arr, int threshold){
    if(arr.size() > threshold) return -1;
    int low = 1, high = *max_element(arr.begin(), arr.end());

    while(low<=high){
        int mid = (low+high)/2;
        if(sumOfDivisor(arr, mid, threshold)<= threshold){
            high = mid - 1;
        }
        else 
            low = mid + 1;
    }
    return low;
}
int main() {
    /*int n=, target;
    cin>>n;
    cin>>target;*/
    vector<int> arr = {1, 2, 5, 9};
    int threshold = 6;
    //for(int i=0;i<n;i++)
      //  cin>>a[i];
    int divisor = findSmallDivisor(arr, threshold);
    cout<<"The smallest divisor is: "<<divisor;
    return 0;
}
/*
The smallest divisor is: 5
1/5+2/5+5/5+9/5 = 5<=6
*/