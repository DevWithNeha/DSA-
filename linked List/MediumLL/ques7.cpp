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

//brute force

/*
bool palindrome(node* head){
    stack<int> st;

    node* temp = head;

    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp!=NULL){
        if(temp->data!=st.top()){
            return false;
        }
        st.pop();
        temp = temp->next;
    }
    return true;
}
*/

// optimal aproach

   node* reverseLL(node* head){
        node* temp = head;
        node* prev = NULL;

        while(temp!=NULL){
            node* nextnode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextnode;
        }
        return prev;
    }

bool palindrome(node* head){
    node* slow = head;
    node* fast = head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    node* secondhalf = reverseLL(slow->next);

    node* first = head;
    node* second = secondhalf;

    while(second!=NULL){
    if(first->data!=second->data){
        return false;
    }
    first = first->next;
    second = second->next;
}
    return true;
}
int main(){
    vector<int> arr = {1,2,3,3,4,5};

    node* head = convertArraytoLL(arr);

   bool pel = palindrome(head);

   if(pel){
    cout<<"palindrome ";
   }else{
    cout<<"not palindrome ";
   }
}