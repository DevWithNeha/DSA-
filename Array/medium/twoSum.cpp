// brute solution

// #include<bits/stdc++.h>
// using namespace std;

// int main(){ 
//     vector<int> arr = {1,2,3,4,5};
//     int k = 15;
//     int n = arr.size();

//     bool found = false;

//     for(int i=0;i<n;i++){
//         // int sum = 0;
//         for(int j = i+1;j<n;j++){
//             // sum +=arr[j];
//             if(arr[i]+arr[j]==k){
//                 cout<<i<<" "<<j<<" ";
//                 found = true;
//             }
//         }
//     }
//             if(!found) cout<<"-1";      
// }
        
    



// better solution
// using hash map

#include<bits/stdc++.h>
using namespace std;

string twoSum(vector<int> &arr , int k){
    map<int,int> mp;
    
    for(int i=0;i<arr.size();i++){
        int a = arr[i];
        int b = k - a;
        if(mp.find(b) !=mp.end()){
            return "YES";
        }
        mp[a] = i;
    }
     return "no";
}
int main(){
    vector<int> arr = {5,4,3,2,1};
    int k = 15;

    cout<< twoSum(arr,k);
}

// better solution without use of hash map

// #include<bits/stdc++.h>
// using namespace std;

// string twoSum(vector<int> &arr , int k){
//     int n = arr.size();
//     int left = 0;
//     int right = n-1;
//     while(left<right){
//         int sum = arr[left]+arr[right];
//         if(sum==k){
//             return "yes";
//         }
//         else if(sum<k) left++;
//         else right--;

//     }
//     return "no";
// }
//     int main(){
//         vector<int> arr = {1,2,3,4,5};
//         int k = 5;

//         cout<< twoSum(arr,k);
//     }
