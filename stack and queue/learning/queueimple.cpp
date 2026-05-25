#include<bits/stdc++.h>
using namespace std;

class circularqueue{
    int arr[100];
    int front,rear,size;

    public:
        circularqueue(int x){
            int size = x;
            front = -1;
            rear = -1;
        }

   // push operation

    void push(int x){
        if((rear+1) % size == front){
            cout<<"queue full\n";
            return;
        }

        // first element

        if(front == -1){
            front=rear = 0;
        }else{
            rear = (rear + 1) % size; // element push hoga 
        }
        arr[rear] = x;
    }

    // pop operation (dequeue)

    void pop(){
        if(front == -1){
            cout<<"queue empty\n";
            return;
        }

        // single element

        if(front == rear){
            front = rear = -1;
        } else{
            front = (front + 1) % size;
        }
    }

    int getfront(){
        if(front == -1){
            return -1;
        }

        return arr[front];
    }

    bool isempty(){
        return front == -1;
    }

    void display(){
        if(front == -1){
            cout<<"queue empty\n";
            return;
        }

        int i = front;
        while(true){
            cout<<arr[i]<<" ";
            if(i == rear) break;
            i = (i+1) % size;
        }
        cout<<endl;
    }
};

int main(){
    circularqueue q(5);

    q.push(10);
    q.push(20);
    q.push(30);

    q.display();

    q.pop();
    q.pop();
    q.display();

    cout<<"front element: "<<q.getfront()<<endl;
    cout<<"empty or not: "<<q.isempty()<<endl;

    q.push(35);
    q.push(25);
    q.push(55);

    q.display();


}

