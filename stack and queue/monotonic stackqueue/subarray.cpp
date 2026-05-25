#include<bits/stdc++.h>
using namespace std;

/*
void subarray(vector<int> &arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=i;j<n;j++){
            temp.push_back(arr[j]);

            for(int x:temp){
                cout<< x <<" "; 
            }
            cout<<endl;
        }
    }
}

*/

/*
int sumofSubarray(vector<int> &arr){
    int n = arr.size();
    int total = 0;

    for(int i=0;i<n;i++){
        total += (long long) arr[i] * (i+1) * (n-i);
    }
    return total;
}

*/

int countSubarray(vector<int> &arr){
    int n = arr.size();
    
     return n* (n+1)/2;
}

int main(){
    vector<int> arr = {3,5,2};

//    subarray(arr);

//    cout<<sumofSubarray(arr);
      cout<<countSubarray(arr);

}