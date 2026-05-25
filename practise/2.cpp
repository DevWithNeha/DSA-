// #include<bits/stdc++.h>
// using namespace std;
// int maxconsecutiveone(vector<int> &arr){
//     int sum = 0;
//     int maxsum = 0;
//     for(int i=0;i<arr.size();i++){
//             sum += arr[i];
//         if(arr[i] == 0)
//             sum = 0;
//         }
//         maxsum = max(maxsum,sum);
//     }

// int main(){
//     vector<int> arr = {1,1,1,0,0,1,1,1,1};

//     cout<<maxconsecutiveone(arr);
// }

#include<bits/stdc++.h>
using namespace std;
int moore(vector<int> &arr){
    int candidate = 0;
    int count = 0;

    for(int i=0;i<arr.size();i++){
        if(count == 0){
            candidate = arr[i];
        }
        else if(candidate == arr[i]){
            count++;
        }
        else{
            count--;
        }
    }
    return candidate;
}

int main(){
    vector<int> arr = {2,2,2,1,3,4,2,2};

    cout<<moore(arr);
}