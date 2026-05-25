#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = nullptr;
    }
};

node* convertArraytoCLL(vector<int> &arr){
    

    node* head = new node(arr[0]);
    node* mover = head;

    for(int i=1;i<arr.size();i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    mover->next = head;

    return head;
}

void printCll(node* head){
    node* temp = head;
    
    // pehle node print

    cout<<temp->data<<" ";
    temp = temp->next;

    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

// insertion


// insert at beignning

node* insertAtbeiginning(node* head,int val){
    node* newnode = new node(val);

    if(head == NULL){
        newnode->next = newnode;
        return newnode;
    }

    node* temp = head;

    while(temp->next!=head){
        temp = temp->next;
    }

    newnode->next = head;
    temp->next = newnode;
    
    return newnode;
}

// insert at end

node* insertAtend(node* head,int val){

    node* newnode = new node(val);
    node* temp = head;

    if(head == NULL){
        newnode->next = newnode;
        return newnode;
    }

    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;

    return head;

}

// insert at kth position


node* insertAtKpos(node* head,int k,int val){
    node* temp = head;
    node* newnode = new node(val);

    if(head == NULL){
        newnode->next = newnode;
        return newnode;
    }

    // beginning pe
    if(k == 1){
        
    while(temp->next!=head){
        temp = temp->next;
    }

    newnode->next = head;
    temp->next = newnode;
    
    return newnode;
    }

    for(int i=0;i<k-1;i++){
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

// deletion

node* deleteAtbeignning(node* head){
    if(head == NULL) return NULL;

    if(head->next == head){
        delete head;
        return NULL;
    }

    node* temp = head;
    node* newnode = head;

    while(temp->next != head){
        temp = temp->next;
    }

    newnode = head->next;
    temp->next = newnode;

    delete head;

    return newnode;
}

node* deleteAtend(node* head){
    if(head == NULL) return NULL;

    node* temp = head;

    while(temp->next->next!=head){
        temp=temp->next;
    }
    node* last = temp->next;

    temp->next = head;
    delete last;

    return head;
}



int lengthCLL(node* head){

    if(head == NULL) return 0;

    int cnt = 0;
     node* temp = head;

    while(temp->next != head){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main(){

    vector<int> arr = {10,20,30};

    node* head = convertArraytoCLL(arr);

    // head = insertAtbeiginning(head,54);

    // head = insertAtend(head,60);

    // head = insertAtKpos(head,2,60);

    // head = deleteAtbeignning(head);

    // head = deleteAtend(head);

    cout<<lengthCLL(head);

    // printCll(head);

}

