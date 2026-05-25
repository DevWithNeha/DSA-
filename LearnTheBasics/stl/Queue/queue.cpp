#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<string> q;

    q.push("neha");
    q.push("kumari");
    q.push("singh");

    cout<<"size of queue: "<<q.size()<<endl;
    q.pop();
    cout<<"first element: "<<q.front()<<endl;
}