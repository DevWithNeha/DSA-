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

/*
node* SegregateEvenodd(node* head){
    if(head==NULL) return NULL;

    vector<int> odd,even;
    node* temp = head;
    int index = 1;

    while(temp!=NULL){
        if(index%2==1){
            odd.push_back(temp->data);
        } else{
            even.push_back(temp->data);
        }
        temp = temp->next;
        index++;
    }

    temp = head;

    for(int x:odd){
        temp->data = x;
        temp=temp->next;
    }

     for(int x:even){ // x ik tamporary variable h jo even vector ke ele ko ik ik karkestore karta  h
        temp->data = x;
        temp=temp->next;
    }
    return head;
}

*/

node* SegregateEvenodd(node* head){
    node* odd = head;
    node* even = head->next;
    node* evenhead = head->next;

    if(head==NULL || head->next==NULL) return head;

    while(even!=NULL && even->next!=NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;

    }
    odd->next = evenhead;
    return head;

}
int main(){
    vector<int> arr = {1,2,3,3,4,5};

    node* head = convertArraytoLL(arr);

    head = SegregateEvenodd(head);

    printLL(head);
}