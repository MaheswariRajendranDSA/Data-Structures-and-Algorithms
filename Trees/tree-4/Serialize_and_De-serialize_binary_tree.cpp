#include<bits/stdc++.h>
#include<string>
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

string serializeTree(Node * root){
    if(!root) return "";
    string s = "";
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node * curNode = q.front();
        q.pop();

        if(curNode == NULL )
            s.append("#,");
        else{
            s.append(to_string(curNode->data)+',');
            if(curNode != NULL)
            {
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
    }
    cout<<s;
    cout<<"\n";
    return s;
}

Node * deserializeTree(string data){
    if(data.size()== 0 ) return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    Node *root = new Node(stoi(str));
    queue<Node* > q;
    q.push(root);

    while(!q.empty())
    {
        Node *node = q.front();
        q.pop();
        getline(s, str, ',');
        if(str == "#")
            node->left == NULL;
        else
        {
            Node *leftNode = new Node(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }
        getline(s, str, ',');
        if(str == "#")
            node->right == NULL;
        else
        {
            Node *rightNode = new Node(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }

    }
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
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left= new Node(4);
    root->right->right= new Node(5);
    cout<<"Serialize a binary tree:"<<"\n";
    Solution obj;
    string serlTree = obj.serializeTree(root);
    Node* deserlzeTree = obj.deserializeTree(serlTree);
     cout<<"De-serialize a binary tree:"<<"\n";
    obj.inorder(deserlzeTree);
    return 0;
}
/*
Serialize a binary tree:
1,2,3,#,#,4,5,#,#,#,#,
De-serialize a binary tree:
2 1 4 3 5
*/