#include<bits/stdc++.h>
using namespace std;

pair<int, int> searchMatrix(vector<vector<int>> &matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m-1;

    while(row<n && col>=0){
        if(matrix[row][col] == target)
            return {row, col};
        else if(matrix[row][col]< target)
            row++;
        else 
            col--;
    }
    return {-1, -1};
}
int main(){
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, 
    {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 14;
    pair<int, int> ans = searchMatrix(matrix, target);
    cout<<"The search in a 2D matrix is "<<ans.first<<" "<<ans.second;
    return 0;
}

/*
The search in a 2D matrix is 3 2
*/