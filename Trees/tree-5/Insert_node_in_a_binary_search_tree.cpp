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
Node *insertNodeBST(Node *root, int val)
{
    if(root == NULL) return new Node(val);
    Node * cur = root;
    while(true){
        if(cur->data <= val)
        {
            if(cur->right!=NULL)
                cur = cur->right;
            else{
                cur->right = new Node(val);
                break;
                }
        }
        else {
            if(cur->left!=NULL)
                cur = cur->left;
            else {
                cur->left = new Node(val);
                break;
                }
            }
        }
        return root;
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
    cout<<"Insert Node in a binary search tree:"<<"\n";
    Solution obj;
    int val;
    cin>>val;
    Node *target = obj.insertNodeBST(root, val);
    obj.inorder(target);
    return 0;
}
/*
Insert Node in a binary search tree:
15
8 3 1 6 4 7 10 14 13 15
*/