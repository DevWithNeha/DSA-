// brute force

/*

#include<bits/stdc++.h>
using namespace std;

int kthLargestEle(vector<int>& arr, int k){

    int n = arr.size();
    sort(arr.begin(),arr.end());

    return arr[n-k];
} 

int main(){
    vector<int> arr = {8,5,6,9,10,12};

    int k = 5;

    cout<<kthLargestEle(arr,k);

}


// better soolution


#include<bits/stdc++.h>
using namespace std;

int kthLargestEle(vector<int> &arr,int k){
    priority_queue<int> pq;

    for(int x:arr){
        pq.push(x);
    }

    int first;

    while(k--){
        first = pq.top();
        pq.pop();
    }
    return first;
}

int main(){
    vector<int> arr = {8,5,6,9,10,12};

    int k = 5;

    cout<<kthLargestEle(arr,k);
}

*/

#include<bits/stdc++.h>
using namespace std;

int kthLargestEle(vector<int>& arr,int k){
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i=k;i<arr.size();i++){
        if(arr[i] > pq.top()){
            pq.pop();

            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main(){
    vector<int> arr = {8,5,6,9,10,12};

    int k = 5;

    cout<<kthLargestEle(arr,k);
}
 