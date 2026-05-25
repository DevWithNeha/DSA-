#include<bits/stdc++.h>
using namespace std;

vector<int> AsteroidCollision(vector<int> &arr){
    int n = arr.size();
    stack<int> st;

    for(int x:arr){
        bool destroy = false;

        while(!st.empty() && st.top() > 0 && x < 0){
            if(abs(st.top()) < abs(x)){
                st.pop();
            } else if(abs(st.top()) == abs(x)){
                st.pop();
                destroy = true;
                break;
            } else{
                destroy = true;
                break;
            }
        }

        if(!destroy) st.push(x);
    }

    vector<int> res;

    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }

    reverse(res.begin(),res.end());
    return res;
}

int main(){
    vector<int> arr = {5,10,-15};

    vector<int> res = AsteroidCollision(arr);

    for(int x:res){
        cout<<x<<" ";
    }
}