
// better sol

//using priority queue

#include<bits/stdc++.h>
using namespace std;

vector<int> mergeTwoHeap(vector<int>& a,vector<int>& b){

    priority_queue<int> p;

    for(int x:a){
        p.push(x);
    }

    for(int x:b){
        p.push(x);
    }

    vector<int> ans;

    while(!p.empty()){
        ans.push_back(p.top());

        p.pop();
    }
    return ans;
}

int main(){
    vector<int> a = {10,20,15};
    vector<int> b = {30,40,50};

    vector<int> ans = mergeTwoHeap(a,b);

    for(int x:ans){
        cout<<x<<" ";
    }
}

// optimal solution

// using array and step down

// #include<bits/stdc++.h>
// using namespace std;
// void stepdown(vector<int>& arr,int n,int i){
//     while(true){
//         int left = 2*i+1;
//         int right = 2*i+2;

//         int largest = i;

//         if(left<n && arr[left] > arr[largest]){
//             largest = left;
//         }

//         if(right<n && arr[right] > arr[largest]){
//             largest = right;
//         }

//         if(largest == i) break;

//         swap(arr[i],arr[largest]);

//         i = largest;

//     }
// }

// vector<int> mergeTwoHeap(vector<int>& a,vector<int>& b){
 
//     vector<int> ans;

//     for(int x:a){
//         ans.push_back(x);
//     }

//     for(int x:b){
//         ans.push_back(x);
//     }

//     int n = ans.size();

//     for(int i = n/2-1;i>=0;i--){
//         stepdown(ans,n,i);
//     }
// return ans;
// }

// int main(){
//     vector<int> a = {10,20,15};
//     vector<int> b = {30,40,50};

//     vector<int> ans = mergeTwoHeap(a,b);

//     for(int x:ans){
//         cout<<x<<" ";
//     }
// }
