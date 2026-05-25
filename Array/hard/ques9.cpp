

// #include<bits/stdc++.h>
// using namespace std;

// vector<int> findmissingRepeatingNumbers(vector<int> nums){
//     int n = nums.size();

//     long long sn = (n*(n+1))/2;
//     long long s2n = (n*(n+1)*(2*n+1))/6;

//     long long s = 0;
//     long long s2 = 0;

//     for(int i = 0;i<n;i++){
//         s += nums[i];
//         s2 += (long long) nums[i]* (long long)nums[i];
//     }

//     long long val1 = s - sn; // repeating - missing  (x-y)
//     long long val2 = s2 - s2n;// repeating2 - missing2 (x2-y2)

//     val2 = val2 / val1; // x+y

//     long long x = (val1 + val2) / 2; 
//     long long y = x - val1;

//     return {(int)x,(int)y};

// }

// int main(){
//     int n;
//     cin>>n;

//     vector<int> nums(n);
//     for(int i = 0;i<n;i++){
//         cin>>nums[i];
//     }

    
//     vector<int> ans = findmissingRepeatingNumbers(nums);

//     cout<<"repeating number: "<<ans[0]<<endl;
//     cout<<"missing number: "<<ans[1]<<endl;

// }


// with the help of hashing

#include<bits/stdc++.h>
using namespace std;

vector<int> findmissingRepeatingNumbers(vector<int> nums){
    int n = nums.size();

    // hash array to store frequency 
    vector<int> hash(n+1,0);

    for(int i=0;i<n;i++){
        hash[nums[i]]++;
    }

    int repeating = -1,missing = -1;

    for(int i =1;i<=n;i++){
        if(hash[i]==2) repeating = i;
        else if(hash[i]==0) missing = i;

        if(repeating != -1 && missing != -1)
        break;
    }
    return {repeating,missing};
}

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }

    
    vector<int> ans = findmissingRepeatingNumbers(nums);

    cout<<"repeating number: "<<ans[0]<<endl;
    cout<<"missing number: "<<ans[1]<<endl;


}