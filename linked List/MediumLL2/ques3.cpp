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

node* removeduplicates(node* head){
   if(head == NULL) return head;

   node* temp = head;

   while(temp!=NULL && temp->next!=NULL){
    if(temp->data == temp->next->data){
        node* delnode = temp->next;

        temp->next = delnode->next;

        if(delnode->next!=NULL){
            delnode->next->prev = temp;
        } 

        delete delnode;
        
    } else{
            temp = temp->next;
        }
   }
   return head;
    }

int main(){
    vector<int> arr = {1,1,1,2,3,3,4,4,5};

    node* head = convertArraytoDLL(arr);

    head = removeduplicates(head);

    printLL(head);
}