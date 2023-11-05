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
//Node * helper(Node * root);
Node *deleteNodeBST(Node *root, int val)
{
    if(root == NULL) return NULL;
    if(root->data == val) 
    {
        return helper(root);
    }

    Node * cur = root;
    while(root!=NULL){
        if(root->data > val)
        {
            if(root->left!=NULL && root->left->data == val){
                root->left = helper(root->left);
                break;
            }
            else{
                root = root->left;
                }
        }
        else
        {
            if(root->right!=NULL && root->right->data == val){
                root->right = helper(root->right);
                break;
            }
            else{
                root = root->right;
                }
        }
    }
        return cur;
}
Node *helper (Node *root){
    if(root ->left == NULL)
        return root->right;

    if(root->right == NULL)
        return root->left;

    Node *rightChild = root->right;
    Node *lastRight = findLastRight(root->left);
    lastRight-> right = rightChild;
    return root->left;
}
Node* findLastRight (Node *root){
    if(root->right == NULL)
        return root;
    
    return findLastRight(root->right);
}
void inorder(Node *root){
    if(!root) return;
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
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
    cout<<"Delete Node in binary search tree:"<<"\n";
    Solution obj;
    int val;
    cin>>val;
    Node *target = obj.deleteNodeBST(root, val);
    obj.inorder(target);
    return 0;
}
/*
Delete Node in binary search tree:
8
3 1 6 4 7 10 14 13
*/