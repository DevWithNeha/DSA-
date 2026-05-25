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

node* deleteAlloccurance(node* head,int key){
    node* temp = head;

    while(temp!=NULL){
        if(temp->data==key){
            if(temp == head){
                head = temp->next;
            }
    
        node* nextnode = temp->next;
        node* prevnode = temp->prev;

        if(nextnode!=NULL) nextnode->prev = prevnode;
        if(prevnode!=NULL) prevnode->next = nextnode;

        delete temp;
        temp = nextnode;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
    }




int main(){
    vector<int> arr = {2,4,6,8,2,6,2};
    int key = 2;

    node* head = convertArraytoDLL(arr);

    head = deleteAlloccurance(head,key);

    printLL(head);
}