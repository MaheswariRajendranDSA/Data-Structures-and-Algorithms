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
Node * inorderSuccessor (Node* root, Node *p){
    Node * successor = NULL;
    Node * dummy = root;
    while(dummy){
        if(p->data >=dummy->data)
            dummy = dummy->right;
        else {
            successor = dummy;
            dummy = dummy->left;
        }
    }
    return successor;
}
Node * inorderPredeccessor (Node* root, Node *p){
    Node * predeccessor = NULL;
    //cout<<p->data;
    while(root){
        if(p->data <= root->data)
            root = root->left;
        else {
            predeccessor = root;
            root = root->right;
        }
    }
    return predeccessor;
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
    cout<<"Inorder successor of binary tree:"<<"\n";
    Solution obj;
    Node *target = obj.inorderSuccessor(root, root->left->left);
    cout<<target->data<<"\n";
    cout<<"Preorder successor of binary tree:"<<"\n";
    Node *pretarget = obj.inorderPredeccessor(root, root->left->right);
    cout<<pretarget->data<<"\n";
   return 0;
}
/*
Inorder successor of binary tree:
3
Preorder successor of binary tree:
4
*/