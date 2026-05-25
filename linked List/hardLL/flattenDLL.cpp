
// leetcode = 430
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node* child;

    node(int data1){
        data = data1;
        next = NULL;
        prev = NULL;
        child = NULL;
    }
};

void printList(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

/*
node* flattenDLL(node* head){
        if(head == NULL) return head;

        node* curr = head;

        while(curr!=NULL){
            if(curr->child){
                // agr curr ka child h toh pehle next node ko store kr lo 

                node* nextnode = curr->next;

                // child ko next bna do

                curr->next = curr->child;
                curr->child->prev = curr;

                //child ka last dhundo  

                node* temp = curr->child;
                while(temp->next!=NULL){
                    temp = temp->next;
                }

                temp->next = nextnode;
                if(nextnode) nextnode->prev = temp;

                // child ko null kro

                curr->child = NULL;

            }
            curr = curr->next;
        }
        return head;
    }

*/

// using recursion

node* flattenDLL(node* head){
    if(head == NULL) return head;

    node* curr = head;

    while(curr!=NULL){
        if(curr->child != NULL){
            //flatten the child node
            node* next = curr->next;

            // recursively flatten child
            node* childhead = flattenDLL(curr->child);

            curr->next = childhead;
            childhead->prev = curr;

            curr->child = NULL;

            // find tail

            node* temp = childhead;
            while(temp->next != NULL){
                temp = temp->next;
            }

            // attach tail to next

            if(next!=NULL){
                temp->next = next;
                next->prev = temp;
            }
        }
        curr = curr->next;
    }
    return head; 
}

int main(){
    /*
        1-2-3
          |
          7-8
            |
            11-12
    */

    node* head = new node(1);
    node* n2 = new node(2);
    node* n3 = new node(3);

    head->next = n2;
    n2->prev = head;

    n2->next = n3;
    n3->prev = n2;

    node* n7 = new node(7);
    node* n8 = new node(8);

    n2->child = n7;
    n7->prev = n2;
    n7->next = n8;
    n8->prev = n7;

    node* n11 = new node(11);
    node* n12 = new node(12);

    n8->child = n11;
    n11->prev = n8;

    n11->next = n12;
    n12->prev = n11;

    head = flattenDLL(head);

    printList(head);
}