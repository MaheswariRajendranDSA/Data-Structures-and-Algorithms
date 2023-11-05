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
Node * createTreePreorder(vector<int> &arr)
{
    int i = 0;
    return build(arr, i, INT_MAX);
}
Node * build(vector<int> &arr, int &i, int bound)
{
    if(i == arr.size() || arr[i]>bound)
            return NULL;
    Node * root = new Node (arr[i++]);
    root->left = build(arr, i, root->data);
    root->right = build (arr, i, bound);
    return root;
}
void inorder(Node *root)
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
    vector<int> arr(n);
    for(int i=0 ; i<n; i++)
        cin>>arr[i];
    cout<<"Construct a tree from preorder:"<<"\n";
    Solution obj;
    Node *target = obj.createTreePreorder(arr);
    obj.inorder(target);
   return 0;
}
/*
6
8 5 1 7 10 12
Construct a tree from preorder:
norder : 1 5 7 8 10 12
*/