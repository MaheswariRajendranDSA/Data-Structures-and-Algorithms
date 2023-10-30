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
vector<int>all_traversal(Node* node){
    vector<int> pre, in ,post;
    if(node == NULL)
    return pre;

    stack<pair<Node*, int>>st;
    st.push({node, 1});
    while(!st.empty()){
        pair<Node*, int> it = st.top();
        st.pop();
        
        if(it.second ==1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
        if(it.first->left != NULL)
        {
            st.push({it.first->left, 1});
        }}
         else if(it.second ==2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
        if(it.first->right != NULL)
        {
            st.push({it.first->right, 1});
        }}
        else{
            post.push_back(it.first->data);
        }
    }
    cout<<"Preorder is:"<<"\n";
    for(int i=0;i<pre.size();i++)
    {
        cout<<pre[i];
    }
    cout<<"\n"<<"Inorder is:"<<"\n";
    for(int i=0;i<in.size();i++)
    {
        cout<<in[i];
    }
    cout<<"\n"<<"Postorder is:"<<"\n";
    for(int i=0;i<post.size();i++)
    {
        cout<<post[i];
    }
    }
int main(){
     Node* root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(5);
    root->right->left = new Node(2);
    root->right->right= new Node(3);
    cout<<"All traversal"<<"\n";
    all_traversal(root);
    return 0;
}

/*
All traversal
Preorder is://root->left-?right
14523
Inorder is://left->root-?right
41253
Postorder is://left->right-?root
42351
*/