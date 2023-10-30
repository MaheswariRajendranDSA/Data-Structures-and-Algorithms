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
int DiameterOfTree(Node* node){
    int diameter = 0;
    dfsHeight(node, diameter);
    return diameter;
    }

int dfsHeight(Node* node, int &diameter){
    if( node == NULL )
    return 0;

    int leftHeight = dfsHeight(node -> left, diameter);
    int rightHeight = dfsHeight(node -> right, diameter);

    diameter = max(diameter, leftHeight+rightHeight);

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
    cout<<"Diameter of binary tree:"<<"\n";
    Solution obj;
    int res = obj.DiameterOfTree(root);
    cout<<res;
    return 0;
}
/*
Diameter of binary tree:
4
*/