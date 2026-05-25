#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s){
    unordered_map<char,int> mp;

    // frequency count karenge

    for(char ch:s){
        mp[ch]++;
    }

    //bucket bna lenge
    
    vector<string> bucket(s.size()+1);

    for(auto it:mp){
        char ch = it.first;
        int freq = it.second;

        bucket[freq] += string(freq,ch);
    }

    string result = "";

    for(int i=s.size();i>=0;i--){
        if(bucket[i]!=""){
            result += bucket[i];
        }
    }
    return result;
}

int main(){
    string s;
    cout<<"enter string: ";
    cin>>s;

    cout<<frequencySort(s);

}