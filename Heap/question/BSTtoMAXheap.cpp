#include<bits/stdc++.h>
using namespace std;
class node{
    public:

    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
void inorder(node* root,vector<int> &ans){
    if(!root)
    return;

    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

void postorder(node* root,vector<int>& ans,int &index){
    if(!root)
    return;

    // left
    postorder(root->left,ans,index);
    //right
    postorder(root->right,ans,index);
    //node
    root->data = ans[index];
    index++;
}

void preorder(node* root){
    if(!root)
    return;

    cout<<root->data<<" ";

    preorder(root->left);
    preorder(root->right);
}

void converttomaxheap(node* root){
    // inorder traversal
    vector<int>ans;
    inorder(root,ans);
    // postorder traversal

    int index = 0;
    postorder(root,ans,index);

}

int main(){
    node* root = new node(4);

    root->left = new node(2);
    root->right = new node(6);

    root->left->left = new node(1);
    root->left->right = new node(3);

    root->right->left = new node(5);
    root->right->right = new node(7);

    converttomaxheap(root);

    preorder(root);
    
}