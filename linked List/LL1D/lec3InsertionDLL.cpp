#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* back;

    // constructor

    node(int data1,node* next1,node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// DLL traverse hogya
node* convertArraytoDLL(vector<int> arr){
    node* head = new node(arr[0]);
    node* prev = head;

    for(int i=1;i<arr.size();i++){
        node* temp = new node(arr[i]);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}

void printDLL(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

node* insertbeforehead(node* head,int val){
    node* newNode = new node(val,head,nullptr);
    head->back = newNode;
    
    return newNode;
}

node* insertafterhead(node* head,int val){
    node* newNode = new node(val,head->next,head); //constructor ke hisaab se hi karna hota

    head->next->back = newNode;
    head->next = newNode;

    return head;
        
    
}

node* insertbeforetail(node* head,int val){
    if(head == NULL) return new node(val);

    if(head->next==NULL){
        node* newNode = new node(val);
        newNode->next = head;
        head->back = newNode;
        return newNode;
    }
    node* tail = head;

    while(tail->next!=NULL){
        tail = tail->next;
    }

    node* prev = tail->back;

    node* newNode = new node(val);

    prev->next = newNode;

    newNode->next = tail;
    newNode->back = prev;

    tail->back = newNode;

    return head;
}

node* insertaftertail(node* head,int val){
    if(head == NULL) return new node(val);
    node* tail = head;

    while(tail->next!=NULL){
        tail = tail->next;
    }
    node* newNode = new node(val);

    tail->next = newNode;
    newNode->back = tail;

    return head;
}

node* insertbeforekthpos(node* head,int k,int val){
    if(head == NULL) return new node(val);

    node* temp = head;

    // insert before head
    if(k==1){
        node* newNode = new node(val);
        newNode->next = head;
        temp->back = newNode;
        return newNode;
        }

        int cnt = 1;
        while(temp!=NULL && cnt<k){
            temp = temp->next;
            cnt++;
        }

        if(temp == NULL) return head;

        node* prev = temp->back;
        node* newNode = new node(val);

        newNode->next = temp;
        newNode->back = prev;

        temp->back = newNode;

        if(prev!=NULL){
            prev->next = newNode;
        }
        return head;
}

int main(){
    vector<int> arr = {2,3,5,6};
    int k = 2;
    int val = 100;
    

    node* head = convertArraytoDLL(arr);
    
    // head = insertbeforehead(head,100);

    // head = insertafterhead(head,100);

    // head = insertbeforetail(head,100);

    // head = insertaftertail(head,100);

    head = insertbeforekthpos(head,k,val);

    printDLL(head);

}
