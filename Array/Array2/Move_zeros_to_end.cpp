#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = arr.size();
    int j = -1;
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    if(j==-1) 
    {
        cout<<"-1";
        return 0;
    }
    for(int i=j+1;i<n;i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
/*
1 2 3 2 4 5 1 0 0 0 
*/