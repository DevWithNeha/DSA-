#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* random;

    node(int val){
        data = val;
        next = NULL;
        random = NULL;
    }
};

void printLL(node* head){
    node* temp = head;

    while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
    }
}

void printList(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<"val: "<<temp->data;

        if(temp->random){
            cout<<"random: "<<temp->random->data;
        } else{
            cout<<" random NULL";
        }
        temp = temp->next;
    }
}

/*
node* cloneLL(node* head){
    if(head == NULL) return NULL;

    node* temp = head;
    unordered_map<node*,node*> mp;

    while(temp!=NULL){
       mp[temp] = new node(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp!=NULL){
        mp[temp] ->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next; 
    }
    return mp[head];
}

*/

node* cloneLL(node* head){
    if(head == NULL) return NULL;

    node* temp = head;

    
    while(temp!=NULL){
        // pehla copy ko insert kro
        node* copy = new node(temp->data);
        copy->next = temp->next;
        temp->next = copy;
        temp = copy->next;
    }

    // copy ka random 
    temp = head;
    while(temp!=NULL){
        if(temp->random){
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }

    // seperate both copy and original

    node* dummy = new node(0);
    node* copy = dummy;
    temp = head;

    while(temp!=NULL){
        copy->next = temp->next;
        temp->next = temp->next->next;

        copy = copy->next;
        temp = temp->next;
    }
    return dummy->next;
}

int main(){
    node* n1 = new node(1);
    node* n2 = new node(2);
    node* n3 = new node(3);

    n1->next = n2;
    n2->next = n3;

    n1->random = n3;
    n2->random = n1;
    n3->random = NULL;

    node* head = n1;

    head = cloneLL(head);
    printList(head);
  
    
    
   

}