#include<bits/stdc++.h>
using namespace std;

class myqueue{
    public:
    stack<int> s1,s2;

    myqueue() {}

    void push(int x){
        s1.push(x);
    }

    int pop(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        int val = s2.top();
        s2.pop();
        return val;
    }

    int peek(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    bool empty(){
        return s1.empty() && s2.empty();
    }
};

int main(){
    myqueue q;

    q.push(10);
    q.push(20);
    q.push(30);

     cout << "Front: " << q.peek() << endl;  

    cout << "Popped: " << q.pop() << endl;  

    cout << "Front after pop: " << q.peek() << endl;

    cout<<"popped: "<<q.pop()<<endl;

    cout<<"next: "<<q.peek()<<endl;

    q.push(40);

    cout<<"queue element: ";
    while(!q.empty()){
    cout<<q.pop()<<" ";
}

return 0;
}