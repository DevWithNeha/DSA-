#include<bits/stdc++.h>
using namespace std;

/*
vector<int> stockspan(vector<int> &prices){
    int n = prices.size();
    vector<int> span(n);

    for(int i=0;i<n;i++){
        int count = 1;

        int j = i-1;

        while(j >= 0 && prices[j] <= prices[i]){
            count++;
            j--;
        }
        span[i] = count;
    }
    return span;
}
    */

vector<int> stockspan(vector<int> & prices){
    int n = prices.size();
    vector<int> span(n);
    stack<int> st;

    for(int i=0;i<n;i++){
        while(!st.empty() && prices[st.top()] < prices[i]){
            st.pop();
        }

        if(st.empty()) span[i] = i+1;
        else span[i] = i-st.top();

        st.push(i);
    }
    return span; 
}

int main(){
    vector<int> prices = {100,80,60,70,60,75,85};

     vector<int> res = stockspan(prices);

     for(int x:res){
        cout<<x<<" ";
     }
}