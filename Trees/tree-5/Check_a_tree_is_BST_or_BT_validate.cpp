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
bool isValidBST(Node *root){
    return (isValidCheck(root, INT_MIN, INT_MAX));
}
bool isValidCheck(Node *root, int minVal, int maxVal){
    if(root == NULL) return true;
    if(root->data >= maxVal || root->data <= minVal)
         return false;
    return isValidCheck(root->left, minVal, root->data) && 
    isValidCheck(root->right, root->data, maxVal);
}
};
int main(){
      Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    //root->right->left = new Node(2);
    root->left->left= new Node(1);
    root->left->right= new Node(6);
    root->left->right->left= new Node(4);
    root->left->right->right= new Node(7);
    root->right->right= new Node(14);
    root->right->right->left= new Node(13);
    cout<<"Check a tree is BST or BT:"<<"\n";
    Solution obj;
    bool target = obj.isValidBST(root);
    if(target) cout<<"TRUE";
    else
        cout<<"FALSE";
   return 0;
}
/*
Check a tree is BST or BT:
TRUE
*/