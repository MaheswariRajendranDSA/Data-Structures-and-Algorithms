#include<bits/stdc++.h>
using namespace std;

int firstoccurance(vector<int> &a, int target)
{
    int n = a.size();
    int low = 0, high = n-1, first = -1;

    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]==target)
        {
            first = mid;
            high = mid-1;
        }
        else if(a[mid] < target)
        {
            low = mid+1;
        }
        else 
            high = mid-1;
    }
    return first;
}
int lastoccurance(vector<int> &a, int target)
{
    int n = a.size();
    int low = 0, high = n-1, last=-1;

    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]==target)
        {
            last = mid;
            low = mid+1;
        }
         else if(a[mid] < target)
         {
           low = mid+1;
         }
        else 
            high = mid-1;
    }
    return last;
}
pair<int, int> getFirstandLastOccurance (vector<int> &a, int target){
    int n = a.size();
    int first  = firstoccurance(a, target);
    if(first ==-1) return {-1, -1};
    int last = lastoccurance(a, target);
    return {first, last}; 
}
int main() {
    /*int n=, target;
    cin>>n;
    cin>>target;*/
    vector<int>a = {3, 4, 6, 6, 6, 6, 16, 17};
    int target = 6;
    //for(int i=0;i<n;i++)
      //  cin>>a[i];
    pair<int,int> occur = getFirstandLastOccurance (a, target);
    cout<<"first_occurance is: "<<occur.first<<"\n"<<"last_occurance is: "<<occur.second;
    return 0;
}
/*
first_occurance is: 2
last_occurance is: 5
*/