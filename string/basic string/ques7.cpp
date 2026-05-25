// #include<bits/stdc++.h>
// using namespace std;

// bool isAnagram(string s,string t){
//     if(s.size()!=t.size()) return false;

//     sort(s.begin(),s.end());
//     sort(t.begin(),t.end());

//     return s==t;
// }
// int main(){
//     string s = "listen";
//     string t = "silent";

//     if(isAnagram(s,t))
//         cout<<"Anagram";
//     else 
//         cout<<"not Anagram";
// }


// tc = O(n) sc = O(1)

/*
#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s,string t){
    if(s.size()!=t.size()) return false;

   int freq[26] = {0};

   for(int i=0;i<s.length();i++){
    freq[s[i] - 'a']++;
    freq[t[i] - 'a']--;
   }
   for(int i=0;i<26;i++){
    if(freq[i]!=0) return false;
   }
   return true;
}
int main(){
    string s = "listen";
    string t = "silent";

    if(isAnagram(s,t))
        cout<<"Anagram";
    else 
        cout<<"not Anagram";
}

*/

#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s,string t){
    if(s.length()!=t.length()) return false;

    unordered_map<char,int> mp;

    for(char ch:s){
        mp[ch]++;
    }

    for(char ch:t){
        mp[ch]--;
    }


    for(auto it:mp){
        if(it.second!=0) return false;
    }
    return true;
}

int main(){
    string s = "listen";
    string t = "silent";
    
    if(isAnagram(s,t))
        cout<<"anagram";
    else    
        cout<<"not anagran";
}