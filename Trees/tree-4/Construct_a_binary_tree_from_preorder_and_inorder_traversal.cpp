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

Node* buildTree(vector<int> &preorder, vector<int> &inorder){
    map<int, int> inMap;
    for(int i=0;i<inorder.size();i++)
        inMap[inorder[i]] = i;
    
    Node * res = buildTreePreandIn(preorder, 0, preorder.size()-1, inorder, 
    0, inorder.size()-1, inMap);
    return res;
}

Node * buildTreePreandIn(vector<int> &preorder, int preStart, int preEnd, 
vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap){

    if(preStart>preEnd || inStart>inEnd) return NULL;

    Node* root = new Node (preorder[preStart]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTreePreandIn(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, inMap );
    root->right = buildTreePreandIn(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, inMap );
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
    vector<int> preorder(n), inorder(n);
    for(int i =0;i<n;i++)
        cin>>preorder[i];
    for(int i=0;i<n;i++)
        cin>>inorder[i];
    cout<<"Constuct a unique binary tree using preorder and inorder :"<<"\n";
    Solution obj;
    Node * res = obj.buildTree(preorder, inorder);
    obj.inorder(res);
    return 0;
}
/*
Input
size = 5
preorder = 3 9 20 15 7
inorder = 9 3 15 20 7
Constuct a unique binary tree using preorder and inorder :
inorder  = 9 3 15 20 7
*/