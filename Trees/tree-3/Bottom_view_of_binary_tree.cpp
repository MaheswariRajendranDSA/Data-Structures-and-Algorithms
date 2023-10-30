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

vector<int> bottomView(Node* node){
    map<int, int> map;
    queue<pair<Node*,int>> q;
    q.push({node, 0});

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        Node* tempnode = p.first;
        int line = p.second;
        map[line]=tempnode->data;

        if(tempnode->left)
        q.push({tempnode->left, line-1});

        if(tempnode->right)
        q.push({tempnode->right, line+1});
    }
    vector<int> ans;
    for(auto p : map){
            ans.push_back(p.second);
        }
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
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
    cout<<"Bottom view of binary tree:"<<"\n";
    Solution obj;
    obj.bottomView(root);
    return 0;
}
/*
Bottom view of binary tree:
8 4 10 12 11 13
*/