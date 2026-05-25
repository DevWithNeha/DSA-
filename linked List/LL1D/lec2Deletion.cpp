// deletion in ll

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

// isme head return karega
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

// pura traverse karengee aur print karenge

void printLL(node* head){
    node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

node* deletehead(node* head){

    if(head == NULL) return NULL;

    node* temp = head;
    head = head->next;

    delete temp;

    return head;
}

node* removetail(node* head){
    if(head==NULL || head->next == NULL) return NULL;

    node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next =nullptr;

    return head;
}

node* removeK(node* head,int k){
    if(head==NULL ) return head;

    if(k==1){
        node* temp = head;
        head = head->next;

        delete temp;
        return head;
    }

    int cnt = 0;
    node* temp = head;
    node* prev = NULL;

    while(temp!=NULL){
        cnt++;
        if(cnt == k){
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

node* removeEl(node* head,int el){
    if(head==NULL ) return head;

    if(head->data == el){
        node* temp = head;
        head = head->next;

        delete temp;
        return head;
    }

    node* temp = head;
    node* prev = NULL;

    while(temp!=NULL){
        
        if(temp->data == el){
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {2,4,6,8};
    int k = 3; // ye position h
    int el = 8; // ye actual value h

    node* head = convertArraytoLL(arr);

    cout<<"before deleting: ";
    printLL(head);

    // head function me pass hua
    // function ne first node delete kiya
    // function ne new head return kiya
    // wo new head wapas head me store ho gaya

    // head = deletehead(head); // head ko new head se update kr rhe h

    // head = removetail(head);

    // head = removeK(head,k);

    head = removeEl(head,el);

    cout<<"after deleting :";
    printLL(head);

    
}