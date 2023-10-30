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
vector<int>preorder(Node* node){
    vector<int> ans;
    if(node == NULL)
    return ans;

    stack<Node*>st;
    st.push(node);

    while(!st.empty()){
        node = st.top();
        st.pop();
        ans.push_back(node->data);
          if(node->right!=NULL){
                st.push(node->right);
            }
            if(node->left!=NULL){
                st.push(node->left);
            }
        }
    }
int main(){
     Node* root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(2);
    root->right->right= new Node(3);
    cout<<"Preorder traversal is:"<<"\n";
    vector<int> res = preorder(root);
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
    return 0;
}

/*
root->left->right
Preorder traversal is:
1 4 5 2 3
*/