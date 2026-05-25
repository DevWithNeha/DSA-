#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int x){
        data = x;
        next = NULL;
    }
};

class Queue{
    node * front,*rear;

public:
    Queue(){
        front = rear = NULL;
    }

void push(int x){
    node * newnode = new node(x);

    if(rear == NULL){
        front = rear = newnode;
        return;
    }

    rear->next = newnode;
    rear = newnode;
}

void display(){
    node* temp = front;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int pop(){
    if(front == NULL){
        cout<<"queue empty\n";
        return -1;
    }
    int val = front->data;
    node* temp = front;
    front = front->next;

    if(front == NULL){
        rear = NULL;
    }
    delete temp;

    return val;
}

int getdata(){
    if(front == NULL) return -1;
    return front->data;
    }

bool isempty(){
    return front == NULL;
}
};

int main(){
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    q.display();

    q.pop();
    q.display();

    cout<<"front data: "<<q.getdata()<<endl;
    cout<<"empty or not? "<<q.isempty()<<endl;
    
}