#include<bits/stdc++.h>
using namespace std;

int calculateTotalHr ( vector<int> &arr, int hr){
    int totalHr = 0;
    for(int i = 0; i <arr.size(); i++)
    {
        totalHr += ceil((double)arr[i]/(double)hr);
    }
    return totalHr;
}
int findKokoatebanana(vector<int> &arr, int hr){
    int low = 1, high = *max_element(arr.begin(), arr.end());
    while( low <= high)
    {
        int mid  = (low+high)/2;
        int totalHr = calculateTotalHr(arr, mid);
        if(totalHr <= hr) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

int main() {
    /*int n=, target;
    cin>>n;
    cin>>target;*/
    vector<int> arr = {3, 6, 7, 11};
    int hr = 8;
    //for(int i=0;i<n;i++)
      //  cin>>a[i];
    int hrs = findKokoatebanana(arr, hr);
    cout<<"The koko ate bananas per hour is: "<<hrs;
    return 0;
}
/*
The koko ate bananas per hour is: 4
*/