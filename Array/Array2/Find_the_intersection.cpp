#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr1 = {1, 1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 3, 4, 4, 5};
    int n = arr1.size();
    int m = arr2.size();
    int i = 0, j = 0; // pointers
    vector < int > Intersection; // Uninon vector
    while (i < n && j < m) {
    if (arr1[i] < arr2[j]) // Case 1 and 2
    {
      i++;
    } else if(arr1[i] > arr2[j])// case 3
    {
      j++;
    }
    else{
        Intersection.push_back(arr1[i]);
        i++;
        j++;
    }
  }
    for(auto &val : Intersection){
        cout<<val<<" ";
    }
}

/*
The intersection is : 2 3 4 5 
*/