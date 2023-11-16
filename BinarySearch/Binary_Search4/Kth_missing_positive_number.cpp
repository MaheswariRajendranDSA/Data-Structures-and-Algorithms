#include<bits/stdc++.h>
using namespace std;

int findMissingElement(vector<int> &arr, int missingIndex){
 int n = arr.size();
 int low = 0, high = n-1;

    while(low <= high )
    {
        int mid = (low+high)/2;
        int missing = arr[mid]-(mid+1);
        if(missing < missingIndex)
            low = mid+1;
        else
            high = mid - 1;
    }
    return high+1+missingIndex;
}
int main() {
    /*int n=, target;
    cin>>n;
    cin>>target;*/
    vector<int> arr = {4, 7, 8};
    int missingIndex = 4;
    //for(int i=0;i<n;i++)
      //  cin>>a[i];
    int missingElement = findMissingElement(arr, missingIndex);
    cout<<"The missing Element of index 3 is: "<<missingElement;
    return 0;
}
/*
The missing Element of index 3 is: 5
*/