//space complexity = O(n)

/*

#include<bits/stdc++.h>
using namespace std;
void rightRotate(vector<int> &arr,int k){
    int n = arr.size();
    k=k%n;

    vector<int> temp;

    // n-k element ko temp array me push kro
    for(int i=n-k;i<n;i++){
        temp.push_back(arr[i]);
    }
    
    // starting ka element ko temp me push kro
    for(int i=0;i<n-k;i++){
        temp.push_back(arr[i]);
    }

    // temp array se saare element ko main array me daal do
    for(int i=0;i<n;i++){
        arr[i] = temp[i];
    }
}

int main(){
    int k;
    cout<<"enter k: ";
    cin>>k;

    vector<int> arr = {1,2,3,4,5};

    rightRotate(arr,k);

    for(int x:arr) cout<<x<<" ";
}

*/


// space complexity = O(1)

#include<bits/stdc++.h>
using namespace std;

void rightRotate(vector<int> &arr,int k){
    int n = arr.size();

    k = k%n;

        // reverse first (n-k) element
        reverse(arr.begin(),arr.begin() + (n-k));
        // reverse k element
        reverse(arr.begin() + (n-k),arr.end());
        // reverse whole array
        reverse(arr.begin(),arr.end());
    
}

int main(){
    int k;
    cout << "enter K: ";
    cin>>k;

    vector<int> arr = {1,2,3,4,5};

    rightRotate(arr,k);

    for(int x:arr) cout<<x<<" ";
}

