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
vector<int>inorder(Node* node){
    vector<int> ans;
    if(node == NULL)
    return ans;

    stack<Node*>st;

    while(true){
        if(node!=NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if(st.empty())
            break;
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            node = node->right;
        }
    }
    }
int main(){
     Node* root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(2);
    root->right->right= new Node(3);
    cout<<"Inorder traversal is:"<<"\n";
    vector<int> res = inorder(root);
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
    return 0;
}

/*
left->root->right
Preorder traversal is:
4 1 2 5 3
*/