#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int data1){
        data = data1;
        next = nullptr;
    }
};

 node* convertArraytoll(vector<int> &arr){
    node* head = new node(arr[0]);
    node* mover = head;

    for(int i=1;i<arr.size();i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
 
 }
void printll(node* head){
    node* temp = head;
    while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
    }
    cout<<"NULL";
} 

node* insertatK(node* head,int k,int val){
    if(k == 1){
        node* newnode = new node(val);
        newnode->next = head;
        return head;
    }
    if(head == NULL) return NULL;

    node* temp = head;
    for(int i=0;i<k-1;i++){
        temp = temp->next;
    }
    
    node* newnode = new node(val);
    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

node* insertbeforeValue(node* head,int el,int k){

    if(head->data == k){
        node* newnode = new node(el);
        newnode->next = head;
        return newnode;
    }

    node* temp = head;
    node* prev = NULL;

    while(temp!=NULL){
        if(temp->data == k){
            node* newnode = new node(el);
            prev->next = newnode;
            newnode->next = temp;

            return head;
            
            
        }
        prev = temp;
        temp = temp->next;
    }
    
}


int main(){
    vector<int> arr = {2,4,6,8};

    node* head = convertArraytoll(arr);

    // cout<<head->data;

    // head = insertatK(head,3,99);

    head = insertbeforeValue(head,23,4);

    printll(head);
}