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
Node *prev = NULL;
void flattenListlistRecursion(Node *root)
{
    if(!root) return;
    flattenListlistRecursion(root->right);
    flattenListlistRecursion(root->left);

    root->right = prev;
    root->left = NULL;
    prev = root;
}
};
int main(){
      Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    //root->right->left = new Node(2);
    root->left->left= new Node(4);
    root->left->left->right= new Node(7);
    root->right->left= new Node(5);
    root->right->right= new Node(6);
    cout<<"Flatten a binary tree to a linked list:"<<"\n";
    Solution obj;
    obj.flattenListlistRecursion(root);
    while(root->right!= NULL)
    {
        cout<<root->data<<"->";
        root = root->right;
    }
    cout<<root->data;
    return 0;
}
/*
Flatten a binary tree to a linked list:
1->2->4->7->3->5->6
*/