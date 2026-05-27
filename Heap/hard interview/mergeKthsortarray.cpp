  // brute force using array

/*
#include<bits/stdc++.h>
using namespace std;

vector<int> mergekthSortArray(vector<vector<int>> &arr){

    vector<int> ans;

    // saare ele ko ans me push kro

    for(int i=0;i<arr.size();i++){
        for(int j = 0;j<arr.size();j++){
            ans.push_back(arr[i][j]);
        }
    }

    // sort kro

    sort(ans.begin() , ans.end());

    return ans;

}

int main(){
    vector<vector<int>> arr = {
        {1,4,7},
        {2,5,8},
        {3,6,9}
    };

    vector<int> ans = mergekthSortArray(arr);

    for(auto x:ans){
        cout<<x<<" ";
    }
}

*/

// better solution 

/*
#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int>& a,vector<int>& b){
    vector<int> ans;

    int i = 0;
    int j = 0;


    while(i<a.size() && j<b.size()){
        if(a[i] < b[j]){
            ans.push_back(a[i]);
            i++;
        } else{
            ans.push_back(b[j]);
            j++;
        }
    }

    while(i < a.size()){
        ans.push_back(a[i]);
        i++;
    }

    while(j < b.size()){
        ans.push_back(b[j]);
        j++;
    }
    return ans;
}
vector<int> mergeKthSortarray(vector<vector<int>> &arr){
    vector<int> ans = arr[0];


    for(int i=1;i<arr.size();i++){
        ans = merge(ans,arr[i]);
    }
    return ans;
}

int main(){
    vector<vector<int>> arr = {
        {1,4,7},
        {2,5,8},
        {3,6,9}
    };

    vector<int> ans = mergeKthSortarray(arr); 

    for(auto x:ans){
        cout<<x<<" ";
    }
}

*/

// optimal sol using min heap

#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    int row;
    int col;

    node(int data,int row,int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare{
    public:
    bool operator()(node* a , node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKArray(vector<vector<int>>& arr,int k){
    priority_queue<node*,vector<node*>,compare> minheap;

    // first ele of every array push 
    for(int i=0;i<k;i++){
        node* temp = new node(arr[i][0],i,0);

        minheap.push(temp);
    }

    vector<int> ans;

    // remove top and add into ans and add next col

    while(!minheap.empty()){
        //smallest element
        node* temp = minheap.top();
        minheap.pop();

        int element = temp->data;
        int row = temp->row;
        int col = temp->col;

        // store element
        ans.push_back(element);

        // next col push into min heap
        if(col+1 < arr[row].size()){
            node* next = new node(arr[row][col+1],row,col+1);

            minheap.push(next);
        }
    }
return ans;
} 

int main(){
    vector<vector<int>> arr = {
        {1,4,7},
        {2,5,8},
        {3,6,9}
    };

    int k = arr.size();

    vector<int> ans = mergeKArray(arr,k);

    for(auto x:ans){
        cout<<x<<" ";
    }
}

