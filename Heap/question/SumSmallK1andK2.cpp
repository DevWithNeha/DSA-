// brute force

/*
#include<bits/stdc++.h>
using namespace std;

int SumSmallestBetK1andK2(vector<int>& arr,int k1,int k2){
    sort(arr.begin(),arr.end());
    int sum = 0;
    
    for(int i=k1;i<k2-1;i++){
        sum += arr[i];
    }

    return sum;
}

int main(){
    vector<int> arr = {20,8,22,4,12,10,14};
    int k1 = 3;
    int k2 = 6;

    cout<<SumSmallestBetK1andK2(arr,k1,k2);
}



#include<bits/stdc++.h>
using namespace std;

int SumSmallestBetK1andK2(vector<int>& arr,int k1,int k2){
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int x:arr){
        pq.push(x);
    }

    int sum = 0;
    int count = 0;

    while(!pq.empty()){
        int top = pq.top();
        pq.pop();

        count++;

        if(count>k1 && count<k2){
            sum += top;
        }
        if(k2==count) break;
    }
    return sum;
}

int main(){
    vector<int> arr = {20,8,22,4,12,10,14};
    int k1 = 3;
    int k2 = 6;

    cout<<SumSmallestBetK1andK2(arr,k1,k2);
}




#include<bits/stdc++.h>
using namespace std;

int SumSmallestBetK1andK2(vector<int>& arr,int k1,int k2){
    priority_queue<int> pq;

    for(int x:arr){
        pq.push(x);

        if(pq.size() < k2-1){
            pq.pop();
        }
    }

    while(pq.size() > k2-k1-1){
        pq.pop();
    }

    int sum = 0;

    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
    }
    return sum;
}

int main(){
    vector<int> arr = {20,8,22,4,12,10,14}; 
    int k1 = 3;
    int k2 = 6;

    cout<<SumSmallestBetK1andK2(arr,k1,k2);
}

*/

#include<bits/stdc++.h>
using namespace std;

int SumSmallestBetK1andK2(vector<int>& arr,int k1,int k2){
    priority_queue<int> p1;
    priority_queue<int> p2;


    for(int i=0;i<k1;i++){
        p1.push(arr[i]);
    }

    for(int i=0;i<k2-1;i++){
        p2.push(arr[i]);
    }

    for(int i=k1;i<arr.size();i++){
        if(arr[i] < p1.top()){
            p1.pop();
            p1.push(arr[i]);
        }
    }

    for(int i=k2-1;i<arr.size();i++){
        if(arr[i] < p2.top()){
            p2.pop();
            p2.push(arr[i]);
        }
    }

    int sum1 = 0 ;
    int sum2 = 0;

    while(!p1.empty()){
        sum1+=p1.top();
        p1.pop();
    }

    while(!p2.empty()){
        sum2+=p2.top();
        p2.pop();
    }

    return sum2 - sum1;
}

int main(){
    vector<int> arr = {20,8,22,4,12,10,14}; 
    int k1 = 3;
    int k2 = 6;

    cout<<SumSmallestBetK1andK2(arr,k1,k2);
}