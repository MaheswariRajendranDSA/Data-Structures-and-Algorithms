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

vector<int> rightView(Node* node){
    vector<int> ans;
    recursion(node, 0, ans);
    return ans;
}

public:

void recursion(Node* node, int level, vector<int> &ans){
    if(node == NULL) return;

    if(ans.size() == level)
        ans.push_back(node->data);

    if(node->right != NULL)
        recursion(node->right, level+1, ans);

    if(node->left != NULL)
        recursion(node->left, level+1, ans);
}
};
int main(){
      Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    //root->right->left = new Node(2);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    root->left->left->left= new Node(8);
    root->left->left->right= new Node(9);
    root->left->right->left= new Node(10);
    root->left->right->right= new Node(11);
    root->left->right->right->left= new Node(12);
    root->left->right->right->right= new Node(13);
    cout<<"Right View of binary tree:"<<"\n";
    Solution obj;
    vector<int> rightview = obj.rightView(root);
    for(int i=0;i< rightview.size();i++ )
    {
        cout<<rightview[i]<<" ";
    }
    return 0;
}
/*
Right View of binary tree:
1 3 7 11 13
*/