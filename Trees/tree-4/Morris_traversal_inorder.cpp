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

vector<int> morrisInorder(Node *root)
{
    vector<int> inorder;
    if(!root) return inorder;

    Node *cur = root;

    while(cur!= NULL)
    {
        if(cur->left==NULL)
        {
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        else {
            Node *prev = cur->left;
            while(prev->right && prev->right != cur)
            {
                prev = prev->right;
            }
            if(prev->right==NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else {
                prev->right = NULL;
                inorder.push_back(cur->data);
                cur = cur->right;
            }
        }
    }
    return inorder;
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
    cout<<"Morris inorder traversal of binary tree:"<<"\n";
    Solution obj;
    vector<int> inorder = obj.morrisInorder(root);
    for(int i=0;i<inorder.size();i++)
        cout<<inorder[i]<<" ";
    return 0;
}
/*
Minimum time taken to BURN a binary tree:
start node = 5
time = 3
*/