#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &mat, int m, int tar){
    int low =0, high = m-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(mat[mid]>=tar)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
int rowWithMatrix(vector<vector<int>> &matrix, int n, int m){
    int cnt_max = 0;
    int index = -1;
    for(int i=0;i<n;i++){
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if(cnt_ones > cnt_max){
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}
int main(){
    vector<vector<int>> matrix = {{0, 0, 1}, {0, 1, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout<<"The row with maximum number of 1's is "<<rowWithMatrix(matrix, n, m);
    return 0;
}

/*
The row with maximum number of 1's is 1
*/