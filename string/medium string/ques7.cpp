// brute force solution 
// tc :- O(n3)


/*
#include<bits/stdc++.h>
using namespace std;

int BeautySubstr(string s){
    int n = s.size();
    int result = 0;

    for(int i=0;i<n;i++){
        for(int j = i;j<n;j++){
            vector<int> freq(26,0);

            for(int k = i;k<=j;k++){
                freq[s[k]-'a']++;
            }
            int maxi = 0,mini = INT_MAX;

            for(int f:freq){
                if(f>0){
                    maxi = max(maxi,f);
                    mini = min(mini,f);
                }
            }
            result += (maxi-mini);
        }
    }
    return result;
}

int main(){
    string s;
    cout<<"enter string: ";
    cin>>s;

    cout<<BeautySubstr(s);
}

*/

#include<bits/stdc++.h>
using namespace std;

int BeautySubstr(string s){
    int n = s.size();
    int result = 0;

    for(int i=0;i<n;i++){
        
         vector<int> freq(26,0);

        for(int j = i;j<n;j++){

            freq[s[j]-'a']++;
            
            int maxi = 0,mini = INT_MAX;

            for(int f:freq){
                if(f>0){
                    maxi = max(maxi,f);
                    mini = min(mini,f);
                }
            }
            result += (maxi-mini);
        }
    }
    return result;
}

int main(){
    string s;
    cout<<"enter string: ";
    cin>>s;

    cout<<BeautySubstr(s);
}