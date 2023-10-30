#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
     Node* left;
     Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
class Solution {
public:
int maxPathSum(Node* node){
    int maxi = INT_MIN;
    dfsHeight(node, maxi);
    return maxi;
    }

int dfsHeight(Node* node, int &maxi){
    if( node == NULL )
    return 0;

    int leftHeight = dfsHeight(node -> left, maxi);
    int rightHeight = dfsHeight(node -> right, maxi);

    maxi = max(maxi, leftHeight+rightHeight+node -> data);

    return node -> data + max(leftHeight, rightHeight );
}
};
int main(){
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    //root->right->left = new Node(2);
    root->right->right= new Node(4);
    root->right->right->right= new Node(5);
    cout<<"Maximum Path Sum:"<<"\n";
    Solution obj;
    int res = obj.maxPathSum(root);
    cout<<res;
    return 0;
}
/*
Maximum Path Sum:
15
*/