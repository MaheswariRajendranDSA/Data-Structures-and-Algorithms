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
private:
    Node * first;
    Node * middle;
    Node * last;
    Node * prev;
public:
void inorder(Node * root)
{
    if(!root) return;
    inorder(root->left);
    if(prev!=NULL && root->data < prev->data){
        if(first == NULL)
        {
            first = prev;
            middle = root;
        }
        else
            last = root;
    }
    prev = root;
    inorder(root->right);
}
public:
void recoverTree(Node * root){
    first = middle = last = NULL;
    prev = new Node (INT_MIN);
    inorder(root);
    if(first && last ){
        swap(first->data, last->data);
        cout<<first->data<<" "<<last->data;
    }
    else if(first && middle)
    {
        if( !last)
        {
        swap(first->data, middle->data);
        cout<<first->data<<" "<<middle->data;
        }
    }
}
};
int main(){
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(9);
    root->left->left= new Node(1);
    root->left->right= new Node(6);
    root->left->right->left= new Node(4);
    root->left->right->right= new Node(7);
    root->right->right= new Node(14);
    root->right->right->left= new Node(16);
    cout<<"Recover BST:"<<"\n";
    Solution obj;
    obj.recoverTree(root);
   return 0;
}
/*
Two Sum:
11
TRUE
*/