#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

node* convertArraytoDLL(vector<int> arr){
    if(arr.size()==0) return NULL;

    node* head = new node(arr[0]);
    node* temp = head;

    for(int i=1;i<arr.size();i++){
        node* newnode = new node(arr[i]);
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
    return head;
}

node* printLL (node* head){
    node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
vector<pair<int,int>> findpairs(node* head,int k){
    vector<pair<int,int>> ans;

    if(head == NULL) return ans;

    node* left = head;
    node* right = head;

    while(right->next!=NULL){
        right = right->next;
    }
    while(left!=right && left->prev!=right){
        int sum = (left->data+right->data);

        if(sum == k){
            ans.push_back({left->data,right->data});
            left = left->next;
            right = right->prev;
        }
        else if(sum<k){
            left = left->next;
        } else{
            right = right->prev;
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {2,2,4,4,6,6,8};
    int key = 8;

    node* head = convertArraytoDLL(arr);

    vector<pair<int,int>> result = findpairs(head,key);

    cout<<"print are:\n";
    for(auto it:result){
        cout<<"("<<it.first<<","<<it.second<<")";
    }
  

    // printLL(head);
}