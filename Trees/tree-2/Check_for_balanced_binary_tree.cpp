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
bool CheckBalancedBinaryTree(Node* node){
    return dfsHeight(node)!= -1;
    }

int dfsHeight(Node* node){
    if( node == NULL )
    return 0;

    int leftHeight = dfsHeight(node -> left);
    if(leftHeight == -1) return -1;

    int rightHeight = dfsHeight(node -> right);
    if(rightHeight == -1) return -1;

    if(abs(leftHeight - rightHeight ) > 1) return -1;

    return 1 + max(leftHeight, rightHeight );
}
};
int main(){
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    //root->right->left = new Node(2);
    root->right->right= new Node(4);
    root->right->right->right= new Node(5);
    cout<<"Check for balanced binary tree:"<<"\n";
    Solution obj;
    bool res = obj.CheckBalancedBinaryTree(root);
    if(res == 1)
    cout<<"TRUE";
    else
    cout<<"FALSE";
    return 0;
}
/*
Check for balanced binary tree:
FALSE
*/