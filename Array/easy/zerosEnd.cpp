
/*
// total tc => O(2n)
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1,0,0,2,3,0,4,5};

    int n = arr.size();

    vector<int> temp;

    // non zero element sara collect kr rhe h  tc => O(n)
    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }

    }

        // non-zero element ko copy krke temp me daal rhe tc =>O(x)
      int nz = temp.size();

      for(int i = 0;i<nz;i++){
        arr[i] = temp[i];
      } 

      //bacha hua space me 0 daal rhe h  tc => O(n-x)
      for(int i=nz;i<n;i++){
        arr[i] = 0;
      }
    
     for(int x:arr) cout<<x<<" ";
}

*/


// tc = o(1)
// does not need any extra space aur array just need two pointer to solve it

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1,0,0,23,0,4};

    int n = arr.size();

    int j = -1;
    for(int i = 0;i<n;i++){
        if(arr[i] == 0) {
        j = i;
        break;
        }
    }

    for(int i = j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }

    for(int x:arr) cout<<x<<" ";
}