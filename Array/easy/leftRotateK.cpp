
// // isme koi extra space ni lga h
// // space complexity :- O(1) 

// #include<bits/stdc++.h>
// using namespace std;

// void leftRotate(vector<int> &arr,int k){
//     int n = arr.size();
//      k = k%n;

//     reverse(arr.begin(),arr.begin()+k);
//     reverse(arr.begin()+k,arr.end());
//     reverse(arr.begin(),arr.end());
// }

// int main(){
//     int k;
//     cout<<"enter k: ";
//     cin>>k;
    
//     vector<int> arr = {1,2,3,4,5};

//     leftRotate(arr,k);

//     for(int x:arr) cout<<x<<" ";

// }


// space complexity :- O(n)


// #include<bits/stdc++.h>
// using namespace std;
// void leftRotate(vector<int> &arr,int k){
//     int n = arr.size();
//      k = k%n;

//     vector<int> temp;

//      temp me k ke aage wala ko store karenge
//     for(int i = k;i<n;i++){
//         temp.push_back(arr[i]);
//     }
      
//      0 se k tk wale ko ussi temp me push karenge 
//      for(int i=0;i<k;i++){
//         temp.push_back(arr[i]);
//     }

//      phir use temp array ko main array me daal denge
//     for(int i=0;i<n;i++){
//         arr[i] = temp[i];
//     }
// }

// int main(){
//     vector<int> arr = {1,2,3,4,5};
//     int k;
//     cout<<"enter k: ";
//     cin>>k;
     
//     leftRotate(arr,k);

//     for(int x:arr) cout<<x<<" ";
// }

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1,2,3,4,5};

    int n = arr.size();
    int k =arr[0];

    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = k;

    for(int x:arr) cout<<x<<" ";
}