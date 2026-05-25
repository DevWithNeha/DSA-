// brute force

/*

#include<bits/stdc++.h>
using namespace std;
int magicianandChocolate(vector<int>& arr,int k){
    int total = 0;
    int maxi = INT_MIN;

    while(k--){

        int maxi = INT_MIN;
        int index = -1;

        for(int i=0;i<arr.size();i++){
            if(arr[i] > maxi){
                maxi = arr[i];
                index = i;
            }    
        }
        total += maxi;

        arr[index] = maxi/2;
    }
    return total;
}

int main(){
    vector<int> arr = {2,4,8,6,5};

    int k = 3;

    cout<<magicianandChocolate(arr,k);
}

*/

// optimal sol

#include<bits/stdc++.h>
using namespace std;

int magicianandChocolate(vector<int>& arr,int k){
    priority_queue<int> pq;

    int total = 0;

    for(int x:arr){
        pq.push(x);
    }

    while(k--){
    int first = pq.top();
    pq.pop();

    total+= first;

    pq.push(first/2);

    }
    return total;
}

int main(){
     vector<int> arr = {2,4,8,6,5};

    int k = 3;

    cout<<magicianandChocolate(arr,k);
}


