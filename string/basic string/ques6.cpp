// #include<bits/stdc++.h>
// using namespace std;
// bool RotateString(string s,string goal){
//     if(s.size()!=goal.size())  return false;

//     string temp = s+s;

//     if(temp.find(goal)!=-1) return true;
//     else return false;
// }
// int main(){
//     string s;
//     cin>>s;
//     string goal;
//     cin>>goal;

//     cout<<RotateString(s,goal);
// }


// in this code we return goal

#include<bits/stdc++.h>
using namespace std;
string RotateString(string s,string goal){
    if(s.size()!=goal.size()) {
        return "";
    }

    string temp = s+s;

    if(temp.find(goal)!=-1) return goal;
    else return "";
}
int main(){
    string s;
    cin>>s;
    string goal;
    cin>>goal;

    cout<<RotateString(s,goal);
}