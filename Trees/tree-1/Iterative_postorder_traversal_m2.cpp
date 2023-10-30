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
    Node* cur = node;
    stack<Node*>st;
    while(cur!=NULL||!st.empty()){

        if(cur != NULL)
        {
        st.push(cur);
        cur = cur->left;
        }
        else
        {
        Node* temp = st.top() -> right;
        if(temp ==  NULL)
        {
            temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            while(!st.empty() && temp == st.top()->right)
            {
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
            }
        }
        else
        cur = temp;
    }
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