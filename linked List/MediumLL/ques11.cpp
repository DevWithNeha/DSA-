#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

node* convertArraytoLL(vector<int> &arr){
    if(arr.size()==0) return NULL;

    node* head = new node(arr[0]);
    node* mover = head;

    for(int i=1;i<arr.size();i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(node* head){
    node* temp = head;

    while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
    }
}

node* findmid(node* head){
    node* slow = head;
    node* fast = head->next;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node* merge(node* left,node* right){
    node* dummy = new node(-1);
    node* temp = dummy;

    while(left!=NULL && right!=NULL){
        if(left->data<right->data){
            temp->next = left;
            left = left->next;
        }else{
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }
    if(left!=NULL) temp->next = left;
    else temp->next = right;

    return dummy->next;
}

node* sortList(node* head){
    if(head==NULL || head->next==NULL) return head;

    node* mid = findmid(head);
    node* right = mid->next;
    mid->next = NULL;

    node* left = head;

    left = sortList(left);
    right = sortList(right);

    return merge(left,right);
}

int main(){
    vector<int> arr = {1,2,3,9,4,5};
    int n = 2;

    node* head = convertArraytoLL(arr);

    head = sortList(head);

    printLL(head);
}