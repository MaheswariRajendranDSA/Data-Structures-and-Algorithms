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
vector<vector<int>>levelorder(Node* node){
    vector<vector<int>> ans;
    if(node == NULL)
    return ans;

    queue<Node*>q;
    q.push(node);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;

        for(int i=0;i<size;i++)
        {
            Node* node = q.front();
            q.pop();
            cout<<node->data<<" ";
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
            level.push_back(node->data);
        }
        cout<<"\n";
        ans.push_back(level);
    }
}
int main(){
     Node* root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(2);
    root->right->right= new Node(3);
    cout<<"Levelorder traversal is:"<<"\n";
    vector<vector<int>> res = levelorder(root);
    return 0;
}

/*
Levelorder traversal is:
1 
4 5 
2 3 
*/