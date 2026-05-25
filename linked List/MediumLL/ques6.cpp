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
int lengthofloop(node* head){
    unordered_map<node* ,int> mp;
    node* temp = head;

    int timer = 0;

    while(temp!=NULL){
        if(mp.find(temp)!=mp.end()){
            return timer - mp[temp];
        }

        mp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}

*/

int lengthofloop(node* head){
    node* fast = head;
    node* slow = head;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(slow==fast){
            int cnt = 1;
            node* temp = slow->next;

            while(temp!=slow){
                cnt++;
                temp = temp->next;
            }
            return cnt;
        }
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5};

    node* head = convertArraytoLL(arr);

    // loop present karne ke liye
     head->next->next->next->next = head->next->next;

     int len = lengthofloop(head);

     cout<<"length of loop: "<<len;
}