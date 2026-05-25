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

node* deletehead(node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    node* prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

node* deletetail(node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }

    node* tail = head;

    while(tail->next!=NULL){
        tail = tail->next;
    }
    node* newtail = tail->back;
    newtail->next = nullptr;
    tail->back = nullptr;

    delete tail;
    return head;
}

node* deletekthpos(node* head,int k){
    if(head == NULL){
        return NULL;
    }

    node* temp = head;

    // delete head

    if(k==1){
        head = head->next;
        if(head!=NULL){
            head->back = NULL;
        }
        delete temp;
        return head;
    }

    int cnt = 1;
    
    while(temp!=NULL && cnt<k){
        temp = temp->next;
        cnt++;
    }
    
    // k>length
    if(temp == NULL) return head;

    node* prevNode = temp->back;
    node* nextNode = temp->next;

    if(prevNode != NULL){
        prevNode->next = nextNode;
    }

    if(nextNode != NULL){
        nextNode->back = prevNode;
    }

    delete temp;
    return head;
}

node* deletenode(node* head , node* temp){

    if(head == NULL && temp == NULL){
        return head;
    }

    if(temp == head){
        head = head->next;
        if(head!=NULL){
            head->back = nullptr;
        }
        delete temp;
        return head;
    }
    node* prev = temp->back;
    node* front = temp->next;

   if(prev != NULL){
    prev->next = front;
   }

   if(front != NULL){
    front->back = prev;
   }

   temp->next = nullptr;
   temp->back = nullptr;

   delete temp;
   return head;

}
int main(){
    vector<int> arr = {2,3,5,7};
    int k= 4;

    node* head = convertArraytoDLL(arr);

    cout<<"befor deleteing: ";
    printDLL(head);

    // head = deletehead(head);

    // head = deletetail(head);

    // head = deletekthpos(head,k);

    node* temp = head;
    int cnt = 1;

    while(temp!=NULL && cnt<k){
        temp= temp->next;
        cnt++;
    }

    head = deletenode(head,temp);

    cout<<"\nafter deleting: ";
    printDLL(head);
}
