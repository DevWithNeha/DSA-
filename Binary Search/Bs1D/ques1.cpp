// #include<bits/stdc++.h>
// using namespace std;

// int search(vector<int> &nums,int target){
//     int low = 0;
//     int high = nums.size()-1;
//     while(low<=high){
//         int mid = (low+high)/2;
//         if(nums[mid] == target) 
//             return mid;
        
//         else if(nums[mid]<target) low = mid+1;
//         else high = mid-1;
//     }
//     return -1;
// }

// int main(){
//     vector<int> nums = {1, 3, 5, 7, 9, 11};
//     int target = 7;

    
//     int result = search(nums, target);

//     if (result != -1)
//         cout << "Target found at index: " << result << endl;
//     else
//         cout << "Target not found" << endl;

//     return 0;
// }

// recursive way

#include<bits/stdc++.h>
using namespace std;

int search(vector<int> &nums,int low,int high,int target){
 
    if (low>high) 
        return -1;

        int mid = (low+high)/2;

        if(nums[mid] == target) 
            return mid;
        
        else if(nums[mid]<target) 
            return search(nums,mid+1,high,target);
        else 
            return search(nums,low,mid-1,target);
    
   
}

int main(){
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    int target = 7;

    
    int result = search(nums,0,nums.size()-1, target);

    if (result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}