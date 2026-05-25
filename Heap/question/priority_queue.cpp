#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> p; // max heap

    p.push(20);
    p.push(10);
    p.push(23);
    p.push(34);
    p.push(2);

    // cout<<p.top();
 
    // p.pop();
    // cout<<p.top()<<" ";

    // cout<<p.size()<<endl;

    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }

    cout<<endl;

    priority_queue<int,vector<int>,greater<int>> pi;

    pi.push(20);
    pi.push(10);
    pi.push(23);
    pi.push(34);
    pi.push(2);

    while(!pi.empty()){
       cout<< pi.top()<<" ";
       pi.pop();
    }
}