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
vector<int>postorder(Node* node){
    vector<int> ans;
    if(node == NULL)
    return ans;

    stack<Node*>st1, st2;
    st1.push(node);
    while(!st1.empty()){
        node = st1.top();
        st1.pop();
        st2.push(node);
        if(node->left!=NULL)
        {
            st1.push(node->left);
        }
        if(node->right!=NULL)
        {
            st1.push(node->right);
        }
    }
    while(!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    }
int main(){
     Node* root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(2);
    root->right->right= new Node(3);
    cout<<"Postorder traversal is:"<<"\n";
    vector<int> res = postorder(root);
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
    return 0;
}

/*
left->right->root
Postorder traversal is:
4 2 3 5 1
*/