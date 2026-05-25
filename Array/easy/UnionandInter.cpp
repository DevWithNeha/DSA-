// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> a = {1,2,3,4};
//     vector<int> b = {3,4,5,6};

//     int i=0;
//     int j=0;
//     int n = a.size();
//     int m = b.size();

//     cout<<"union: ";

//     while(i<n && j<m){
//         if(a[i]<b[j]){
//             cout<<a[i]<<" ";
//             i++;
//         }

//         else if(a[i]>b[j]){
//             cout<<b[j]<<" ";
//             j++;
//         }

//         else{
//             cout<<b[j]<<" ";
//             i++;
//             j++;
//         }
//     }
//     while(i<n){
//         cout<<a[i]<<" ";
//         i++;
//     }

//     while(j<m){
//         cout<<b[j]<<" ";
//         j++;
//     }

//     i = 0;
//     j = 0;

//     cout<<"\nintersection: ";

//     while(i<n && j<m){
//         if(a[i]<b[j]){
//             i++;
//         }

//         else if(a[i]>b[j]){
//             j++;
//         }
//         else{
//             cout<<a[i]<<" ";
//             i++;
//             j++;
//         }
//     }

    
// }


// set ke help se

// duplicate allow ni karta 
// element ko sorted order me rkhta hh
#include<bits/stdc++.h>
using namespace std;

int main(){

    int a[] = {1,2,3,4};
    int b[] ={3,4,5,6};

    int i=0,j=0;
    int n = 4,m=4;

    set <int> st;

    cout<<"union: ";

    for(int i=0;i<n;i++){
        st.insert(a[i]);
    }
    for(int j=0;j<m;j++){
        st.insert(b[j]);
    }

    for(int x:st) cout<<x<<" ";

 
    st.clear();

    cout<<"\n intersection: ";

    for(int i=0;i<n;i++){
        st.insert(a[i]);
    }
    for(int j=0;j<m;j++){
        if(st.count(b[j]))
        cout<<b[j]<<" ";
    }

}