#include<bits/stdc++.h>
using namespace std;

bool canPlaceCows ( vector<int> &stalls, int distance, int noOfCows){
    int countCows =1, lastStall = stalls[0];
    for(int i=0;i<stalls.size();i++)
    {
        if(stalls[i] - lastStall >= distance)
        {
            countCows++;
            lastStall = stalls[i];
        }
        if(countCows >= noOfCows) return true;
    }
    return false;
}
int aggressizeCows(vector<int> &stalls, int noOfCows){
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n-1] - stalls[0];

    while(low<=high)
    {
        int mid = (low+high)/2;
        if(canPlaceCows(stalls, mid, noOfCows)){
            low = mid + 1;
        }
        else 
            high = mid - 1;
    }
    return high;
}
int main() {
    /*int n=, target;
    cin>>n;
    cin>>target;*/
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int noOfCows = 4;
    //for(int i=0;i<n;i++)
      //  cin>>a[i];
    int maximumDistance = aggressizeCows(stalls, noOfCows);
    cout<<"The maximum distance of placing all cows is : "<<maximumDistance;
    return 0;
}
/*
The maximum distance of placing all cows is : 3
*/