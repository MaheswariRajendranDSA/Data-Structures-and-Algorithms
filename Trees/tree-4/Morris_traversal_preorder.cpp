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
    vector<int> preorder;
    if(!root) return preorder;

    Node *cur = root;

    while(cur!= NULL)
    {
        if(cur->left==NULL)
        {
            preorder.push_back(cur->data);
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
                preorder.push_back(cur->data);
                cur = cur->left;
            }
            else {
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return preorder;
}
};
int main(){
      Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left= new Node(4);
    root->left->left->right= new Node(7);
    root->right->left= new Node(5);
    root->right->right= new Node(6);
    cout<<"Morris preorder traversal of binary tree:"<<"\n";
    Solution obj;
    vector<int> preorder = obj.morrisInorder(root);
    for(int i=0;i<preorder.size();i++)
        cout<<preorder[i]<<" ";
    return 0;
}
/*
Morris preorder traversal of binary tree:
1 2 4 7 3 5 6
*/