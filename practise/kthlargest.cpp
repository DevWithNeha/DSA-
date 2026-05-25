// using bs best in sorted array
/*
#include<bits/stdc++.h>
using namespace std;
int lessEle(vector<int>& arr,int mid){

    int count = 0;

    for(int x:arr){
        if(x<=mid){
            count++;
        }
    }
    return count;
}
int kthlargest(vector<int> &arr,int k){
    int n = arr.size();

    // kth largest -> kth smallest

    k = n-k+1;

    int low = *min_element(arr.begin() , arr.end());
    int high = *max_element(arr.begin() , arr.end());

    while(low <= high){

        int mid = (low+high)/2;
        
        int count = lessEle(arr,mid);

        if(count<k){
            low = mid+1;
        }else{
            high = mid-1;
        }

    }
    return low;

}

int main(){
    vector<int> arr = {1,2,3,4,5,6};

    int k = 4;

    cout<<kthlargest(arr,k);
}

*/

// using heap best in unsorted and sorted both

#include<bits/stdc++.h>
using namespace std;
int kthlargest(vector<int>& arr,int k){
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
    vector<int> arr = {1,2,3,4,5,6};

    int k = 4;

    cout<<kthlargest(arr,k);
}

