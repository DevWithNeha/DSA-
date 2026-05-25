#include<bits/stdc++.h>
using namespace std;

// class Minstack{
//     stack<pair<int,int>> st;

//     public:

//         Minstack() {}

//         void push(int val){
//             if(st.empty()){
//                 st.push({val,val});
//             } else{
//                 int mini = min(val,st.top().second);
//                 st.push({val,mini});
//             }
//         }

//         void pop(){
//             if(!st.empty()){
//                 st.pop();
//             }
//         }

//         int top(){
//             return st.top().first;
//         }

//         int getmin(){
//             return st.top().second;
//         }
// };

class Minstack{
    stack<long long> st;
    long long mini;

    public:
        Minstack() {}

        void push(int val){
            if(st.empty()){
                st.push(val);
                mini = val;
            } else if(val>=mini){
                st.push(val);
            } else{
                st.push(2LL * val - mini); // encode kr diye
                mini = val;
            }
        }

        void pop(){
            if(st.empty()) return;

            long long top = st.top();
            st.pop();

            if(top<mini){
                mini = 2*mini-top; // restore kro jisko encode kiye the
            }
        }

        int top(){
            long long top = st.top();

            if(top<mini) return mini;
            return top;
        }

        int getmin(){
            return mini;
        }
};

int main(){
    Minstack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout<<st.getmin()<<endl;
    st.pop();
    cout<<st.getmin()<<endl;
    st.pop();
    cout<<st.getmin()<<endl;
    
}