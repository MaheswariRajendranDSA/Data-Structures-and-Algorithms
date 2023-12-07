#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &mat, int col, int m){
    int low =0, high = m-1;
    
    while(low<=high){
        int mid = (low+high)/2;
        if(mat[mid] > col){
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return low;
}
int countSmallEqual(vector<vector<int>> &matrix, int n, int m, int col){
    int cnt = 0;
    for(int i=0;i<n;i++){
       cnt += upperBound(matrix[i], col, m);
    }
    return cnt;
}
int median(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int low = INT_MAX, high = INT_MIN;

    for(int i=0;i<n;i++){
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m-1]);
    }

    int req = (n*m)/2;
    while(low<=high){
        int mid = (low+high)/2;
        int smallEqual = countSmallEqual(matrix, n, m, mid);
        if(smallEqual <= req)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int main(){
    vector<vector<int>> matrix = {{1, 3, 8},
                             {2, 3, 4},
                             {1, 2, 5}};
    int ans = median(matrix);
    cout<<"The median of the row-wise sorted matrix is: "<<ans;
    return 0;
}

/*
The median of the row-wise sorted matrix is: 3
*/