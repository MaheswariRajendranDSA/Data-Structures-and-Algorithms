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

Node* buildTree(vector<int> &postorder, vector<int> &inorder){
    map<int, int> inMap;
    for(int i=0;i<inorder.size();i++)
        inMap[inorder[i]] = i;
    
    Node * res = buildTreePreandIn(postorder, 0, postorder.size()-1, inorder, 
    0, inorder.size()-1, inMap);
    return res;
}

Node * buildTreePreandIn(vector<int> &postorder, int postStart, int postEnd, 
vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap){

    if(postStart>postEnd || inStart>inEnd) return NULL;

    Node* root = new Node (postorder[postEnd]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTreePreandIn(postorder, postStart, postStart+numsLeft-1, inorder, inStart, inRoot-1, inMap );
    root->right = buildTreePreandIn(postorder, postStart+numsLeft, postEnd-1, inorder, inRoot+1, inEnd, inMap );
    return root;
}

void inorder(Node* root)
{
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
};
int main(){
    int n;
    cin>>n;
    vector<int> postorder(n), inorder(n);
    for(int i =0;i<n;i++)
        cin>>postorder[i];
    for(int i=0;i<n;i++)
        cin>>inorder[i];
    cout<<"Constuct a unique binary tree using postorder and inorder :"<<"\n";
    Solution obj;
    Node * res = obj.buildTree(postorder, inorder);
    obj.inorder(res);
    return 0;
}
/*
Input
size = 6
postorder = 40 50 20 60 30 10
inorder   = 40 20 50 10 60 30
Constuct a unique binary tree using preorder and inorder :
inorder  = 40 20 50 10 60 30
*/