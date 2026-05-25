// linear search

/*
#include<bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr,int maxpages){
    int students = 1;
    int pages = 0;

    for(int i=0;i<arr.size();i++){
        if(pages+arr[i]<=maxpages){
            pages += arr[i];
        }
        else{
            students++;
            pages = arr[i];
        }
    }
return students;
}

int BookAllocated(vector<int> &arr,int m){
    int low = *max_element(arr.begin(),arr.end());
    int high = 0;
    for(int i=0;i<arr.size();i++){
        high +=arr[i];
    }

    for(int pages = low;pages<high;pages++){
        int students = countStudents(arr,pages);

        if(students<=m){
        return pages;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {25,46,28,49,24};
    int m = 4;

    cout<<BookAllocated(arr,m);
}

*/

// binary search

#include<bits/stdc++.h>
using namespace std;
int countStudents(vector<int> &arr,int maxpages){
    int students = 1;
    int pages = 0;

    for(int i=0;i<arr.size();i++){
        if(pages+arr[i]<=maxpages){
            pages +=arr[i];
        }
        else{
            students++;
            pages = arr[i];
        }
    }
    return students;
}

int BookAllocated(vector<int> &arr,int m){
    int low = *max_element(arr.begin(),arr.end());
    int high = 0;
    for(int i=0;i<arr.size();i++){
        high += arr[i];
    }

    while(low<=high){
        int mid = (low+high)/2;

        int students = countStudents(arr,mid);

        if(students>m){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {25,46,28,49,24};
    int m = 4;

    cout<<BookAllocated(arr,m);
}