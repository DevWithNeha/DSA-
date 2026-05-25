#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    // this is two constructor 
    node(int data1,node* next1){
        data = data1;
        next = next1;
    }

    node(int data1){
        data = data1;
        next = nullptr;
    }
};

node* convertArraytoLL(vector<int> arr){

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
    cout<<temp->data<<"->";
    temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

node* inserthead(node* head , int val){
    node* temp = new node(val);
    temp->next = head;
    head = temp;

    return head;
}

node* insertTail(node* head,int val){
    node* newNode = new node(val);

    if(head == NULL){
        return newNode;
    }

    node* temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

node* insertPosition(node* head , int el,int k){
   if(k==1){
    node* newNode = new node(el);
    newNode->next = head;
    return head;
   }
    
   if(head==NULL){
    return NULL;
   }

    int cnt = 1;
    node* temp = head;
    while(temp!=NULL){
        if(cnt==k-1){
            node* x = new node(el);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        cnt++;
        temp = temp->next;
    }
    return head;
}

node* insertBeforeValue(node* head , int el,int val){

   if(head==NULL){
    return NULL;
   }


    node* temp = head;
    while(temp->next!=NULL){
        if(temp->data==val){
            node* x = new node(el);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {2,4,6,8};
    int el = 10;
    int k = 2;
    int val = 4;

    node* head = convertArraytoLL(arr);

    cout<<"before insertion: ";
    printLL(head);

    // head = inserthead(head,val);

    head = insertTail(head,val);

    // head = insertPosition(head,el,k);

    //  head = insertBeforeValue(head,el,val);

    cout<<"after insertion: ";
    printLL(head);
}