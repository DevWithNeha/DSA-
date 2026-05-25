// with extra space arr3



//#include<bits/stdc++.h>
// using namespace std;

// void merge(long long arr1[],long long arr2[],int n,int m){
//     long long arr3[n+m];
//     int left = 0;
//     int right = 0;
//     int index = 0;

//     while(left<n && right<m){
//         if(arr1[left]<=arr2[right]){
//             arr3[index]=arr1[left];
//             left++;
//         }
//         else{
//             arr3[index] = arr2[right];
//             right++;
//         }
//         index++;
//     }
//     while(left<n){
//         arr3[index++] = arr1[left++];
//     }
//     while(right<m){
//         arr3[index++] = arr2[right++];
//     }

//     for(int i=0;i<n+m;i++){
//         if(i<n){
//             arr1[i] = arr3[i];
//         }
//         else{
//             arr2[i-n] = arr3[i];
//         }
//     }
// }

// int main(){
//     int n,m;
//     cin>>n>>m;

//     long long arr1[n],arr2[m];

//     for(int i=0;i<n;i++){
//         cin>>arr1[i];
//     }
//     for(int i=0;i<m;i++){
//         cin>>arr2[i];
//     }

//     sort(arr1,arr1+n);
//     sort(arr2,arr2+m);

//     merge(arr1,arr2,n,m);

//     for(int i=0;i<n;i++){
//         cout<<arr1[i]<<" ";
//     }
//     cout<<endl;

//     for(int i=0;i<m;i++){
//         cout<<arr2[i]<<" ";
//     }

//     cout<<endl;
// }



// without any extra space
#include<bits/stdc++.h>
using namespace std;

int nextgap(int gap){
    if(gap<=1) return 0;
    return(gap/2)+(gap%2);
}

void merge(long long arr1[],long long arr2[],int n,int m){
    int gap = nextgap(n+m);

    while(gap>0){

        int i=0;
        int j = gap+i;
        
        while(j<n+m){
            if(i<n && j<n){
                if(arr1[i]>arr1[j])
                    swap(arr1[i],arr1[j]);
            }

            else if(i<n && j>=n){
                if(arr1[i]>arr2[j-n])
                    swap(arr1[i],arr2[j-n]);
            }

            else{
                if(arr2[i-n]>arr2[j-n])
                    swap(arr2[i-n],arr2[j-n]);
            }
            i++;
            j++;
        }
        gap = nextgap(gap);
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    long long arr1[n],arr2[m];

    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }

    sort(arr1,arr1+n);
    sort(arr2,arr2+m);

    merge(arr1,arr2,n,m);

    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<m;i++){
        cout<<arr2[i]<<" ";
    }

    cout<<endl;
}