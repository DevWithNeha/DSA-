
//#include<bits/stdc++.h>
// using namespace std;
// int majorityEle(vector<int> &arr){
//     map<int,int> mp;
//     int n = arr.size();
//     for(int i=0;i<n;i++){
//         mp[arr[i]]++;
//     }
//     for(auto it:mp){
//         if(it.second > (n/2)){
//             return it.first;
//         }
//     }
//     return -1;
// }

// int main(){
//     vector<int> arr = {2,5,3,5,2,4,2};
//     cout<<majorityEle(arr);
// }


// optimal solution  tc = o(n) sc =o(1)
#include<bits/stdc++.h>
using namespace std;

int majorityEle(vector<int> &arr){
    int count = 0;
    int b = 0;

    for(int i=0;i<arr.size();i++){
        if(count == 0){
            b = arr[i];
        }
        if(b == arr[i]){
            count++;
        }
        else{
            count--;
        }
    }
    return b;
}
int main(){
    vector<int> arr={2,2,5,2,2};
    cout<<majorityEle(arr);
}