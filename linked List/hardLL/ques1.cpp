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
node* getkthnode(node* temp , int k){
    k = k-1;

    while(temp!=NULL && k>0){
        temp = temp->next;
        k--;
    }
    return temp;
}

node* reverseLL(node* head){
    
    node* prevnode = NULL;
    node* temp = head;

    while(temp!=NULL){
        node* nextnode = temp->next;
        temp->next = prevnode;
        prevnode = temp;
        temp = nextnode;
    }
    return prevnode;
}

node* reversekthnode(node* head,int k){
    node* temp = head;
    node* prevnode = NULL;

    while(temp!=NULL){
        // find kth node

        node* kthnode = getkthnode(temp,k);

        if(kthnode == NULL){
            if(prevnode) prevnode->next = temp;
            break;
        }

        //next part store kro

        node* nextnode = kthnode->next;

        // link ko todo

        kthnode->next = NULL;

        // reverse current group

        reverseLL(temp);

        //head update kro

        if(temp == head){
            head = kthnode;
        } else{
            prevnode->next = kthnode;
        }
        //pointer update kro

        prevnode = temp;
        temp = nextnode;
    }
    return head;
}


int main(){
    vector<int> arr = {4,6,3,2,5,42,2,0};
    int k = 3;

    node* head = convertArraytoLL(arr);


    head = reversekthnode(head,k);
    printLL(head);


}