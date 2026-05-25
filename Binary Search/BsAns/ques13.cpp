// by taking extra space

// #include<bits/stdc++.h>
// using namespace std;

// int findmedian(vector<int>& a,vector<int>& b){
//     vector<int> merged;

//     int i=0 , j=0;

//     while(i<a.size() && j<b.size()){
//         if(a[i]<b[j]){
//             merged.push_back(a[i++]);
//         }else{
//             merged.push_back(b[j++]);
//         }
//     }
//     while(i<a.size()) merged.push_back(a[i++]);
//     while(j<b.size()) merged.push_back(b[j++]);

//     int n = merged.size();

//     if(n%2==1) return merged[n/2];
//     else return (merged[n/2]+merged[n/2-1])/2.0;

// }

// int main(){
//     vector<int> a = {1,2,3};
//     vector<int> b = {4,5};

//     cout<<findmedian(a,b);
// }


// not taking any extra space

#include<bits/stdc++.h>
using namespace std;

int median(vector<int>& a, vector<int>& b){
    int n1 = a.size() , n2 = b.size();


    // binary search hmesha smaller array pe apply hota h
    if(n1>n2) return median(b,a);

    int low = 0;
    int high = n1;
    int left = (n1+n2+1)/2;

    while(low<=high){
        int mid1 = (low+high)/2;
        int mid2 = left-mid1;

        int l1 = INT_MIN , l2 = INT_MIN;
        int r1 = INT_MAX , r2 = INT_MAX;

        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];

        if(mid1-1 >= 0) l1 = a[mid1-1];
        if(mid2-1 >= 0) l2 = b[mid2-1];

        if(l1<=r2 && l2<=r1){
            if((n1+n2)%2==1){
                return max(l1,l2);
            }else{
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
        }
        // move left
        else if(l1>r2){
            high = mid1-1;
        }
        //move right
        else{
            if(l2>r1){
                low = mid1+1;
            }
        }
    }
}

int main(){

    vector<int> a = {1,3,8};
    vector<int> b = {7,8,9,10};

    cout<<median(a,b);
}